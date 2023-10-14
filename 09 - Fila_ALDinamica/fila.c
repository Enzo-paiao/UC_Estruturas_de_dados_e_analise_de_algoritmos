#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializa uma fila vazia
void inicializarFila(Fila *fila) {
  fila->frente = NULL;
  fila->tras = NULL;
}

// Enfileira um pedido na fila
void enfileirarPedido(Fila *fila, Pedido novoPedido) {
  Pedido *novo = (Pedido *)malloc(sizeof(Pedido));
  if (novo == NULL) {
    printf("Erro ao alocar memória para o pedido.\n");
    exit(1);
  }

  strcpy(novo->nomeCliente, novoPedido.nomeCliente);
  strcpy(novo->telefoneContato, novoPedido.telefoneContato);
  strcpy(novo->enderecoEntrega, novoPedido.enderecoEntrega);
  strcpy(novo->produtoPedido, novoPedido.produtoPedido);
  novo->valorProduto = novoPedido.valorProduto;
  novo->proximo = NULL;
  novo->anterior = fila->tras;

  if (fila->tras == NULL) {
    fila->frente = novo;
  } else {
    fila->tras->proximo = novo;
  }

  fila->tras = novo;
}

// Desenfileira um pedido da fila
int desenfileirarPedido(Fila *fila) {
  if (fila->frente == NULL) {
    printf("A fila está vazia.\n");
    return 0;
  }

  Pedido *temp = fila->frente;
  fila->frente = temp->proximo;

  if (fila->frente == NULL) {
    fila->tras = NULL;
  } else {
    fila->frente->anterior = NULL;
  }

  free(temp);
  return 1;
}

// Imprime o conteúdo da fila na tela
void imprimirFila(Fila *fila) {
  Pedido *atual = fila->frente;
  printf("=== Conteúdo da Fila ===\n");
  while (atual != NULL) {
    printf("Nome: %s\n", atual->nomeCliente);
    printf("Telefone: %s\n", atual->telefoneContato);
    printf("Endereço: %s\n", atual->enderecoEntrega);
    printf("Produto: %s\n", atual->produtoPedido);
    printf("Valor: %.2f\n", atual->valorProduto);
    printf("\n");
    atual = atual->proximo;
  }
}

// Imprime o conteúdo da fila em um arquivo de texto
void imprimirFilaEmArquivo(Fila *fila, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return;
  }

  Pedido *atual = fila->frente;
  while (atual != NULL) {
    fprintf(arquivo, "Nome: %s\n", atual->nomeCliente);
    fprintf(arquivo, "Telefone: %s\n", atual->telefoneContato);
    fprintf(arquivo, "Endereço: %s\n", atual->enderecoEntrega);
    fprintf(arquivo, "Produto: %s\n", atual->produtoPedido);
    fprintf(arquivo, "Valor: %.2f\n", atual->valorProduto);
    fprintf(arquivo, "\n");
    atual = atual->proximo;
  }

  fclose(arquivo);
}

// Lê o conteúdo de um arquivo de texto para a fila
void lerFilaDeArquivo(Fila *fila, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para leitura.\n");
    return;
  }

  Pedido novoPedido;
  char linha[256];

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    if (strncmp(linha, "Nome: ", 6) == 0) {
      sscanf(linha, "Nome: %s", novoPedido.nomeCliente);
      fgets(linha, sizeof(linha), arquivo); // Lê a próxima linha (Telefone)
      sscanf(linha, "Telefone: %s", novoPedido.telefoneContato);
      fgets(linha, sizeof(linha), arquivo); // Lê a próxima linha (Endereço)
      sscanf(linha, "Endereço: %s", novoPedido.enderecoEntrega);
      fgets(linha, sizeof(linha), arquivo); // Lê a próxima linha (Produto)
      sscanf(linha, "Produto: %s", novoPedido.produtoPedido);
      fgets(linha, sizeof(linha), arquivo); // Lê a próxima linha (Valor)
      sscanf(linha, "Valor: %f", &novoPedido.valorProduto);

      enfileirarPedido(fila, novoPedido);
    }
  }

  fclose(arquivo);
}

// Retorna a quantidade de pedidos na frente de um cliente especificado
int pedidosNaFrente(Fila *fila, const char *nomeCliente) {
  Pedido *atual = fila->frente;
  int contador = 0;
  while (atual != NULL) {
    if (strcmp(atual->nomeCliente, nomeCliente) == 0) {
      return contador;
    }
    contador++;
    atual = atual->proximo;
  }
  return -1; // Cliente não encontrado na fila
}
