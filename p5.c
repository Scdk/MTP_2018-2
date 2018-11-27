/* P5.c */
/* Lucas Resende Carneiro */
/* 11811ECP009 */

#include <stdio.h>

typedef
  unsigned long long int
  Bytes8;
typedef
  struct LCG { Bytes8 a, c, m, rand_max, atual; }
  LCG;

float somatorio(float *vet_ini, int vet_tamanho, float resultado){
  return(vet_tamanho < 0)? resultado : somatorio(vet_ini, vet_tamanho - 1, vet_ini[vet_tamanho] + resultado);
}

float produtorio(float *vet_ini, int vet_tamanho, float resultado){
  return(vet_tamanho < 0)? resultado : produtorio(vet_ini, vet_tamanho - 1, vet_ini[vet_tamanho] * resultado);
}

void semente(LCG * r, Bytes8 seed){
  // constrantes do POSIX [de]rand48, glibc [de]rand48[_r]
  // ULL transforma a constante 'int' em 'unsigned long long int'
  r->a = 0x5DEECE66DULL;
  r->c = 11ULL;
  r->m = (1ULL << 48);
  r->rand_max = r->m - 1;
  r->atual = seed;
}

Bytes8 lcg_rand(LCG * r) {
  r->atual = (r->a * r->atual + r->c) % r->m;
  return r->atual;
}

double lcg_rand_01(LCG * r){
  return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r){
  int i;
  for(i = 0; i < tam; i++)
    vetor[i] = (max-min) * lcg_rand_01(r) + min;
}

int main(){
  float vetor[50], resultado = 0, *vet;
  int escolha = 0, vet_tamanho = sizeof(vetor)/sizeof(float) - 1;
  LCG random;
  semente(&random, 123456);
  gera_numeros(vetor, 50, 0.5, 1.5, &random);
  printf("Digite 1 para somatorio e 2 para produtorio: ");
  scanf("%d", &escolha);
  if(escolha == 1)
    printf("%f\n", somatorio(vetor, vet_tamanho, 0));
  else if(escolha == 2)
    printf("%f\n", produtorio(vetor, vet_tamanho, 1));
      else
        printf("Escolha uma opcao valida");
  return 0;
}
