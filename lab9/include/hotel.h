#ifndef HOTEL_H_
#define HOTEL_H_

#define MAX_ROOMS 50
#define NAME_LEN 50

typedef struct
{
    char name[NAME_LEN];
} Guest;

typedef struct
{
    int number;
    Guest guest;
} Room;

typedef struct
{
    Room rooms[MAX_ROOMS];
    Guest guests[MAX_ROOMS];
    int roomCount;
    int guestCount;
} Hotel;

void initHotel(Hotel* hotel);
Room* nextFree(Hotel* hotel);
Room* byID(Hotel* hotel, int number);
Guest regGuest(const char* name);
void checkInGuest(Hotel* hotel, Guest guest, Room* room);
void checkOutGuest(Hotel* hotel, Guest guest);
void checkedInList(Hotel* hotel);

#endif // HOTEL_H_