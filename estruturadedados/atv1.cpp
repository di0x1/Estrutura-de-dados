#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int i, *vet;
    vet = (int *) malloc(10 * sizeof(int));
    if (vet) {

        printf("Memoria alocada com sucesso \n ");
        for (i=0;i<10;i++) {
            *(vet + i) = rand() % 100;
            printf("%d ",*(vet + i));
        }

    }
    return 0;
}