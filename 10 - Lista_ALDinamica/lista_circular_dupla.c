#include "lista_circular_dupla.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para comparar dois nomes de alunos
int CompararNomesCircularDupla(const char *nome1, const char *nome2) {
  return strcmp(nome1, nome2);
}

// Função para comparar códigos de alunos
int CompararCodigosCircularDupla(int codigo1, int codigo2) {
  if (codigo1 < codigo2) {
    return -1;
  } else if (codigo1 > codigo2) {
    return 1;
  } else {
    return 0;
  }
}

// Função para inserir um aluno na lista duplamente encadeada circular
AlunoCircularDupla *InserirAlunoCircularDupla(AlunoCircularDupla *lista,
                                              int codigo, const char *nome) {
  AlunoCircularDupla *novoAluno =
      (AlunoCircularDupla *)malloc(sizeof(AlunoCircularDupla));
  novoAluno->codigo = codigo;
  strcpy(novoAluno->nome, nome);

  if (lista == NULL) {
    novoAluno->proximo = novoAluno;
    novoAluno->anterior = novoAluno;
    lista = novoAluno;
  } else {
    novoAluno->proximo = lista;
    novoAluno->anterior = lista->anterior;
    lista->anterior->proximo = novoAluno;
    lista->anterior = novoAluno;
  }

  return novoAluno;
}

// Função para listar todos os alunos
void ListarAlunosCircularDupla(AlunoCircularDupla *lista) {
  if (lista == NULL) {
    printf("Lista de alunos duplamente encadeada circular vazia.\n");
    return;
  }

  AlunoCircularDupla *primeiroAluno = lista;
  do {
    printf("Código: %d, Nome: %s\n", lista->codigo, lista->nome);
    lista = lista->proximo;
  } while (lista != primeiroAluno);
}

// Função para pesquisar um aluno na lista por nome
AlunoCircularDupla *
PesquisarListaPorNomeCircularDupla(AlunoCircularDupla *lista,
                                   const char *nome) {
  if (lista == NULL) {
    return NULL;
  }

  AlunoCircularDupla *primeiroAluno = lista;
  do {
    if (CompararNomesCircularDupla(nome, lista->nome) == 0) {
      return lista;
    }
    lista = lista->proximo;
  } while (lista != primeiroAluno);

  return NULL; // Retorna NULL se o aluno não for encontrado
}

// Função para pesquisar um aluno na lista por código
AlunoCircularDupla *
PesquisarListaPorCodigoCircularDupla(AlunoCircularDupla *lista, int codigo) {
  if (lista == NULL) {
    return NULL;
  }

  AlunoCircularDupla *primeiroAluno = lista;
  do {
    if (codigo == lista->codigo) {
      return lista;
    }
    lista = lista->proximo;
  } while (lista != primeiroAluno);

  return NULL; // Retorna NULL se o aluno não for encontrado
}
