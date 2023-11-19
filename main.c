#include "list.h"
#include "timer.h"

int main() {

    t_d_list list = createList(3);
    displayAllLevels(list);

    //startTimer();
    if (classicSearch(list, 7)){
        printf("Value found !\n");
    }else {
        printf("Value not found\n");
    }
    //stopTimer();
    //displayTime();

    startTimer();
    if (optimisedSearch(list, list.max_lvl-1, 7)){
        printf("Value FOUND !\n");
    }else{
        printf("Value not found\n");
    }
    //stopTimer();
    //displayTime();
    return 0;
}
