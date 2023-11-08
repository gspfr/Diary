#include "cell.h"

int main() {
    t_d_cell* cell;
    t_d_cell *cell2;
    t_d_cell *cell3;
    t_d_cell *cell4;

    cell = createCell(25, 4);
    cell2 = createCell(18, 2);
    cell3 = createCell(23, 3);
    cell4 = createCell(32, 5);

    t_d_cell* cell5;
    t_d_cell *cell6;
    t_d_cell *cell7;
    t_d_cell *cell8;

    cell5 = createCell(56, 3);
    cell6 = createCell(59, 5);
    cell7 = createCell(59, 1);
    cell8 = createCell(91, 3);


    t_d_list list = createEmptyList(5);
    insertCell(&list, cell);
    insertCell(&list, cell2);
    insertCell(&list, cell3);
    insertCell(&list, cell4);

    insertCell(&list, cell5);
    insertCell(&list, cell6);
    insertCell(&list, cell7);
    insertCell(&list, cell8);


    displayAllLevels(list);
    return 0;
}
