#include "Floresta.h"
#include <stdio.h>
#include <stdlib.h>

// Função para imprimir a árvore de forma gráfica com os nós à esquerda
void printTreeGraphically(Node* root, int space) {
    // Caso base
    if (root == NULL)
        return;

    // Incremento de espaço entre níveis
    space += 5;

    // Processa a subárvore esquerda
    printTreeGraphically(root->left, space);

    // Imprime o nó atual após o espaço
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Processa o nó da subárvore direita
    printTreeGraphically(root->right, space);
}

int main() {
  // Declaração de um array de ponteiros para árvores (forest) para três
  // categorias diferentes.
  Node *forest[3]; // Crie três árvores para três categorias diferentes

  // Inicializa todas as árvores como vazias (NULL).
  for (int i = 0; i < 3; i++) {
    forest[i] = NULL;
  }

  // Loop principal para o menu de opções.
  while (1) {
    printf("\nOpções:\n");
    printf("1. Inserir na árvore\n");
    printf("2. Pesquisar na árvore\n");
    printf("3. Excluir da árvore\n");
    printf("4. Caminhamento Pré-Ordem\n");
    printf("5. Caminhamento Em-Ordem\n");
    printf("6. Caminhamento Pós-Ordem\n");
    printf("7. Sair\n");
    printf("8. Ver em gráfico\n");
    printf("Escolha uma opção: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 7) {
      break; // Encerra o programa quando a opção 7 (Sair) é escolhida.
    }

    int category;
    printf("Escolha uma categoria (0, 1, ou 2): ");
    scanf("%d", &category);

    if (category < 0 || category >= 3) {
      printf("Categoria inválida.\n");
      continue; // Volta para o início do loop se a categoria for inválida.
    }

    int key;
    Node *result;

    switch (choice) {
    case 1:
      // Inserir na árvore
      printf("Digite o valor a ser inserido: ");
      scanf("%d", &key);
      forest[category] = insert(forest[category], key);
      printf("Valor inserido com sucesso.\n");
      break;
    case 2:
      // Pesquisar na árvore
      printf("Digite o valor a ser pesquisado: ");
      scanf("%d", &key);
      result = search(forest[category], key);
      if (result != NULL) {
        printf("Valor encontrado na árvore.\n");
      } else {
        printf("Valor não encontrado na árvore.\n");
      }
      break;
    case 3:
      // Excluir da árvore
      printf("Digite o valor a ser excluído: ");
      scanf("%d", &key);
      forest[category] = deleteNode(forest[category], key);
      printf("Valor excluído com sucesso.\n");
      break;
    case 4:
      printf("Caminhamento Pré-Ordem: ");
      preorder(forest[category]);
      printf("\n");
      break;
    case 5:
      printf("Caminhamento Em-Ordem: ");
      inorder(forest[category]);
      printf("\n");
      break;
    case 6:
      printf("Caminhamento Pós-Ordem: ");
      postorder(forest[category]);
      printf("\n");
      break;
    case 8:
      printf("Visualização Gráfica da Árvore:\n");
      printTreeGraphically(forest[category], 0);
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  }

  // Liberar memória antes de sair
  for (int i = 0; i < 3; i++) {
    freeTree(forest[i]);
  }

  return 0;
}
