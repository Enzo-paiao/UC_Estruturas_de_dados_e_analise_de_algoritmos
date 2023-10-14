#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Fila filaPedidos;
  inicializarFila(&filaPedidos);

  int opcao;
  do {
    printf("=== Menu ===\n");
    printf("1. Cadastrar um pedido\n");
    printf("2. Imprimir a fila na tela\n");
    printf("3. Imprimir a fila em um arquivo\n");
    printf("4. Ler a fila de um arquivo\n");
    printf("5. Consultar pedidos na frente de um cliente\n");
    printf("6. Sair\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: {
      Pedido novoPedido;
      printf("Nome do cliente: ");
      scanf("%s", novoPedido.nomeCliente);
      printf("Telefone para contato: ");
      scanf("%s", novoPedido.telefoneContato);
      printf("Endereço para entrega: ");
      scanf("%s", novoPedido.enderecoEntrega);
      printf("Produto pedido: ");
      scanf("%s", novoPedido.produtoPedido);
      printf("Valor do produto: ");
      scanf("%f", &novoPedido.valorProduto);
      enfileirarPedido(&filaPedidos, novoPedido);
      printf("Pedido cadastrado com sucesso!\n");
      break;
    }
    case 2: {
      imprimirFila(&filaPedidos);
      break;
    }
    case 3: {
      char nomeArquivo[50];
      printf("Digite o nome do arquivo para imprimir a fila: ");
      scanf("%s", nomeArquivo);
      imprimirFilaEmArquivo(&filaPedidos, nomeArquivo);
      printf("Fila impressa no arquivo com sucesso!\n");
      break;
    }
    case 4: {
      char nomeArquivo[50];
      printf("Digite o nome do arquivo para ler a fila: ");
      scanf("%s", nomeArquivo);
      lerFilaDeArquivo(&filaPedidos, nomeArquivo);
      printf("Fila lida do arquivo com sucesso!\n");
      break;
    }
    case 5: {
      char nomeCliente[50];
      printf("Digite o nome do cliente: ");
      scanf("%s", nomeCliente);
      int pedidosFrente = pedidosNaFrente(&filaPedidos, nomeCliente);
      printf("Existem %d pedidos na frente do cliente %s.\n", pedidosFrente,
             nomeCliente);
      break;
    }
    }
  } while (opcao != 6);

  return 0;
}
/*Acesso bidirecional: Uma das principais vantagens das filas duplamente
encadeadas é o acesso bidirecional. Isso significa que você pode acessar
elementos tanto na frente quanto no final da fila com facilidade, o que pode ser
útil em muitos cenários.

Inserção e exclusão eficientes: Inserir ou excluir elementos no início e no
final de uma fila duplamente encadeada é uma operação eficiente (O(1)), desde
que você tenha referências para os elementos apropriados. Isso é útil para
implementar filas de tarefas em sistemas multitarefa.
-----------------------------------------------------------------------------------------------
Overhead: Devido à complexidade adicional, as filas duplamente encadeadas têm um
overhead maior em comparação com as filas simplesmente encadeadas, o que pode
ser uma desvantagem em situações onde a eficiência é fundamental.

Custos de desempenho: Embora as inserções e exclusões no início e no final da
fila sejam eficientes, as operações no meio da fila podem ser menos eficientes
do que em uma lista simplesmente encadeada, especialmente se você precisar
percorrer muitos nós para chegar ao elemento desejado.

*/