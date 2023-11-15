#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *vetor;
    int quantidade;
} LISTA;
LISTA criarLista(int tamanho) {
    LISTA novaLista;
    novaLista.vetor = (int *)malloc(tamanho * sizeof(int));
    novaLista.quantidade = 0;
    return novaLista;
}

int liberarLista(LISTA *lista) {
    free(lista->vetor);
    lista->quantidade = 0;
}


int inserirElemento(LISTA *lista, int elemento) {
    lista->vetor[lista->quantidade++] = elemento;
}

int inserirOrdenado(LISTA *lista, int elemento) {
    int i = lista->quantidade - 1;
    while (i >= 0 && lista->vetor[i] > elemento) {
        lista->vetor[i + 1] = lista->vetor[i];
        i--;
    }
    lista->vetor[i + 1] = elemento;
    lista->quantidade++;
}


int imprimirListaIterativa(LISTA lista) {
    for (int i = 0; i < lista.quantidade; i++) {
        printf("%d ", lista.vetor[i]);
    }
    printf("\n");
}

int buscaBinariaRecursiva(LISTA lista, int elemento, int inicio, int fim) {
    if (inicio > fim) {
        return -1; 
    }

    int meio = (inicio + fim) / 2;
    if (lista.vetor[meio] == elemento) {
        return meio; 
    } else if (lista.vetor[meio] < elemento) {
        return buscaBinariaRecursiva(lista, elemento, meio + 1, fim);
    } else {
        return buscaBinariaRecursiva(lista, elemento, inicio, meio - 1);
    }
}


int imprimirListaRecursiva(LISTA lista, int indice) {
    if (indice == lista.quantidade) {
        printf("\n");
        return;
    }

    printf("%d ", lista.vetor[indice]);
    imprimirListaRecursiva(lista, indice + 1);
}


int buscarMaiorRecursivo(LISTA lista, int indice, int maiorAtual) {
    if (indice == lista.quantidade) {
        return maiorAtual;
    }

    if (lista.vetor[indice] > maiorAtual) {
        maiorAtual = lista.vetor[indice];
    }

    return buscarMaiorRecursivo(lista, indice + 1, maiorAtual);
}


int buscarMenorRecursivo(LISTA lista, int indice, int menorAtual) {
    if (indice == lista.quantidade) {
        return menorAtual;
    }

    if (lista.vetor[indice] < menorAtual) {
        menorAtual = lista.vetor[indice];
    }

    return buscarMenorRecursivo(lista, indice + 1, menorAtual);
}


int calcularSomaRecursiva(LISTA lista, int indice) {
    if (indice == lista.quantidade) {
        return 0;
    }

    return lista.vetor[indice] + calcularSomaRecursiva(lista, indice + 1);
}


int calcularProdutoRecursivo(LISTA lista, int indice) {
    if (indice == lista.quantidade) {
        return 1;
    }

    return lista.vetor[indice] * calcularProdutoRecursivo(lista, indice + 1);
}

int main() {
    int tamanhoLista, elementoBusca;

   
    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanhoLista);
    LISTA lista = criarLista(tamanhoLista);

    
    for (int i = 0; i < tamanhoLista; i++) {
     
        inserirElemento(&lista, rand() % 100);
    }

    
    printf("Elementos da lista (algoritmo iterativo): ");
    imprimirListaIterativa(lista);

    
    printf("Digite um elemento para inserir de forma ordenada: ");
    scanf("%d", &elementoBusca);
    inserirOrdenado(&lista, elementoBusca);

   
    printf("Elementos da lista (algoritmo recursivo): ");
    imprimirListaRecursiva(lista, 0);

   
    printf("Digite um elemento para buscar na lista (busca binária recursiva): ");
    scanf("%d", &elementoBusca);
    int posicaoBinaria = buscaBinariaRecursiva(lista, elementoBusca, 0, tamanhoLista - 1);
    if (posicaoBinaria != -1) {
        printf("Elemento encontrado na posicao %d.\n", posicaoBinaria);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    
    printf("O maior elemento da lista e: %d\n", buscarMaiorRecursivo(lista, 0, lista.vetor[0]));

    
    printf("O menor elemento da lista e: %d\n", buscarMenorRecursivo(lista, 0, lista.vetor[0]));

    printf("A soma de todos os elementos da lista e: %d\n", calcularSomaRecursiva(lista, 0));

    printf("O produto de todos os elementos da lista e: %d\n", calcularProdutoRecursivo(lista, 0));

    liberarLista(&lista);

    return 0;
}

