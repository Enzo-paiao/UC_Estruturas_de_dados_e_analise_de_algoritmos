#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definição da estrutura do Conjunto
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} Conjunto;

// Função para criar um Conjunto vazio
void createConjunto(Conjunto *conjunto) {
    conjunto->head = NULL;
    conjunto->size = 0;
}

// Função para verificar se o Conjunto está vazio
bool isEmpty(Conjunto *conjunto) {
    return (conjunto->size == 0);
}

// Função para verificar pertinência (contains)
bool contains(Conjunto *conjunto, int value) {
    Node* current = conjunto->head;
    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Função para inserir um elemento no Conjunto
void insert(Conjunto *conjunto, int value) {
    if (!contains(conjunto, value)) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = conjunto->head;
        conjunto->head = newNode;
        conjunto->size++;
    }
}

// Função para remover um elemento do Conjunto
void removeElement(Conjunto *conjunto, int value) {
    Node* current = conjunto->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                conjunto->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            conjunto->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Função para calcular a União de dois Conjuntos
Conjunto unionConjunto(Conjunto conjunto1, Conjunto conjunto2) {
    Conjunto result;
    createConjunto(&result);

    Node* current = conjunto1.head;
    while (current != NULL) {
        insert(&result, current->data);
        current = current->next;
    }

    current = conjunto2.head;
    while (current != NULL) {
        insert(&result, current->data);
        current = current->next;
    }

    return result;
}

// Função para calcular a Interseção de dois Conjuntos
Conjunto intersection(Conjunto conjunto1, Conjunto conjunto2) {
    Conjunto result;
    createConjunto(&result);

    Node* current = conjunto1.head;
    while (current != NULL) {
        if (contains(&conjunto2, current->data)) {
            insert(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

// Função para calcular a Diferença entre dois Conjuntos
Conjunto difference(Conjunto conjunto1, Conjunto conjunto2) {
    Conjunto result;
    createConjunto(&result);

    Node* current = conjunto1.head;
    while (current != NULL) {
        if (!contains(&conjunto2, current->data)) {
            insert(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

// Função para obter o tamanho do Conjunto
int size(Conjunto *conjunto) {
    return conjunto->size;
}

// Função para atualizar um elemento no Conjunto
void updateElement(Conjunto *conjunto, int oldValue, int newValue) {
    if (contains(conjunto, newValue)) {
        return; // Novo valor já existe no Conjunto, evita duplicatas
    }

    Node* current = conjunto->head;
    while (current != NULL) {
        if (current->data == oldValue) {
            current->data = newValue;
            return;
        }
        current = current->next;
    }
}

// Função para liberar a memória alocada para o Conjunto
void clear(Conjunto *conjunto) {
    Node* current = conjunto->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    conjunto->head = NULL;
    conjunto->size = 0;
}

int main() {
    Conjunto conjunto1, conjunto2, resultado;
    createConjunto(&conjunto1);
    createConjunto(&conjunto2);

    int choice;
    int value;
    int oldValue;
    int newValue;

    while (1) {
        printf("\nOperações disponíveis:\n");
        printf("1 - Inserir elemento (insert) no Conjunto 1\n");
        printf("2 - Inserir elemento (insert) no Conjunto 2\n");
        printf("3 - Remover elemento (remove) do Conjunto 1\n");
        printf("4 - Remover elemento (remove) do Conjunto 2\n");
        printf("5 - Verificar pertinência (contains) no Conjunto 1\n");
        printf("6 - Verificar pertinência (contains) no Conjunto 2\n");
        printf("7 - Calcular União (union)\n");
        printf("8 - Calcular Interseção (intersection)\n");
        printf("9 - Calcular Diferença (difference)\n");
        printf("10 - Verificar se o Conjunto 1 está vazio (isEmpty)\n");
        printf("11 - Verificar se o Conjunto 2 está vazio (isEmpty)\n");
        printf("12 - Obter tamanho do Conjunto 1 (size)\n");
        printf("13 - Obter tamanho do Conjunto 2 (size)\n");
        printf("14 - Atualizar elemento no Conjunto 1\n");
        printf("15 - Atualizar elemento no Conjunto 2\n");
        printf("16 - Limpar Conjunto 1\n");
        printf("17 - Limpar Conjunto 2\n");
        printf("0 - Sair\n");
        printf("Escolha uma operação: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido no Conjunto 1: ");
                scanf("%d", &value);
                insert(&conjunto1, value);
                break;
            case 2:
                printf("Digite o valor a ser inserido no Conjunto 2: ");
                scanf("%d", &value);
                insert(&conjunto2, value);
                break;
            case 3:
                printf("Digite o valor a ser removido do Conjunto 1: ");
                scanf("%d", &value);
                removeElement(&conjunto1, value);
                break;
            case 4:
                printf("Digite o valor a ser removido do Conjunto 2: ");
                scanf("%d", &value);
                removeElement(&conjunto2, value);
                break;
            case 5:
                printf("Digite o valor a ser verificado no Conjunto 1: ");
                scanf("%d", &value);
                if (contains(&conjunto1, value)) {
                    printf("O valor %d pertence ao Conjunto 1.\n", value);
                } else {
                    printf("O valor %d não pertence ao Conjunto 1.\n", value);
                }
                break;
            case 6:
                printf("Digite o valor a ser verificado no Conjunto 2: ");
                scanf("%d", &value);
                if (contains(&conjunto2, value)) {
                    printf("O valor %d pertence ao Conjunto 2.\n", value);
                } else {
                    printf("O valor %d não pertence ao Conjunto 2.\n", value);
                }
                break;
            case 7:
                resultado = unionConjunto(conjunto1, conjunto2);
                printf("União calculada:\n");
                Node* current = resultado.head;
                while (current != NULL) {
                    printf("%d ", current->data);
                    current = current->next;
                }
                printf("\n");
                clear(&resultado);
                break;
            case 8:
                resultado = intersection(conjunto1, conjunto2);
                printf("Interseção calculada:\n");
                current = resultado.head;
                while (current != NULL) {
                    printf("%d ", current->data);
                    current = current->next;
                }
                printf("\n");
                clear(&resultado);
                break;
            case 9:
                resultado = difference(conjunto1, conjunto2);
                printf("Diferença calculada:\n");
                current = resultado.head;
                while (current != NULL) {
                    printf("%d ", current->data);
                    current = current->next;
                }
                printf("\n");
                clear(&resultado);
                break;
            case 10:
                printf("O Conjunto 1 %s vazio.\n", isEmpty(&conjunto1) ? "está" : "não está");
                break;
            case 11:
                printf("O Conjunto 2 %s vazio.\n", isEmpty(&conjunto2) ? "está" : "não está");
                break;
            case 12:
                printf("Tamanho do Conjunto 1: %d\n", size(&conjunto1));
                break;
            case 13:
                printf("Tamanho do Conjunto 2: %d\n", size(&conjunto2));
                break;
            case 14:
                printf("Digite o valor a ser atualizado no Conjunto 1: ");
                scanf("%d", &oldValue);
                printf("Digite o novo valor: ");
                scanf("%d", &newValue);
                updateElement(&conjunto1, oldValue, newValue);
                break;
            case 15:
                printf("Digite o valor a ser atualizado no Conjunto 2: ");
                scanf("%d", &oldValue);
                printf("Digite o novo valor: ");
                scanf("%d", &newValue);
                updateElement(&conjunto2, oldValue, newValue);
                break;
            case 16:
                clear(&conjunto1);
                printf("Conjunto 1 foi limpo.\n");
                break;
            case 17:
                clear(&conjunto2);
                printf("Conjunto 2 foi limpo.\n");
                break;
            case 0:
                return 0; // Encerra o programa
            default:
                printf("Operação inválida\n");
        }
    }

    // Libera a memória alocada antes de encerrar o programa
    clear(&conjunto1);
    clear(&conjunto2);

    return 0;
}
