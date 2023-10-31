#include "cell.h"

int main() {
    t_d_cell* cell;
    t_d_cell *cell2;
    t_d_cell *cell3;
    t_d_cell *cell4;

    cell = createCell(18, 4);
    cell2 = createCell(25, 1);
    cell3 = createCell(31, 2);
    cell4 = createCell(32, 5);

    t_d_cell* cell5;
    t_d_cell *cell6;
    t_d_cell *cell7;
    t_d_cell *cell8;

    cell5 = createCell(56, 3);
    cell6 = createCell(59, 5);
    cell7 = createCell(59, 1);
    cell8 = createCell(91, 3);

    /*t_d_cell* cell9;
    t_d_cell *cell10;

    cell9 = createCell(9, 3);
    cell10 = createCell(10, 3);

    t_d_cell* cell11;
    t_d_cell *cell12;
    t_d_cell *cell13;

    cell11 = createCell(11, 3);
    cell12 = createCell(12, 3);
    cell13 = createCell(13, 3);*/



    t_d_list list = createEmptyList(5);
    insertHead(&list, cell, 0);
    insertHead(&list, cell2, 0);
    insertHead(&list, cell3, 0);
    insertHead(&list, cell4, 0);

    insertHead(&list, cell5, 1);
    insertHead(&list, cell6, 1);
    insertHead(&list, cell7, 1);
    insertHead(&list, cell8, 1);

    /*insertHead(&list, cell9, 2);
    insertHead(&list, cell10, 2);
    insertHead(&list, cell11, 3);
    insertHead(&list, cell12, 3);
    insertHead(&list, cell13, 3);*/

    //displayLevel(list, 0);
    displayAllLevels(list);
    return 0;
}
