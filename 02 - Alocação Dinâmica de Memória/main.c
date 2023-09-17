#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
  char cpf[12];
  char nome[100];
  float salario;
};

struct Pessoa *alocarPessoa(int n) {
  struct Pessoa *pessoas = (struct Pessoa *)malloc(n * sizeof(struct Pessoa));
  if (pessoas == NULL) {
    printf("Falha na alocação de memória para Pessoa.\n");
    exit(1);
  }
  return pessoas;
}

void preencherPessoa(struct Pessoa *pessoas, int n) {
  for (int i = 0; i < n; i++) {
    printf("Digite o CPF da pessoa %d: ", i + 1);
    scanf("%s", pessoas[i].cpf);

    printf("Digite o nome da pessoa %d: ", i + 1);
    scanf(" %[^\n]s", pessoas[i].nome);

    printf("Digite o salário da pessoa %d: ", i + 1);
    scanf("%f", &pessoas[i].salario);
  }
}

void imprimirPessoa(const struct Pessoa *pessoas, int n) {
  printf("Vetor de Pessoas:\n");
  for (int i = 0; i < n; i++) {
    printf("Pessoa %d:\n", i + 1);
    printf("CPF: %s\n", pessoas[i].cpf);
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Salário: %.2f\n", pessoas[i].salario);
    printf("\n");
  }
}

struct Veiculo {
  char chassi[20];
  char marca[50];
  char modelo[50];
  float preco;
};

struct Veiculo *alocarVeiculo(int n) {
  struct Veiculo *veiculos =
      (struct Veiculo *)malloc(n * sizeof(struct Veiculo));
  if (veiculos == NULL) {
    printf("Falha na alocação de memória para Veiculo.\n");
    exit(1);
  }
  return veiculos;
}

void preencherVeiculo(struct Veiculo *veiculos, int n) {
  for (int i = 0; i < n; i++) {
    sprintf(veiculos[i].chassi, "Chassi-%d", i + 1);
    sprintf(veiculos[i].marca, "Marca-%d", i + 1);
    sprintf(veiculos[i].modelo, "Modelo-%d", i + 1);
    veiculos[i].preco = (i + 1) * 10000.0;
  }
}

void imprimirVeiculo(const struct Veiculo *veiculos, int n) {
  printf("Vetor de Veículos:\n");
  for (int i = 0; i < n; i++) {
    printf("Veículo %d:\n", i + 1);
    printf("Chassi: %s\n", veiculos[i].chassi);
    printf("Marca: %s\n", veiculos[i].marca);
    printf("Modelo: %s\n", veiculos[i].modelo);
    printf("Preço: %.2f\n", veiculos[i].preco);
    printf("\n");
  }
}

int main() {
  int escolha, n;

  printf("Escolha a opção:\n");
  printf("1. Executar o Array de multiplos\n");
  printf("2. Executar o código Pessoa\n");
  printf("3. Executar o código Veiculo\n");
  scanf("%d", &escolha);

  if (escolha == 1) {

    int *array;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    if (n <= 0) {
      printf("Tamanho do array inválido.\n");
      return 1;
    }
    array = (int *)calloc(n, sizeof(int));
    if (array == NULL) {
      printf("Falha na alocação de memória.\n");
      return 1;
    }
    printf("Array: ");
    for (int i = 0; i < n; i++) {
      array[i] = i * 10;
      printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
  } else if (escolha == 2) {
    printf("Digite o tamanho do vetor de Pessoas: ");
    scanf("%d", &n);
    if (n <= 0) {
      printf("Tamanho do vetor de Pessoas inválido.\n");
      return 1;
    }
    struct Pessoa *pessoas = alocarPessoa(n);
    preencherPessoa(pessoas, n);
    imprimirPessoa(pessoas, n);
    free(pessoas);
  } else if (escolha == 3) {
    printf("Digite o tamanho do vetor de Veiculos: ");
    scanf("%d", &n);
    if (n <= 0) {
      printf("Tamanho do vetor de Veiculos inválido.\n");
      return 1;
    }
    struct Veiculo *veiculos = alocarVeiculo(n);
    preencherVeiculo(veiculos, n);
    imprimirVeiculo(veiculos, n);
    free(veiculos);
  } else {
    printf("Opção inválida.\n");
    return 1;
  }

  return 0;
}
