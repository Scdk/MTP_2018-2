/* P0.c */
/* Lucas Resende Carneiro */
/* 11811ECP009 */
#include <stdio.h>

int main(){
  int estado = 0, i = 0;
  char bits[256];
  printf("Digite o numero a ser testado: ");
  scanf("%s", bits);
  while(bits[i] != '\0'){
    if(estado == 0 && bits[i] == '0')
      estado = 0;
    else if(estado == 0 && bits[i] == '1')
      estado = 1;
          else if(estado == 1 && bits[i] == '0')
            estado = 2;
                else if(estado == 1 && bits[i] == '1')
                  estado = 0;
                      else if(estado == 2 && bits[i] == '0')
                        estado = 1;
                            else
                              estado = 2;
    i++;
  }
  if(estado == 0)
    printf("\nO valor do estado eh %d, a sequencia original era %s e o numero eh multiplo de 3", estado, bits);
  else
    printf("\nO valor do estado eh %d, a sequencia original era %s e o numero nao eh multiplo de 3", estado, bits);
  return 0;
}
