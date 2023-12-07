#include "menu.h"

void menu(){
    int choice = 0;

    contact_list list = createContactList();
    appointment appointment1;
    char *s = "ouais";
    appointment1.purpose = s;
    appointment1.length.hour = 1;
    appointment1.length.minute = 30;
    appointment1.time.hour = 10;
    appointment1.time.minute = 0;
    appointment1.date.day = 6;
    appointment1.date.month = 12;
    appointment1.date.year = 2023;
    while(choice!=9){
        printf("What do you want to do ?\n");
        printf("1.Search a contact\n2.Display appointment with a contact\n3.Create a contact\n4.Create an appointment\n5.Delete an appointment\n");
        printf("6.Save all the appointments\n7.Load a file with the appointments\n8.Display time to insert\n9.Exit\n");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:{
                printf("ouais1\n");
                char* string = scanString();
                printf("%d", search_contact0(list, string));
                break;
            }
            case 2:{
                printf("ouais2\n");
                display_appointment(appointment1);
                break;
            }
            case 3:{
                printf("Enter the first name:\n");
                char *first_name = scanString();
                printf("Enter the last name:\n");
                char *last_name = scanString();
                contact *cont = createContact(first_name, last_name);
                insertContact(&list, cont);
                break;
            }
            case 4:{
                printf("ouais4\n");
                break;
            }
            case 5:{
                printf("ouais5\n");
                break;
            }
            case 6:{
                printf("ouais6\n");
                break;
            }
            case 7:{
                printf("ouais7\n");
                break;
            }
            case 8:{
                printf("ouais8\n");
                break;
            }
            case 9:{
                break;
            }
            default:{
                printf("Invalid input !\n");
                break;
            }
        }
    }
}