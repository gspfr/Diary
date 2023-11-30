#ifndef DIARY_MAIN__1__APPOINTMENT_H
#define DIARY_MAIN__1__APPOINTMENT_H

typedef struct {
    char* surname;
    char* firstname;

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

char *scanString();

#endif //DIARY_MAIN__1__APPOINTMENT_H
