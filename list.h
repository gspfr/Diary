#ifndef DIARY_LIST_H
#define DIARY_LIST_H

#include "cell.h"

t_d_list createList(int);
int classicSearch(t_d_list, int);
int optimisedSearch(t_d_list, int, int);
int searchfromCell(t_d_cell *cell, int, int);
void savetimes();




#endif //DIARY_LIST_H
