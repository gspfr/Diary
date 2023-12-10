#include "appointment.h"


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
    FILE *file_surname = fopen("noms2008nat_txt.txt", "r");
    FILE *file_firstname = fopen("nat2021.csv", "r");
    contact_list list = createEmptyContactList(4);


    char firstname[50];
    char surname[50];
    int i =0;

    while (fgets(firstname, sizeof(firstname), file_firstname) != NULL && i < 21898){
        firstname[strcspn(firstname, "\n")] = '\0';
        //printf("%s ", firstname);

        for (int k = 0; k < 10; k++){
            if (fgets(surname, sizeof(surname), file_surname) == NULL) {
                // Gérer l'échec de lecture du fichier des noms
                printf("Erreur de lecture du fichier des noms.\n");
                fclose(file_firstname);
                fclose(file_surname);
                return list;
            }
            surname[strcspn(surname, "\n")] = '\0';
        }
        contact *cont = createContact(firstname, surname);
        insertContact(&list, cont);

        i++;
    }

    i = 0;
    contact *temp = list.heads[0];

    fclose(file_firstname);
    fclose(file_surname);
    return list;
}

void insertContact(contact_list *list, contact *newContact){
    if (list == NULL || newContact == NULL) {
        printf("Invalid input.\n");
        return;
    }

    if (list->heads[0] == NULL) {       // The list is empty
        list->heads[0] = newContact;
        newContact->nb_level = 4;
        newContact->nexts = (contact**)realloc(newContact->nexts, newContact->nb_level*sizeof(contact*));
        for (int j = 0; j<4; j++){
            newContact->nexts[j] = NULL;
            list->heads[j] = newContact;
        }
        return;
    }else {
        contact *current = list->heads[0];
        contact *previous = NULL;

        while (current != NULL && (strcmp(newContact->surname, current->surname) > 0)) {     //Comparison of the strings firstname of the contact we want to insert and the current one
            /*We go to the next if the current is not NULL and if the result of strcmp is -1
             * meaning that the string firstname of the contact we want to insert is before in the alphabetic order*/
            previous = current;
            current = current->nexts[0];
        }


        if (previous == NULL) {             // Inserting at the beginning of a list
            newContact->nexts[0] = list->heads[0];
            list->heads[0] = newContact;
            newContact->nb_level = 4;
            newContact->nexts = (contact**)realloc(newContact->nexts, newContact->nb_level*sizeof(contact*));
            for (int j = 0; j<4; j++){
                newContact->nexts[j] = current;
                list->heads[j] = newContact;
            }
            if (newContact->nexts[0] != NULL && newContact->nb_level == newContact->nexts[0]->nb_level){
                contact *temp = newContact->nexts[0];
                newContact->nexts[0] = newContact->nexts[0]->nexts[0];
                insertContact(list, temp);
            }
        } else {                            // Inserting in or at the end of the list
            int level;
            for (level = 0; level < 4; level++) {
                if (newContact->surname[level] != previous->surname[level]) {
                    break;
                }
            }

            newContact->nb_level = 4 - level;
            newContact->nexts = (contact**)realloc(newContact->nexts, newContact->nb_level * sizeof(contact*));
            for (int j = 0; j < newContact->nb_level; j++) {
                newContact->nexts[j] = NULL;
            }

            if (newContact->nb_level > 0){      // Inserting at each level
                for (int i = 0; i < newContact->nb_level; i++) {
                    contact *temp = list->heads[i];
                    contact *prev = NULL;

                    while (temp != NULL && (strcmp(newContact->surname, temp->surname) > 0)) {
                        prev = temp;
                        temp = temp->nexts[i];
                    }

                    if (prev == NULL && strcmp(newContact->surname, temp->surname) != 0) {
                        newContact->nexts[i] = list->heads[i];
                        list->heads[i] = newContact;
                    } else if (temp != NULL && strcmp(newContact->surname, temp->surname) != 0){
                        prev->nexts[i] = newContact;
                        newContact->nexts[i] = temp;
                    }else{
                        prev->nexts[i] = newContact;
                        newContact->nexts[i] = NULL;
                    }
                }

                for(int i = 0; i <newContact->nb_level; i++){
                    if (newContact->nexts[i] != NULL && newContact->nb_level == newContact->nexts[i]->nb_level){
                        if (strcmp(newContact->surname, newContact->nexts[i]->surname) != 0){
                            contact *temp = newContact->nexts[i];
                            newContact->nexts[i] = newContact->nexts[i]->nexts[i];
                            newContact->nexts[newContact->nb_level-1] = newContact->nexts[newContact->nb_level-1]->nexts[newContact->nb_level-1];
                            insertContact(list, temp);
                        }
                    }
                }
            }
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

char* toLowerString(char *str){
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

contact *createContact(char *firstname, char *surname){
    contact *cont = (contact*)malloc(sizeof(contact));
    cont->nexts = (contact**)malloc(sizeof(contact*));
    cont->firstname = (char*)malloc(strlen(firstname)+1);        //one char is one byte so no need to *sizof(char)
    strcpy(cont->firstname, toLowerString(firstname));

    cont->surname = (char*)malloc(strlen(surname)+1);
    strcpy(cont->surname, toLowerString(surname));
    return cont;
}

void display_appointment(appointment appointment1){
    printf("Date: %d/%d/%d\n", appointment1.date.day, appointment1.date.month, appointment1.date.year);
    printf("At : %dh%d during %dh%d\n", appointment1.time.hour,appointment1.time.minute, appointment1.length.hour,appointment1.length.minute);
    printf("Purpose: %s\n", appointment1.purpose);
}

int search_contact0(contact_list contactList, char* name){
    contact *temp = contactList.heads[0];
    while (temp != NULL){
        if (strcmp(temp->surname, name) == 0){
            return 1;
        }
        temp = temp->nexts[0];
    }
    return 0;
}

