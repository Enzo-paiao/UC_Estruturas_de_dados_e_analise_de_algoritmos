#include "lista.h"
#include "lista_circular.h"
#include "lista_circular_dupla.h"
#include "lista_duplamente_encadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int opcao;
  Aluno *lista_simples = NULL;
  AlunoCircular *lista_circular = NULL;
  AlunoCircularDupla *lista_circular_dupla = NULL;
  AlunoDuplamenteEncadeada *lista_duplamente_encadeada = NULL;

  while (1) {
    printf("Menu:\n");
    printf("1. Usar Lista Encadeada Simples\n");
    printf("2. Usar Lista Encadeada Circular\n");
    printf("3. Usar Lista Duplamente Encadeada Circular\n");
    printf("4. Usar Lista Duplamente Encadeada\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
      // Usar Lista Encadeada Simples
      while (1) {
        printf("Menu Lista Encadeada Simples:\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Pesquisar Aluno por Nome\n");
        printf("4. Pesquisar Aluno por Código\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
          printf("Informe o código do aluno: ");
          int codigo_simples;
          scanf("%d", &codigo_simples);
          printf("Informe o nome do aluno: ");
          char nome_simples[50];
          scanf(" %49[^\n]", nome_simples);
          lista_simples =
              InserirAluno(lista_simples, codigo_simples, nome_simples);
          break;
        case 2:
          ListarAlunos(lista_simples);
          break;
        case 3:
          printf("Informe o nome do aluno a ser pesquisado: ");
          char nome_pesquisa[50];
          scanf(" %49[^\n]", nome_pesquisa);
          Aluno *alunoPorNome =
              PesquisarListaPorNome(lista_simples, nome_pesquisa);
          if (alunoPorNome != NULL) {
            printf("Aluno encontrado: Código: %d, Nome: %s\n",
                   alunoPorNome->codigo, alunoPorNome->nome);
          } else {
            printf("Aluno não encontrado.\n");
          }
          break;
        case 4:
          printf("Informe o código do aluno a ser pesquisado: ");
          int codigo_pesquisa;
          scanf("%d", &codigo_pesquisa);
          Aluno *alunoPorCodigo =
              PesquisarListaPorCodigo(lista_simples, codigo_pesquisa);
          if (alunoPorCodigo != NULL) {
            printf("Aluno encontrado: Código: %d, Nome: %s\n",
                   alunoPorCodigo->codigo, alunoPorCodigo->nome);
          } else {
            printf("Aluno não encontrado.\n");
          }
          break;
        case 5:
          break; // Voltar ao menu principal

        default:
          printf("Opção inválida!\n");
        }
      }
    } else if (opcao == 2) {
      // Usar Lista Encadeada Circular
      while (1) {
        printf("Menu Lista Encadeada Circular:\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Pesquisar Aluno por Nome\n");
        printf("4. Pesquisar Aluno por Código\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
          printf("Informe o código do aluno: ");
          int codigo_circular;
          scanf("%d", &codigo_circular);
          printf("Informe o nome do aluno: ");
          char nome_circular[50];
          scanf(" %49[^\n]", nome_circular);
          lista_circular = InserirAlunoCircular(lista_circular, codigo_circular,
                                                nome_circular);
          break;
        case 2:
          ListarAlunosCircular(lista_circular);
          break;
        case 3:
          printf("Informe o nome do aluno a ser pesquisado: ");
          char nome_pesquisa_circular[50];
          scanf(" %49[^\n]", nome_pesquisa_circular);
          AlunoCircular *alunoPorNomeCircular = PesquisarListaPorNomeCircular(
              lista_circular, nome_pesquisa_circular);
          if (alunoPorNomeCircular != NULL) {
            printf("Aluno encontrado: Código: %d, Nome: %s\n",
                   alunoPorNomeCircular->codigo_circular,
                   alunoPorNomeCircular->nome_circular);
          } else {
            printf("Aluno não encontrado.\n");
          }
          break;
        case 4:
          printf("Informe o código do aluno a ser pesquisado: ");
          int codigo_pesquisa_circular;
          scanf("%d", &codigo_pesquisa_circular);
          AlunoCircular *alunoPorCodigoCircular =
              PesquisarListaPorCodigoCircular(lista_circular,
                                              codigo_pesquisa_circular);
          if (alunoPorCodigoCircular != NULL) {
            printf("Aluno encontrado: Código: %d, Nome: %s\n",
                   alunoPorCodigoCircular->codigo_circular,
                   alunoPorCodigoCircular->nome_circular);
          } else {
            printf("Aluno não encontrado.\n");
          }
          break;
        case 5:

          break;

        default:
          printf("Opção inválida!\n");
        }
      }
    } else if (opcao == 3) {
      // Usar Lista Duplamente Encadeada Circular
      while (1) {
        printf("Menu Lista Duplamente Encadeada Circular:\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Pesquisar Aluno por Nome\n");
        printf("4. Pesquisar Aluno por Código\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
          printf("Informe o código do aluno: ");
          int codigo_circular_dupla;
          scanf("%d", &codigo_circular_dupla);
          printf("Informe o nome do aluno: ");
          char nome_circular_dupla[50];
          scanf(" %49[^\n]", nome_circular_dupla);
          lista_circular_dupla = InserirAlunoCircularDupla(
              lista_circular_dupla, codigo_circular_dupla, nome_circular_dupla);
          break;
        case 2:
          ListarAlunosCircularDupla(lista_circular_dupla);
          break;
        case 3:
          printf("Informe o nome do aluno a ser pesquisado: ");
          char nome_pesquisa_circular_dupla[50];
          scanf(" %49[^\n]", nome_pesquisa_circular_dupla);
          AlunoCircularDupla *alunoPorNomeCircularDupla =
              PesquisarListaPorNomeCircularDupla(lista_circular_dupla,
                                                 nome_pesquisa_circular_dupla);
          if (alunoPorNomeCircularDupla != NULL) {
            printf("Aluno encontrado: Código: %d, Nome: %s\n",
                   alunoPorNomeCircularDupla->codigo,
                   alunoPorNomeCircularDupla->nome);
          } else {
            printf("Aluno não encontrado.\n");
          }
          break;
        case 4:
          printf("Informe o código do aluno a ser pesquisado: ");
          int codigo_pesquisa_circular_dupla;
          scanf("%d", &codigo_pesquisa_circular_dupla);
          AlunoCircularDupla *alunoPorCodigoCircularDupla =
              PesquisarListaPorCodigoCircularDupla(
                  lista_circular_dupla, codigo_pesquisa_circular_dupla);
          if (alunoPorCodigoCircularDupla != NULL) {
            printf("Aluno encontrado: Código: %d, Nome: %s\n",
                   alunoPorCodigoCircularDupla->codigo,
                   alunoPorCodigoCircularDupla->nome);
          } else {
            printf("Aluno não encontrado.\n");
          }
          break;
        case 5:
          break; // Voltar ao menu principal
        default:
          printf("Opção inválida!\n");
        }
      }

    } else if (opcao == 4) {
      // Usar Lista Duplamente Encadeada
      while (1) {
        printf("Menu Lista Duplamente Encadeada:\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Pesquisar Aluno por Nome\n");
        printf("4. Pesquisar Aluno por Código\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
          printf("Informe o código do aluno: ");
          int codigo_duplamente_encadeada;
          scanf("%d", &codigo_duplamente_encadeada);
          printf("Informe o nome do aluno: ");
          char nome_duplamente_encadeada[50];
          scanf(" %49[^\n]", nome_duplamente_encadeada);
          lista_duplamente_encadeada = InserirAlunoDuplamenteEncadeada(
              lista_duplamente_encadeada, codigo_duplamente_encadeada,
              nome_duplamente_encadeada);
          break;
        case 2:
          ListarAlunosDuplamenteEncadeada(lista_duplamente_encadeada);
          break;
        case 3:
          printf("Informe o nome do aluno a ser pesquisado: ");
          char nome_pesquisa_duplamente_encadeada[50];
          scanf(" %49[^\n]", nome_pesquisa_duplamente_encadeada);
          AlunoDuplamenteEncadeada *alunoPorNomeDuplamenteEncadeada =
              PesquisarListaPorNomeDuplamenteEncadeada(
                  lista_duplamente_encadeada,
                  nome_pesquisa_duplamente_encadeada);
          if (alunoPorNomeDuplamenteEncadeada != NULL) {
            printf("Aluno encontrado: Código: %d, Nome: %s\n",
                   alunoPorNomeDuplamenteEncadeada->codigo,
                   alunoPorNomeDuplamenteEncadeada->nome);
          } else {
            printf("Aluno não encontrado.\n");
          }
          break;
        case 4:
          printf("Informe o código do aluno a ser pesquisado: ");
          int codigo_pesquisa_duplamente_encadeada;
          scanf("%d", &codigo_pesquisa_duplamente_encadeada);
          AlunoDuplamenteEncadeada *alunoPorCodigoDuplamenteEncadeada =
              PesquisarListaPorCodigoDuplamenteEncadeada(
                  lista_duplamente_encadeada,
                  codigo_pesquisa_duplamente_encadeada);
          if (alunoPorCodigoDuplamenteEncadeada != NULL) {
            printf("Aluno encontrado: Código: %d, Nome: %s\n",
                   alunoPorCodigoDuplamenteEncadeada->codigo,
                   alunoPorCodigoDuplamenteEncadeada->nome);
          } else {
            printf("Aluno não encontrado.\n");
          }
          break;
        case 5:
          break; // Voltar ao menu principal
        default:
          printf("Opção inválida!\n");
        }
      }
    } else if (opcao == 5) {
      break; // Sair do programa
    } else {
      printf("Opção inválida!\n");
    }
  }
  AlunoCircularDupla *primeiroAlunoCircularDupla = lista_circular_dupla;
  if (lista_circular_dupla != NULL) {
    do {
      AlunoCircularDupla *proximo = lista_circular_dupla->proximo;
      free(lista_circular_dupla);
      lista_circular_dupla = proximo;
    } while (lista_circular_dupla != primeiroAlunoCircularDupla);
  }
  while (lista_duplamente_encadeada != NULL) {
    AlunoDuplamenteEncadeada *proximo = lista_duplamente_encadeada->proximo;
    free(lista_duplamente_encadeada);
    lista_duplamente_encadeada = proximo;
  }
  return 0;
}
