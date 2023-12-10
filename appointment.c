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

    /*while (temp != NULL){
        printf("%d %s_%s %d niveaux\n",i, temp->surname, temp->firstname, temp->nb_level);
        temp = temp->nexts[0];
        i++;
    }*/

    /*for (int i = 0; i<list.max_lvl;i++){
        contact *temp = list.heads[i];
        printf("level %d\n\n\n\n", i);
        int j = 0;
        while (temp != NULL){
            //printf("%d %s_%s %d niveaux\n",j, temp->surname, temp->firstname, temp->nb_level);
            temp = temp->nexts[i];
            j++;
        }
        printf("\n\n\n\n\n\n");
    }*/


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


        if (previous == NULL) {             // Inserting at the beginning of the list
            newContact->nexts[0] = list->heads[0];
            list->heads[0] = newContact;
            newContact->nb_level = 4;
            newContact->nexts = (contact**)realloc(newContact->nexts, newContact->nb_level*sizeof(contact*));
            for (int j = 0; j<4; j++){
                newContact->nexts[j] = NULL;
            }
        } else {                            // Inserting in or at the end of the list
            previous->nexts[0] = newContact;
            newContact->nexts[0] = current;

            int level;
            for (level = 0; level < 3; level++) {
                if (newContact->surname[level] != previous->surname[level]) {
                    break;
                }
            }

            newContact->nb_level = 4 - level;
            newContact->nexts = (contact**)realloc(newContact->nexts, newContact->nb_level * sizeof(contact*));
            for (int j = 0; j < newContact->nb_level; j++) {
                newContact->nexts[j] = NULL;
            }

            if (newContact->nb_level > 1){
                for (int i = 1; i < newContact->nb_level; i++) {
                    contact *temp = list->heads[i];
                    contact *prev = NULL;

                    while (temp != NULL && (strcmp(newContact->surname, temp->surname) > 0)) {
                        prev = temp;
                        temp = temp->nexts[i];
                    }

                    if (prev == NULL) {
                        newContact->nexts[i] = list->heads[i];
                        list->heads[i] = newContact;
                    } else {
                        prev->nexts[i] = newContact;
                        newContact->nexts[i] = temp;
                    }
                }
            }





            /*if (strcmp(&previous->surname[0], &newContact->surname[0]) == 0){       // The first letter is the same

                if (strcmp(&previous->surname[1], &newContact->surname[1]) == 0){      // The second letter is the same

                    if (strcmp(&previous->surname[2], &newContact->surname[2]) == 0) {      // The third letter is the same
                        newContact->nb_level = 1;
                        newContact->nexts = (contact**)malloc(newContact->nb_level*sizeof(contact*));
                        for (int j = 0; j<newContact->nb_level; j++){
                            newContact->nexts[j] = NULL;
                        }
                    }else{      // The third letter is different
                        newContact->nb_level = 2;
                        newContact->nexts = (contact**)malloc(newContact->nb_level*sizeof(contact*));
                        for (int j = 0; j<newContact->nb_level; j++){
                            newContact->nexts[j] = NULL;
                        }
                    }

                    }else{      // The second letter is different
                    newContact->nb_level = 3;
                    newContact->nexts = (contact**)malloc(newContact->nb_level*sizeof(contact*));
                    for (int j = 0; j<newContact->nb_level; j++){
                        newContact->nexts[j] = NULL;
                    }
                }
            }else{          // The first letter is different
                newContact->nb_level = 4;
                newContact->nexts = (contact**)malloc(newContact->nb_level*sizeof(contact*));
                for (int j = 0; j<newContact->nb_level; j++){
                    newContact->nexts[j] = NULL;
                }
            }*/
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
    /*cont->nexts = (contact**)malloc(4*sizeof(contact*));

    for (int j = 0; j<4; j++){
        cont->nexts[j] = NULL;
    }*/
    cont->nexts = (contact**)malloc(sizeof(contact*));
    cont->firstname = (char*)malloc(strlen(firstname)+1);        //one char is one byte so no need to *sizof(char)
    strcpy(cont->firstname, toLowerString(firstname));

    cont->surname = (char*)malloc(strlen(surname)+1);
    strcpy(cont->surname, toLowerString(surname));
    cont->appointments = (appointment**) malloc(10* sizeof(appointment*));
    for(int i=0;i<10;i++){
        cont->appointments[i] = NULL;
    }
    return cont;
}

