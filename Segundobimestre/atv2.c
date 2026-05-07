#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int nota1;
    int nota2;
    float sub;
}dados;

typedef struct apelido{

    dados da;
    struct apelido *proximo;
}no;

no *top = NULL;

dados entrada_dados();
void empilhar();
void desempilhar();
void imprimir();

int main(){

    int opcao;

    do{char nome[50];

        printf("\n\nMenu\n1. Empilhar \n2. desenpilhar \n3. imprimir \n4. inverter pilha");
        scanf("%d", &opcao);

            switch (opcao){

                case 1:
                    empilhar();
                    break;

                case 2:
                    desempilhar();
                    break;
            
                case 3:
                    imprimir();
                    break;
    
                case 4:
                    //inverter pilha
                    break;

        }

    }while (opcao != 5);

    return 0;

}

dados entrada_dados(){
    dados dat;

    printf("Digite o nome do aluno: \n");
    scanf("%s", dat.nome); fflush(stdin);
    printf("Digite a nota 1: \n");
    scanf("%d", &dat.nota1); fflush(stdin);
    printf("Digite a nota 2: \n");
    scanf("%d", &dat.nota2); fflush(stdin);
    printf("Digite a nota da sub: \n");
    scanf("%f", &dat.sub); fflush(stdin);


    return dat;
}

void empilhar(){
    no *novo = malloc(sizeof(no));
    dados cu = entrada_dados();

    novo -> da = cu;
    novo -> proximo = top;
    top = novo;
}

void desempilhar(){
    if(top == NULL)
        printf("A pilha esta vazia");
    else{
        no *temp = top;
        top = top -> proximo;
        free(temp);
    }
}

void imprimir(){
    no *temp = top;

    while(temp != NULL){
        printf("%30s %d %d %5.1f \n",
        temp -> da.nome,
        temp->da.nota1,
        temp->da.nota2,
        temp->da.sub
        );

        temp = temp -> proximo;
    }


}


void inverter_pilha(){
    
}
