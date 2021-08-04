/*
 *
 * Tiago Flores Lindner
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    char email[150];
    char fone[15];
} contato;

typedef struct {
    contato c;
    struct no *proximo;
    struct no *ant;
} no;

typedef struct {
    no* inicio;
    no* fim;
    int tamanhoLista;
} lista;


void inicializa(lista *l) {
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanhoLista = 0;
}//inicializa

int vazia(lista *l) {
    return (l->inicio == NULL);
}//vazia

void libera_lista(lista *l) {
    no *aux_A, *aux_B;
    aux_A = l->inicio;
    while (aux_A != NULL) {
        aux_B = aux_A->proximo;
        free(aux_A);
        aux_A = aux_B;
    }
    free(l);

}//libera

int remover(lista *l, int pos) {
    no * auxiliar = l->inicio;
    if (vazia(l))
        return 0; //falhou

    if(l->inicio == l->fim )
        l->fim = NULL;
    l->inicio = l->inicio->proximo;
    if(l->inicio!=NULL)
        l->inicio->ant = NULL;
    l->tamanhoLista--;
    free(auxiliar);
    return 1; //funcionou

}//remover

int insere(lista *l, contato *cont, int pos) {
    no *auxiliar;
    auxiliar = (no*) malloc(sizeof (no));
    if(auxiliar !=NULL){
        auxiliar->proximo = NULL;
        auxiliar->ant = l->fim;
        auxiliar->c = *cont;
        printf("%s", auxiliar->c.nome);
        printf("%s", auxiliar->c.email);
        printf("%s", auxiliar->c.fone);
        if (vazia(l)) {
            l->inicio = auxiliar;
            printf("%s", l->inicio->c.nome);
    }
        else
            l->fim->proximo = auxiliar;
        l->fim = auxiliar;
        l->tamanhoLista++;
    }else return 0;

}//insere

int imprime (lista *l, int pos) {
    no * auxiliar = l->inicio;
     if (vazia(l)){
        printf("Lista Vazia. \n");
        return 0;
     }
     printf("Elementos da lista: ");
     while(auxiliar!=NULL){
        printf("%d ", auxiliar->c);
        auxiliar = auxiliar->proximo;
     }
     printf("\n\n");

} //imprime (arrumar para só imprimir o indicado

void imprimeLista(lista *l){

    for(int i=0; i<tamanho(l->tamanhoLista); i++){
        imprime(l, i);

    }//for

}//imprime toda a lista (usar o esquema do imprime da fila)

int tamanho(lista *l) {
    return l->tamanhoLista;
}//tamanho


//Programa

 int main(){

    int i, pos;
    contato leitura;
    lista teste;
    inicializa(&teste);

    while (i != 6){
    printf("\nEscolha uma das funcoes: ");
    printf("\n1: Consultar posicao");
    printf("\n2: Inserir um codigo");
    printf("\n3: Retirar um codigo");
    printf("\n4: Consultar a quantidade de codigos");
    printf("\n5: Imprimir a lista");
    printf("\n6: Sair\n");

    scanf("%d", &i);

        switch(i){

            case 1:
                printf("\nInsira a posicao para consultar: ");
                scanf("%d", &pos);
                imprime(&teste, pos);
                break;

            case 2:
                printf("Digite o Nome: ");
                fflush(stdin);
                gets(leitura.nome);
                printf("Digite o email: ");
                fflush(stdin);
                gets(leitura.email);
                printf("Digite o fone : ");
                fflush(stdin);
                gets(leitura.fone);

                printf("\nInsira a posicao para inserir: ");
                scanf("%d", &pos);
                insere(&teste, &leitura, pos);
                break;

            case 3:
                printf("\nInsira a posicao para remover: ");
                scanf("%d", &pos);
                remover(&teste, pos);
                break;

            case 4:
                printf("\nNumero de elementos: %d" ,tamanho(&teste));
                break;

            case 5:
                printf("\n");
                imprimeLista(&teste);
                break;

            case 6:
                break;

            default:
                printf("\nOpcao invalida!");
                break;

        }//switch

    }//while

    return 0;
 }

 /*
  imprimeLista(&teste);

    for(i=0;i<2;i++){//inserir 2
        printf("Digite o Nome: ");
        gets(pessoa.nome);
        printf("Digite o email: ");
        gets(pessoa.email);
        printf("Digite o fone : ");
        gets(pessoa.fone);
        push(&p, pessoa);
        puts("");//pular uma linha;
    }

    for(i=0; i<7; i++){
        insere(&teste, i);
        printf("Inserindo %d\n", i);
        imprimeLista(&teste);
    }

    while(tamanho(&teste)>1){
        remover(&teste, &a);
        remover(&teste, &b);
        r = a+b;
        printf("Removi %d e %d, inserindo %d\n", a, b, r);
        insere(&teste, r);
        imprimeLista(&teste);

    }
    */