void display_appointment(appointment appointment1){
    printf("Date: %d / %d / %d\n", appointment1.date.day, appointment1.date.month, appointment1.date.year);
    printf("At : %dh%d during %d hour and %d minutes\n", appointment1.time.hour,appointment1.time.minute, appointment1.length.hour,appointment1.length.minute);
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

void auto_completion(contact_list list) {
    char search[4];
    printf("Enter first 3 letters : ");
    scanf("%3s", search);
    printf("Corresponding names :\n");
    for (int i = 0; i < 21898; i++) {
        char *temp =  list.heads[i]->surname;
        if (strncmp(temp, search, 3) == 0) {
            printf("%s\n", temp);
        }
    }
}

appointment* createAppointment(contact* Contact){
    appointment* newAppointement = (appointment*) malloc(sizeof (appointment));
    char* s = (char *) malloc(100*sizeof(char ));
    printf("Enter the date of the appointment in day/month/year format:\n");
    scanf("%d/%d/%d", &newAppointement->date.day, &newAppointement->date.month, &newAppointement->date.year);
    getchar();
    while(newAppointement->date.day<1 || newAppointement->date.day>31){
        printf("Please enter a valid value for the day !\n");
        scanf("%d", &newAppointement->date.day);
        getchar();
    }
    while(newAppointement->date.month<1 || newAppointement->date.month>12){
        printf("Please enter a valid value for the month !\n");
        scanf("%d", &newAppointement->date.month);
        getchar();
    }
    while(newAppointement->date.year<2023){
        printf("Please enter a valid value for the year !\n");
        scanf("%d", &newAppointement->date.year);
        getchar();
    }
    printf("Enter the time of the appointment in hour:minutes format:\n");
    scanf("%d:%d", &newAppointement->time.hour, &newAppointement->time.minute);
    getchar();
    while (newAppointement->time.hour<0 || newAppointement->time.hour>24){
        printf("Please enter a valid value for the hour !\n");
        scanf("%d", &newAppointement->time.hour);
        getchar();
    }
    while (newAppointement->time.minute<0 || newAppointement->time.minute>60){
        printf("Please enter a valid value for the hour !\n");
        scanf("%d", &newAppointement->time.minute);
        getchar();
    }
    printf("Enter the length of the appointment in hour:minutes format:\n");
    scanf("%d:%d", &newAppointement->length.hour, &newAppointement->length.minute);
    getchar();
    while (newAppointement->length.hour<0 || newAppointement->length.hour>24){
        printf("Please enter a valid value for the hour !\n");
        scanf("%d", &newAppointement->length.hour);
        getchar();
    }
    while (newAppointement->length.minute<0 || newAppointement->length.minute>60){
        printf("Please enter a valid value for the hour !\n");
        scanf("%d", &newAppointement->length.minute);
        getchar();
    }
    printf("Enter the purpose of the appointment:\n");
    scanf("%s", s);
    getchar();
    newAppointement->purpose = s;
    newAppointement->next = NULL;
    return newAppointement;
}

void deleteAppointment(contact* cont){
    appointment* printApp;
    printApp = cont->appointments[0];
    int i = 1;
    while (printApp!=NULL){
        printf("Appointment number %d:\n", i);
        display_appointment(*printApp);
        printf("\n");
        printApp = printApp->next;
        i++;
    }
    printf("Which appointment do you want to delete ? Select a number :");
    int del;
    scanf("%d", &del);
    printApp = cont->appointments[i-1];
    if(del==1){
        cont->appointments[0] = cont->appointments[0]->next;
    }
    else{
        cont->appointments[i-2]->next = cont->appointments[i-1]->next;
        free(printApp->purpose);
        free(printApp);
    }
}