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
int imprimirLista(LISTA lista) {
    for (int i = 0; i < lista.quantidade; i++) {
        printf("%d ", lista.vetor[i]);
    }
    printf("\n");
}
int buscarSequencial(LISTA lista, int elemento, int *comparacoes) {
    for (int i = 0; i < lista.quantidade; i++) {
        (*comparacoes)++;
        if (lista.vetor[i] == elemento) {
            return i;
        }
    }
    return -1; 
}
int buscarSequencialOrdenada(LISTA lista, int elemento, int *comparacoes) {
    for (int i = 0; i < lista.quantidade; i++) {
        (*comparacoes)++;
        if (lista.vetor[i] == elemento) {
            return i;
        } else if (lista.vetor[i] > elemento) {
            return -1; 
        }
    }
    return -1;
}
int buscaBinariaIterativa(LISTA lista, int elemento, int *comparacoes) {
    int inicio = 0;
    int fim = lista.quantidade - 1;

    while (inicio <= fim) {
        (*comparacoes)++;
        int meio = (inicio + fim) / 2;
        if (lista.vetor[meio] == elemento) {
            return meio; 
        } else if (lista.vetor[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; 
}
int buscarMaior(LISTA lista) {
    int maior = lista.vetor[0];
    for (int i = 1; i < lista.quantidade; i++) {
        if (lista.vetor[i] > maior) {
            maior = lista.vetor[i];
        }
    }
    return maior;
}

int buscarMenor(LISTA lista) {
    int menor = lista.vetor[0];
    for (int i = 1; i < lista.quantidade; i++) {
        if (lista.vetor[i] < menor) {
            menor = lista.vetor[i];
        }
    }
    return menor;
}
int calcularSoma(LISTA lista) {
    int soma = 0;
    for (int i = 0; i < lista.quantidade; i++) {
        soma += lista.vetor[i];
    }
    return soma;
}
int calcularProduto(LISTA lista) {
    int produto = 1;
    for (int i = 0; i < lista.quantidade; i++) {
        produto *= lista.vetor[i];
    }
    return produto;
}
int buscaBinariaRecursiva(LISTA lista, int elemento, int inicio, int fim, int *comparacoes) {
    if (inicio > fim) {
        return -1; 
    }
  (*comparacoes)++;
    int meio = (inicio + fim) / 2;
    if (lista.vetor[meio] == elemento) {
        return meio; 
    } else if (lista.vetor[meio] < elemento) {
        return buscaBinariaRecursiva(lista, elemento, meio + 1, fim, comparacoes);
    } else {
        return buscaBinariaRecursiva(lista, elemento, inicio, meio - 1, comparacoes);
    }
}
int main() {
    int tamanhoLista1, tamanhoLista2, elementoBusca;
    int comparacoesSeq1 = 0, comparacoesSeqOrd1 = 0, comparacoesBin1 = 0;
    int comparacoesSeq2 = 0, comparacoesSeqOrd2 = 0, comparacoesBin2 = 0;
    printf("Digite o tamanho da primeira lista: ");
    scanf("%d", &tamanhoLista1);
    LISTA lista1 = criarLista(tamanhoLista1);
    for (int i = 0; i < tamanhoLista1; i++) {
        inserirElemento(&lista1, rand() % 100);
    }
    printf("Elementos da primeira lista:\n");
    imprimirLista(lista1);
    printf("Digite um elemento para buscar na primeira lista: ");
    scanf("%d", &elementoBusca);
    int posicaoSeq1 = buscarSequencial(lista1, elementoBusca, &comparacoesSeq1);
    printf("Resultado da busca sequencial: ");
    if (posicaoSeq1 != -1) {
        printf("Elemento encontrado na posicao %d.\n", posicaoSeq1);
    } else {
        printf("Elemento nao encontrado.\n");
    }
    printf("\nDigite o tamanho da segunda lista: ");
    scanf("%d", &tamanhoLista2);
    LISTA lista2 = criarLista(tamanhoLista2);
    for (int i = 0; i < tamanhoLista2; i++) {
        inserirElemento(&lista2, i * 2);
    }
    printf("Elementos da segunda lista:\n");
    imprimirLista(lista2);
    printf("Digite um elemento para buscar na segunda lista: ");
    scanf("%d", &elementoBusca);
    int posicaoSeq2 = buscarSequencial(lista2, elementoBusca, &comparacoesSeq2);
    printf("Resultado da busca sequencial: ");
    if (posicaoSeq2 != -1) {
        printf("Elemento encontrado na posicao %d.\n", posicaoSeq2);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    int posicaoSeqOrd2 = buscarSequencialOrdenada(lista2, elementoBusca, &comparacoesSeqOrd2);
    printf("Resultado da busca sequencial ordenada: ");
    if (posicaoSeqOrd2 != -1) {
        printf("Elemento encontrado na posicao %d.\n", posicaoSeqOrd2);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    int posicaoBin2 = buscaBinariaIterativa(lista2, elementoBusca, &comparacoesBin2);
    printf("Resultado da busca binaria iterativa: ");
    if (posicaoBin2 != -1) {
        printf("Elemento encontrado na posicao %d.\n", posicaoBin2);
    } else {
        printf("Elemento nao encontrado.\n");
    }
    printf("\nComparacoes na busca sequencial (lista1): %d\n", comparacoesSeq1);
    printf("Comparacoes na busca sequencial (lista2): %d\n", comparacoesSeq2);
    printf("Comparacoes na busca sequencial ordenada (lista2): %d\n", comparacoesSeqOrd2);
    printf("Comparacoes na busca binaria iterativa (lista2): %d\n", comparacoesBin2);
    printf("\nMaior elemento da primeira lista: %d\n", buscarMaior(lista1));
    printf("Menor elemento da primeira lista: %d\n", buscarMenor(lista1));
    printf("Soma dos elementos da primeira lista: %d\n", calcularSoma(lista1));
    printf("Produto dos elementos da primeira lista: %d\n", calcularProduto(lista1));
    int comparacoesBinRec1 = 0;
    int posicaoBinRec1 = buscaBinariaRecursiva(lista1, elementoBusca, 0, tamanhoLista1 - 1, &comparacoesBinRec1);
    printf("\nResultado da busca binaria recursiva: ");
    if (posicaoBinRec1 != -1) {
        printf("Elemento encontrado na posicao %d.\n", posicaoBinRec1);
    } else {
        printf("Elemento nao encontrado.\n");
    }
    printf("Comparacoes na busca binaria recursiva (lista1): %d\n", comparacoesBinRec1);
    liberarLista(&lista1);
    liberarLista(&lista2);

    return 0;
}

