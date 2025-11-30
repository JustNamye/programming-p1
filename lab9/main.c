#include <stdio.h>
#include <stdlib.h>
#include "include/hotel.h"

int main(void)
{
    Hotel hotel;
    initHotel(&hotel);

    Guest guest0 = regGuest("Maxim");
    Guest guest1 = regGuest("A3");
    Guest guest2 = regGuest("A5");

    checkInGuest(&hotel, guest0, nextFree(&hotel));
    checkInGuest(&hotel, regGuest("Artem"), nextFree(&hotel));
    checkInGuest(&hotel, regGuest("Oleg"), nextFree(&hotel));

    checkInGuest(&hotel, regGuest("A1"), nextFree(&hotel));
    checkInGuest(&hotel, regGuest("A2"), byID(&hotel, 2));
    checkInGuest(&hotel, guest1, nextFree(&hotel));
    checkInGuest(&hotel, regGuest("A4"), nextFree(&hotel));
    checkInGuest(&hotel, guest2, byID(&hotel, 10));
    checkInGuest(&hotel, regGuest("A6"), nextFree(&hotel));
    checkInGuest(&hotel, regGuest("A7"), nextFree(&hotel));
    checkInGuest(&hotel, regGuest("A8"), byID(&hotel, 4));

    checkInGuest(&hotel, regGuest("Bad1"), byID(&hotel, -1));
    checkInGuest(&hotel, regGuest("Bad2"), byID(&hotel, 999));

    printf("<--->\n");

    checkedInList(&hotel);
    puts("\nRooms:");
    roomsList(&hotel);
    puts("\nGuests:");
    guestList(&hotel);

    printf("<--->\n");

    checkOutGuest(&hotel, guest0);
    checkOutGuest(&hotel, guest1);
    checkOutGuest(&hotel, guest2);

    printf("<--->\n");

    checkedInList(&hotel);
    puts("\nRooms:");
    roomsList(&hotel);
    puts("\nGuests:");
    guestList(&hotel);

    return EXIT_SUCCESS;
}