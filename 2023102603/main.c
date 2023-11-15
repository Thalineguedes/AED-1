include <stdio.h>
#include <stdlib.h>
typedef struct{
 float lado;
}Cubo;
int iniciarCubo(Cubo* cubo, float lado){
  cubo->lado = lado;
}
float calcularArea (Cubo* cubo){
  return 6 * cubo->lado * cubo->lado;
}
float calcularVolume(Cubo* cubo){
  return cubo->lado * cubo->lado * cubo->lado;
}
float obterLado(Cubo* cubo){
  return cubo->lado;
}
int main(){
  Cubo cubo;
  float lado;
  printf("Digite o tamanho do lado do cubo: ");
  scanf("%f", &lado);
  iniciarCubo(&cubo, lado);
  printf("lado do cubo: %.2f\n", obterLado(&cubo));
  printf("Àrea do cubo: %.2f\n", calcularArea(&cubo));
  printf("Volume ddo cubo: %.2f\n", calcularVolume(&cubo));

  return 0;
}
