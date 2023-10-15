
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Definição da estrutura do Deque
typedef struct {
    int data[MAX_SIZE];
    int front, rear, size;
} Deque;

// Função para inicializar um Deque vazio
void initDeque(Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
    deque->size = 0;
}

// Função para verificar se o Deque está vazio
bool isEmpty(Deque *deque) {
    return deque->size == 0;
}

// Função para verificar se o Deque está cheio
bool isFull(Deque *deque) {
    return deque->size == MAX_SIZE;
}

// Função para inserir um elemento no início do Deque
void pushFront(Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Erro: Deque cheio\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front--;
    }

    deque->data[deque->front] = value;
    deque->size++;
}

// Função para inserir um elemento no final do Deque
void pushBack(Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Erro: Deque cheio\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX_SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }

    deque->data[deque->rear] = value;
    deque->size++;
}

// Função para remover e retornar o elemento do início do Deque
int popFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Erro: Deque vazio\n");
        return -1;
    }

    int value = deque->data[deque->front];

    if (deque->front == deque->rear) {
        initDeque(deque);
    } else if (deque->front == MAX_SIZE - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }

    deque->size--;

    return value;
}

// Função para remover e retornar o elemento do final do Deque
int popBack(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Erro: Deque vazio\n");
        return -1;
    }

    int value = deque->data[deque->rear];

    if (deque->front == deque->rear) {
        initDeque(deque);
    } else if (deque->rear == 0) {
        deque->rear = MAX_SIZE - 1;
    } else {
        deque->rear--;
    }

    deque->size--;

    return value;
}

// Função para acessar o elemento do início do Deque sem removê-lo
int front(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Erro: Deque vazio\n");
        return -1;
    }
    return deque->data[deque->front];
}

// Função para acessar o elemento do final do Deque sem removê-lo
int back(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Erro: Deque vazio\n");
        return -1;
    }
    return deque->data[deque->rear];
}

// Função para obter o número de elementos no Deque
int size(Deque *deque) {
    return deque->size;
}

// Função para pesquisar um elemento no Deque e retornar o índice (-1 se não encontrado)
int search(Deque *deque, int value) {
    if (isEmpty(deque)) {
        return -1;
    }

    int current = deque->front;
    int index = 0;

    while (index < deque->size) {
        if (deque->data[current] == value) {
            return index;
        }
        index++;
        if (current == MAX_SIZE - 1) {
            current = 0;
        } else {
            current++;
        }
    }

    return -1;
}

// Função para atualizar um elemento no Deque no índice especificado
void updateElement(Deque *deque, int index, int newValue) {
    if (index < 0 || index >= deque->size) {
        printf("Erro: Índice inválido\n");
        return;
    }

    int currentIndex = deque->front;
    int currentIndexInDeque = 0;

    while (currentIndexInDeque != index) {
        if (currentIndex == MAX_SIZE - 1) {
            currentIndex = 0;
        } else {
            currentIndex++;
        }
        currentIndexInDeque++;
    }

    deque->data[currentIndex] = newValue;
}

int main() {
    Deque deque;
    initDeque(&deque);

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
                pushFront(&deque, value);
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &value);
                pushBack(&deque, value);
                break;
            case 3:
                value = popFront(&deque);
                if (value != -1) {
                    printf("Elemento removido do início: %d\n", value);
                }
                break;
            case 4:
                value = popBack(&deque);
                if (value != -1) {
                    printf("Elemento removido do final: %d\n", value);
                }
                break;
            case 5:
                value = front(&deque);
                if (value != -1) {
                    printf("Elemento do início: %d\n", value);
                }
                break;
            case 6:
                value = back(&deque);
                if (value != -1) {
                    printf("Elemento do final: %d\n", value);
                }
                break;
            case 7:
                printf("O Deque %s vazio.\n", isEmpty(&deque) ? "está" : "não está");
                break;
            case 8:
                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &value);
                index = search(&deque, value);
                if (index != -1) {
                    printf("Valor encontrado no índice: %d\n", index);
                } else {
                    printf("Valor não encontrado no Deque.\n");
                }
                break;
            case 9:
                printf("Digite o índice do elemento a ser atualizado: ");
                scanf("%d", &index);
                printf("Digite o novo valor: ");
                scanf("%d", &newValue);
                updateElement(&deque, index, newValue);
                break;
            case 0:
                return 0; // Encerra o programa
            default:
                printf("Operação inválida\n");
        }
    }

    return 0;
}
