#ifndef DIARY_MAIN__1__APPOINTMENT_H
#define DIARY_MAIN__1__APPOINTMENT_H

#include "list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

 struct Appointment{
    date date;
    starting_time time;
    length length;
    char* purpose;
    struct Appointment * next;
}typedef appointment;

typedef struct Contact{
    char* surname;
    char* firstname;
    struct Contact** nexts;
    int nb_level;
    appointment ** appointments;
}contact;

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
appointment* createAppointment(contact*);
int search_contact0(contact_list, char* );
void auto_completion(contact_list list);
void deleteAppointment(contact*);

int optimisedSearchContact(contact_list, char*);
int searchfromContact(contact*, int, char*);

#endif //DIARY_MAIN__1__APPOINTMENT_H
