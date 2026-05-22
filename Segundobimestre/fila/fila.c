#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void enfileirar(int item);
void desenfileirar();
void imprimir();
int entrada_dados();
void gerarvalores();
int i;

typedef struct apelido_no{
    int dado;
    struct apelido_no *proximo;

}no;

no *inicio = NULL;
no *fim = NULL;

int main(){
    int opcao;
    int n;

    do{
        printf("\n\nMenu\n1. Enfileirar \n2. Desenfileirar\n3. Imprimir \n4. Gerar valores\n5. Sair\n");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                n = entrada_dados();
                enfileirar(n);
                break;

            case 2:
                desenfileirar();
                break;

            case 3:
                imprimir();
                break;

            case 4:
                gerarvalores();
                break;

        }

    }while(opcao != 5);

    return 0;
}

void enfileirar(int item){
    printf("\n Enfileirando...\n");
    no *novo = malloc(sizeof(no));

    novo -> dado = item;
    novo -> proximo = NULL;

    if(inicio == NULL)
        inicio = novo;
    else
        fim -> proximo = novo;

    fim = novo;
    printf("\n Valor %d enfileirado", novo->dado);
}

void desenfileirar(){
    printf("\n Desenfileirando");
    if(inicio == NULL)
        printf("\n A fila esta vazia");
    else{
        no *temp;
        temp = inicio;
        inicio = inicio -> proximo;

        if(inicio == NULL)
            fim = NULL;

        printf("\n Desenfileirado %d \n", temp->dado);
        free(temp);
    }
}

void imprimir(){
    no *temp;
    temp = inicio;

    if(temp == NULL){
        printf("\n A fila esta vazia");
        return;
    }

    int tmp = temp -> dado;
    printf("\nImprimindo \n");
    while(temp != NULL){
        printf("%d\n", temp -> dado);

        if(temp->dado > tmp){
            tmp = temp -> dado;
        }

        temp = temp -> proximo;
        i++;
    }

    printf("%d maior numero", tmp);
}

int entrada_dados(){
    int valor;
    printf("\n Entre com o valor para enfileirar: ");
    scanf("%d", &valor);
    return valor;
}

void gerarvalores(){

    int i;
    int recebe;

    for(i = 0; i < 5; i++){
        recebe = rand() % 10 + 100;
        enfileirar(recebe);
    }
}
