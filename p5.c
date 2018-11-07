/* P4.c */
/* Lucas Resende Carneiro */
/* 11811ECP009 */

#include <stdio.h>

float soma(float m[50], int n, float result){
  if(n < 0)
    return result;
  else
    result += m[n];
    soma(m, n-1, result);
}

float produto(float m[50], int n, float result){
  if(result == 0)
    result++;
  if(n < 0)
    return result;
  else
    result *= m[n];
    produto(m, n-1, result);
}

typedef
  unsigned long long int
  Bytes8;
typedef
  struct LCG { Bytes8 a, c, m, rand_max, atual; }
  LCG;

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
  int escolha = 0;
  float vetor[50], result = 0;
  LCG random;
  semente(&random, 123456);
  gera_numeros(vetor, 50, 0.5, 1.5, &random);
  printf("Digite 1 para somatorio e 2 para produtorio: ");
  scanf("%d", &escolha); getchar();
  if(escolha == 1){
    printf("%f\n", soma(vetor, 49, result));
  }
  else
    printf("%f\n", produto(vetor, 49, result));
  return 0;
}
