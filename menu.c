#include "menu.h"

void menu(){
    int choice = 0;


    contact_list list = createContactList();

    while(choice!=9){
        printf("\n\nWhat do you want to do ?\n");
        printf("1.Search a contact at level 0\n2.Create an appointment\n3.Create a contact\n4.Display appointments with a contact\n5.Delete an appointment\n");
        printf("6.Save all the appointments\n7.Search a contact with multi-level search\n8.Exit\n");
        scanf("%d", &choice);
        getchar();
        printf("\n");
        switch (choice) {
            case 1:{
                printf("Enter the surname:\n");
                char* string = scanString();
                printf("\n");
                if (search_contact0(list, string)==1) {
                    printf("This person exists in your list\n");
                }else {
                    printf("This person doesn't exist in your list\n");
                }
                break;
            }
            case 2:{
                printf("Enter the surname of the contact:\n");
                char* string = scanString();
                printf("\n");
                appointment* temp2;
                if (search_contact0(list, string)==1){
                    contact *temp = list.heads[0];
                    while (temp != NULL){
                        if (strcmp(temp->surname, string) == 0){

                            temp2 = createAppointment(temp);
                            temp2->next = temp->appointments[0];
                            temp->appointments[0] = temp2;
                        }
                        temp = temp->nexts[0];
                    }
                }
                else{
                    printf("The contact doesn't exist in your list, let's create it :\n");
                    printf("Enter the first name:\n");
                    char *first_name = scanString();
                    printf("Enter the last name:\n");
                    char *last_name = scanString();
                    printf("\n");
                    contact *cont = createContact(first_name, last_name);
                    insertContact(&list, cont);

                    temp2 = createAppointment(cont);
                    cont->appointments[0] = temp2;
                }
                display_appointment(*temp2);
                break;
            }
            case 3:{
                printf("Enter the first name:\n");
                char *first_name = scanString();
                printf("Enter the last name:\n");
                char *last_name = scanString();
                printf("\n");
                contact *cont = createContact(first_name, last_name);
                insertContact(&list, cont);
                break;
            }
            case 4:{
                for (int i = 0; i<list.max_lvl;i++) {
                    contact *temp = list.heads[i];
                    printf("level %d\n", i);
                    int j = 0;
                    while (temp != NULL) {
                        printf("%d %s_%s %d niveaux\n", j, temp->surname, temp->firstname, temp->nb_level);
                        temp = temp->nexts[i];
                        j++;
                    }
                    printf("\n");
                }
                printf("Enter the surname of the contact:\n");
                char* string = scanString();
                printf("\n");
                contact * temp = list.heads[0];
                while (temp != NULL){
                    if (strcmp(temp->surname, string) == 0) {
                        appointment* printApp;
                        printApp = temp->appointments[0];
                        int i = 1;
                        if(temp->appointments[0]==NULL){
                            printf("You don't have any appointment with this contact !\n");
                            break;
                        }
                        while (printApp!=NULL){
                            printf("Appointment number %d:\n", i);
                            display_appointment(*printApp);
                            printf("\n");
                            printApp = printApp->next;
                            i++;
                        }
                        break;
                    }
                    temp = *temp->nexts;
                }
                break;
            }
            case 5:{
                printf("Enter the surname of the contact:\n");
                char* string = scanString();
                printf("\n");
                contact * temp = list.heads[0];
                while (temp != NULL){
                    if (strcmp(temp->surname, string) == 0) {
                        deleteAppointment(temp);
                        break;
                    }
                    temp = *temp->nexts;
                }
                break;
            }
            case 6:{
                save_appointment(list);
                break;
            }
            case 7:{
                printf("Enter the surname:\n");
                char* string = scanString();
                printf("\n");
                if (optimisedSearchContact(list, string) == 1){
                    printf("This person exists in your list\n");
                }else {
                    printf("This person doesn't exist in your list\n");
                }
                break;
            }
            case 8:{
                break;
            }
            default:{
                printf("Invalid input !\nPlease enter a number between 1 and 9");
                break;
            }
        }
    }
}