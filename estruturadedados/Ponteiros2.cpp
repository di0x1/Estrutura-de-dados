#include <stdio.h>
int main() {
    char nome[50] = "Moreno";
    char *pp,**pp1;

    pp = nome;
    pp1 = &pp;

    printf("Variavel nome: %s \n",nome);
    printf("Usando ponteiro: %s \n",pp);
    printf("Usando ponteiro de ponteiro: %s \n",*pp1);

    // printf("2o caractere usando pp com [] %s \n",pp1[2]);
    // for (int i = 3; i < 3; i++) {
    //printf("3o caractere usando aritimetica %s \n",*(nome + i));
    //}

    int idade = 20;
    int *pid,**ppid;

    pid = &idade;
    ppid = &pid;

    printf("Variavel idade: %d \n",idade);
    printf("Usando ponteiro: %d \n",*pid);
    printf("Usando ponteiro de ponteiro: %d \n",**ppid);

    printf("End. Nome: %p \n",&nome);
    printf("End. ponteiro de nome %p \n",&pp);
    printf("End. ponteiro de ponteiro %p \n",pp1);

    printf("End. Idade: %p \n",&idade);
    printf("End. ponteiro de nome %p \n",&pid);
    printf("End. ponteiro de ponteiro %p \n",ppid);

    printf("End. onde ponteiro de nome aponta %p \n",*pp);
    printf("End. ponteiro de ponteiro de nome aponta %p \n",**pp1);


    return 0;
}