#include "appointment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* scanString() {
    int ArraySize = 10; // Initial size of the array
    char* string = (char*)malloc(ArraySize * sizeof(char)); // Allocate memory for the array
    int index = 0; // Initialize array index
    while (1) {  // Until user presses Enter
        char c = getchar();
        if (c == '\n' || c == EOF) {
            string[index] = '\0'; // End of input
            break;
        } else {
            string[index] = c; // Stores the character in the array
            index++;
            if (index == ArraySize - 1) {// If the array is full, reallocate more memory
                ArraySize *= 2;
                string = (char*)realloc(string, ArraySize * sizeof(char));
            }
        }
    }
    return string;
}



contact_list createContactList(){
    printf("OK\n");
    FILE *file = fopen("C:\\Users\\Gabriel\\CLionProjects\\Diary\\noms2008nat_txt.txt", "r");
    contact_list list = createEmptyContactList(4);



    printf("OK\n");
    /*if (file == NULL){
        printf("ERROR opening the file.\n");
        return list;
    }else{
        printf("SUCCESS opening the file.\n");
    }
    printf("OK\n");


    //char lines[218981][50];  // Assurez-vous que la taille du tableau est suffisamment grande
    char **lines = NULL;
    lines = (char**)malloc(218981*sizeof(char*));
    for (int f = 0; f<218981; f++){
        lines[f] = (char*)malloc(50*sizeof(char));
    }

    int i = 0;

    while (fgets(lines[i], sizeof(lines[i]), file) != NULL) {
        lines[i][strcspn(lines[i], "\n")] = '\0';  // Supprimer le saut de ligne
        i++;
    }

    fclose(file);

    // Insérer les noms dans l'ordre décroissant
    for (int j = i - 1; j >= 0; j--) {
        contact *cont = (contact *)malloc(sizeof(contact));
        cont->nexts = (contact **)malloc(list.max_lvl * sizeof(contact*));
        for (int k = 0; k < list.max_lvl; k++) {
            cont->nexts[k] = NULL;
        }

        cont->firstname = (char *)malloc(strlen(lines[j]) + 1);
        strcpy(cont->firstname, lines[j]);
        cont->surname = NULL;
        //printf("%d %s\n", i - j, cont->firstname);
        insertContact(&list, cont);
    }

    // Afficher la liste
    contact *temp = list.heads[0];
    while (temp != NULL) {
        //printf("%s\n", temp->firstname);
        temp = temp->nexts[0];
    }


    return list;*/
    char line[50];
    int i =0;

    while (fgets(line, sizeof(line), file) != NULL){

        line[strcspn(line, "\n")] = '\0';
        contact *cont = (contact*)malloc(sizeof(contact));
        cont->nexts = (contact**)malloc(list.max_lvl*sizeof(contact*));
        for (int i = 0; i<list.max_lvl; i++){
            cont->nexts[i] = NULL;
        }
        cont->firstname = (char*)malloc(strlen(line)+1);        //one char is one byte so no need to *sizof(char)
        strcpy(cont->firstname, line);
        cont->surname = NULL;

        printf("%d %s\n",i, cont->firstname);
        i++;
        insertContact(&list, cont);
        //printf("%d\n", i);
    }


    contact *temp = list.heads[0];
    printf("%s\n", list.heads[0]->firstname);
    fclose(file);
    return list;
}

void insertContact(contact_list *list, contact *newContact){
    if (list == NULL || newContact == NULL) {
        printf("Invalid input.\n");
        return;
    }

    if (list->heads[0] == NULL) {       // The list is empty
        list->heads[0] = newContact;
        return;
    }else {
        contact *current = list->heads[0];
        contact *previous = NULL;

        while (current != NULL && (strcmp(newContact->firstname, current->firstname) > 0)) {     //Comparison of the strings firstname of the contact we want to insert and the current one
            /*We go to the next if the current is not NULL and if the result of strcmp is -1
             * meaning that the string firstname of the contact we want to insert is before in the alphabetic order*/
            previous = current;
            current = current->nexts[0];
        }

        if (previous == NULL) {
            newContact->nexts[0] = list->heads[0];
            list->heads[0] = newContact;
        } else {
            previous->nexts[0] = newContact;
            newContact->nexts[0] = current;
        }
    }


}

contact_list createEmptyContactList (int max) {
    contact_list list;
    list.max_lvl = max;
    list.heads = (contact**)malloc(list.max_lvl*sizeof(contact*));
    for (int i = 0; i < list.max_lvl; i++){
        list.heads[i] = NULL;
    }
    return list;
}

char *entries_in_calendar(contact person){
    char* contact_entry = (char*)malloc(50);
    snprintf(contact_entry, 100, "%s_%s", person.firstname, person.surname);
    for (int i = 0; contact_entry[i]; ++i) {
        contact_entry[i] = tolower(contact_entry[i]); // Converts to lowercase
    }
    return contact_entry;
}

