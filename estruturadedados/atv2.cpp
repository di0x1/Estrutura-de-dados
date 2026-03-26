#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int i, tam, *vet, *vet2;
    int ctd=0;
    printf("Tamanho do vetor \n ");
    scanf("%d", &tam);
    vet = (int *) malloc(tam * sizeof(int));
    if (vet) {

        printf("Memoria alocada com sucesso \n ");
        for (i=0;i<tam;i++) {
            *(vet + i) = rand() % 100;
            printf("%d ",*(vet + i));
        }
        for (i=0;i<tam;i++) {
            if (vet[i] % 2 == 0) {
                ctd++;
            }
        }
        int x;
        vet2 = (int *) malloc(ctd * sizeof(int));
        if (vet2) {
            printf("Memoria alocada com sucesso \n ");
            for (i=0;i<tam;i++) {
                if (*(vet + i) % 2 == 0) {

                    vet2[x] = vet[i];
                    x++;
                }
            }
        }
        printf("\n");

        for (i=0;i<ctd;i++) {
            printf(" par %d ",*(vet2 + i));
        }

        printf("%d \n",ctd);
    }



    return 0;
}