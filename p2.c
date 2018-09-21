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

long int convBD(char bits[256], int cont){
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

void convDH(long int dec, char hex[64]){
  int i, res = dec;
  long int aux;
  for(i = 0; res > 16; i++)
    res = res / 16;
  for(; dec > 15; i--){
    aux = (dec % 16);
    dec = dec / 16;
    if(aux > 9){
      aux =  70 - (15 - aux);
      hex[i] = aux;
    }
    else
      hex[i] = aux + 48;
  }
  aux = (dec % 16);
  if(aux > 9){
    aux =  70 - (15 - aux);
    hex[i] = aux;
  }
  else
    hex[i] = aux + 48;

}

void binDec(){
  int cont = 0;
  char bits[256];
  long int dec = 0;
  printf("Digite o numero que deseja converter: ");
  scanf("%s", bits); getchar();
  for(cont = 0; bits[cont] != '\0'; cont++);
  dec = convBD(bits, cont);
  printf("%li\n", dec);
}

void binHex(){
  int i, cont;
  char bits[256], hex[64];
  long int dec = 0;
  printf("Digite o numero que deseja converter: ");
  scanf("%s", bits); getchar();
  for(cont = 0; bits[cont] != '\0'; cont++);
  dec = convBD(bits, cont);
  convDH(dec, hex);
  printf("%s\n", hex);
}

int main(){
  int opcao = 0;
  opcao = menu(opcao);
  switch(opcao){
    case 1:
      binDec();
      return 0;
    case 2:
      binHex();
      return 0;
  }
  return 0;
}
