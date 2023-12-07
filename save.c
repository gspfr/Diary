//
// Created by franc on 03/12/2023.
//

#include "save.h"
void save_appointment(calendar calendar1){
    FILE *save_file = fopen("save.txt","w");
    char format[] = "%d\t%d\t%d\n" ;
    appointment* temp = calendar1.all_appointment;
    while(temp != NULL){
        fprintf(save_file, "Date : %d/%d/%d\n",temp->date.day, temp->date.month, temp->date.year);
        fprintf(save_file, "Time : %d hours %d minutes\n", temp->time.hour, temp->time.minute);
        fprintf(save_file, "Length : %d hours %d minutes\n", temp->length.hour, temp->length.minute);
        temp = NULL;
    }
    fclose(save_file);
}