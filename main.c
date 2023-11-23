#include "list.h"
#include "timer.h"

int main() {
    startTimer();
    t_d_list list = createList(27);
    stopTimer();
    displayTime();

    if (optimisedSearch(list, list.max_lvl-1, 25001)){
        printf("Value FOUND !\n");
    }else{
        printf("Value not found\n");
    }

    startTimer();
    if (classicSearch(list, 25001)){
        printf("Value found !\n");
    }else {
        printf("Value not found\n");
    }
    stopTimer();
    displayTime();

    return 0;
}
