#include "cell.h"

t_d_cell* createCell(int val, int nb_level){
    t_d_cell* cell = (t_d_cell*)malloc(sizeof(t_d_cell));
    cell->value = val;
    cell->nb_level = nb_level;
    cell->nexts = (t_d_cell**)malloc(nb_level*sizeof(t_d_cell*));
    for (int i = 0; i < cell->nb_level; i++){
        cell->nexts[i] = NULL;
    }
    return cell;
}

t_d_list createEmptyList (int max) {
    t_d_list list;
    list.max_lvl = max;
    list.heads = (t_d_cell**)malloc(list.max_lvl*sizeof(t_d_cell*));
    for (int i = 0; i < list.max_lvl; i++){
        list.heads[i] = NULL;
    }
    return list;
}

void insertHead(t_d_list* list, t_d_cell* cell){
    if (cell->nb_level > list->max_lvl){
        printf("Cannot insert a cell with more levels than the list\n");
        return;
    }

    if (list->heads[0] == NULL) {                                       // Pas besoin de mettre le -1 car le premier niveau de la liste est le 0 comme dansz une liste
        for (int i = 0; i < cell->nb_level; i++){
            cell->nexts[i] = list->heads[i];
            list->heads[i] = cell;
        }
    }else{
        for (int i = 0; i < cell->nb_level; i++){
            cell->nexts[i] = list->heads[i];
            list->heads[i] = cell;
        }
    }
}

void displayLevel(t_d_list list, int level){
    if (level > list.max_lvl) {
        printf("Cannot display at a greater level than the maximum level of the list\n");
        return;
    }
    t_d_cell *temp, *temp0;
    temp = list.heads[level];
    temp0 = list.heads[0];
    int x;

    if(temp != NULL) {                          // If the list is not empty
        while (temp != NULL) {
            x = 0;
            while ((temp0 != NULL) && (temp0->value != temp->value)) {              // The difference between the indexes of the two element at the level given and the level 0
                temp0 = temp0->nexts[0];
                x++;
            }
            for (int j = 0; j < x; j++) {
                printf("-----------");
            }
            printf("-->[ %2d|@-]", temp->value);
            temp0 = temp0->nexts[0];
            temp = temp->nexts[level];
        }
    }
    x = 0;
    while ((temp0!= NULL)){                     // If the list is empty
        temp0 = temp0->nexts[0];
        x++;
    }
    for (int j = 0; j < x; j++) {
        printf("-----------");
    }
    printf("-->NULL\n");
}

void displayAllLevels(t_d_list list){
    for (int i = 0; i < list.max_lvl; i++){
        printf("[list head_%d @-]", i);
        displayLevel(list, i);
    }
}

void insertCell(t_d_list* list, t_d_cell* cell){
    if (cell->nb_level > list->max_lvl){
        printf("Cannot insert a cell with more levels than the list\n");
        return;
    }

    if ((list->heads[0] == NULL) || (cell->value < list->heads[0]->value)){
        insertHead(list, cell);
        return;
    }

    for (int i = 0; i < cell->nb_level; i++) {
        t_d_cell *temp = list->heads[i];
        t_d_cell *prev = NULL;

        while (temp != NULL && temp->value < cell->value) {
            prev = temp;
            temp = temp->nexts[i];
        }

        if (prev == NULL) {
            cell->nexts[i] = list->heads[i];
            list->heads[i] = cell;
        } else if (temp == NULL) {
            prev->nexts[i] = cell;
        } else {
            prev->nexts[i] = cell;
            cell->nexts[i] = temp;
        }
    }
}



