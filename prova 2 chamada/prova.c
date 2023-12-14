// lista_ligada_estatica_aluno.c
#include "lista_ligada_estatica_aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct ListaLigadaAluno criarListaLigadaAluno() {
    struct ListaLigadaAluno lista;
    for (int i = 0; i < MAX_TAM - 1; i++) {
        lista.nos[i].prox = &lista.nos[i + 1];
    }
    lista.nos[MAX_TAM - 1].prox = NULL;
    lista.tamanho = 0;
    return lista;
}

void inserirAlunoListaLigada(struct ListaLigadaAluno *lista, struct Aluno aluno) {
    if (lista->tamanho < MAX_TAM) {
        struct NoAluno *novoNo = &lista->nos[lista->tamanho++];
        novoNo->aluno = aluno;
        novoNo->prox = NULL;
    }
}

void imprimirListaLigadaAluno(struct ListaLigadaAluno *lista) {
    struct NoAluno *atual = lista->nos[0].prox;
    while (atual != NULL) {
        printf("Código: %d, Nome: %s, Idade: %d, Número de Filhos: %d\n",
               atual->aluno.codigo, atual->aluno.nome,
               atual->aluno.idade, atual->aluno.numeroFilhos);
        atual = atual->prox;
    }
}
