#ifndef LISTA_ENCADEADA_H_INCLUDED
#define LISTA_ENCADEADA_H_INCLUDED

typedef int tipo;

typedef struct no{
        int valor;
        struct no *proximo;
} no;

typedef no *lista;

lista inserir_fim(lista l, int numero);
lista inserir_inicio(lista l, int numero);
void exibir_lista(lista l);
void exibir_lista_reversa(lista l);
void somatorio(lista l);
void tamanhoLista(lista l);
void Quadrado(lista l);
void ProcurarPosicao(lista l);
lista InserirOrdenado(lista l);
int qtdPrimo(lista l);
lista PreenchendoLista(lista l);
lista InserirPosicao(lista l, int valor, int posicao);
#endif // LISTA_ENCADEADA_H_INCLUDED
