#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

//PREENCHENDO A LISTA PARA DEPOIS REALIZAR UMA AÇÃO
//Optei por pedir que o usuario escolha os números que estarão na lista
//Melhorei a implementação já que na lista sequencial usei -1 como critério de parada
lista PreenchendoLista(lista l){
    //char para controlar o loop de acordo com a letra que o usuario digita
    char opcao;
    //do = faça isso enquanto
    do {
        int num;
        printf("Digite um numero para adicionar a lista encadeada: ");
        scanf("%d", &num);
        //usando uma função já criada anteriormente para preencher e limpar o código
        //inserindo números no fim já que o último número que o usuário declarar
        //será o último da lista
        l = inserir_fim(l, num);
        //perguntando se quer add mais números
        printf("Deseja continuar adicionando numeros? (s/n): ");
        scanf(" %c", &opcao);
        //tratamento para caso capslock ativado
    } while (opcao == 's' || opcao == 'S');
    //retornando a lista
    printf("ESSA FOI A LISTA DECLARADA:");
    exibir_lista(l);
    return l;
}

//FUNÇÃO 1, inserir um novo valor para o inicio.
lista inserir_inicio(lista l, int numero) {
    //Aloca espaço para o novo nó
    lista novo = (lista) malloc(sizeof(no));
    //inicializan o valor do novo a parir do parâmetro passado para função
    novo-> valor = numero;
    //O próximo do novo aponta para o inicio da lista, ou seja, o antigo início passa a ser o segundo elemento (proximo do primeiro)
    //ou seja, o novo nó passa a frente da lista e é necessário apontar o ponteiro dele para o resto da lista
    novo-> proximo = l;
    //Atualização da lista, através do retorno do ponteiro do novo início
    return novo;
}

//FUNÇÃO 5, print da lista
void exibir_lista(lista l){
    lista aux = l;
    //enquanto nao achar o que aponta para o nulo (último) printa o valor e passa para o proximo nó
    if (aux == NULL){
        printf("A lista esta vazia\n");
    }
    while(aux != NULL) {
        //enquanto aux é diferente de null (fim da lista)
        //imprime o valor contido no elemento
        printf("[%d]", aux-> valor);
        //avança para o próximo
        aux = aux-> proximo;
    }
     printf("\n");
}
//FUNÇÃO 6, ordem da lista invertida
void exibir_lista_reversa(lista l){
    //caso base
    if(l == NULL) {
        printf("\n");
        return ;
    }
    //caso recursivo
    //termina quando chegar no final da lista
    //quando o l é nulo (caso base)
    exibir_lista_reversa(l-> proximo);
    //e imprime o valor do nó, depois procura o proximo caso que retorna ao caso base
    //e imprime tmb (chamando recursivamente)
    printf("[%d]", l-> valor);

}

//FUNCÃO 2, insere um valor no fim.
lista inserir_fim(lista l, int numero) {
    //cria uma lista igual a lista e chama de aux
    lista aux = l;
    //caso a lista esteja vazia (se l igual a null) insere no inicio já que não faz diferença
    if(l == NULL) {
        return inserir_inicio(l, numero);
    }
    //percorrendo a lista aux, enquanto o ponteiro que aponta para o prox não é o último
    while(aux-> proximo != NULL) {
        aux = aux-> proximo;
    }
    //aqui aux igual ao último, pq o loop estourou
    //criando um nó para o novo elemento
    lista novo = (lista) malloc(sizeof(no));
    //adicionando o numero ao campo do valor e fazendo ele apontar para null já que é o último
    novo-> valor = numero;
    novo-> proximo = NULL;
    //último aponte para o novo
    aux-> proximo = novo;
    return l;
}

//FUNÇÃO 7, excluindo o primeiro elemento da lista (cabeça).
lista remover_inicio(lista l) {
    //para caso a lista esteja vazia
    if(l== NULL)
        return NULL;
    //cria uma lista igual a l e chama de aux
    //a referencia de uma lista encadeada é sempre apenas o 1º elemento, sendo assim, pedindo para aux apontar para
    //o proximo de l, aux aponta para o segundo elemento da lista
    //ou seja, aux é uma lista igual a l mas sem o primeiro elemento
    lista aux = l-> proximo;
    //free para apagar l da memoria e aux agora aponta para uma copia de l que começa no segundo nó
    free(l);
    return aux;
}

//FUNÇÃO 8, removendo o ultimo elemento
lista remover_fim(lista l) {
    //para caso a lista esteja vazia
    if(l == NULL)
        return NULL;
    //caso a lista só tenha um elemento tanto faz remover do fim ou inicio
    if(l-> proximo == NULL)
       return remover_inicio(l);
    //criacao de uma lista igual a lista mas chamada de aux
    lista aux = l;
    //encontrando o penuntimo elemento
    while(aux-> proximo-> proximo != NULL) {
        aux = aux-> proximo;
    }
    //apagando o ultimo elemento
    free(aux-> proximo);
    //agora o penuntimo é o último
    aux-> proximo = NULL;
    return l;
}
//FUNÇÃO 12, somando todos os elementos da lista
void somatorio(lista l) {
    int soma = 0;
    //para caso a lista esteja vazia
    if(l == NULL)
        return soma;
    //enquanto a lista nao chegar no último, a variavel soma adquire o valor guardado na parte do nó que tem o valor
    while (l != NULL){
        //soma recebe a soma atual + o valor do novo elemento
        soma = soma + l-> valor;
        //e passa a lista para o proximo elemento
        l = l-> proximo;
}   printf("A soma eh: %d \n", soma);
}

