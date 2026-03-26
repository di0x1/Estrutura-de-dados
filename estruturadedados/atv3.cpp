#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int **mat, i, j;

    mat = (int **) malloc (5 * sizeof(int *));
    for (i = 0; i < 5; i++) {
        mat[i] = (int *) malloc (7 * sizeof(int));
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 7; j++) {
            mat[i][j] = rand () % 490 + 10;
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 7; j++) {
            printf ("%d ", mat[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
