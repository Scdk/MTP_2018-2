/* P4.c */
/* Lucas Resende Carneiro */
/* 11811ECP009 */

#include <stdio.h>

int ackermann(int m, int n){
  if(m == 0)
    return n+1;
  else if ((m > 0) && (n == 0))
    ackermann((m - 1), 1);
    else
      ackermann((m - 1),ackermann(m, (n-1)));
}

int main(){
  int m = 0, n = 0;
  printf("Digite o numero m: ");
  scanf("%d", &m); getchar();
  printf("Digite o numero n: ");
  scanf("%d", &n); getchar();
  printf("%d\n", ackermann(m,n));
  return 0;
}
