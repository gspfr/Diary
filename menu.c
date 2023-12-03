#include "menu.h"

void menu(){
    int choice = 0;

    contact_list list = createContactList();

    while(choice!=9){
        printf("What do you want to do ?\n");
        printf("1.Search a contact\n2.Display appointment with a contact\n3.Create a contact\n4.Create an appointment\n5.Delete an appointment\n");
        printf("6.Save all the appointments\n7.Load a file with the appointments\n8.Display time to insert\n9.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:{
                printf("ouais1\n");
                break;
            }
            case 2:{
                printf("ouais2\n");
                break;
            }
            case 3:{
                printf("ouais3\n");
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