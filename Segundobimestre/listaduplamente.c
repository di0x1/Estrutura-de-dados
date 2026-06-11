/*Construir um programa em linguagem C que implemente uma lista DUPLAMENTE encadeada.
O programa deverá possuir as seguintes opções no menu:
- inserir no inicio
- inserir no fim
- inserir no meio
- apresentar a quantidade de elementos da lista (criar funcao)
- inserir 10 elementos sorteados //sorteio inclusive se é inicio, meio ou fim)
- apresentar lista
- remover elemento
- sair
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct apelido_no{
   int valor;
   struct apelido_no *ant;
   struct apelido_no *prox;
}no;


//-------------------------------------
int main(){
    srand(time(NULL));
    no *lista = NULL;
    int opcao, valor, anterior;
    do{
        system("cls");
        printf("1 inserir no inicio\n");
        printf("2 inserir no final\n");
        printf("3 inserir no meio\n");
        printf("4 inserir 10 aleatorios\n");
        printf("5 remover\n");
        printf("6 listar\n");
        printf("7 fim\n\n");
        printf("  OPCAO: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nvalor a inserir: ");
            fflush(stdin);
            scanf("%d", &valor);
            inserir_inicio(&lista, valor);
            break;
        case 2:
            printf("\nvalor a inserir: ");
            fflush(stdin);
            scanf("%d", &valor);
            inserir_fim(&lista, valor);
            break;
        case 3:
            printf("\nvalor a inserir: ");
            fflush(stdin);
            scanf("%d", &valor);
            printf("valor de referencia (inserir apos valor: )");
            fflush(stdin);
            scanf("%d", &anterior);

            inserir_meio(&lista, valor, anterior);
            break;
        case 4:
            // aleatorio
            inserir_aleatorio(&lista);
            break;
        case 5:
            printf("\nvalor a remover: ");
            fflush(stdin);
            scanf("%d", &valor);
            remover_no(&lista, valor);
            break;

        case 6:
            imprimir(lista);
            break;
        }
    } while (opcao != 7);
    system("pause");
    return 0;
}

void inserir_inicio(no **lista, int valor){
    no *novo = (no *)malloc(sizeof(no));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = *lista;
    if (*lista != NULL)
        (*lista)->ant = novo;
    *lista = novo;
}

void inserir_fim(no **lista, int valor){
    no *novo = (no *)malloc(sizeof(no));
    novo->valor = valor;
    novo->prox = NULL;
    if (*lista == NULL){

        novo->ant = NULL;
        *lista = novo;

    
    }else{
        no *temp = *lista;
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = novo;
        novo->ant = temp;
    }
}

void inserir_meio(**lista,int valor,int anterior){
    no *auxiliar ,*novo = (*no)malloc(sizeof(no));

    novo->valor  = valor;

    if (*lista){
        novo ->prox = NULL;
        novo ->ant = NULL;
        *lista = novo;
    }else{
        auxiliar = *lista;
        while (auxiliar->valor != anterior && auxiliar->prox != NULL){
            auxiliar = auxiliar->prox;
            novo->prox = auxiliar->prox;
            novo->ant = auxiliar;
                if (auxiliar->prox != NULL)
                    auxiliar->prox->ant = novo;
                    auxiliar->prox = novo;
        }
    }
    
}
    
