#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"

void initHotel(Hotel *hotel)
{
    hotel->roomCount = 0;
    hotel->guestCount = 0;
}

int isFree(Room *room)
{
    return room->guest.name[0] == '\0';
}

Room *addRoom(Hotel *hotel)
{
    // check for room limit
    if (hotel->roomCount >= MAX_ROOMS)
    {
        puts("Not enough space for new room!");
        return NULL;
    }
    Room *room = &hotel->rooms[hotel->roomCount];
    room->number = hotel->roomCount;
    hotel->roomCount++;
    return room;
}

Room *nextFree(Hotel *hotel)
{
    for (int i = 0; i < hotel->roomCount; i++)
    {
        Room *room = &hotel->rooms[i];
        if (isFree(room))
        {
            return room;
        }
    }
    return addRoom(hotel);
}

Room *byID(Hotel *hotel, int number)
{
    if (number >= hotel->roomCount || number < 0)
    {
        return nextFree(hotel);
    }
    return &hotel->rooms[number];
}

Guest regGuest(const char *name)
{
    Guest guest;
    strncpy(guest.name, name, sizeof(guest.name) - 1);
    guest.name[sizeof(guest.name) - 1] = '\0';
    return guest;
}

int isGuestCheckedIn(Hotel *hotel, Guest guest)
{
    for (int i = 0; i < hotel->guestCount; i++)
    {
        if (strcmp(hotel->guests[i].name, guest.name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void checkInGuest(Hotel *hotel, Guest guest, Room *room)
{
    if (!isFree(room))
    {
        puts("This room is not free!");
        return;
    }
    if (isGuestCheckedIn(hotel, guest))
    {
        puts("This guest is already checked in!");
        return;
    }
    hotel->guests[hotel->guestCount++] = guest;
    room->guest = guest;
    printf("%s was checked in in room number %d\n", guest.name, room->number + 1);
}

void checkOutGuest(Hotel *hotel, Guest guest)
{
    if (!isGuestCheckedIn(hotel, guest))
    {
        puts("Guest is not checked in!");
        return;
    }
    for (int i = 0; i < hotel->roomCount; i++)
    {
        if (strcmp(hotel->guests[i].name, guest.name) == 0)
        {
            hotel->rooms[i].guest.name[0] = '\0';
            printf("Checked out %s from room number %d\n", guest.name, hotel->rooms[i].number+1);
            break;
        }
    }
    for (int i = 0; i < hotel->guestCount; i++)
    {
        if (strcmp(hotel->guests[i].name, guest.name) == 0)
        {
            for (int j = i; j < hotel->guestCount - 1; j++)
            {
                hotel->guests[j] = hotel->guests[j + 1];
            }
            hotel->guestCount--;
            break;
        }
    }
}

void checkedInList(Hotel *hotel)
{
    for (int i = 0; i < hotel->roomCount; i++)
    {
        Room *room = &hotel->rooms[i];
        printf("Room %d: ", room->number + 1);
        if (room->guest.name[0] != '\0')
            printf("%s\n", room->guest.name);
        else
            printf("Empty\n");
    }
}