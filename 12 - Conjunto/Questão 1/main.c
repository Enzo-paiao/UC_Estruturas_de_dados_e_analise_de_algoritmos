#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Definição da estrutura do Conjunto
typedef struct {
    int data[MAX_SIZE];
    int size;
} Conjunto;

// Função para criar um Conjunto vazio
void createConjunto(Conjunto *conjunto) {
    conjunto->size = 0;
}

// Função para verificar se o Conjunto está vazio
bool isEmpty(Conjunto *conjunto) {
    return (conjunto->size == 0);
}

// Função para verificar pertinência (contains)
bool contains(Conjunto *conjunto, int value) {
    for (int i = 0; i < conjunto->size; i++) {
        if (conjunto->data[i] == value) {
            return true;
        }
    }
    return false;
}

// Função para inserir um elemento no Conjunto
void insert(Conjunto *conjunto, int value) {
    if (!contains(conjunto, value)) {
        conjunto->data[conjunto->size] = value;
        conjunto->size++;
    }
}

// Função para remover um elemento do Conjunto
void removeElement(Conjunto *conjunto, int value) {
    int index = -1;
    for (int i = 0; i < conjunto->size; i++) {
        if (conjunto->data[i] == value) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < conjunto->size - 1; i++) {
            conjunto->data[i] = conjunto->data[i + 1];
        }
        conjunto->size--;
    }
}

// Função para calcular a União de dois Conjuntos
void unionConjunto(Conjunto *result, Conjunto *conjunto1, Conjunto *conjunto2) {
    createConjunto(result);

    for (int i = 0; i < conjunto1->size; i++) {
        insert(result, conjunto1->data[i]);
    }

    for (int i = 0; i < conjunto2->size; i++) {
        insert(result, conjunto2->data[i]);
    }
}

// Função para calcular a Interseção de dois Conjuntos
void intersection(Conjunto *result, Conjunto *conjunto1, Conjunto *conjunto2) {
    createConjunto(result);

    for (int i = 0; i < conjunto1->size; i++) {
        if (contains(conjunto2, conjunto1->data[i])) {
            insert(result, conjunto1->data[i]);
        }
    }
}

// Função para calcular a Diferença entre dois Conjuntos
void difference(Conjunto *result, Conjunto *conjunto1, Conjunto *conjunto2) {
    createConjunto(result);

    for (int i = 0; i < conjunto1->size; i++) {
        if (!contains(conjunto2, conjunto1->data[i])) {
            insert(result, conjunto1->data[i]);
        }
    }
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

    for (int i = 0; i < conjunto->size; i++) {
        if (conjunto->data[i] == oldValue) {
            conjunto->data[i] = newValue;
        }
    }
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
                unionConjunto(&resultado, &conjunto1, &conjunto2);
                printf("União calculada:\n");
                for (int i = 0; i < resultado.size; i++) {
                    printf("%d ", resultado.data[i]);
                }
                printf("\n");
                break;
            case 8:
                intersection(&resultado, &conjunto1, &conjunto2);
                printf("Interseção calculada:\n");
                for (int i = 0; i < resultado.size; i++) {
                    printf("%d ", resultado.data[i]);
                }
                printf("\n");
                break;
            case 9:
                difference(&resultado, &conjunto1, &conjunto2);
                printf("Diferença calculada:\n");
                for (int i = 0; i < resultado.size; i++) {
                    printf("%d ", resultado.data[i]);
                }
                printf("\n");
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
            case 0:
                return 0; // Encerra o programa
            default:
                printf("Operação inválida\n");
        }
    }

    return 0;
}
