#include <stdio.h>
#include <stdlib.h>

#define M 4

// Definindo o número mínimo de chaves para um nó folha
#define MIN_KEYS ((M - 1) / 2)

typedef struct Node {
    int n; // Número de chaves no nó
    int keys[M - 1]; // Chaves armazenadas no nó
    struct Node *child[M]; // Ponteiros para filhos
    struct Node *next; // Ponteiro para o próximo nó folha (usado apenas em nós folha)
} Node;

Node *createNode() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->n = 0;
    for (int i = 0; i < M; i++) {
        newNode->child[i] = NULL;
    }
    newNode->next = NULL;
    return newNode;
}

void splitChild(Node *parent, int index, Node *child) {
    Node *newChild = createNode();
    newChild->n = M / 2 - 1;

    for (int i = 0; i < M / 2 - 1; i++) {
        newChild->keys[i] = child->keys[i + M / 2];
    }

    if (child->child[0] != NULL) {
        for (int i = 0; i < M / 2; i++) {
            newChild->child[i] = child->child[i + M / 2];
        }
    }

    child->n = M / 2 - 1;

    for (int i = parent->n - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
        parent->child[i + 2] = parent->child[i + 1];
    }

    parent->keys[index] = child->keys[M / 2 - 1];
    parent->child[index + 1] = newChild;

    parent->n++;
}

void insertNonFull(Node *node, int key) {
    int i = node->n - 1;

    if (node->n == 0) {
        node->keys[node->n++] = key;
        return;
    }

    if (node->child[0] == NULL) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        if (node->child[i]->n == M - 1) {
            splitChild(node, i, node->child[i]);

            if (key > node->keys[i]) {
                i++;
            }
        }

        insertNonFull(node->child[i], key);
    }
}

void insert(Node **root, int key) {
    if (*root == NULL) {
        *root = createNode();
        (*root)->keys[0] = key;
        (*root)->n++;
    } else {
        if ((*root)->n == M - 1) {
            Node *newRoot = createNode();
            newRoot->child[0] = *root;
            splitChild(newRoot, 0, *root);
            *root = newRoot;
        }

        insertNonFull(*root, key);
    }
}

void printTree(Node *root, int level) {
    if (root != NULL) {
        int i;
        for (i = root->n - 1; i >= 0; i--) {
            printTree(root->child[i + 1], level + 1);

            for (int j = 0; j < level; j++) {
                printf("    ");
            }
            printf("%d\n", root->keys[i]);
        }

        printTree(root->child[i + 1], level + 1);
    }
}

int main() {
    Node *root = NULL;
    int key;

    printf("Digite os números para inserir na árvore (digite -1 para encerrar):\n");

    while (1) {
        printf("Digite um número: ");
        scanf("%d", &key);

        if (key == -1) {
            break;
        }

        insert(&root, key);
    }

    printf("\nÁrvore B+ de ordem %d:\n", M);
    printTree(root, 0);

    return 0;
}
