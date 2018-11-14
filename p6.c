/* P6.c */
/* Lucas Resende Carneiro */
/* 11811ECP009 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { float x, y; } Ponto;

Ponto * gera_numeros(int n){
  Ponto *pontos = (Ponto *) calloc(n, sizeof(Ponto));
  int i;
  for(i = 0; i < n; i++){
    pontos[i].x = cos(i*2.0*M_PI/(n-1));
    pontos[i].y = sin(i*2.0*M_PI/(n-1));
  }
  return pontos;
}

void mostra_numeros(Ponto * p_ini, Ponto * p_fim){
  if(p_ini < p_fim){
    printf("(%.3f, %.3f) ", p_ini->x, p_ini->y);
    mostra_numeros(p_ini + 1, p_fim);
  }
}

int main(){
  unsigned int n = 0;
  Ponto *pontos;
  printf("Digite o numero de vezes que o ciclo trigonometrico vai ser dividido: ");
  scanf("%d", &n); getchar();
  pontos = gera_numeros(n);
  mostra_numeros(pontos, pontos + n);
  free(pontos);
  printf("\n");
  return 0;
}
