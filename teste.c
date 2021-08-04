/*
 *
 * Tiago Flores Lindner
 *
    Usei os arquivos de exemplos como base para montar esse único arquivo de programa
    Então a maior parte dos créditos vai pro senhor eu acho.
    Desculpa por isso, é mais pq estava focado em fazer os trabalhos finais das cadeiras.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    struct no *proximo;
    struct no *ant;
} no;

typedef no *lista;

typedef struct {
    lista inicio;
    lista fim;
    int tamanhoFila;
} fila;


void inicializa(fila *f) {
    f->fim = NULL;
    f->inicio = NULL;
    f->tamanhoFila = 0;
}

int vazia(fila *f) {
    return (f->inicio == NULL);
}

void libera_fila(fila *f) {
    lista aux_A, aux_B;
    aux_A = f->inicio;
    while (aux_A != NULL) {
        aux_B = aux_A->proximo;
        free(aux_A);
        aux_A = aux_B;
    }
    free(f);
}

int remover(fila *f, int *d) {
    no * auxiliar = f->inicio;
    if (vazia(f))
        return 0; //falhou
    *d = auxiliar->valor;
    if(f->inicio == f->fim )
        f->fim = NULL;
    f->inicio = f->inicio->proximo;
    if(f->inicio!=NULL)
        f->inicio->ant = NULL;
    f->tamanhoFila--;
    free(auxiliar);
    return 1; //funcionou
}
int insere(fila *f, int val) {
    lista auxiliar;
    auxiliar = (lista) malloc(sizeof (no));
    if(auxiliar !=NULL){
        auxiliar->proximo = NULL;
        auxiliar->ant = f->fim;
        auxiliar->valor = val;
        if (vazia(f))
            f->inicio = auxiliar;
        else
            f->fim->proximo = auxiliar;
        f->fim = auxiliar;
        f->tamanhoFila++;
    }else return 0;
}

int imprimeFila (fila *f) {
    no * auxiliar = f->inicio;
     if (vazia(f)){
        printf("Fila VAZIA. \n");
        return 0;
     }
     printf("Elementos da fila: ");
     while(auxiliar!=NULL){
        printf("%d ", auxiliar->valor);
        auxiliar = auxiliar->proximo;
     }
     printf("\n\n");
}

int tamanho(fila *f) {
    return f->tamanhoFila;
}
/*
 *Programa para testar a Fila
 */

 int main(){

    int i;
    int r, a, b;
    fila teste;
    inicializa(&teste);

    imprimeFila(&teste);
    for(i=0; i<7; i++){
        insere(&teste, i);
        printf("Inserindo %d\n", i);
        imprimeFila(&teste);
    }

    while(tamanho(&teste)>1){
        remover(&teste, &a);
        remover(&teste, &b);
        r = a+b;
        printf("Removi %d e %d, inserindo %d\n", a, b, r);
        insere(&teste, r);
        imprimeFila(&teste);
    }
 }

