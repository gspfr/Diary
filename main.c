#include "timer.h"
#include "menu.h"

int main() {

    

    /*for (int i = 0; i<list.max_lvl;i++) {
        contact *temp = list.heads[i];
        printf("level %d\n", i);
        int j = 0;
        while (temp != NULL) {
            printf("%d %s_%s %d niveaux\n",j, temp->surname, temp->firstname, temp->nb_level);
            temp = temp->nexts[i];
            j++;
        }
        printf("\n");
    }*/



    //createContactList();
    //menu();


    /*FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level;
    char *time_lvl0;
    char *time_all_levels;

    level = 8;
    while(level<=26){
        printf("%d", level);
        t_d_list list = createList(level);
        startTimer();
        if (classicSearch(list, 10000000)){
            printf("Value found !\n");
        }else {
            printf("Value not found\n");
        }
        stopTimer();
        displayTime();

        time_lvl0 = getTimeAsString(); // fonction du module timer

        startTimer();
        if (optimisedSearch(list, list.max_lvl-1, 10000000)){
            printf("Value FOUND !\n");
        }else{
            printf("Value not found\n");
        }
        stopTimer();
        displayTime();

        time_all_levels = getTimeAsString();
        fprintf(log_file,format,level,time_lvl0, time_all_levels);
        level++;
    }
    fclose(log_file);*/








    //savetimes();
    /*printf("Enter your name!");
    char* name = scanString();
    printf("%s",name);*/

    //menu();

    //printf("%d\n", strcmp("b", "a"));
    //contact_list list = createContactList();
    //printf("%d", strcmp(list.heads[0]->firstname, list.heads[0]->nexts[0]->firstname));

    /*FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level;
    char *time_lvl0;
    char *time_all_levels;

    level = 8;
    while(level<=25){
        printf("%d", level);
        t_d_list list = createList(level);
        startTimer();
        if (classicSearch(list, 100000)){
            printf("Value found !\n");
        }else {
            printf("Value not found\n");
        }
        stopTimer();
        displayTime();

        time_lvl0 = getTimeAsString(); // fonction du module timer

        startTimer();
        if (optimisedSearch(list, list.max_lvl-1, 100000)){
            printf("Value FOUND !\n");
        }else{
            printf("Value not found\n");
        }
        stopTimer();
        displayTime();

        time_all_levels = getTimeAsString();
        fprintf(log_file,format,level,time_lvl0, time_all_levels);
        level++;
    }
    fclose(log_file);*/
    return 0;
}
