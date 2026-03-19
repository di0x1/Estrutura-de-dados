#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int vet[10];
    int i=0;
    int *pid;
    pid = vet;
    int x=0;
    bool existe;

    for (i=0;i<10;i++) {
        do {
            vet[x] = rand() % 12;
            existe = false;
                for (x=0;x<10;x++)
                    if (vet[i] == vet[x])
                        existe = true;
        }while(existe);
    }

    for (i=0;i<9;i++) {
        printf("%d %p \n ",*(pid + i ), &*(pid + i));
    }

    return 0;
}

