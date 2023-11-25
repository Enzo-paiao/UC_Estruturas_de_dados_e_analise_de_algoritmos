#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Definindo a estrutura do funcionário
typedef struct Employee {
  char name[50];
  char hireDate[11];
  float salary;
  struct Employee *next;
} Employee;

// Função para criar um novo funcionário
Employee *createEmployee(char *name, char *hireDate, float salary) {
  Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
  if (newEmployee != NULL) {
    strcpy(newEmployee->name, name);
    strcpy(newEmployee->hireDate, hireDate);
    newEmployee->salary = salary;
    newEmployee->next = NULL;
  }
  return newEmployee;
}

// Função para inserir um funcionário na tabela hash
void insertEmployee(Employee **hashTable, char *name, char *hireDate,
                    float salary) {
  int index = hashFunction(name);
  Employee *newEmployee = createEmployee(name, hireDate, salary);

  if (hashTable[index] == NULL) {
    hashTable[index] = newEmployee;
  } else {
    // Inserção ordenada na lista encadeada
    Employee *current = hashTable[index];
    Employee *prev = NULL;

    while (current != NULL && strcmp(name, current->name) > 0) {
      prev = current;
      current = current->next;
    }

    if (prev == NULL) {
      newEmployee->next = hashTable[index];
      hashTable[index] = newEmployee;
    } else {
      prev->next = newEmployee;
      newEmployee->next = current;
    }
  }
}

// Função para pesquisar funcionário por nome
Employee *searchByName(Employee **hashTable, char *name) {
  int index = hashFunction(name);
  Employee *current = hashTable[index];

  while (current != NULL && strcmp(name, current->name) != 0) {
    current = current->next;
  }

  return current;
}

// Função para pesquisar funcionários por data de admissão
void searchByDate(Employee **hashTable, char *hireDate) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Employee *current = hashTable[i];
    while (current != NULL) {
      if (strcmp(hireDate, current->hireDate) == 0) {
        printf("Nome: %s, Data de Admissao: %s, Salario: %.2f\n", current->name,
               current->hireDate, current->salary);
      }
      current = current->next;
    }
  }
}

// Função para excluir funcionário
void deleteEmployee(Employee **hashTable, char *name) {
  int index = hashFunction(name);
  Employee *current = hashTable[index];
  Employee *prev = NULL;

  while (current != NULL && strcmp(name, current->name) != 0) {
    prev = current;
    current = current->next;
  }

  if (current != NULL) {
    if (prev == NULL) {
      hashTable[index] = current->next;
    } else {
      prev->next = current->next;
    }

    free(current);
  } else {
    printf("Funcionario nao encontrado.\n");
  }
}

// Função para imprimir a tabela hash
void printHashTable(Employee **hashTable) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Employee *current = hashTable[i];
    while (current != NULL) {
      printf("Nome: %s, Data de Admissao: %s, Salario: %.2f\n", current->name,
             current->hireDate, current->salary);
      current = current->next;
    }
  }
}

// Função para calcular o índice na tabela hash
int hashFunction(char *name) {
  int hash = 0;
  for (int i = 0; name[i] != '\0'; i++) {
    hash += name[i];
  }
  return hash % TABLE_SIZE;
}

// Função para salvar a tabela hash em um arquivo binário
void saveToFile(Employee **hashTable) {
  FILE *file = fopen("employee_data.bin", "wb");
  if (file != NULL) {
    fwrite(hashTable, sizeof(Employee *), TABLE_SIZE, file);

    for (int i = 0; i < TABLE_SIZE; i++) {
      Employee *current = hashTable[i];
      while (current != NULL) {
        fwrite(current, sizeof(Employee), 1, file);
        current = current->next;
      }
    }

    fclose(file);
  }
}

// Função para carregar a tabela hash de um arquivo binário
void loadFromFile(Employee **hashTable) {
  FILE *file = fopen("employee_data.bin", "rb");
  if (file != NULL) {
    for (int i = 0; i < TABLE_SIZE; i++) {
      hashTable[i] = NULL; // Inicializa cada entrada da tabela como NULL
      Employee *prev = NULL;

      while (1) {
        Employee *current = (Employee *)malloc(sizeof(Employee));
        if (fread(current, sizeof(Employee), 1, file) != 1) {
          free(current);
          break;
        }

        current->next = NULL;

        if (prev == NULL) {
          hashTable[i] = current;
        } else {
          prev->next = current;
        }

        prev = current;
      }
    }

    fclose(file);
  }
}

// Função principal
int main() {
  Employee *hashTable[TABLE_SIZE] = {NULL};

  // Carrega dados do arquivo se existir
  loadFromFile(hashTable);

  int choice;
  char name[50], hireDate[11];
  float salary;

  do {
    printf("\n1. Cadastrar Funcionario\n");
    printf("2. Pesquisar Funcionario por Nome\n");
    printf("3. Pesquisar Funcionario por Data de Admissao\n");
    printf("4. Excluir Funcionario\n");
    printf("5. Mostrar Tabela Hash\n");
    printf("6. Salvar e Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Nome: ");
      scanf("%s", name);
      printf("Data de Admissao (dd/mm/aaaa): ");
      scanf("%s", hireDate);
      printf("Salario: ");
      scanf("%f", &salary);
      insertEmployee(hashTable, name, hireDate, salary);
      break;

    case 2:
      printf("Nome: ");
      scanf("%s", name);
      Employee *result = searchByName(hashTable, name);
      if (result != NULL) {
        printf("Funcionario encontrado - Nome: %s, Data de Admissao: %s, "
               "Salario: %.2f\n",
               result->name, result->hireDate, result->salary);
      } else {
        printf("Funcionario nao encontrado.\n");
      }
      break;

    case 3:
      printf("Data de Admissao (dd/mm/aaaa): ");
      scanf("%s", hireDate);
      searchByDate(hashTable, hireDate);
      break;

    case 4:
      printf("Nome: ");
      scanf("%s", name);
      deleteEmployee(hashTable, name);
      break;

    case 5:
      printHashTable(hashTable);
      break;

    case 6:
      saveToFile(hashTable);
      break;

    default:
      printf("Opcao invalida. Tente novamente.\n");
    }
  } while (choice != 6);

  return 0;
}
