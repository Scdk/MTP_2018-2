/* P2.c */
/* Lucas Resende Carneiro */
/* 11811ECP009 */
#include <stdio.h>

int menu(int opcao){
  printf("Escolha um tipo de conversao: \n");
  printf("=========================================================\n");
  printf("1 - Binario => Decimal\n2 - Binario => Hexadecimal\n3 - Hexadecimal => Decimal\n4 - Hexadecimal => Binario\n");
  printf("5 - Decimal => Binario\n6 - Decimal => Hexadecimal\n7 - Octal => Decimal\n8 - Decimal => Octal\n");
  printf("Digite: ");
  scanf("%d", &opcao);
  return opcao;
}

long int expo(int pot, int expo){
  int i;
  long int result = pot;
  for(i = 1; i < expo; i++){
    result = result * pot;
  }
  if(expo == 0)
    result = 1;
  return result;
}

long int convbd(char bits[256], int cont){
  int i = 0, aux = 0;
  long int result = 0;
  for(; cont > 0; cont--){
    if(bits[cont - 1] == '0')
      aux = 0;
    else if (bits[cont - 1] == '1')
      aux = 1;
    result =  result + (aux * expo(2, i));
    i++;
  }
  return result;
}

void bindec(){
  int cont = 0;
  char bits[256];
  long int dec = 0;
  printf("Digite o numero que deseja converter: ");
  scanf("%s", bits); getchar();
  for(cont = 0; bits[cont] != '\0'; cont++);
  dec = convbd(bits, cont);
  printf("%li\n", dec);
}

void hexdec(){
  int i, j = 0;
  char bits[256], bits2[256], hex[100];
  printf("Digite o numero que deseja converter: ");
  scanf("%s", bits); getchar();
  for(i = 0; bits[i] != '\0'; i++)
    for(i = 0; i < 3; i++){
      bits2[j] = bits[j];
      j++;
    }
    bits2[j] = '\0';

}

int main(){
  int opcao = 0;
  opcao = menu(opcao);
  switch(opcao){
    case 1:
      bindec();
      return 0;
    case 2:
      hexdec();
      return 0;
  }
  return 0;
}
