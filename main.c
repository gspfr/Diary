#include "list.h"

int main() {

    t_d_list list = createList(3);
    displayAllLevels(list);
    if (classicSearch(list, 3)){
        printf("Value found !\n");
    }else {
        printf("Value not found\n");
    }

    return 0;
}
