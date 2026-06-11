#include <stdio.h>

#include <stdlib.h>


 

void enquete (int item);

void desenquete();

void imprimir();

int entrada_dados();

void redestribuir();


 

typedef struct apelido_no{

   int dado;

   struct apelido_no *proximo;

}no;


 

no *frente = NULL;

no *fim = NULL;

no *frente2 = NULL;

no *fim2 = NULL;

no *frente3 = NULL;

no *fim3 = NULL;





int main(){
    int filas;
   int opcao;
   int fifi;

   int n;


 

   do{

       printf("\n \nmenu \n1. enfilerar \n");

       printf("2. desenfilerar \n3. imprimir \n4. sair \n");

       scanf("%d", &opcao);


 

       switch (opcao){


 

           case 1:

               n = entrada_dados();

               enquete(n);

               break;


 

           case 2:

               desenquete();

               break;


 

           case 3:

               imprimir();

               break;


 

           case 4:
                redistribuir();
               break;


 

           case 5:

               printf("Saindo...\n");

               break;


 

           

       }

   }while (opcao != 5);


 

   return 0;

}


 

void enquete(int item){

   printf("\n Enfilerando..");

   no *novo = malloc(sizeof(no));

   novo ->dado = item;

   novo ->proximo = NULL;

   if(frente == NULL){

       frente = novo;

   }else{

       fim ->proximo = novo;

       fim = novo;

   }


 

   printf("\n Valor %d enfileirado", novo->dado);

}


 

void desenquete(){

   printf("\n Desenfilerando");

   if(frente == NULL)

       printf("\n a fila esta vazia");

   else{

       no *temp = frente;

       frente = frente ->proximo;

       printf("\n Valor %d desenfileirado", temp->dado);

       if(frente == NULL)

           fim = NULL;

       free(temp);

   }

}





void imprimir(){

   no *temp = frente;

   printf("\n Imprimindo a fila \n");

   while(temp != NULL){

       printf("%d ", temp->dado);

       temp = temp ->proximo;

   }

   printf("\n");

}


 

int entrada_dados(){

   int n;

   printf("\n Digite um numero inteiro: ");

   scanf("%d", &n);

   return n;

}





void redistribuir(){
    no *temp = NULL;
    temp = frente;
    frente2 = temp;
    if(temp == NULL){
        printf("Sua fila esta vazia \n");
        
    }else{
        do{
            temp = temp -> proximo;
            frente2 = temp -> proximo;
            temp = temp -> proximo;
            
        }while(temp == NULL);
        
        free(frente);
        
    }
   

}


 