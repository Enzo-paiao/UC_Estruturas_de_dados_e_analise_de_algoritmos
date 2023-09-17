#include <ctype.h>
#include <stdio.h>

int isAlpha(char c) {
  if (isalpha(c)) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char c;
  int choice;

  printf("Digite um caractere: ");
  scanf(" %c", &c);

  printf("Escolha uma função para executar:\n");
  printf("1. isAlpha\n");
  printf("2. isdigit\n");
  printf("3. isupper\n");
  printf("4. islower\n");
  printf("5. isalnum\n");
  printf("Digite o número da opção desejada: ");
  scanf("%d", &choice);

  switch (choice) {
  case 2:
    if (isdigit(c))
      printf("'%c' é um dígito.\n", c);
    else
      printf("'%c' não é um dígito.\n", c);
    break;

  case 3:
    if (isupper(c))
      printf("'%c' é uma letra maiúscula.\n", c);
    else
      printf("'%c' não é uma letra maiúscula.\n", c);
    break;

  case 4:
    if (islower(c))
      printf("'%c' é uma letra minúscula.\n", c);
    else
      printf("'%c' não é uma letra minúscula.\n", c);
    break;

  case 5:
    if (isalnum(c))
      printf("'%c' é uma letra ou um dígito.\n", c);
    else
      printf("%c não é uma letra ou um dígito.\n", c);
    break;

  case 1:
    if (isAlpha(c))
      printf("O caractere '%c' é uma letra.\n", c);
    else
      printf("O caractere '%c' não é uma letra.\n", c);
    break;

  default:
    printf("Opção inválida.\n");
    break;
  }

  return 0;
}
