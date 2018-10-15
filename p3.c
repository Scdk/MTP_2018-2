#include <stdio.h>

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

void extract_numbers(char number[256], char str[256]){
  int i, j = 0;
  printf("Digite o numero: ");
  scanf("%s", str);
  for(i = 0; str[i] != '\0'; i++){
    if(str[i] >= '0' && str[i] <= '9'){
      number[j] = str[i];
      j++;
    }
  }
  number[j] = '\0';
}

void string_to_int(char number[256]){
  int i, j;
  long int result = 0;
  for(j = 0; number[j] != '\0'; j++);
  j--;
  for(i = 0; number[j] != '\0'; j--){
      result += ((number[j] - 48) * expo(10, i));
      i++;
  }
  printf("%ld\n", result);
}

int main(){
  char number[256], str[256];
  extract_numbers(number, str);
  string_to_int(number);
  return 0;
}
