#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

struct ponto {
  float x;
  float y;
};

typedef struct ponto Ponto;
Ponto* Cria_ponto (float x, float y);
void libera_ponto (Ponto *pto);
int acessa_ponto (Ponto *pto, float *x, float *y);
int atribuir_ponto (Ponto *pto, float x, float y);
float distancia_ponto (Ponto *pt01, Ponto *pto2);

#endif // PONTO_HINCLUDED 
