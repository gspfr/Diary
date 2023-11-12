#include "list.h"

t_d_list createList (int n){
    if (n > 0){
        int value = (int)pow(2, n) - 1;
        int *array = (int*)malloc(value * sizeof(int ));
        //printf("%d\n", value);

        for (int i = 0; i < value; i++){            // initialisation of the value at 0
            array[i] = 0;

            if (i % 2 == 1){
                array[i]++;
            }
            if (i % 4 == 3){
                array[i]++;
            }
        }

        int max = array[0];                         // Searching for the maximum number of level of the cells
        for (int i = 1; i < value; i++){
            if (array[i] > max){
                max = array[i];
            }
        }
        //printf("%d\n", max);

        t_d_list list = createEmptyList(max+1);                 // Creation of the list

        for (int i = 0; i < value; i++){                        // Creation of the cells and their insertion in the list
            t_d_cell *cell = createCell(i+1, array[i]+1);         // creation of the cell with its value = i+1 and its number of level equal to the number found in the array
            insertCell(&list, cell);
        }

        return list;

    }else if (n == 0){
        t_d_cell *cell = createCell(1, 1);
        t_d_list list = createEmptyList(1);
        insertCell(&list, cell);

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


