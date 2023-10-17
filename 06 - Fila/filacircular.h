#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_FILA_F4 5

// Estrutura da fila
struct Fila_F4 {
  int dados_F4[TAMANHO_FILA_F4];
  int inicio_F4;
  int fim_F4;
  int quantidade_F4;
};

// Função para criar uma fila vazia
void CriarFila_F4(struct Fila_F4 *fila_F4) {
  fila_F4->inicio_F4 = 0;
  fila_F4->fim_F4 = 0;
  fila_F4->quantidade_F4 = 0;
}

// Função para verificar se a fila está vazia
int FilaVazia_F4(const struct Fila_F4 *fila_F4) {
  return fila_F4->quantidade_F4 == 0;
}

// Função para verificar se a fila está cheia
int FilaCheia_F4(const struct Fila_F4 *fila_F4) {
  return fila_F4->quantidade_F4 == TAMANHO_FILA_F4;
}

// Função para enfileirar um elemento na fila
int Enfileirar_F4(struct Fila_F4 *fila_F4, int valor_F4) {
    if (FilaCheia_F4(fila_F4)) {
        // A fila está cheia, sobrescrever o elemento mais antigo (circular)
        fila_F4->inicio_F4 = (fila_F4->inicio_F4 + 1) % TAMANHO_FILA_F4;
    }
    int index_substituir = (fila_F4->inicio_F4 + fila_F4->quantidade_F4) % TAMANHO_FILA_F4;
    fila_F4->dados_F4[index_substituir] = valor_F4;
    if (fila_F4->quantidade_F4 < TAMANHO_FILA_F4) {
        fila_F4->quantidade_F4++;
    }
    return 1; // Sucesso
}



int Desenfileirar_F4(struct Fila_F4 *fila_F4, int *valor_F4) {
    if (FilaVazia_F4(fila_F4)) {
        return 0; // Falha, fila vazia
    }
    *valor_F4 = fila_F4->dados_F4[fila_F4->inicio_F4];
    fila_F4->inicio_F4 = (fila_F4->inicio_F4 + 1) % TAMANHO_FILA_F4;
    if (fila_F4->quantidade_F4 > 0) {
        fila_F4->quantidade_F4--;
    }
    return 1; // Sucesso
}


// Função para mostrar a fila
void MostrarFila_F4(const struct Fila_F4 *fila_F4) {
  if (FilaVazia_F4(fila_F4)) {
    printf("A fila está vazia.\n");
    return;
  }

  printf("Conteúdo da fila: ");
  int i_F4 = fila_F4->inicio_F4;
  for (int j_F4 = 0; j_F4 < fila_F4->quantidade_F4; j_F4++) {
    printf("%d ", fila_F4->dados_F4[i_F4]);
    i_F4 = (i_F4 + 1) % TAMANHO_FILA_F4;
  }
  printf("\n");
}
