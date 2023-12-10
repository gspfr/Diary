#include "timer.h"
#include "menu.h"

int main() {
    printf("%d\n", strcmp("jean", "jean"));
    menu();

    /*for (int i = 0; i<list.max_lvl;i++) {
        contact *temp = list.heads[i];
        printf("level %d\n", i);
        int j = 0;
        while (temp != NULL) {
            printf("%d %s_%s %d niveaux\n",j, temp->surname, temp->firstname, temp->nb_level);
            temp = temp->nexts[i];
            j++;
        }
        printf("\n");
    }*/
    return 0;
}
