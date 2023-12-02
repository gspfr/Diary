#ifndef DIARY_MAIN__1__APPOINTMENT_H
#define DIARY_MAIN__1__APPOINTMENT_H

#include "list.h"
#include <string.h>

typedef struct Contact{
    char* surname;
    char* firstname;
    struct Contact** nexts;
}contact;

typedef struct {
    int day;
    int month;
    int year;
}date;

typedef struct {
    int hour;
    int minute;
}starting_time;

typedef struct {
    int hour;
    int minute;
}length;

typedef struct {
    char* reason;
}purpose;

typedef struct {
    date date;
    starting_time time;
    length length;
    purpose purpose;
}appointment;


typedef struct t{
    contact **heads;
    int max_lvl;
}contact_list;

char *scanString();

contact_list createContactList();
void insertContact(contact_list *, contact *);
contact_list createEmptyContactList (int max);



#endif //DIARY_MAIN__1__APPOINTMENT_H
