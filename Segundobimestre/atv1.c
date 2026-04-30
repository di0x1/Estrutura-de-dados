#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void push(int item);
void pop();
void imprimir();
int entrada_dados();
void gerarvalores();
int i,x;
typedef struct apelido_no{
    int dado;
    struct apelido_no *proximo;

}no;

no *top = NULL;

int main(){
    int opcao;
    int n;

    do{
        printf("\n\nMenu\n1.Empilhar \n2. Desenpilhar\n3. Imprimir \n4. Gerar valores");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                n = entrada_dados();
                push(n);
                break;

            case 2:
                pop();
                break;
            
            case 3:
                imprimir();
                printf("%d",x);
                break;
    
            case 4:
                gerarvalores();
                break;
            

        }

    }while(opcao !=5);

    return 0;
}

void push (int item){
    printf("\n Empilhando...\n");
    no *novo = malloc(sizeof(no));

    novo -> dado =item;
    novo -> proximo = top;
    top = novo;
    printf("\n Valor %d empilhando", novo->dado);

}

void pop(){
    printf("\n Desenpilhando");
    if (top == NULL)
        printf("A pilha esta vazia");
    else{
        no *temp;
        temp=top;
        top=top -> proximo;

        printf("\n Desenpilhado %d \n",temp->dado);
        free(temp);
    }  
}

void imprimir(){
    no *temp;
    temp = top;
    int tmp = temp -> dado;
    printf("\nImprimido \n");
    while(temp != NULL){
        printf("%d\n", temp -> dado);
        temp = temp -> proximo;
        i++;
        if(temp->dado > tmp){
            tmp = temp -> dado;
        }

        temp = temp ->proximo;

    }

    printf("%d maior numero",tmp);
}

int entrada_dados(){
    int valor;
    printf("\n Entre com empilhar");
    scanf("%d",&valor);
    return valor;
}

void gerarvalores(){

    int i;
    int recebe;

    for (i=0; i<5; i++){
        recebe = rand() % 10 + 100;
        push(recebe);
    }
}

