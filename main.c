#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main(int argc, char *argv) {

    //declaração da lista
    lista l = NULL;
    lista l1 = NULL;
    lista l2 = NULL;
    lista l3 = NULL;
    lista l4 = NULL;
    lista l5 = NULL;
    lista l6 = NULL;
    lista l7 = NULL;
    lista l8 = NULL;
    lista l9 = NULL;
    lista l10 = NULL;
    lista l11 = NULL;
    lista l12 = NULL;
    lista l13 = NULL;
    lista l14 = NULL;
    lista l15 = NULL;

    int numero;
    int opcao;
    int valor;
    int posicao;

   //l = inserir_fim(l, 2);
    //l = inserir_fim(l, 5);
    //l = inserir_fim(l, 11);
    //l = inserir_inicio(l,1);
    //exibir_lista(l);
    //printf("\n");
    //exibir_lista_reversa(l);
    //somatorio(l);
    //tamanhoLista(l);
    //Quadrado(l);
    //qtdPrimo(l);
    //InserirOrdenado(l);
    //exibir_lista(l);


 while (1){
    system ("cls");
    printf("         LISTA ENCADEADA\n");
    printf("   DIGITE UMA OPCAO PARA MANIPULAR A LISTA\n");
    printf("\t1 - Inserir um numero na primeira posicao\n");
    printf("\t2 - Inserir um numero na ultima posicao\n");
    printf("\t3 - Inserir um numero na posicao que deseja\n");
    printf("\t4 - Inserir um numero mantendo a ordem crescente da lista\n");
    printf("\t5 - Exibir a lista completa\n");
    printf("\t6 - Reverter a lista\n");
    printf("\t7 - Remover o numero que esta na primeira posicao\n");
    printf("\t8 - Remover o numero que esta na ultima posicao\n");
    printf("\t9 - Remover um numero da posicao que escolher\n");
    printf("\t10 - Remover valor\n");
    printf("\t11 - Procurar um numero\n");
    printf("\t12 - Somar todos os numeros da lista\n");
    printf("\t13 - Tamanho da lista\n");
    printf("\t14 - Elevar cada numero da lista ao quadrado\n");
    printf("\t15 - Saber a quantidade de primos na lista\n");
    printf("\t99 - Fechar o programa\n");
    scanf("%d", &opcao);

     switch(opcao){
        case 1:
        printf("Preencha a lista\n");
          l =  PreenchendoLista(l);
        printf("\nDigite o numero que deseja inserir na primeira posicao da lista: ");
        scanf("%d", &valor);
           l = inserir_inicio(l, valor);
        printf("Essa eh a nova lista: ");
            exibir_lista(l);
            break;
        case 2:
            printf("Preencha a lista\n");
            l1 = PreenchendoLista(l1);
        printf("\nDigite o numero que deseja inserir na ultima posicao da lista: ");
        scanf("%d", &valor);
            l1 = inserir_fim(l1, valor);
        printf("Essa eh a nova lista: ");
            exibir_lista(l1);
            break;
        case 3:
            printf("Preencha a lista\n");
           l2 = PreenchendoLista(l2);
        printf("\nDigite o numero que deseja inserir na lista:");
        scanf("%d", &valor);
        printf("\nDigite a posicao para o numero: ");
        scanf("%d", &posicao);
            InserirPosicao(l2,valor,posicao);
        printf("Essa eh a nova lista: ");
            exibir_lista(l2);
            break;
    case 4:
         printf("Preencha a lista\n");
         printf("\nESSA LISTA PRECISA SEGUIR A ORDEM CRESCENTE ");
            l3 = PreenchendoLista(l3);
            InserirOrdenado(l3);
            exibir_lista(l3);
            break;
    case 5:
         printf("Preencha a lista\n");
           l4 =  PreenchendoLista(l4);
            break;
    case 6:
        printf("Preencha a lista\n");
       l5 = PreenchendoLista(l5);
        exibir_lista_reversa(l5);
            break;
    case 7:
        printf("Preencha a lista\n");
           l6 = PreenchendoLista(l6);
        printf("\nLista apos a remocao do primeiro numero: ");
            remover_inicio(l6);
            exibir_lista(l6);
            break;
    case 8:
        printf("Preencha a lista\n");
            l7 = PreenchendoLista(l7);
        printf("\nLista apos a remocao do ultimo numero: ");
            remover_fim(l7);
            exibir_lista(l7);
            break;
   /*case 9:
        printf("Preencha a lista\n");
            PreenchendoLista(l15);
        printf("\nDigite a posicao que deseja remover: ");
        scanf("%d", &posicao);
        removerPosicao(int posicao, lista l)
            break;
   /*case 10:
        printf("Preencha a lista\n");
            PreenchendoLista(l14);
        printf("\nDigite o numero que deseja remover: ");
        scanf("%d", &valor);
            removerNo(l14,valor);
            exibir_lista(l14);
            break; */

    case 11:
        printf("Preencha a lista\n");
           l8 =  PreenchendoLista(l8);
            ProcurarPosicao(l8);
            break;
    case 12:
        printf("Preencha a lista\n");
            l9 = PreenchendoLista(l9);
            somatorio(l9);
            break;
    case 13:
        printf("Preencha a lista\n");
           l10 = PreenchendoLista(l10);
            tamanhoLista(l10);
            break;
    case 14:
        printf("Preencha a lista\n");
           l11 = PreenchendoLista(l11);
           printf("A lista ao quadrado\n");
            Quadrado(l11);
            break;
    case 15:
        printf("Preencha a lista\n");
           l13 = PreenchendoLista(l13);
            qtdPrimo(l13);
    case 99:
            exit(0);
            break;

        default: printf("OPCAO INVALIDA");
     } getchar();
       getchar();
}}
