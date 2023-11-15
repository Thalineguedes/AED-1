#include <stdio.h>
#include <stdlib.h>
typedef struct{
char nome [50];
char nascimento [11];
char CPF [12]; 

}Pessoa;
int Preencherdados (Pessoa* pessoa){
  printf("Digite o nome: ");
  scanf("%s", pessoa->nome);
  printf("Digite a data de nascimento: ");
  scanf("%s", pessoa->nascimento);
  printf("Digite o CPF: ");
  scanf("%s", pessoa->CPF);
}
  int imprimirdados (Pessoa*pessoa){
    printf("Nome: %s\n", pessoa->nome);
    printf("Data de nascimento: %s\n", pessoa->nascimento);
    printf("CPF: %s\n", pessoa->CPF);
  }
int main() {
  Pessoa* pessoa = (Pessoa*) malloc(sizeof(Pessoa));
  Preencherdados(pessoa);
  imprimirdados(pessoa);
  free(pessoa);

  return 0;
}
