#include "lista.h"
#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mxTAM 1

#define TAMANHO_LIST 10

// Estrutura de um nó da lista
struct Node {
  int data;
  struct Node *next;
};

// Função para criar um novo nó
struct Node *criarNo(int valor) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Erro: Memória insuficiente.\n");
    exit(1);
  }
  newNode->data = valor;
  newNode->next = NULL;
  return newNode;
}

// Função para inserir um nó no final da list
void inserirNoNoFinal(struct Node **list, int valor) {
  struct Node *novoNo = criarNo(valor);
  if (*list == NULL) {
    *list = novoNo;
  } else {
    struct Node *current = *list;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = novoNo;
  }
}

// Função para imprimir os elementos da lista
void imprimirLista(struct Node *list) {
  struct Node *current = list;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Função para retirar um nó de uma posição específica da list
int retirarNo(struct Node **list, int posicao) {
  if (*list == NULL) {
    printf("Erro: Lista vazia. Não é possível retirar elementos.\n");
    return -1;
  }

  struct Node *current = *list;
  struct Node *previous = NULL;

  if (posicao == 0) {
    int valor = current->data;
    *list = current->next;
    free(current);
    return valor;
  }

  int contador = 0;
  while (current != NULL && contador < posicao) {
    previous = current;
    current = current->next;
    contador++;
  }

  if (current == NULL) {
    printf("Erro: Posição inválida. Não foi possível retirar o elemento.\n");
    return -1;
  }

  int valor = current->data;
  previous->next = current->next;
  free(current);
  return valor;
}

struct Funcionario {
  char CPF[12];
  char nome[100];
  char endereco[200];
  char telefone[15];
  char celular[15];
  char dataNascimento[11];
  char dataAdmissao[11];
  char departamento[50];
  char cargo[50];
  float salario;
};

typedef struct Funcionario Funcionario;

// Função para ler um funcionário a partir do teclado
void LerFuncionario(Funcionario *f) {
  printf("CPF: ");
  scanf("%s", f->CPF);
  printf("Nome: ");
  scanf("%s", f->nome);
  printf("Endereco: ");
  scanf("%s", f->endereco);
  printf("Telefone: ");
  scanf("%s", f->telefone);
  printf("Celular: ");
  scanf("%s", f->celular);
  printf("Data de Nascimento (dd/mm/aaaa): ");
  scanf("%s", f->dataNascimento);
  printf("Data de Admissao (dd/mm/aaaa): ");
  scanf("%s", f->dataAdmissao);
  printf("Departamento: ");
  scanf("%s", f->departamento);
  printf("Cargo: ");
  scanf("%s", f->cargo);
  printf("Salario: ");
  scanf("%f", &f->salario);
}

// Função para listar um funcionário
void ListarFuncionario(Funcionario f) {
  printf("\nCPF: %s", f.CPF);
  printf("\nNome: %s", f.nome);
  printf("\nEndereco: %s", f.endereco);
  printf("\nTelefone: %s", f.telefone);
  printf("\nCelular: %s", f.celular);
  printf("\nData de Nascimento: %s", f.dataNascimento);
  printf("\nData de Admissao: %s", f.dataAdmissao);
  printf("\nDepartamento: %s", f.departamento);
  printf("\nCargo: %s", f.cargo);
  printf("\nSalario: %.2f", f.salario);
  printf("\n");
}

// Função para gravar os registros em um arquivo binário
void GravarFuncionariosEmArquivo(Funcionario funcionarios[],
                                 int numFuncionarios) {
  FILE *arquivo = fopen("funcionarios.bin", "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return;
  }

  // Escreve o número de funcionários no início do arquivo
  fwrite(&numFuncionarios, sizeof(int), 1, arquivo);

  // Escreve os registros dos funcionários
  fwrite(funcionarios, sizeof(Funcionario), numFuncionarios, arquivo);

  fclose(arquivo);
}

// Função para ler os registros de um arquivo binário
int LerFuncionariosDeArquivo(Funcionario funcionarios[]) {
  FILE *arquivo = fopen("funcionarios.bin", "rb");
  if (arquivo == NULL) {
    printf("Arquivo de funcionarios nao encontrado.\n");
    return 0;
  }

  int numFuncionarios;

  // Lê o número de funcionários do arquivo
  fread(&numFuncionarios, sizeof(int), 1, arquivo);

  // Lê os registros dos funcionários
  fread(funcionarios, sizeof(Funcionario), numFuncionarios, arquivo);

  fclose(arquivo);

  return numFuncionarios;
}

// Função para pesquisar funcionário por CPF
void PesquisarFuncionarioPorCPF(Funcionario funcionarios[], int numFuncionarios,
                                const char *cpf) {
  int encontrado = 0;

  for (int i = 0; i < numFuncionarios; i++) {
    if (strcmp(funcionarios[i].CPF, cpf) == 0) {
      printf("Funcionario encontrado:\n");
      ListarFuncionario(funcionarios[i]);
      encontrado = 1;
      break; // Para a pesquisa após encontrar o primeiro funcionário com o CPF
    }
  }

  if (!encontrado) {
    printf("Funcionario com CPF %s nao encontrado.\n", cpf);
  }
}

int main() {
  struct Node *list = NULL;
  int valor, posicao, opcao;
  lista_2 l_2;
  CriarLista_2(&l_2);
  int choice_2;
  struct Produto_4 produtos_4[MAX_PRODUTOS];
  int numProdutos_4 = 0;
  int escolha_4;

  printf("Escolha uma opcao:\n");
  printf("1. Manipulacao de Lista de Numeros Inteiros\n");
  printf("2. Números Reais.TXT\n");
  printf("3. Cadastro de Funcionarios\n");
  printf("4. Cadastro de Produtos\n");
  printf("5. Cadastro de Números\n");
  printf("0. Sair\n");
  scanf("%d", &opcao);

  if (opcao == 3) {
    Funcionario funcionarios[mxTAM];
    int numFuncionarios = 0;

    // Tenta abrir o arquivo binário para leitura
    FILE *arquivo = fopen("funcionarios.bin", "rb");
    if (arquivo != NULL) {
      // Lê os registros do arquivo
      fread(&numFuncionarios, sizeof(int), 1, arquivo);
      fread(funcionarios, sizeof(Funcionario), numFuncionarios, arquivo);
      fclose(arquivo);
    }

    printf("Cadastro de Funcionarios\n");
    int opcao;

    do {
      printf("\nMenu:\n");
      printf("1. Cadastrar Funcionarios\n");
      printf("2. Listar Funcionarios Cadastrados\n");
      printf("3. Pesquisar Funcionario por CPF\n");
      printf("4. Sair\n");
      printf("Escolha uma opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
        if (numFuncionarios < mxTAM) {
          printf("\nFuncionario %d\n", numFuncionarios + 1);
          LerFuncionario(&funcionarios[numFuncionarios]);
          numFuncionarios++;
        } else {
          printf("\nLimite de funcionarios cadastrados atingido.\n");
        }
        break;
      case 2:
        printf("\nFuncionarios Cadastrados:\n");
        for (int i = 0; i < numFuncionarios; i++) {
          ListarFuncionario(funcionarios[i]);
        }
        break;
      case 3:
        if (numFuncionarios > 0) {
          char cpfPesquisa[12];
          printf("\nDigite o CPF para pesquisa: ");
          scanf("%s", cpfPesquisa);
          PesquisarFuncionarioPorCPF(funcionarios, numFuncionarios,
                                     cpfPesquisa);
        } else {
          printf("\nNenhum funcionario cadastrado para pesquisa.\n");
        }
        break;
      case 4:
        printf("\nSaindo do programa.\n");
        break;
      default:
        printf("\nOpcao invalida. Tente novamente.\n");
        break;
      }

    } while (opcao != 4);

    // Após o programa ser encerrado, salvar novamente no arquivo binário.
    arquivo = fopen("funcionarios.bin", "wb");
    if (arquivo != NULL) {
      fwrite(&numFuncionarios, sizeof(int), 1, arquivo);
      fwrite(funcionarios, sizeof(Funcionario), numFuncionarios, arquivo);
      fclose(arquivo);
    }

    return 0;

  } else if (opcao == 1) {
    int num, pos = 0;
    lista l;
    CriarLista(&l);

    while (!ListaCheia(&l)) {
      printf("\nInforme um numero inteiro: ");
      scanf("%d", &num);
      Alistar(&l, num, pos);
    }

    printf("\nNumeros informados: ");
    while (!ListaVazia(&l)) {
      num = Desalistar(&l, pos);
      printf("%d ", num);
    }
    printf("\n");

    ImprimeLista(&l);
  } else if (opcao == 5) {
    for (int i = 0; i < TAMANHO_LIST; i++) {
      printf("Digite um número inteiro para inserir na lista: ");
      scanf("%d", &valor);
      inserirNoNoFinal(&list, valor);
    }

    printf("Lista inicial: ");
    imprimirLista(list);

    do {
      printf("Digite a posição do elemento a ser retirado (0 a %d, -1 para "
             "encerrar): ",
             TAMANHO_LIST - 1);
      scanf("%d", &posicao);

      if (posicao == -1) {
        break; // Encerra a execução
      }

      int valorRetirado = retirarNo(&list, posicao);

      if (valorRetirado != -1) {
        printf("Elemento retirado: %d\n", valorRetirado);
        imprimirLista(list);
      }

    } while (list != NULL);

    printf("A lista está vazia ou a execução foi encerrada.\n");

    // Libera a memória alocada para os nós da lista
    while (list != NULL) {
      struct Node *temp = list;
      list = list->next;
      free(temp);
    }
  } else if (opcao == 2) {
    while (1) {
      printf("\nMenu Interativo:\n");
      printf("1 - Inserir número real na fila\n");
      printf("2 - Desenfileirar e salvar no arquivo\n");
      printf("3 - Ler do arquivo e enfileirar\n");
      printf("4 - Imprimir conteúdo da lista\n");
      printf("0 - Sair\n");
      printf("Escolha uma opção: ");
      scanf("%d", &choice_2);

      switch (choice_2) {
      case 1:
        if (!ListaCheia_2(&l_2)) {
          float num_2;
          printf("Informe um número real: ");
          scanf("%f", &num_2);
          Enfileirar_2(&l_2, num_2);
        } else {
          printf("ERRO: Fila cheia!\n");
        }
        break;
      case 2:
        if (!ListaVazia_2(&l_2)) {
          SalvarLista_2(
              &l_2, "dados.txt"); // Salve a lista sem o elemento desenfileirado
          elemento_2 desenfileirado_2 =
              printf("Desenfileirando todos os elementos e "
                     "salvando no arquivo 'dados.txt'\n");
          while (!ListaVazia_2(&l_2)) {
            elemento_2 desenfileirado_2 = Desenfileirar_2(&l_2);
            printf("Elemento %.2f desenfileirado\n", desenfileirado_2);
          }
          printf("Elemento %.2f desenfileirado e a lista foi salva no arquivo "
                 "'dados.txt'\n",
                 desenfileirado_2);
        } else {
          printf("ERRO: Fila vazia! Não há elementos para salvar.\n");
        }
        break;
      case 3:
        if (CarregarLista_2(&l_2, "dados.txt")) {
          printf("Elementos lidos do arquivo 'dados.txt' e enfileirados.\n");
        } else {
          printf(
              "ERRO: Não foi possível ler o arquivo 'dados.txt'. Verifique se "
              "ele existe.\n");
        }
        break;
      case 4:
        ImprimirLista_2(&l_2);
        break;
      case 0:
        return 0;
      default:
        printf("Opção inválida!\n");
      }
    }
  }

  else if (opcao == 4) {
    while (1) {
      printf("\nMenu de Produtos:\n");
      printf("1. Cadastrar Produto\n");
      printf("2. Listar Produtos\n");
      printf("3. Pesquisar Produto\n");
      printf("4. Excluir Produto\n");
      printf("5. Salvar Lista de Produtos em um Arquivo (modo binário)\n");
      printf("6. Carregar Lista de Produtos de um Arquivo (modo binário)\n");
      printf("0. Sair\n");
      printf("Escolha uma opção: ");
      scanf("%d", &escolha_4);

      // Limpar o buffer de entrada
      int c_4;
      while ((c_4 = getchar()) != '\n' && c_4 != EOF)
        ;

      switch (escolha_4) {
      case 1:
        if (numProdutos_4 < MAX_PRODUTOS) {
          printf("Digite o nome do produto: ");
          char nome_4[50];
          fgets(nome_4, sizeof(nome_4), stdin);
          nome_4[strcspn(nome_4, "\n")] = '\0'; // Remove a quebra de linha

          printf("Digite o preço unitário: ");
          float precoUnitario_4;
          scanf("%f", &precoUnitario_4);

          if (precoUnitario_4 < 0) {
            printf("Erro: Preço unitário não pode ser negativo.\n");
            break;
          }

          printf("Digite a quantidade em estoque: ");
          int quantidadeEstoque_4;
          scanf("%d", &quantidadeEstoque_4);

          if (quantidadeEstoque_4 < 0) {
            printf("Erro: Quantidade em estoque não pode ser negativa.\n");
            break;
          }

          strcpy(produtos_4[numProdutos_4].nomeProduto_4, nome_4);
          produtos_4[numProdutos_4].precoUnitario_4 = precoUnitario_4;
          produtos_4[numProdutos_4].quantidadeEstoque_4 = quantidadeEstoque_4;
          numProdutos_4++;

          printf("Produto cadastrado com sucesso!\n");
        } else {
          printf("Limite de produtos atingido. Não é possível cadastrar mais "
                 "produtos.\n");
        }
        break;
      case 2:
        listarProdutos_4(produtos_4, numProdutos_4);
        break;
      case 3:
        if (numProdutos_4 > 0) {
          char nomeBusca_4[50];
          printf("Digite o nome do produto a ser pesquisado: ");
          fgets(nomeBusca_4, sizeof(nomeBusca_4), stdin);
          nomeBusca_4[strcspn(nomeBusca_4, "\n")] =
              '\0'; // Remove a quebra de linha
          int indice_4 =
              buscarProduto_4(produtos_4, numProdutos_4, nomeBusca_4);
          if (indice_4 != -1) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\nPreço Unitário: R$%.2f\nEstoque: %d\n",
                   produtos_4[indice_4].nomeProduto_4,
                   produtos_4[indice_4].precoUnitario_4,
                   produtos_4[indice_4].quantidadeEstoque_4);
            int opcao_4;
            printf("Deseja excluir o produto? (1 - Sim, 0 - Não): ");
            scanf("%d", &opcao_4);
            if (opcao_4 == 1) {
              excluirProduto_4(produtos_4, &numProdutos_4, indice_4);
              printf("Produto excluído com sucesso!\n");
            }
          } else {
            printf("Produto não cadastrado!\n");
          }
        } else {
          printf("Nenhum produto cadastrado!\n");
        }
        break;
      case 4:
        if (numProdutos_4 > 0) {
          char nomeExcluir_4[50];
          printf("Digite o nome do produto a ser excluído: ");
          fgets(nomeExcluir_4, sizeof(nomeExcluir_4), stdin);
          nomeExcluir_4[strcspn(nomeExcluir_4, "\n")] =
              '\0'; // Remove a quebra de linha
          int indiceExcluir_4 =
              buscarProduto_4(produtos_4, numProdutos_4, nomeExcluir_4);
          if (indiceExcluir_4 != -1) {
            excluirProduto_4(produtos_4, &numProdutos_4, indiceExcluir_4);
            printf("Produto excluído com sucesso!\n");
          } else {
            printf("Produto não cadastrado!\n");
          }
        } else {
          printf("Nenhum produto cadastrado!\n");
        }
        break;
      case 5:
        if (numProdutos_4 > 0) {
          FILE *arquivo_4 = fopen("produtos.bin", "wb");
          if (arquivo_4) {
            fwrite(produtos_4, sizeof(struct Produto_4), numProdutos_4,
                   arquivo_4);
            fclose(arquivo_4);
            printf("Lista de produtos salva no arquivo 'produtos.bin' em modo "
                   "binário.\n");
          } else {
            printf("Erro ao abrir o arquivo para escrita.\n");
          }
        } else {
          printf("Nenhum produto cadastrado para salvar.\n");
        }
        break;
      case 6: {
        FILE *arquivo_4 = fopen("produtos.bin", "rb");
        if (arquivo_4) {
          fseek(arquivo_4, 0, SEEK_END);
          long tamanho_4 = ftell(arquivo_4);
          if (tamanho_4 % sizeof(struct Produto_4) == 0) {
            rewind(arquivo_4);
            numProdutos_4 = tamanho_4 / sizeof(struct Produto_4);
            fread(produtos_4, sizeof(struct Produto_4), numProdutos_4,
                  arquivo_4);
            fclose(arquivo_4);
            printf("Lista de produtos carregada do arquivo 'produtos.bin' em "
                   "modo binário.\n");
          } else {
            fclose(arquivo_4);
            printf("Erro: Tamanho do arquivo não corresponde aos registros de "
                   "produtos.\n");
          }
        } else {
          printf("Arquivo 'produtos.bin' não encontrado ou erro ao abrir para "
                 "leitura.\n");
        }
      } break;
      case 0:
        return 0;
      default:
        printf("Opção inválida!\n");
      }
    }
  } else {
    printf("Opcao invalida.\n");
  }

  return 0;
}