//FUNÇÃO 13, retorna a quantidade de elementos armazenados
void tamanhoLista(lista l) {
    int tam = 0;
    //para caso a lista esteja vazia
    if(l == NULL)
        printf("O tamanho da lista eh: %d \n", tam);
    //enquanto a lista nao chegar no último, o tamanho é acrescido em 1
   while (l != NULL){
        tam++;
    //e passa para o proximo elemento
        l = l-> proximo;
   } printf("A quantidade de elementos armazenados na lista eh: %d \n", tam);
    }

//FUNÇÃO 14, eleva os elementos ao quadrado.
void Quadrado(lista l){
    int quad;
    if (l == NULL){
        printf("A lista esta vazia\n");
    }
    //enquanto l não aponta pro nulo
    while (l != NULL){
        //o int quad recebe o valor armazenado no nó e eleva ao quadrado
        quad = l-> valor*l-> valor;
        //um print para imprimir o valor
        printf("[%d]", quad);
        //atualização para que l passe para o elemento seguinte até chegar no nulo, que finaliza o laço
        l = l-> proximo;
}
}
//FUNÇÃO 11, retorna a posição de um valor da lista
void ProcurarPosicao(lista l){
    //posicao para armazenar a posicao e numero para armazenar o numero que o usuario deseja procurar
    int posicao = 0;
    int numero;
        printf("Digite um numero: ");
        scanf("%d", &numero);
    //lista vazia
    if (l == NULL){
        printf("Lista vazia");
        return;
    }
    //enquanto nao chegar ao final da lista
    while (l != NULL){
        //se o numero armazenado na parte de valor do nó for igual ao numero procurado
        if (l-> valor == numero){
            //printa a posicao
            printf("O numero %d se encontra na %d posicao da lista\n", numero, posicao);
            return;
        }
        //passa pro proximo elemento
        l = l-> proximo;
        //já que passou para o proximo adiciona uma posição
        posicao++;
    }
    //caso rode o loop inteiro e não ache nada
    printf("O numero %d nao foi encontrado na lista\n", numero);
}

//FUNÇÃO 15, quantidade de primos
int qtdPrimo(lista l) {
    int qtd = 0;
    int primo, num;
    //enquanto não chega ao ultimo termo
    while (l != NULL) {
        //num recebe o valor do elemento da lista
        num = l-> valor;
        //assume q o número é primo
        primo = 1;
        //verifica de o número é menor ou igual a um pq se for ele não é primo
        //então primo volta a ser zero, pq no final existe a verificação se primo é zero ou um
        //sendo um, implica que o número é primo e acrescenta na variavel qtd, sendo zero nada é acrescido a qtd
        if (num <= 1) {
            primo = 0;
        } else {
            //verificando se o número é primo através do for
            //caso o número seja divisível por algum valor k entre 2 e a raiz quadrada do valor do elemento
            //ele não é primo e primo recebe zero igual aconteceu anteriormente
            for (int k = 2; k * k <= num; k++) {
                //verificando divisão exata
                if (num % k == 0) {
                //se existe, não é primo
                    primo = 0;
                //e usa o break pra já interromper a ação
                        break;
}
}
}
    //se recebeu um nas verificações é pq o número é primo
        if (primo == 1) {
            //então add um a quantidade
            qtd++;
    }
    //avança para o próximo elemento
    l = l-> proximo;
    }
    //botei já o print dentro da função para facilitar no main
    printf("A lista possui %d numeros primos", qtd);
    return qtd;
}

 //FUNÇÃO 4, inserindo um elemento mantendo a ordem
lista InserirOrdenado(lista l) {
    int numero;
    lista aux = l;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    // Aloca espaço para o novo nó
    lista novoNumero = (lista) malloc(sizeof(no));
    // Inicializa o valor do novo nó a partir do parâmetro passado para a função
    novoNumero-> valor = numero;
    // Lista vazia
    if (l == NULL) {
        // Já que está vazia, o próximo de novoNumero recebe o NULL, já que será o único elemento da lista
        novoNumero-> proximo = NULL;
        //A nova cabeça da lista l é o novo valor adicionado
        l = novoNumero;
    } else {
        //percorre a lista enquanto tiver um próximo nó e o valor do número a ser inserido for maior que o VALOR do próximo nó
        while (aux-> proximo && numero > aux-> proximo-> valor)
            aux = aux-> proximo;
        // a parter de proximo do novo nó é atualizada para apontar para o próximo nó da posição onde o novo nó será inserido
        novoNumero-> proximo = aux-> proximo;
        //atualizado para apontar para o novo nó a ser inserido.
        aux-> proximo = novoNumero;
    }
    aux = l;
    return l;
}

lista InserirPosicao(lista l, int valor, int posicao) {
    //criado um novo nó
    lista nova = (lista)malloc(sizeof(struct no));
    //atribuindo valor para ele
    nova-> valor = valor;

    //a lista estiver vazia  ou se a posição for 0, isso significa que o novo nó deve ser inserido no início da lista
    if (posicao == 0 ||l == NULL) {
        nova-> proximo = l;
        return nova;
    }

    lista atual = l;
    int contador = 0;

    while (atual != NULL && contador < posicao - 1) {
        atual = atual-> proximo;
        contador++;
    }

    if (atual == NULL) {
        atual-> proximo = nova;
        nova-> proximo = NULL;
    } else {
        nova-> proximo = atual-> proximo;
        atual-> proximo = nova;
    }

    return l;
}
