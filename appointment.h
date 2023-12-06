#ifndef DIARY_MAIN__1__APPOINTMENT_H
#define DIARY_MAIN__1__APPOINTMENT_H

#include "list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Contact{
    char* surname;
    char* firstname;
    struct Contact** nexts;
    int nb_level;
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

typedef struct {
    contact **heads;
    int max_lvl;
}contact_list;

typedef struct {
    contact person;
    appointment* all_appointment;
}calendar;


char *scanString();
char *entries_in_calendar(contact);

contact_list createContactList();
void insertContact(contact_list *, contact *);
contact_list createEmptyContactList (int);
char* toLowerString(char *);
contact *createContact(char *, char *);

void display_appointment(appointment);

#endif //DIARY_MAIN__1__APPOINTMENT_H
