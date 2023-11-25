#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

//PREENCHENDO A LISTA PARA DEPOIS REALIZAR UMA A��O
//Optei por pedir que o usuario escolha os n�meros que estar�o na lista
//Melhorei a implementa��o j� que na lista sequencial usei -1 como crit�rio de parada
lista PreenchendoLista(lista l){
    //char para controlar o loop de acordo com a letra que o usuario digita
    char opcao;
    //do = fa�a isso enquanto
    do {
        int num;
        printf("Digite um numero para adicionar a lista encadeada: ");
        scanf("%d", &num);
        //usando uma fun��o j� criada anteriormente para preencher e limpar o c�digo
        //inserindo n�meros no fim j� que o �ltimo n�mero que o usu�rio declarar
        //ser� o �ltimo da lista
        l = inserir_fim(l, num);
        //perguntando se quer add mais n�meros
        printf("Deseja continuar adicionando numeros? (s/n): ");
        scanf(" %c", &opcao);
        //tratamento para caso capslock ativado
    } while (opcao == 's' || opcao == 'S');
    //retornando a lista
    printf("ESSA FOI A LISTA DECLARADA:");
    exibir_lista(l);
    return l;
}

//FUN��O 1, inserir um novo valor para o inicio.
lista inserir_inicio(lista l, int numero) {
    //Aloca espa�o para o novo n�
    lista novo = (lista) malloc(sizeof(no));
    //inicializan o valor do novo a parir do par�metro passado para fun��o
    novo-> valor = numero;
    //O pr�ximo do novo aponta para o inicio da lista, ou seja, o antigo in�cio passa a ser o segundo elemento (proximo do primeiro)
    //ou seja, o novo n� passa a frente da lista e � necess�rio apontar o ponteiro dele para o resto da lista
    novo-> proximo = l;
    //Atualiza��o da lista, atrav�s do retorno do ponteiro do novo in�cio
    return novo;
}

//FUN��O 5, print da lista
void exibir_lista(lista l){
    lista aux = l;
    //enquanto nao achar o que aponta para o nulo (�ltimo) printa o valor e passa para o proximo n�
    if (aux == NULL){
        printf("A lista esta vazia\n");
    }
    while(aux != NULL) {
        //enquanto aux � diferente de null (fim da lista)
        //imprime o valor contido no elemento
        printf("[%d]", aux-> valor);
        //avan�a para o pr�ximo
        aux = aux-> proximo;
    }
     printf("\n");
}
//FUN��O 6, ordem da lista invertida
void exibir_lista_reversa(lista l){
    //caso base
    if(l == NULL) {
        printf("\n");
        return ;
    }
    //caso recursivo
    //termina quando chegar no final da lista
    //quando o l � nulo (caso base)
    exibir_lista_reversa(l-> proximo);
    //e imprime o valor do n�, depois procura o proximo caso que retorna ao caso base
    //e imprime tmb (chamando recursivamente)
    printf("[%d]", l-> valor);

}

//FUNC�O 2, insere um valor no fim.
lista inserir_fim(lista l, int numero) {
    //cria uma lista igual a lista e chama de aux
    lista aux = l;
    //caso a lista esteja vazia (se l igual a null) insere no inicio j� que n�o faz diferen�a
    if(l == NULL) {
        return inserir_inicio(l, numero);
    }
    //percorrendo a lista aux, enquanto o ponteiro que aponta para o prox n�o � o �ltimo
    while(aux-> proximo != NULL) {
        aux = aux-> proximo;
    }
    //aqui aux igual ao �ltimo, pq o loop estourou
    //criando um n� para o novo elemento
    lista novo = (lista) malloc(sizeof(no));
    //adicionando o numero ao campo do valor e fazendo ele apontar para null j� que � o �ltimo
    novo-> valor = numero;
    novo-> proximo = NULL;
    //�ltimo aponte para o novo
    aux-> proximo = novo;
    return l;
}

//FUN��O 7, excluindo o primeiro elemento da lista (cabe�a).
lista remover_inicio(lista l) {
    //para caso a lista esteja vazia
    if(l== NULL)
        return NULL;
    //cria uma lista igual a l e chama de aux
    //a referencia de uma lista encadeada � sempre apenas o 1� elemento, sendo assim, pedindo para aux apontar para
    //o proximo de l, aux aponta para o segundo elemento da lista
    //ou seja, aux � uma lista igual a l mas sem o primeiro elemento
    lista aux = l-> proximo;
    //free para apagar l da memoria e aux agora aponta para uma copia de l que come�a no segundo n�
    free(l);
    return aux;
}

//FUN��O 8, removendo o ultimo elemento
lista remover_fim(lista l) {
    //para caso a lista esteja vazia
    if(l == NULL)
        return NULL;
    //caso a lista s� tenha um elemento tanto faz remover do fim ou inicio
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
    //agora o penuntimo � o �ltimo
    aux-> proximo = NULL;
    return l;
}
//FUN��O 12, somando todos os elementos da lista
void somatorio(lista l) {
    int soma = 0;
    //para caso a lista esteja vazia
    if(l == NULL)
        return soma;
    //enquanto a lista nao chegar no �ltimo, a variavel soma adquire o valor guardado na parte do n� que tem o valor
    while (l != NULL){
        //soma recebe a soma atual + o valor do novo elemento
        soma = soma + l-> valor;
        //e passa a lista para o proximo elemento
        l = l-> proximo;
}   printf("A soma eh: %d \n", soma);
}

