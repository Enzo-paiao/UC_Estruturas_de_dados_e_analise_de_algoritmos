#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
  long int CPF;
  char nome[50];
  float salario;
} Pessoa;

Pessoa *alocarMemoriaPessoa(int n) {
  Pessoa *array = (Pessoa *)calloc(n, sizeof(Pessoa));
  if (array == NULL) {
    printf("Falha na alocação de memória para Pessoa.\n");
    exit(1);
  }
  return array;
}

void preencherVetorPessoa(Pessoa *array, int n) {
  for (int i = 0; i < n; i++) {
    array[i].CPF = 1234567890 + i;
    sprintf(array[i].nome, "Pessoa%d", i);
    array[i].salario = 1000.0 + i * 100;
  }
}

void imprimirVetorPessoa(Pessoa *array, int n) {
  printf("Pessoas: \n");
  for (int i = 0; i < n; i++) {
    printf("Pessoa %d\n", i + 1);
    printf("CPF: %ld\n", array[i].CPF);
    printf("Nome: %s\n", array[i].nome);
    printf("Salário: %.2f\n", array[i].salario);
    printf("\n");
  }
}

typedef struct Veiculo {
  long int chassi;
  char marca[50];
  char modelo[50];
  float preco;
} Veiculo;

Veiculo *alocarMemoriaVeiculo(int n) {
  Veiculo *array = (Veiculo *)malloc(n * sizeof(Veiculo));
  if (array == NULL) {
    printf("Falha na alocação de memória para Veículo.\n");
    exit(1);
  }
  return array;
}

void preencherVetorVeiculo(Veiculo *array, int n) {
  for (int i = 0; i < n; i++) {
    array[i].chassi = 1000000 + i;
    sprintf(array[i].marca, "Marca%d", i);
    sprintf(array[i].modelo, "Modelo%d", i);
    array[i].preco = 10000.0 + i * 1000;
  }
}

void imprimirVetorVeiculo(Veiculo *array, int n) {
  printf("Veículos: \n");
  for (int i = 0; i < n; i++) {
    printf("Veículo %d\n", i + 1);
    printf("Chassi: %ld\n", array[i].chassi);
    printf("Marca: %s\n", array[i].marca);
    printf("Modelo: %s\n", array[i].modelo);
    printf("Preço: %.2f\n", array[i].preco);
    printf("\n");
  }
}

Veiculo *realocarMemoriaVeiculo(Veiculo *array, int *n, int novo_tamanho) {
  array = (Veiculo *)realloc(array, novo_tamanho * sizeof(Veiculo));
  if (array == NULL) {
    printf("Falha na realocação de memória para Veículo.\n");
    exit(1);
  }
  *n = novo_tamanho;
  return array;
}

int *alocarMemoria(int n) {
  // Alocação dinâmica de memória usando malloc
  int *array = (int *)malloc(n * sizeof(int));
  if (array == NULL) {
    printf("Falha na alocação de memória.\n");
    exit(1);
  }
  return array;
}

void preencherVetor(int *array, int n) {
  // Preencher o array
  for (int i = 0; i < n; i++) {
    array[i] = i * 10;
  }
}

void imprimirVetor(int *array, int n) {
  // Imprimir o array
  printf("Array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int escolha, n;

  printf("Escolha a opção:\n");
  printf("1. Executar o Array de multiplos\n");
  printf("2. Executar o código Pessoa\n");
  printf("3. Executar o código Veiculo\n");
  scanf("%d", &escolha);

  if (escolha == 1) {
    int *array, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    array = alocarMemoria(n); // Função para alocação de memória
    preencherVetor(array, n); // Função para preenchimento do vetor
    imprimirVetor(array, n);  // Função para impressão do vetor

    // Liberar a memória alocada com malloc
    free(array);
  } else if (escolha == 2) {
    Pessoa *pessoas;
    int n;
    printf("Digite o número de pessoas: ");
    scanf("%d", &n);

    pessoas = alocarMemoriaPessoa(n);
    preencherVetorPessoa(pessoas, n);
    imprimirVetorPessoa(pessoas, n);

    free(pessoas);
  } else if (escolha == 3) {
    Veiculo *veiculos;
    int n;
    printf("Digite o tamanho inicial do array: ");
    scanf("%d", &n);

    veiculos = alocarMemoriaVeiculo(n);
    preencherVetorVeiculo(veiculos, n);
    imprimirVetorVeiculo(veiculos, n);
    printf("Após realocar: ");
    int novo_tamanho = n + 5;
    veiculos = realocarMemoriaVeiculo(veiculos, &n, novo_tamanho);
    preencherVetorVeiculo(veiculos + n - 5, 5);
    imprimirVetorVeiculo(veiculos, novo_tamanho);

    free(veiculos);
  } else {
    printf("Opção inválida.\n");
    return 1;
  }

  return 0;
}
