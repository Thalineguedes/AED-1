// lista_ligada_estatica_aluno.h
#ifndef LISTA_LIGADA_ESTATICA_ALUNO_H
#define LISTA_LIGADA_ESTATICA_ALUNO_H

struct Aluno {
    int codigo;
    char nome[50];
    int idade;
    int numeroFilhos;
};

struct NoAluno {
    struct Aluno aluno;
    struct NoAluno *prox;
};

struct ListaLigadaAluno {
    struct NoAluno nos[MAX_TAM];
    int tamanho;
};

struct ListaLigadaAluno criarListaLigadaAluno();
void inserirAlunoListaLigada(struct ListaLigadaAluno *lista, struct Aluno aluno);
void imprimirListaLigadaAluno(struct ListaLigadaAluno *lista);

#endif // LISTA_LIGADA_ESTATICA_ALUNO_H
