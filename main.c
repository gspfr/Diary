#include "list.h"
#include "timer.h"

int main() {
    //savetimes();
    FILE *log_file = fopen("log.txt","w");
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
    fclose(log_file);
    return 0;
}
