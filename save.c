#include "save.h"

void save_appointment(contact_list contacts){
    FILE *save_file = fopen("save.txt","w");
    contact* tempCont = contacts.heads[0];
    while(tempCont!=NULL) {
        appointment *temp = tempCont->appointments[0];
        while (temp != NULL) {
            fprintf(save_file, "Date : %d/%d/%d\n", temp->date.day, temp->date.month, temp->date.year);
            fprintf(save_file, "Time : %d hours %d minutes\n", temp->time.hour, temp->time.minute);
            fprintf(save_file, "Length : %d hours %d minutes\n", temp->length.hour, temp->length.minute);
            fprintf(save_file, "Purpose : %s\n\n", temp->purpose);
            temp = temp->next;
        }
        tempCont = *tempCont->nexts;
    }
    fclose(save_file);
}