#include "fila.h"
#include "filacircular.h"
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float elemento;

int main() {
  int opcao;
  elemento num;
  fila f;
  int option;
  roll ff;
  char cpf[12];
  struct Fila_F4 fila_F4;
  CriarFila_F4(&fila_F4);
  int opcao_F4, valor_F4;

  printf("Escolha a versao do programa:\n");
  printf("1. 3 elementos\n");
  printf("2. 10 elementos\n");
  printf("3. 10 CPF's\n");
  printf("4. Fila Circular\n");
  printf("Digite o numero da opcao desejada: ");
  scanf("%d", &opcao);

  if (opcao == 1) {
    CriarFila(&f);

    printf("Informe 3 numeros reais:\n");
    for (int i = 0; i < 3; i++) {
      scanf("%f", &num);
      Enfileirar(&f, num);
    }

    DesenfileirarEGravar(&f);
    printf(
        "Elementos desenfileirados e gravados no arquivo 'elementos.txt'.\n");

    LerDoArquivoEEnfileirar(&f);
    printf("Elementos lidos do arquivo e enfileirados de volta.\n");

    ImprimeFila(&f);
  } else if (opcao == 2) {
    CriarFila(&f);

    printf("Informe 10 numeros reais:\n");
    for (int i = 0; i < 10; i++) {
      scanf("%f", &num);
      Enfileirar(&f, num);
    }

    DesenfileirarEGravar(&f);
    printf(
        "Elementos desenfileirados e gravados no arquivo 'elementos.txt'.\n");

    LerDoArquivoEEnfileirar(&f);
    printf("Elementos lidos do arquivo e enfileirados de volta.\n");

    ImprimeFila(&f);
  } else if (opcao == 3) {
    CF(&ff);

    printf("Escolha a operacao:\n");
    printf("1. Cadastrar funcionarios\n");
    printf("2. Gravar em arquivo binario\n");
    printf("3. Ler de arquivo binario e listar\n");
    printf("4. Pesquisar por CPF\n");
    printf("0. Sair\n");

    while (1) {
      printf("Digite a option: ");
      scanf("%d", &option);

      switch (option) {
      case 1:
        for (int i = 0; i < 10; i++) {
          struct funcionario func;

          printf("Cadastro de Funcionario %d:\n", i + 1);
          printf("CPF: ");
          scanf("%s", func.cpf);

          getchar();

          printf("Nome: ");
          fflush(stdin);
          fgets(func.nome, sizeof(func.nome), stdin);
          func.nome[strcspn(func.nome, "\n")] = '\0';

          printf("Endereco: ");
          fflush(stdin);
          fgets(func.endereco, sizeof(func.endereco), stdin);
          func.endereco[strcspn(func.endereco, "\n")] = '\0';

          printf("Telefone: ");
          scanf("%s", func.telefone);

          printf("Celular: ");
          scanf("%s", func.celular);

          printf("Data de Nascimento (dd/mm/aaaa): ");
          scanf("%d/%d/%d", &func.nascimento.dia, &func.nascimento.mes,
                &func.nascimento.ano);

          printf("Data de Admissao (dd/mm/aaaa): ");
          scanf("%d/%d/%d", &func.admissao.dia, &func.admissao.mes,
                &func.admissao.ano);

          printf("Departamento: ");
          fflush(stdin);
          fgets(func.departamento, sizeof(func.departamento), stdin);
          func.departamento[strcspn(func.departamento, "\n")] = '\0';

          printf("Cargo: ");
          fflush(stdin);
          fgets(func.cargo, sizeof(func.cargo), stdin);
          func.cargo[strcspn(func.cargo, "\n")] = '\0';

          printf("Salario: ");
          scanf("%f", &func.salario);

          EF(&ff, func);
        }
        break;
      case 2:
        GravarEmArquivoBinario(&ff);
        printf("Funcionarios gravados em arquivo binario.\n");
        break;
      case 3:
        LerDeArquivoBinario(&ff);
        IF(&ff);
        break;
      case 4:
        printf("Digite o CPF a ser pesquisado: ");
        scanf("%s", cpf);
        PesquisarPorCPF(&ff, cpf);
        break;
      case 0:
        exit(0);
      default:
        printf("Opcao invalida.\n");
      }
    }
  } else if (opcao == 4) {
    do {
      printf("\nBem vindos!\n");
      printf("\nMenu da Fila Circular:\n");
      printf("1. Enfileirar\n");
      printf("2. Desenfileirar\n");
      printf("3. Mostrar Lista\n");
      printf("0. Sair\n");
      printf("Escolha uma opção: ");
      scanf("%d", &opcao_F4);

      switch (opcao_F4) {
      case 1:
        if (FilaCheia_F4(&fila_F4)) {
          printf("A fila está cheia. Elementos antigos serão substituídos.\n");
        }

        printf("Digite um valor para enfileirar: ");
        scanf("%d", &valor_F4);
        Enfileirar_F4(&fila_F4, valor_F4);
        break;
      case 2:
        if (Desenfileirar_F4(&fila_F4, &valor_F4)) {
          printf("Elemento desenfileirado: %d\n", valor_F4);
        } else {
          printf("A fila está vazia. Não é possível desenfileirar.\n");
        }
        break;
      case 3:
        MostrarFila_F4(&fila_F4);
        break;
      case 0:
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
      }
    } while (opcao_F4 != 0);
  } else {
    printf("Opcao invalida.\n");
  }

  return 0;
}