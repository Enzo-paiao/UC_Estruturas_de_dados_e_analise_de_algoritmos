#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ImprimirMenu() {
  printf("\nEscolha uma opção:\n");
  printf("1. Empilhar números \n");
  printf("2. Empilhar livros \n");
  printf("3. Ler acervo de livros de arquivo \n");
  printf("0. Sair\n");
  printf("Opção: ");
}

int main() {
  int opcao;
  pilha numeros;      // Para exercício 1
  pilha_livro acervo; // Para exercício 2

  FILE *arquivo; // Declarar arquivo fora do switch

  pt_nodo_livro atual = NULL; // Declarar a variável atual aqui

  do {
    ImprimirMenu();
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: // Exercício 1: Empilhar números
      CriarPilha(&numeros);
      int num;
      do {
        printf("\nInforme um número inteiro (ou 0 para encerrar): ");
        scanf("%d", &num);
        if (num != 0) {
          int *numPtr = (int *)malloc(sizeof(int));
          *numPtr = num;
          Empilhar(&numeros, numPtr);
        }
      } while (num != 0);

      printf("\nNúmeros na pilha: ");
      while (!PilhaVazia(&numeros)) {
        int *numPtr = (int *)Desempilhar(&numeros);
        printf("%d ", *numPtr);
        free(numPtr);
      }
      printf("\n");
      break;

    case 2: // Exercício 2: Empilhar livros
      CriarPilhaLivro(&acervo);
      Livro *novoLivro;
      char continuar[4];
      atual = acervo; // Inicialize atual como o topo da pilha

      do {
        novoLivro = (Livro *)malloc(sizeof(Livro));
        printf("\nInforme o título do livro (ou 'sair' para encerrar): ");
        scanf("%s", novoLivro->titulo);
        if (strcmp(novoLivro->titulo, "sair") == 0) {
          free(novoLivro);
          break;
        }
        printf("Informe o autor do livro: ");
        scanf("%s", novoLivro->autor);
        printf("Informe a edição do livro: ");
        scanf("%d", &novoLivro->edicao);

        // Empilhe o novo livro e atualize o nodo anterior
        EmpilharLivro(&acervo, novoLivro);
        if (atual != NULL) {
          atual->ant = acervo;
;
        }
        atual = acervo;
      } while (1);
      EscreverPilhaLivroEmArquivo(&acervo, "acervo.bin");

      printf("Acervo de livros empilhado.\n");
      break;

    case 3: // Exercício 2: Ler acervo de livros de arquivo
      arquivo = fopen("acervo.bin", "rb");
      if (arquivo == NULL) {
        printf("O arquivo 'acervo.bin' não existe ou não pode ser aberto para "
               "leitura.\n");
        break;
      }

      Livro livro;
      while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
        strcpy(novoLivro->titulo, livro.titulo);
        strcpy(novoLivro->autor, livro.autor);
        novoLivro->edicao = livro.edicao;
        EmpilharLivro(&acervo, novoLivro);
      }

      fclose(arquivo);
      printf(
          "Acervo de livros foi lido do arquivo 'acervo.bin' e empilhado.\n");

      // Imprimir o conteúdo da pilha na tela
      printf("\nAcervo de livros lido do arquivo:\n");
      atual = acervo;
      while (atual != NULL) {
        Livro *livro = atual->livro;
        printf("Título: %s\nAutor: %s\nEdição: %d\n\n", livro->titulo,
               livro->autor, livro->edicao);
        atual = atual->prox;
      }
      break;
    }
  } while (opcao != 0);

  return 0;
}
// Acesso bidirecional: Uma pilha duplamente encadeada permite acessar o
// elemento anterior e o elemento seguinte em relação ao topo da pilha. Isso
// torna mais fácil realizar operações que envolvem elementos adjacentes na
// pilha.

// Inserção e exclusão eficiente: Inserir e excluir elementos em uma pilha
// duplamente encadeada é mais eficiente do que em uma pilha simplesmente
// encadeada, especialmente quando se deseja adicionar ou remover elementos no
// meio da pilha.

// Complexidade de implementação: A implementação de uma pilha duplamente
// encadeada é um pouco mais complexa do que uma pilha simplesmente encadeada
// devido à necessidade de gerenciar dois ponteiros em cada nó.

// Desperdício de espaço: Em alguns casos, a capacidade de acesso bidirecional
// pode ser desnecessária, resultando em um desperdício de espaço e complexidade
// em situações em que um acesso unidirecional seria suficiente.