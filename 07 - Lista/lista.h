#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAM 10 // Defina o tamanho máximo da lista

typedef int elemento;

struct tipo_lista {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_lista lista;

// Cria lista.
void CriarLista(lista *l) {
    l->inicio = -1;
    l->fim = -1;
}

// Verifica se a lista está vazia.
int ListaVazia(lista *l) {
    return (l->inicio == -1);
}

// Verifica se a fila está cheia.
int ListaCheia(lista *l) {
    return (l->fim == TAM - 1);
}

// Insere um elemento na lista.
void Alistar(lista *l, elemento e, int pos) {
    int i;

    if (ListaCheia(l))
        printf("\nERRO: lista cheia!");
    else if ((pos < l->inicio) || (pos > l->fim + 1)) {
        printf("\nERRO: posição não existe!");
        printf("\nPosicoes validas: [%d, %d].", l->inicio, l->fim + 1);
    } else {
        for (i = l->fim + 1; i > pos; i--)
            l->vet[i] = l->vet[i - 1];
        l->vet[pos] = e;
        if (l->inicio == -1) {
            l->inicio = 0;
        }
        l->fim++;
    }
}

// Retira um elemento da lista.
elemento Desalistar(lista *l, int pos) {
    int i;
    elemento e;

    if (ListaVazia(l))
        printf("\nERRO: lista vazia!");
    else if ((pos < l->inicio) || (pos > l->fim)) {
        printf("\nERRO: posição não existe!");
        printf("\nPosicoes validas: [%d, %d].", l->inicio, l->fim);
    } else {
        e = l->vet[pos];
        for (i = pos; i < l->fim; i++)
            l->vet[i] = l->vet[i + 1];
        if (l->inicio == l->fim) {
            l->inicio = -1;
            l->fim = -1;
        } else {
            l->fim--;
        }
    }
    return (e);
}

// Imprime o conteúdo da lista.
void ImprimeLista(lista *l) {
    if (ListaVazia(l)) {
        printf("A lista está vazia.\n");
    } else {
        printf("Conteúdo da lista:\n");
        for (int i = l->inicio; i <= l->fim; i++) {
            printf("%d ", l->vet[i]);
        }
        printf("\n");
    }
}

#define MAX_TAM 10
typedef float elemento_2;

struct tipo_lista_2 {
  elemento_2 vet_2[MAX_TAM];
  int inicio_2, fim_2;
};

typedef struct tipo_lista_2 lista_2;

void CriarLista_2(lista_2 *l_2) {
  (*l_2).inicio_2 = 0;
  (*l_2).fim_2 = 0;
}

int ListaVazia_2(lista_2 *l_2) { return ((*l_2).inicio_2 == (*l_2).fim_2); }

int ListaCheia_2(lista_2 *l_2) { return ((*l_2).fim_2 == MAX_TAM); }

void Enfileirar_2(lista_2 *l_2, elemento_2 e_2) {
  if (ListaCheia_2(l_2))
    printf("ERRO: Fila cheia!\n");
  else
    (*l_2).vet_2[(*l_2).fim_2++] = e_2;
}

elemento_2 Desenfileirar_2(lista_2 *l_2) {
  elemento_2 e_2;

  if (ListaVazia_2(l_2)) {
    printf("ERRO: Fila vazia!\n");
    (*l_2).fim_2 = 0; // Atualiza para indicar que a fila está vazia
    return -1.0;  // Retorna um valor inválido para indicar o erro
  }

  e_2 = (*l_2).vet_2[(*l_2).inicio_2];

  // Movendo os elementos uma posição para trás
  for (int i = 0; i < (*l_2).fim_2 - 1; i++) {
    (*l_2).vet_2[i] = (*l_2).vet_2[i + 1];
  }

  (*l_2).fim_2--;

  return e_2;
}

void SalvarLista_2(lista_2 *l_2, const char *nomeArquivo_2) {
  FILE *arquivo_2 = fopen(nomeArquivo_2, "w");

  if (arquivo_2 != NULL) {
    for (int i = 0; i < (*l_2).fim_2; i++) {
      fprintf(arquivo_2, "%.2f\n", (*l_2).vet_2[i]);
    }
    fclose(arquivo_2);
  } else {
    printf("ERRO: Não foi possível abrir o arquivo para salvar.\n");
  }
}

int CarregarLista_2(lista_2 *l_2, const char *nomeArquivo_2) {
  FILE *arquivo_2 = fopen(nomeArquivo_2, "r");

  if (arquivo_2 != NULL) {
    CriarLista_2(l_2); // Limpa a lista atual
    float num_2;
    while (fscanf(arquivo_2, "%f", &num_2) != EOF) {
      Enfileirar_2(l_2, num_2);
    }
    fclose(arquivo_2);
    return 1;
  } else {
    return 0;
  }
}

void ImprimirLista_2(lista_2 *l_2) {
  printf("Conteúdo da lista:\n");
  for (int i = 0; i < (*l_2).fim_2; i++) {
    printf("%.2f\n", (*l_2).vet_2[i]);
  }
}
