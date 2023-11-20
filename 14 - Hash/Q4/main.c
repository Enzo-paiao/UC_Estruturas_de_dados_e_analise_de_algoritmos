#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Employee {
  char name[50];
  char hireDate[11];
  float salary;
  struct Employee *next;
} Employee;

typedef struct HashTable {
  Employee *table[TABLE_SIZE];
} HashTable;

int hashFunction(char *name) {
  int hash = 0;
  while (*name) {
    hash += *name++;
  }
  return hash % TABLE_SIZE;
}

void insertEmployee(HashTable *hashTable, char *name, char *hireDate,
                    float salary) {
  int index = hashFunction(name);

  Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
  strcpy(newEmployee->name, name);
  strcpy(newEmployee->hireDate, hireDate);
  newEmployee->salary = salary;
  newEmployee->next = NULL;

  Employee *current = hashTable->table[index];
  Employee *previous = NULL;

  while (current != NULL && strcmp(name, current->name) > 0) {
    previous = current;
    current = current->next;
  }

  if (previous == NULL) {
    newEmployee->next = hashTable->table[index];
    hashTable->table[index] = newEmployee;
  } else {
    newEmployee->next = current;
    previous->next = newEmployee;
  }
}

Employee *searchByName(HashTable *hashTable, char *name) {
  int index = hashFunction(name);
  Employee *current = hashTable->table[index];

  while (current != NULL) {
    if (strcmp(name, current->name) == 0) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

void searchByDate(HashTable *hashTable, char *hireDate) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    Employee *current = hashTable->table[i];

    while (current != NULL) {
      if (strcmp(hireDate, current->hireDate) == 0) {
        printf("Nome: %s, Data de Admissao: %s, Salario: %.2f\n", current->name,
               current->hireDate, current->salary);
      }
      current = current->next;
    }
  }
}

void deleteEmployee(HashTable *hashTable, char *name) {
  int index = hashFunction(name);
  Employee *current = hashTable->table[index];
  Employee *previous = NULL;

  while (current != NULL && strcmp(name, current->name) != 0) {
    previous = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Funcionario nao encontrado.\n");
    return;
  }

  if (previous == NULL) {
    hashTable->table[index] = current->next;
  } else {
    previous->next = current->next;
  }

  free(current);
  printf("Funcionario excluido com sucesso.\n");
}

void displayHashTable(HashTable *hashTable) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("Entrada %d: ", i);
    Employee *current = hashTable->table[i];
    while (current != NULL) {
      printf("Nome: %s, Data de Admissao: %s, Salario: %.2f -> ", current->name,
             current->hireDate, current->salary);
      current = current->next;
    }
    printf("NULL\n");
  }
}

void saveToFile(HashTable *hashTable) {
  FILE *file = fopen("employee_data.bin", "wb");

  if (file == NULL) {
    perror("Erro ao abrir o arquivo");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < TABLE_SIZE; i++) {
    Employee *current = hashTable->table[i];

    while (current != NULL) {
      fwrite(current, sizeof(Employee), 1, file);
      current = current->next;
    }
  }

  fclose(file);
  printf("Tabela hash salva no arquivo com sucesso.\n");
}

void loadFromFile(HashTable *hashTable) {
  FILE *file = fopen("employee_data.bin", "rb");

  if (file == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  Employee temp;
  while (fread(&temp, sizeof(Employee), 1, file) == 1) {
    insertEmployee(hashTable, temp.name, temp.hireDate, temp.salary);
  }

  fclose(file);
  printf("Tabela hash carregada do arquivo com sucesso.\n");
}

int main() {
  HashTable hashTable;
  memset(&hashTable, 0, sizeof(HashTable));

  loadFromFile(&hashTable);

  int choice;
  char name[50];
  char hireDate[11];
  float salary;

  do {
    printf("\n1. Cadastrar funcionario\n");
    printf("2. Pesquisar por nome\n");
    printf("3. Pesquisar por data de admissao\n");
    printf("4. Excluir funcionario\n");
    printf("5. Exibir tabela hash\n");
    printf("6. Salvar tabela hash em arquivo\n");
    printf("7. Sair\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Digite o nome do funcionario: ");
      scanf("%s", name);
      printf("Digite a data de admissao (dd/mm/aaaa): ");
      scanf("%s", hireDate);
      printf("Digite o salario: ");
      scanf("%f", &salary);
      insertEmployee(&hashTable, name, hireDate, salary);
      break;
    case 2:
      printf("Digite o nome a ser pesquisado: ");
      scanf("%s", name);
      Employee *result = searchByName(&hashTable, name);
      if (result != NULL) {
        printf("Nome: %s, Data de Admissao: %s, Salario: %.2f\n", result->name,
               result->hireDate, result->salary);
      } else {
        printf("Funcionario nao encontrado.\n");
      }
      break;
    case 3:
      printf("Digite a data de admissao a ser pesquisada (dd/mm/aaaa): ");
      scanf("%s", hireDate);
      searchByDate(&hashTable, hireDate);
      break;
    case 4:
      printf("Digite o nome do funcionario a ser excluido: ");
      scanf("%s", name);
      deleteEmployee(&hashTable, name);
      break;
    case 5:
      displayHashTable(&hashTable);
      break;
    case 6:
      saveToFile(&hashTable);
      break;
    case 7:
      saveToFile(&hashTable);
      printf("Programa encerrado.\n");
      break;
    default:
      printf("Opcao invalida.\n");
    }
  } while (choice != 7);

  return 0;
}
