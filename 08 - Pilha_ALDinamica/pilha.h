#define VERDADEIRO 1
#define FALSO 0
#include <stdio.h>
#include <stdlib.h>

typedef int elemento;

// Estrutura para representar um livro
typedef struct {
  char titulo[100];
  char autor[100];
  int edicao;
} Livro;

// Estrutura de um nodo para a pilha de livros
typedef struct livro_nodo *pilha_livro;
typedef struct livro_nodo *pt_nodo_livro;

// Anteriormente definido como "ant"
typedef struct livro_nodo {
  Livro *livro;
  pt_nodo_livro prox;
  pt_nodo_livro ant; // Ponteiro para o nodo antecessor
} tnodo_livro;

// Estrutura de um nodo para a pilha genérica
typedef struct nodo *pilha;
typedef struct nodo *pt_nodo;

typedef struct nodo {
  void *e;
  pt_nodo prox;
  pt_nodo ant; // Ponteiro para o nodo antecessor
} tnodo;

/*
 * Cria uma pilha vazia.
 */
void CriarPilha(pilha *topo) { *topo = NULL; }

/*
 * Cria uma pilha de livros vazia.
 */
void CriarPilhaLivro(pilha_livro *topo) { *topo = NULL; }

/*
 * Verifica se a pilha está vazia.
 */
int PilhaVazia(pilha *topo) { return (*topo == NULL); }

/*
 * Verifica se a pilha de livros está vazia.
 */
int PilhaLivroVazia(pilha_livro *topo) { return (*topo == NULL); }

/*
 * Insere um elemento genérico na pilha.
 */
void Empilhar(pilha *topo, void *elemento) {
  pt_nodo aux;
  aux = (pt_nodo)malloc(sizeof(tnodo));
  aux->e = elemento;
  aux->prox = *topo;
  aux->ant = NULL; // O nodo antecessor do topo é nulo
  if (*topo != NULL) {
    (*topo)->ant = aux; // Atualiza o ponteiro antecessor do nodo antigo do topo
  }
  *topo = aux;
}

/*
 * Insere um livro na pilha de livros.
 */
void EmpilharLivro(pilha_livro *topo, Livro *livro) {
  pt_nodo_livro aux;
  aux = (pt_nodo_livro)malloc(sizeof(tnodo_livro));
  aux->livro = livro;
  aux->prox = *topo;
  aux->ant = NULL; // O nodo antecessor do topo é nulo
  if (*topo != NULL) {
    (*topo)->ant = aux; // Atualiza o ponteiro antecessor do nodo antigo do topo
  }
  *topo = aux;
}

/*
 * Retira um elemento genérico da pilha.
 */
void *Desempilhar(pilha *topo) {
  void *elemento;
  pt_nodo aux;
  aux = *topo;
  *topo = (*topo)->prox;
  if (*topo != NULL) {
    (*topo)->ant =
        NULL; // Atualiza o ponteiro antecessor do novo topo para nulo
  }
  elemento = aux->e;
  free(aux);
  return elemento;
}

Livro *DesempilharLivro(pilha_livro *topo) {
  Livro *livro;
  pt_nodo_livro aux;
  aux = *topo;
  *topo = (*topo)->prox;
  if (*topo != NULL) {
    (*topo)->ant =
        NULL; // Atualiza o ponteiro antecessor do novo topo para nulo
  }
  livro = aux->livro;
  free(aux);
  return livro;
}

void EscreverPilhaLivroEmArquivo(pilha_livro *topo, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return;
  }

  pt_nodo_livro atual = *topo;
  while (atual != NULL) {
    Livro *livro = atual->livro; // Obtenha o livro do nodo atual
    fwrite(livro, sizeof(Livro), 1, arquivo);
    atual = atual->prox; // Avance para o próximo nodo
  }

  fclose(arquivo); // Feche o arquivo após a escrita.
}

void LerPilhaLivroDeArquivo(pilha_livro *topo, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "rb");
  if (arquivo == NULL) {
    printf("O arquivo não existe. Criando um novo arquivo...\n");
    return; // Arquivo não existe, apenas retorna
  }

  Livro livro;
  while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
    Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
    strcpy(novoLivro->titulo, livro.titulo);
    strcpy(novoLivro->autor, livro.autor);
    novoLivro->edicao = livro.edicao;
    EmpilharLivro(topo, novoLivro);
  }

  fclose(arquivo); // Feche o arquivo após a leitura.
}

int PilhaVaziaLivro(pilha_livro topo) { return (topo == NULL); }
