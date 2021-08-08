/*
 *
 * Tiago Flores Lindner
 * Guilherme Moreira
 * Gabriela Pereira
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

//Programa

 int main(){

    int i, pos;
    contato leitura;
    lista teste;
    inicializa(&teste);

    while (i != 6){
    printf("\nEscolha uma das funcoes: ");
    printf("\n1: Consultar uma posicao");
    printf("\n2: Inserir um contato");
    printf("\n3: Retirar um contato");
    printf("\n4: Consultar a quantidade de contatos");
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
                
                printf("\nInsira a posicao para inserir: ");
                scanf("%d", &pos);
                
                printf("\nDigite o nome: ");
                fflush(stdin);
                gets(leitura.nome);
                getchar();
                printf("Digite o e-mail: ");
                fflush(stdin);
                gets(leitura.email);
                getchar();
                printf("Digite o telefone : ");
                fflush(stdin);
                gets(leitura.fone);
                getchar();

                insere(&teste, &leitura, pos);
                printf("\nContato inserido");
                
                break;
                

            case 3:
                printf("\nInsira a posicao para remover: ");
                scanf("%d", &pos);
                remover(&teste, pos);
                break;

            case 4:
                printf("\nNumero de contatos: %d" ,tamanho(&teste));
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

