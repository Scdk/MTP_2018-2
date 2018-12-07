/* P7.c */
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

void grava_pontos(char nome[], Ponto * pontos, int n){
  FILE * arquivo;
  arquivo = fopen(nome, "wb");
  fwrite(pontos, n, sizeof(Ponto), arquivo);
  fclose(arquivo);
  printf("Arquivo gravado");
}

Ponto * le_numeros(char nome[], unsigned int * pn){
  Ponto *pontos = (Ponto *) malloc(sizeof(Ponto));
  unsigned int n = 0;
  FILE * arquivo;
  arquivo = fopen(nome, "rb");
  if(arquivo != NULL){
    while(1){
      fread(pontos, 1, sizeof(Ponto), arquivo);
      if(feof(arquivo)) break;
      n++;
    }
    rewind(arquivo);
    pontos  = (Ponto *) realloc(pontos, n*sizeof(Ponto));
    fread(pontos, n, sizeof(Ponto), arquivo);
    *pn = n;
    return pontos;
  }
  printf("Eh preciso digitar o numero de vezes em que o ciclo vai ser dividido antes de mostrar.");
  return 0;
}

int main(){
  unsigned int n = 0, escolha = 0;
  Ponto *pontos;
  char nome[] = "pontos.dat";
  printf("1 - Digitar o numero de vezes que o ciclo trigonometrico vai ser dividido.\n2 - Mostrar as coordenadas dos pontos que dividem a circunferência.\nEscolha: ");
  scanf("%d", &escolha);
  if(escolha == 1){
    printf("Digite o numero de vezes em que o ciclo trigonometrico vai ser dividido: ");
    scanf("%d", &n); getchar();
    pontos = gera_numeros(n);
    grava_pontos(nome, pontos, n);
  }
    else if(escolha == 2){
      pontos = le_numeros(nome, &n);
      mostra_numeros(pontos, pontos + n);
  }
      else
        printf("Escolha invalida");
  free(pontos);
  printf("\n");
  return 0;
}
