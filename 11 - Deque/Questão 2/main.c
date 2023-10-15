#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura do nó da lista duplamente encadeada
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Definição da estrutura do Deque
typedef struct Deque {
    Node *front;
    Node *rear;
} Deque;

// Função para criar um novo nó com o valor especificado
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Função para criar um Deque vazio
Deque *createDeque() {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Função para verificar se o Deque está vazio
bool isEmpty(Deque *deque) {
    return (deque->front == NULL);
}

// Função para inserir no início do Deque
void pushFront(Deque *deque, int value) {
    Node *newNode = createNode(value);

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Função para inserir no final do Deque
void pushBack(Deque *deque, int value) {
    Node *newNode = createNode(value);

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Função para remover do início do Deque e retornar o valor
int popFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Erro: Deque vazio\n");
        return -1;
    }

    Node *frontNode = deque->front;
    int value = frontNode->data;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = frontNode->next;
        deque->front->prev = NULL;
    }

    free(frontNode);
    return value;
}

// Função para remover do final do Deque e retornar o valor
int popBack(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Erro: Deque vazio\n");
        return -1;
    }

    Node *rearNode = deque->rear;
    int value = rearNode->data;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = rearNode->prev;
        deque->rear->next = NULL;
    }

    free(rearNode);
    return value;
}

// Função para acessar o valor no início do Deque
int front(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Erro: Deque vazio\n");
        return -1;
    }
    return deque->front->data;
}

// Função para acessar o valor no final do Deque
int back(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Erro: Deque vazio\n");
        return -1;
    }
    return deque->rear->data;
}

// Função para obter o tamanho do Deque
int size(Deque *deque) {
    int count = 0;
    Node *current = deque->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Função para pesquisar um elemento no Deque e retornar o índice (-1 se não encontrado)
int search(Deque *deque, int value) {
    int index = 0;
    Node *current = deque->front;

    while (current != NULL) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

// Função para atualizar um elemento no Deque no índice especificado
void updateElement(Deque *deque, int index, int newValue) {
    if (index < 0 || index >= size(deque)) {
        printf("Erro: Índice inválido\n");
        return;
    }

    Node *current = deque->front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->data = newValue;
}

// Função para liberar a memória alocada para o Deque
void freeDeque(Deque *deque) {
    while (!isEmpty(deque)) {
        popFront(deque);
    }
    free(deque);
}

int main() {
    Deque *deque = createDeque();

    int choice;
    int value;
    int index;
    int newValue;

    while (1) {
        printf("\nOperações disponíveis:\n");
        printf("1 - Inserir no início (push_front)\n");
        printf("2 - Inserir no final (push_back)\n");
        printf("3 - Remover do início (pop_front)\n");
        printf("4 - Remover do final (pop_back)\n");
        printf("5 - Acessar o início (front)\n");
        printf("6 - Acessar o final (back)\n");
        printf("7 - Verificar se está vazio (isEmpty)\n");
        printf("8 - Tamanho (size)\n");
        printf("9 - Pesquisar\n");
        printf("10 - Atualizar elemento\n");
        printf("0 - Sair\n");
        printf("Escolha uma operação: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido no início: ");
                scanf("%d", &value);
                pushFront(deque, value);
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &value);
                pushBack(deque, value);
                break;
            case 3:
                value = popFront(deque);
                if (value != -1) {
                    printf("Elemento removido do início: %d\n", value);
                }
                break;
            case 4:
                value = popBack(deque);
                if (value != -1) {
                    printf("Elemento removido do final: %d\n", value);
                }
                break;
            case 5:
                value = front(deque);
                if (value != -1) {
                    printf("Elemento do início: %d\n", value);
                }
                break;
            case 6:
                value = back(deque);
                if (value != -1) {
                    printf("Elemento do final: %d\n", value);
                }
                break;
            case 7:
                printf("O Deque %s vazio.\n", isEmpty(deque) ? "está" : "não está");
                break;
            case 8:
                printf("Tamanho do Deque: %d\n", size(deque));
                break;
            case 9:
                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &value);
                index = search(deque, value);
                if (index != -1) {
                  printf("Valor encontrado no índice: %d\n", index);
                } 
                else {
                  printf("Valor não encontrado no Deque.\n");
                }
                break;
            case 10:
                printf("Digite o índice do elemento a ser atualizado: ");
                scanf("%d", &index);
                if (index >= 0 && index < size(deque)) {
                    printf("Digite o novo valor: ");
                    scanf("%d", &newValue);
                    updateElement(deque, index, newValue);
                }
                else {
                    printf("Erro: Índice inválido\n");
                }
                break;
            case 0:
                freeDeque(deque);
                return 0; // Encerra o programa
                default:
                printf("Operação inválida\n");
            }
        }

  return 0;
}
