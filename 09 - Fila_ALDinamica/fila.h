#ifndef FILA_H
#define FILA_H

// Definição da estrutura para um pedido
typedef struct Pedido {
  char nomeCliente[50];
  char telefoneContato[15];
  char enderecoEntrega[100];
  char produtoPedido[50];
  float valorProduto;
  struct Pedido *proximo;
  struct Pedido *anterior;
} Pedido;

// Definição da estrutura da fila
typedef struct {
  Pedido *frente;
  Pedido *tras;
} Fila;

// Inicializa uma fila vazia
void inicializarFila(Fila *fila);

// Enfileira um pedido na fila
void enfileirarPedido(Fila *fila, Pedido novoPedido);

// Desenfileira um pedido da fila
int desenfileirarPedido(Fila *fila);

// Imprime o conteúdo da fila na tela
void imprimirFila(Fila *fila);

// Imprime o conteúdo da fila em um arquivo de texto
void imprimirFilaEmArquivo(Fila *fila, const char *nomeArquivo);

// Lê o conteúdo de um arquivo de texto para a fila
void lerFilaDeArquivo(Fila *fila, const char *nomeArquivo);

// Retorna a quantidade de pedidos na frente de um cliente especificado
int pedidosNaFrente(Fila *fila, const char *nomeCliente);

#endif
