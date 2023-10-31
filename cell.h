#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H


#include <stdio.h>
#include <stdlib.h>

typedef struct s_d_cell
{
    int value, nb_level;
    struct s_d_cell** nexts;
} t_d_cell;

typedef struct s_d_list
{
    t_d_cell** heads;
    int max_lvl;
} t_d_list;

t_d_cell* createCell(int, int);
t_d_list createEmptyList(int);
void insertHead(t_d_list*, t_d_cell*, int);
void displayLevel(t_d_list, int);
void displayAllLevels(t_d_list list);
void insertCell(t_d_list* list, t_d_cell* cell);

#endif //UNTITLED_CELL_H
