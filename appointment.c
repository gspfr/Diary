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
        //printf("%s\n", surname);

        contact *cont = (contact*)malloc(sizeof(contact));
        cont->nexts = (contact**)malloc(list.max_lvl*sizeof(contact*));

        for (int j = 0; j<list.max_lvl; j++){
            cont->nexts[j] = NULL;
        }

        cont->firstname = (char*)malloc(strlen(firstname)+1);        //one char is one byte so no need to *sizof(char)
        strcpy(cont->firstname, toLowerString(firstname));

        cont->surname = (char*)malloc(strlen(surname)+1);
        strcpy(cont->surname, toLowerString(surname));

        insertContact(&list, cont);

        i++;
    }

    i = 0;
    contact *temp = list.heads[0];

    /*while (temp != NULL){
        printf("%d %s_%s\n",i, temp->surname, temp->firstname);
        temp = temp->nexts[0];
        i++;
    }*/

    printf("%s\n", list.heads[0]->firstname);
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

char* toLowerString(char *str){
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}