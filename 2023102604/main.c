#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float imaginaria;
} Complexo;

Complexo* criarComplexo(float real, float imaginaria) {
    Complexo* complexo = (Complexo*) malloc(sizeof(Complexo));
    complexo->real = real;
    complexo->imaginaria = imaginaria;
    return complexo;
}

int destruirComplexo(Complexo* complexo) {
    free(complexo);
}

Complexo* somarComplexos(Complexo* complexo1, Complexo* complexo2) {
    float real = complexo1->real + complexo2->real;
    float imaginaria = complexo1->imaginaria + complexo2->imaginaria;
    return criarComplexo(real, imaginaria);
}

Complexo* subtrairComplexos(Complexo* complexo1, Complexo* complexo2) {
    float real = complexo1->real - complexo2->real;
    float imaginaria = complexo1->imaginaria - complexo2->imaginaria;
    return criarComplexo(real, imaginaria);
}

Complexo* multiplicarComplexos(Complexo* complexo1, Complexo* complexo2) {
    float real = (complexo1->real * complexo2->real) - (complexo1->imaginaria * complexo2->imaginaria);
    float imaginaria = (complexo1->real * complexo2->imaginaria) + (complexo1->imaginaria * complexo2->real);
    return criarComplexo(real, imaginaria);
}

Complexo* dividirComplexos(Complexo* complexo1, Complexo* complexo2) {
    float divisor = (complexo2->real * complexo2->real) + (complexo2->imaginaria * complexo2->imaginaria);
    float real = ((complexo1->real * complexo2->real) + (complexo1->imaginaria * complexo2->imaginaria)) / divisor;
    float imaginaria = ((complexo1->imaginaria * complexo2->real) - (complexo1->real * complexo2->imaginaria)) / divisor;
    return criarComplexo(real, imaginaria);
}

int main() {
    Complexo* complexo1 = criarComplexo(2, 3);
    Complexo* complexo2 = criarComplexo(4, 5);

    Complexo* soma = somarComplexos(complexo1, complexo2);
    Complexo* subtracao = subtrairComplexos(complexo1, complexo2);
    Complexo* multiplicacao = multiplicarComplexos(complexo1, complexo2);
    Complexo* divisao = dividirComplexos(complexo1, complexo2);

    printf("Soma: %.2f + %.2fi\n", soma->real, soma->imaginaria);
    printf("Subtração: %.2f + %.2fi\n", subtracao->real, subtracao->imaginaria);
    printf("Multiplicação: %.2f + %.2fi\n", multiplicacao->real, multiplicacao->imaginaria);
    printf("Divisão: %.2f + %.2fi\n", divisao->real, divisao->imaginaria);

    destruirComplexo(complexo1);
    destruirComplexo(complexo2);
    destruirComplexo(soma);
    destruirComplexo(subtracao);
    destruirComplexo(multiplicacao);
    destruirComplexo(divisao);

    return 0;
}
