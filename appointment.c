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
    FILE *file = fopen("C:\\Users\\Gabriel\\CLionProjects\\Diary\\noms2008nat_txt.txt", "r");
    contact_list list = createEmptyContactList(4);

    if (file == NULL){
        printf("ERROR opening the file.\n");
        return list;
    }else{
        printf("SUCCESS opening the file.\n");
    }

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