#include "list.h"
#include "timer.h"

t_d_list createList (int n){
    if (n > 0){
        int value = (int)pow(2, n) - 1;
        int *array = (int*)malloc(value * sizeof(int));

        for (int i = 0; i < value; i++){            // initialisation of the value at 0
            array[i] = 0;
        }

        for (int i = 0; i < n - 1; i++){
            for (int j = (int)pow(2, i+1) - 1; j < value - 1; j += (int)pow(2, i + 1)){
                array[j]++;
            }
        }

        t_d_list list = createEmptyList(n);                 // Creation of the list

        for (int i = value -1; i >= 0; i--){        // Creation of the cells and their insertion in the list
            insertCell(&list, i + 1, array[i] + 1); // creation of the cell with its value = i+1 and its number of level equal to the number found in the array
        }
        return list;

    }else if (n == 0){
        t_d_list list = createEmptyList(1);
        insertCell(&list, 1, 1);

        return list;
    }else {
        printf("Please enter a positive integer.\n");
        t_d_list list = createEmptyList(0);
        return list;
    }
}

int classicSearch(t_d_list list, int value){
    t_d_cell *temp = list.heads[0];
    while (temp != NULL){
        if (temp->value == value){
            return 1;
        }
        temp = temp->nexts[0];
    }
    return 0;
}

int optimisedSearch(t_d_list list, int level, int value){
    if (value < 1){
        printf("Give a value at least equal to 1\n");
        return 0;
    }
    t_d_cell *temp = list.heads[level], *prev = NULL;

    while (temp != NULL){
        if (temp->value == value) {                 // si la valeur est trouvée
            return 1;
        } else if (temp->value > value){                        // Si la valeur du temp est supérieur à la value recherché on refait la même fonction au niveau inférieur
            return optimisedSearch(list, level-1, value);
        }
        prev = temp;
        temp = temp->nexts[level];
    }
    return searchfromCell(prev, level-1, value);
}

int searchfromCell(t_d_cell *cell, int level, int value){
    t_d_cell *temp = cell, *prev = NULL;
    while (temp != NULL){
        if (temp->value == value){
            return 1;
        } else if (temp->value > value){
            return searchfromCell(prev, level-1, value);
        }
        prev = temp;
        temp = temp->nexts[level];
    }
    if (level != 0){
        return searchfromCell(prev, level-1, value);
    }
    return 0;
}

void savetimes(){
    FILE *log_file = fopen("log.txt", "w");
    char format[] = "%d\t %s\t%s\n";
    int level;
    char *time_lvl0;
    char *time_all_levels;
    level = 7;
    int array[10000];
    srand(time(NULL));
    for (int i =0; i < 10000; i++){
        int value = ((rand()<<15)|rand()) % (int)pow(2, 18)-1;
        array[i] = value;
        printf("%d\n", value);
    }

    //Eveything in a loop
    while (level < 28){

        //search at level 0
        t_d_list list = createList(level);
        startTimer();
        for (int i = 0; i < 10000; i++){
            classicSearch(list, array[i]);
        }
        stopTimer();

        //displayTime();
        time_lvl0 = getTimeAsString();

        //search at last level

        startTimer();
        for (int i =0; i < 10000; i++){
            optimisedSearch(list, level-1,array[i]);
        }
        stopTimer();

        //displayTime();
        time_all_levels = getTimeAsString();

        fprintf(log_file, format, level, time_lvl0, time_all_levels);


        level++;
    }
    //Close the document
    fclose(log_file);

    return;
}