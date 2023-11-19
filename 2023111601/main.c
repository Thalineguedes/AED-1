#include <stdio.h>

int k_esimo_digito(int n, int k) {
    if (k == 1) {
        return n % 10;
    } else {
        return k_esimo_digito(n / 10, k - 1);
    }
}

int main() {
    int n = 2845;
    int k = 3;
    printf("O %d-ésimo dígito de %d é: %d\n", k, n, k_esimo_digito(n, k));

    return 0;
}
