#include <stdio.h>

typedef struct {
    float x;
    float y;
    float z;
} Vetor;
void soma(Vetor* v1, Vetor* v2, Vetor* resultado) {
    resultado->x = v1->x + v2->x;
    resultado->y = v1->y + v2->y;
    resultado->z = v1->z + v2->z;
}
float produto_escalar(Vetor* v1, Vetor* v2) {
    return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
}

int main() {
    Vetor vetor1 = {1.0, 2.0, 3.0};
    Vetor vetor2 = {4.0, 5.0, 6.0};
    Vetor resultado_soma;
    soma(&vetor1, &vetor2, &resultado_soma);
    printf("Soma: (%.2f, %.2f, %.2f)\n", resultado_soma.x, resultado_soma.y, resultado_soma.z);
    float resultado_escalar = produto_escalar(&vetor1, &vetor2);
    printf("Produto Escalar: %.2f\n", resultado_escalar);

    return 0;
}