//FUN��O 13, retorna a quantidade de elementos armazenados
void tamanhoLista(lista l) {
    int tam = 0;
    //para caso a lista esteja vazia
    if(l == NULL)
        printf("O tamanho da lista eh: %d \n", tam);
    //enquanto a lista nao chegar no �ltimo, o tamanho � acrescido em 1
   while (l != NULL){
        tam++;
    //e passa para o proximo elemento
        l = l-> proximo;
   } printf("A quantidade de elementos armazenados na lista eh: %d \n", tam);
    }

//FUN��O 14, eleva os elementos ao quadrado.
void Quadrado(lista l){
    int quad;
    if (l == NULL){
        printf("A lista esta vazia\n");
    }
    //enquanto l n�o aponta pro nulo
    while (l != NULL){
        //o int quad recebe o valor armazenado no n� e eleva ao quadrado
        quad = l-> valor*l-> valor;
        //um print para imprimir o valor
        printf("[%d]", quad);
        //atualiza��o para que l passe para o elemento seguinte at� chegar no nulo, que finaliza o la�o
        l = l-> proximo;
}
}
//FUN��O 11, retorna a posi��o de um valor da lista
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
        //se o numero armazenado na parte de valor do n� for igual ao numero procurado
        if (l-> valor == numero){
            //printa a posicao
            printf("O numero %d se encontra na %d posicao da lista\n", numero, posicao);
            return;
        }
        //passa pro proximo elemento
        l = l-> proximo;
        //j� que passou para o proximo adiciona uma posi��o
        posicao++;
    }
    //caso rode o loop inteiro e n�o ache nada
    printf("O numero %d nao foi encontrado na lista\n", numero);
}

//FUN��O 15, quantidade de primos
int qtdPrimo(lista l) {
    int qtd = 0;
    int primo, num;
    //enquanto n�o chega ao ultimo termo
    while (l != NULL) {
        //num recebe o valor do elemento da lista
        num = l-> valor;
        //assume q o n�mero � primo
        primo = 1;
        //verifica de o n�mero � menor ou igual a um pq se for ele n�o � primo
        //ent�o primo volta a ser zero, pq no final existe a verifica��o se primo � zero ou um
        //sendo um, implica que o n�mero � primo e acrescenta na variavel qtd, sendo zero nada � acrescido a qtd
        if (num <= 1) {
            primo = 0;
        } else {
            //verificando se o n�mero � primo atrav�s do for
            //caso o n�mero seja divis�vel por algum valor k entre 2 e a raiz quadrada do valor do elemento
            //ele n�o � primo e primo recebe zero igual aconteceu anteriormente
            for (int k = 2; k * k <= num; k++) {
                //verificando divis�o exata
                if (num % k == 0) {
                //se existe, n�o � primo
                    primo = 0;
                //e usa o break pra j� interromper a a��o
                        break;
}
}
}
    //se recebeu um nas verifica��es � pq o n�mero � primo
        if (primo == 1) {
            //ent�o add um a quantidade
            qtd++;
    }
    //avan�a para o pr�ximo elemento
    l = l-> proximo;
    }
    //botei j� o print dentro da fun��o para facilitar no main
    printf("A lista possui %d numeros primos", qtd);
    return qtd;
}

 //FUN��O 4, inserindo um elemento mantendo a ordem
lista InserirOrdenado(lista l) {
    int numero;
    lista aux = l;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    // Aloca espa�o para o novo n�
    lista novoNumero = (lista) malloc(sizeof(no));
    // Inicializa o valor do novo n� a partir do par�metro passado para a fun��o
    novoNumero-> valor = numero;
    // Lista vazia
    if (l == NULL) {
        // J� que est� vazia, o pr�ximo de novoNumero recebe o NULL, j� que ser� o �nico elemento da lista
        novoNumero-> proximo = NULL;
        //A nova cabe�a da lista l � o novo valor adicionado
        l = novoNumero;
    } else {
        //percorre a lista enquanto tiver um pr�ximo n� e o valor do n�mero a ser inserido for maior que o VALOR do pr�ximo n�
        while (aux-> proximo && numero > aux-> proximo-> valor)
            aux = aux-> proximo;
        // a parter de proximo do novo n� � atualizada para apontar para o pr�ximo n� da posi��o onde o novo n� ser� inserido
        novoNumero-> proximo = aux-> proximo;
        //atualizado para apontar para o novo n� a ser inserido.
        aux-> proximo = novoNumero;
    }
    aux = l;
    return l;
}

lista InserirPosicao(lista l, int valor, int posicao) {
    //criado um novo n�
    lista nova = (lista)malloc(sizeof(struct no));
    //atribuindo valor para ele
    nova-> valor = valor;

    //a lista estiver vazia  ou se a posi��o for 0, isso significa que o novo n� deve ser inserido no in�cio da lista
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
