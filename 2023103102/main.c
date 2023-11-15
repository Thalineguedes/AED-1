#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int codigo;
    char nome[50];
    int idade;
    float coeficiente;
} ALUNO;
typedef struct {
    ALUNO *alunos;
    int quantidade;
} TURMA;
TURMA criarTurma(int quantidadeAlunos) {
    TURMA novaTurma;
    novaTurma.alunos = (ALUNO *)malloc(quantidadeAlunos * sizeof(ALUNO));
    novaTurma.quantidade = 0;
    return novaTurma;
}

int liberarTurma(TURMA *turma) {
    free(turma->alunos);
    turma->quantidade = 0;
}

int inserirAluno(TURMA *turma, ALUNO aluno) {
    turma->alunos[turma->quantidade++] = aluno;
}

int buscarAlunoPorCodigo(TURMA turma, int codigo) {
    for (int i = 0; i < turma.quantidade; i++) {
        if (turma.alunos[i].codigo == codigo) {
            printf("Aluno encontrado:\n");
            printf("Código: %d\n", turma.alunos[i].codigo);
            printf("Nome: %s\n", turma.alunos[i].nome);
            printf("Idade: %d\n", turma.alunos[i].idade);
            printf("Coeficiente: %.2f\n", turma.alunos[i].coeficiente);
            return;
        }
    }
    printf("Aluno com código %d não encontrado na turma.\n", codigo);
}

int imprimirCodigoNomeAlunos(TURMA turma) {
    printf("Código e Nome dos Alunos na Turma:\n");
    for (int i = 0; i < turma.quantidade; i++) {
        printf("Código: %d, Nome: %s\n", turma.alunos[i].codigo, turma.alunos[i].nome);
    }
}

int main() {
    int quantidadeAlunos;
    int codigoBusca;

    printf("Digite a quantidade de alunos na turma: ");
    scanf("%d", &quantidadeAlunos);
    TURMA turma = criarTurma(quantidadeAlunos);

    for (int i = 0; i < quantidadeAlunos; i++) {
        ALUNO aluno;
        printf("\nAluno %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &aluno.codigo);
        printf("Nome: ");
        scanf("%s", aluno.nome); 
        printf("Idade: ");
        scanf("%d", &aluno.idade);
        printf("Coeficiente: ");
        scanf("%f", &aluno.coeficiente);

        inserirAluno(&turma, aluno);
    }

     imprimirCodigoNomeAlunos(turma);

    printf("\nDigite o código do aluno para buscar: ");
    scanf("%d", &codigoBusca);
    buscarAlunoPorCodigo(turma, codigoBusca);

   
    liberarTurma(&turma);

    return 0;
}
