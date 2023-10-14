#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0

#define TAM3 3

#define TAM10 10

typedef float elemento;

struct tipo_fila {
  elemento vet[TAM10];
  int inicio, fim;
};
typedef struct tipo_fila fila;

void CriarFila(fila *f) {
  (*f).inicio = -1;
  (*f).fim = -1;
}

int FilaVazia(fila *f) {
  return ((*f).inicio == -1);
}

int FilaCheia(fila *f) {
  return ((*f).fim == TAM10 - 1);
}

void Enfileirar(fila *f, elemento e) {
  if (!FilaCheia(f)) {
    if (FilaVazia(f)) {
      (*f).inicio = 0;
    }
    (*f).vet[++(*f).fim] = e;
  }
}

elemento Desenfileirar(fila *f) {
  if (!FilaVazia(f)) {
    elemento e = (*f).vet[(*f).inicio];
    if ((*f).inicio == (*f).fim) {
      CriarFila(f); 
    } else {
      (*f).inicio++;
    }
    return e;
  } else {
    return -1;
  }
}
void ImprimeFila(fila *f) {
  if (FilaVazia(f)) {
    printf("A fila está vazia.\n");
  } else {
    printf("Conteúdo da fila:\n");
    for (int i = (*f).inicio; i <= (*f).fim; i++) {
      printf("%.2f\n", (*f).vet[i]);
    }
  }
}

// Procedimento para desenfileirar os elementos e gravá-los em um arquivo de texto
void DesenfileirarEGravar(fila *f) {
  FILE *arquivo;
  arquivo = fopen("elementos.txt", "w");
  
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  
  while (!FilaVazia(f)) {
    elemento num = Desenfileirar(f);
    fprintf(arquivo, "%.2f\n", num);
  }
  
  fclose(arquivo);
}

void LerDoArquivoEEnfileirar(fila *f) {
  FILE *arquivo;
  arquivo = fopen("elementos.txt", "r");
  
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  
  elemento num;
  while (fscanf(arquivo, "%f", &num) != EOF) {
    Enfileirar(f, num);
  }
  
  fclose(arquivo);
}
