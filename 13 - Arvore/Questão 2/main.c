#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Floresta.h"

int main() {
  int escolha;
  char nomeCategoria[20];
  int categoriaEscolhida = 0;
  Registro reg;
  Categoria *categoriaAtual = NULL;

  while (1) {
    printf("\nOperações:\n");
    printf("1 - Inserir categoria\n");
    printf("2 - Escolher categoria\n");
    printf("3 - Inserir registro na categoria\n");
    printf("4 - Pesquisar registro na categoria\n");
    printf("5 - Excluir registro na categoria\n");
    printf("6 - Imprimir categoria em ordem\n");
    printf("7 - Imprimir categoria pré-ordem\n");
    printf("8 - Imprimir categoria pós-ordem\n");
    printf("9 - Imprimir representação visual da árvore\n");
    printf("10 - Sair\n");

    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
      printf("Digite o nome da categoria a ser inserida: ");
      scanf("%s", nomeCategoria);
      InserirCategoria(nomeCategoria);
      printf("Categoria inserida.\n");
    } else if (escolha == 2) {
      printf("Escolha a categoria (0 para a primeira): ");
      scanf("%d", &categoriaEscolhida);

      Categoria *tempCategoria = floresta;
      for (int i = 0; i < categoriaEscolhida; i++) {
        if (tempCategoria == NULL) {
          printf("Categoria não encontrada.\n");
          break;
        }
        tempCategoria = tempCategoria->proxima;
      }

      if (tempCategoria != NULL) {
        categoriaAtual = tempCategoria;
        printf("Categoria escolhida: %s\n", categoriaAtual->nome);
      } else {
        printf("Categoria não encontrada.\n");
      }
    } else if (escolha == 3) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Digite o valor do registro a ser inserido: ");
      scanf("%d", &reg.Chave);
      InserirNaCategoria(reg, categoriaAtual);
      printf("Registro inserido na categoria.\n");
    } else if (escolha == 4) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Digite o valor do registro a ser pesquisado: ");
      scanf("%d", &reg.Chave);
      PesquisarNaCategoria(&reg, categoriaAtual);
      printf("Resultado da pesquisa: %d\n", reg.Chave);
    } else if (escolha == 5) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Digite o valor do registro a ser excluído: ");
      scanf("%d", &reg.Chave);
      ExcluirDaCategoria(reg, categoriaAtual);
      printf("Registro excluído da categoria.\n");
    } else if (escolha == 6) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Categoria em ordem: ");
      EmOrdemCategoria(categoriaAtual);
      printf("\n");
    } else if (escolha == 7) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Categoria pré-ordem: ");
      PreOrdemCategoria(categoriaAtual);
      printf("\n");
    } else if (escolha == 8) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Categoria pós-ordem: ");
      PosOrdemCategoria(categoriaAtual);
      printf("\n");
    } else if (escolha == 9) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Representação visual da árvore:\n");
      ImprimirArvore(categoriaAtual->arvore, 0);
    } else if (escolha == 10) {
      break;
    } else {
      printf("Opção inválida. Tente novamente.\n");
    }
  }

  return 0;
}
