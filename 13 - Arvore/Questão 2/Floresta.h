#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node *left;
  struct Node *right;
} Node;

// Função para criar um novo nó com a chave fornecida
Node *createNode(int key) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failed"); // Se a alocação de memória falhar,
                                        // exibe uma mensagem de erro.
    exit(1);
  }
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *insert(Node *root, int key) {
  if (root == NULL) {
    return createNode(key);
  }

  static int childSelector =
      0; // Variável para alternar entre os dois filhos de um nó pai

  if (key < root->key) {
    if (root->left == NULL) {
      root->left = createNode(key);
    } else {
      if (childSelector == 0) {
        root->left->left = insert(root->left->left, key);
        childSelector = 1;
      } else {
        root->left->right = insert(root->left->right, key);
        childSelector = 0;
      }
    }
  } else if (key > root->key) {
    if (root->right == NULL) {
      root->right = createNode(key);
    } else {
      if (childSelector == 0) {
        root->right->left = insert(root->right->left, key);
        childSelector = 1;
      } else {
        root->right->right = insert(root->right->right, key);
        childSelector = 0;
      }
    }
  }

  return root;
}

// Função para pesquisar um valor na árvore
Node *search(Node *root, int key) {
  if (root == NULL || root->key == key) {
    return root;
  }

  if (key < root->key) {
    return search(root->left, key); // Se a chave é menor que a chave do nó
                                    // atual, procura na subárvore esquerda.
  }

  return search(root->right,
                key); // Caso contrário, procura na subárvore direita.
}

// Função para encontrar o nó com o valor mínimo na árvore
Node *findMin(Node *node) {
  while (node && node->left != NULL) {
    node = node->left;
  }
  return node;
}

// Função para excluir um nó com a chave fornecida da árvore
Node *deleteNode(Node *root, int key) {
  if (root == NULL) {
    return root;
  }

  if (key < root->key) {
    root->left =
        deleteNode(root->left, key); // Se a chave é menor que a chave do nó
                                     // atual, exclui na subárvore esquerda.
  } else if (key > root->key) {
    root->right =
        deleteNode(root->right, key); // Se a chave é maior que a chave do nó
                                      // atual, exclui na subárvore direita.
  } else {
    if (root->left == NULL) {
      Node *temp = root->right;
      free(root); // Libera o nó atual.
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root); // Libera o nó atual.
      return temp;
    }

    Node *temp = findMin(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root; // Retorna o nó raiz atualizado após a exclusão.
}

// Função para realizar um caminhamento pré-ordem na árvore
void preorder(Node *root) {
  if (root != NULL) {
    printf("%d ", root->key); // Imprime o valor da chave do nó atual.
    preorder(root->left);  // Chama recursivamente para a subárvore esquerda.
    preorder(root->right); // Chama recursivamente para a subárvore direita.
  }
}

// Função para realizar um caminhamento em-ordem na árvore
void inorder(Node *root) {
  if (root != NULL) {
    inorder(root->left); // Chama recursivamente para a subárvore esquerda.
    printf("%d ", root->key); // Imprime o valor da chave do nó atual.
    inorder(root->right);     // Chama recursivamente para a subárvore direita.
  }
}

// Função para realizar um caminhamento pós-ordem na árvore
void postorder(Node *root) {
  if (root != NULL) {
    postorder(root->left);  // Chama recursivamente para a subárvore esquerda.
    postorder(root->right); // Chama recursivamente para a subárvore direita.
    printf("%d ", root->key); // Imprime o valor da chave do nó atual.
  }
}
// Função para liberar a memória ocupada pela árvore
void freeTree(Node *root) {
  if (root != NULL) {
    freeTree(root->left);  // Chama recursivamente para a subárvore esquerda.
    freeTree(root->right); // Chama recursivamente para a subárvore direita.
    free(root);            // Libera o nó atual.
  }
}
