#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
    int dado;
    struct no *anterior;
    struct no *proximo;
}no;

no *inicio = NULL;
no *fim = NULL;

int entrada_dados();
no *criar_no(int valor);
void inserir_inicio(int valor);
void inserir_fim(int valor);
void inserir_meio(int valor, int posicao);
int contar();
void inserir_sorteados();
void apresentar();
void remover(int valor);

no *criar_no(int valor){
    no *novo = malloc(sizeof(no));
    novo->dado = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

void inserir_inicio(int valor){
    no *novo = criar_no(valor);
    if(inicio == NULL){
        inicio = fim = novo;
    }else{
        novo->proximo = inicio;
        inicio->anterior = novo;
        inicio = novo;
    }
    printf("\n Inserido %d no inicio", valor);
}

void inserir_fim(int valor){
    no *novo = criar_no(valor);
    if(fim == NULL){
        inicio = fim = novo;
    }else{
        novo->anterior = fim;
        fim->proximo = novo;
        fim = novo;
    }
    printf("\n Inserido %d no fim", valor);
}

void inserir_meio(int valor, int posicao){
    int total = contar();
    if(posicao <= 0 || inicio == NULL){
        inserir_inicio(valor);
        return;
    }
    if(posicao >= total){
        inserir_fim(valor);
        return;
    }
    no *atual = inicio;
    int meio = total / 2;
    if(posicao <= meio){
        int i = 0;
        while(i < posicao){
            atual = atual->proximo;
            i++;
        }
    }else{
        atual = fim;
        int i = total - 1;
        while(i > posicao){
            atual = atual->anterior;
            i--;
        }
    }
    no *novo = criar_no(valor);
    no *ant = atual->anterior;
    novo->anterior = ant;
    novo->proximo = atual;
    ant->proximo = novo;
    atual->anterior = novo;
    printf("\n Inserido %d na posicao %d", valor, posicao);
}

int contar(){
    int qtd = 0;
    no *atual = inicio;
    while(atual != NULL){
        qtd++;
        atual = atual->proximo;
    }
    return qtd;
}

void inserir_sorteados(){
    int i;
    for(i = 0; i < 10; i++){
        int valor = rand() % 100 + 1;
        int modo = rand() % 3;
        if(modo == 0){
            inserir_inicio(valor);
        }else if(modo == 1){
            inserir_fim(valor);
        }else{
            int total = contar();
            int pos = (total > 0) ? (rand() % (total + 1)) : 0;
            inserir_meio(valor, pos);
        }
    }
    printf("\n 10 elementos sorteados inseridos");
}

void apresentar(){
    if(inicio == NULL){
        printf("\n A lista esta vazia");
        return;
    }
    no *atual = inicio;
    printf("\n Lista (inicio -> fim): ");
    while(atual != NULL){
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n Lista (fim -> inicio): ");
    atual = fim;
    while(atual != NULL){
        printf("%d ", atual->dado);
        atual = atual->anterior;
    }
    printf("\n Quantidade de elementos: %d", contar());
}

void remover(int valor){
    if(inicio == NULL){
        printf("\n A lista esta vazia");
        return;
    }
    no *atual = inicio;
    while(atual != NULL && atual->dado != valor){
        atual = atual->proximo;
    }
    if(atual == NULL){
        printf("\n Valor %d nao encontrado", valor);
        return;
    }
    if(atual->anterior != NULL){
        atual->anterior->proximo = atual->proximo;
    }else{
        inicio = atual->proximo;
    }
    if(atual->proximo != NULL){
        atual->proximo->anterior = atual->anterior;
    }else{
        fim = atual->anterior;
    }
    free(atual);
    printf("\n Valor %d removido", valor);
}

int entrada_dados(){
    int valor;
    printf("\n Entre com o valor: ");
    scanf("%d", &valor);
    return valor;
}

int main(){
    int opcao;
    int valor;
    int posicao;
    srand(time(NULL));

    do{
        printf("\n\nMenu\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Inserir no meio\n");
        printf("4. Quantidade de elementos\n");
        printf("5. Inserir 10 elementos sorteados\n");
        printf("6. Apresentar lista\n");
        printf("7. Remover elemento\n");
        printf("8. Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                valor = entrada_dados();
                inserir_inicio(valor);
                break;
            case 2:
                valor = entrada_dados();
                inserir_fim(valor);
                break;
            case 3:
                valor = entrada_dados();
                printf("\n Entre com a posicao: ");
                scanf("%d", &posicao);
                inserir_meio(valor, posicao);
                break;
            case 4:
                printf("\n Quantidade de elementos: %d", contar());
                break;
            case 5:
                inserir_sorteados();
                break;
            case 6:
                apresentar();
                break;
            case 7:
                valor = entrada_dados();
                remover(valor);
                break;
            case 8:
                printf("\n Saindo...");
                break;
            default:
                printf("\n Opcao invalida");
        }
    }while(opcao != 8);

    return 0;
}
