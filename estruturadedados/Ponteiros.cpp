#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

   int x = 10,y = 20,z = 100,N = 24;
   char tc = 'c';
   int *ptr1,*ptr2,*ptr3,*ptrN;
   char *ptr4;

   ptr1 = &x;
   ptr2 = &y;
   ptr3 = &z;
   ptr4 = &tc;
   ptrN = &N;



   printf("Valor de x: %d\n",x);
   printf("Valor de y: %d\n",y);
   printf("Valor de z: %d\n",z);
   printf("Valor de N: %d\n",N);
   printf("Valor de tc: %c\n",tc);

   printf("\n=====================================================\n");

   printf("Valor de x: %p\n",&x);
   printf("Valor de y: %p\n",&y);
   printf("Valor de z: %p\n",&z);
   printf("Valor de N: %p\n",&N);
   printf("Valor de tc: %p\n",&tc);

   printf("\n=====================================================\n");

   printf("Valor de ptr1: %p\n",&ptr1);
   printf("Valor de ptr2: %p\n",&ptr2);
   printf("Valor de ptr3: %p\n",&ptr3);
   printf("Valor de ptr4: %p\n",&ptr4);
   printf("Valor de ptrN: %p\n",&ptrN);

   printf("\n=====================================================\n");

   printf("Valor de ptr1: %p\n",ptr1);
   printf("Valor de ptr2: %p\n",ptr2);
   printf("Valor de ptr3: %p\n",ptr3);
   printf("Valor de ptr4: %p\n",ptr4);
   printf("Valor de ptrN: %p\n",ptrN);

   printf("\n=====================================================\n");

   printf("Vlr. onde prt1 aponta %d \n",*ptr1);
   printf("Vlr. onde prt2 aponta %d \n",*ptr2);
   printf("Vlr. onde prt3 aponta %d \n",*ptr3);
   printf("Vlr. onde prt4 aponta %d \n",*ptr4);
   printf("Vlr. onde prtN aponta %d \n",*ptrN);

   printf("\n=====================================================\n");

   printf("End. mem. onde ptr1 aponta = %p\n",&*ptr1);
   printf("End. mem. onde ptr2 aponta = %p\n",&*ptr2);
   printf("End. mem. onde ptr3 aponta = %p\n",&*ptr3);
   printf("End. mem. onde ptr4 aponta = %p\n",&*ptr4);
   printf("End. mem. onde ptrN aponta = %p\n",&*ptrN);

   printf("\n=====================================================\n");

   char nome[41];

   printf("Me informe seu nome completo:\n");
    fgets(nome, 41, stdin);

   int i;

   printf("Endereco de memoria da variavel, %p \n", &nome);

   for (i = 0; i<strlen(nome); i++) {

       printf("endereco de memoria de cada caractere %c = %p \n",nome[i],&nome[i]);
   }

   return 0;

}
