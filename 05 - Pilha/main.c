#include "pilhacircular.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pilha3.h"
typedef int elemento;
#define mxTAM 3
#define TAM_P2 10
typedef int elment;
#include "Pilha1.h"
typedef double elemento_P2; // Alterado para números reais
#include "Pilha2.h"

void ImprimirPilha(PilhaCircular *pilha) {
  if (PilhaVazia(pilha)) {
    printf("A pilha está vazia.\n");
    return;
  }

  printf("\nConteúdo da pilha:\n");
  int i = pilha->topo;
  do {
    printf("%c\n", pilha->dados[i]);
    i = (i - 1 + MAX_TAM) % MAX_TAM;
  } while (i != pilha->topo);
}

int main() {
  double num_P2;
  pilha_P2 p_P2;
  CriarPilha_P2(&p_P2);
  int escolha;
  PilhaFuncionarios_p3 pilhaFuncionarios_p3;
  CriarPilhaFuncionarios(&pilhaFuncionarios_p3);


  
  printf("Escolha o programa a ser executado:\n");
  printf("1. Pilha topo - 1\n");
  printf("2. Pilha 10 números\n");
  printf("3. Pilha Funcionarios\n");
  printf("4. Pilha circular\n");
  printf("5. Conversao para binario\n");
  scanf("%d", &escolha);

  if (escolha == 4) {
    PilhaCircular *pilha = CriarPilha();

    if (pilha == NULL) {
      printf("Erro: não foi possível criar a pilha\n");
      return 1;
    }

    printf("Empilhando elementos:\n");
    char elementos[] = "GFEDCBA";
    int numElementos = sizeof(elementos) - 1; // Ignorar o caractere nulo '\0'
    int i;

    for (i = 0; i < numElementos && !PilhaCheia(pilha); i++) {
      if (Empilhar(pilha, elementos[i])) {
        printf("Elemento %c empilhado\n", elementos[i]);
      } else {
        printf("Falha ao empilhar elemento %c\n", elementos[i]);
      }
    }

    ImprimirPilha(pilha);

    printf("\nDesempilhando elementos pelo topo:\n");
    int numElementosDesejados = 2;
    for (i = 0; i < numElementosDesejados && !PilhaVazia(pilha); i++) {
      char elemento = pilha->dados[pilha->topo];
      printf("Elemento desempilhado do topo: %c\n", elemento);
      pilha->topo = (pilha->topo - 1 + MAX_TAM) % MAX_TAM; // Atualiza topo
    }

    ImprimirPilha(pilha);

    free(pilha);

    return 0;
  } else if (escolha == 5) {
    int num, resto;
    PILHAS battery;
    CP(&battery);

    printf("\nInforme um numero inteiro: ");
    scanf("%d", &num);

    while (num != 0) {
      resto = num % 2;

      // Verifica se a PILHAS está cheia
      if (PC(&battery)) {
        printf("A representacao binaria possui mais que 5 bits.\n");
        break;
      }

      Empr(&battery, resto);
      num /= 2;
    }

    printf("\nCorrespondente em binario: ");

    if (PV(&battery)) {
      printf("0"); // Tratamento zero.
    }

    while (PV(&battery) == 0) {
      resto = Dsep(&battery);
      printf("%d", resto);
    }

    printf("\n");
    system("pause");
    return 0;
  } else if (escolha == 1) {
    int num;
    pilha ppp;
    CreatePile(&ppp);

    while (Fullpile(&ppp) == FALSO) {
      printf("\nInforme um numero inteiro: ");
      scanf("%d", &num);
      Mount(&ppp, num);
    }

    printf("\nNumeros informados: ");
    while (EmptyPile(&ppp) == FALSO) {
      num = Unmount(&ppp);
      printf("\n%d", num);
    }
  }else if (escolha == 3) {
    while (!PilhaFuncionariosCheia(&pilhaFuncionarios_p3)) {
        Funcionario_p3 novoFuncionario_p3;

        printf("Informe os dados do novo funcionário:\n");
        printf("CPF: ");
        scanf("%s", novoFuncionario_p3.cpf_p3);
        printf("Nome: ");
        scanf("%s", novoFuncionario_p3.nome_p3);
        printf("Endereço: ");
        scanf("%s", novoFuncionario_p3.endereco_p3);
        printf("Telefone de Contato: ");
        scanf("%s", novoFuncionario_p3.telefone_contato_p3);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf("%s", novoFuncionario_p3.data_nascimento_p3);
        printf("Data de Admissão (dd/mm/aaaa): ");
        scanf("%s", novoFuncionario_p3.data_admissao_p3);
        printf("Departamento: ");
        scanf("%s", novoFuncionario_p3.departamento_p3);
        printf("Cargo: ");
        scanf("%s", novoFuncionario_p3.cargo_p3);
        printf("Salário: ");
        scanf("%lf", &novoFuncionario_p3.salario_p3);

        EmpilharFuncionario(&pilhaFuncionarios_p3, novoFuncionario_p3);
    }

    printf("Funcionários empilhados.\n");

    printf("Deseja gravar os funcionários em um arquivo? (1 para sim, 0 para não): ");
    int gravar;
    scanf("%d", &gravar);

    if (gravar) {
        GravarFuncionariosEmArquivo(&pilhaFuncionarios_p3, "funcionarios.bin");
        printf("Funcionários gravados no arquivo.\n");
    }

    printf("Deseja ler os funcionários do arquivo? (1 para sim, 0 para não): ");
    int ler;
    scanf("%d", &ler);

    if (ler) {
        LerFuncionariosDeArquivo(&pilhaFuncionarios_p3, "funcionarios.bin");
        printf("Funcionários lidos do arquivo.\n");

        printf("Deseja imprimir os funcionários? (1 para sim, 0 para não): ");
        int imprimir;
        scanf("%d", &imprimir);

        if (imprimir) {
            ImprimirFuncionarios(&pilhaFuncionarios_p3);
        }
    }
  } else if (escolha == 2) {
    printf("Informe 10 números reais para empilhar:\n");
    for (int i_P2 = 0; i_P2 < TAM_P2; i_P2++) {
      printf("Informe o número %d: ", i_P2 + 1);
      scanf("%lf", &num_P2);
      Empilhar_P2(&p_P2, num_P2);
    }

    // Desempilha os elementos e grava em um arquivo no modo texto
    FILE *arquivo_P2 = fopen("pilha.txt", "w");
    if (arquivo_P2 == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return 1;
    }

    printf("\nConteúdo da pilha desempilhado e gravado no arquivo:\n");
    while (!PilhaVazia_P2(&p_P2)) {
      num_P2 = Desempilhar_P2(&p_P2);
      printf("%lf\n", num_P2);
      fprintf(arquivo_P2, "%lf\n", num_P2);
    }

    fclose(arquivo_P2);

    // Lê os elementos do arquivo e empilha novamente
    arquivo_P2 = fopen("pilha.txt", "r");
    if (arquivo_P2 == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return 1;
    }

    printf("\nConteúdo da pilha após ler do arquivo e empilhar novamente:\n");
    while (fscanf(arquivo_P2, "%lf", &num_P2) == 1) {
      Empilhar_P2(&p_P2, num_P2);
      printf("%lf\n", num_P2);
    }

    fclose(arquivo_P2);
  }
}
