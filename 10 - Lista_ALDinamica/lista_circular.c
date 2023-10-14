#include "lista_circular.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para comparar dois nomes de alunos
int CompararNomesCircular(const char *nome1, const char *nome2) {
  return strcmp(nome1, nome2);
}

// Função para comparar códigos de alunos
int CompararCodigosCircular(int codigo1, int codigo2) {
  if (codigo1 < codigo2) {
    return -1;
  } else if (codigo1 > codigo2) {
    return 1;
  } else {
    return 0;
  }
}

// Função para inserir um aluno na lista encadeada circular
AlunoCircular *InserirAlunoCircular(AlunoCircular *lista_circular, int codigo,
                                    const char *nome) {
  AlunoCircular *novoAluno = (AlunoCircular *)malloc(sizeof(AlunoCircular));
  novoAluno->codigo_circular = codigo;
  strcpy(novoAluno->nome_circular, nome);

  if (lista_circular == NULL) {
    novoAluno->proximo_circular = novoAluno;
    lista_circular = novoAluno;
  } else {
    AlunoCircular *primeiroAluno = lista_circular;
    while (lista_circular->proximo_circular != primeiroAluno) {
      lista_circular = lista_circular->proximo_circular;
    }
    lista_circular->proximo_circular = novoAluno;
    novoAluno->proximo_circular = primeiroAluno;
  }

  return novoAluno;
}

// Função para listar todos os alunos
void ListarAlunosCircular(AlunoCircular *lista_circular) {
  if (lista_circular == NULL) {
    printf("Lista de alunos circular vazia.\n");
    return;
  }

  AlunoCircular *primeiroAluno = lista_circular;
  do {
    printf("Código: %d, Nome: %s\n", lista_circular->codigo_circular,
           lista_circular->nome_circular);
    lista_circular = lista_circular->proximo_circular;
  } while (lista_circular != primeiroAluno);
}

// Função para pesquisar um aluno na lista por nome
AlunoCircular *PesquisarListaPorNomeCircular(AlunoCircular *lista_circular,
                                             const char *nome) {
  if (lista_circular == NULL) {
    return NULL;
  }

  AlunoCircular *primeiroAluno = lista_circular;
  do {
    if (CompararNomesCircular(nome, lista_circular->nome_circular) == 0) {
      return lista_circular;
    }
    lista_circular = lista_circular->proximo_circular;
  } while (lista_circular != primeiroAluno);

  return NULL; // Retorna NULL se o aluno não for encontrado
}

// Função para pesquisar um aluno na lista por código
AlunoCircular *PesquisarListaPorCodigoCircular(AlunoCircular *lista_circular,
                                               int codigo) {
  if (lista_circular == NULL) {
    return NULL;
  }

  AlunoCircular *primeiroAluno = lista_circular;
  do {
    if (codigo == lista_circular->codigo_circular) {
      return lista_circular;
    }
    lista_circular = lista_circular->proximo_circular;
  } while (lista_circular != primeiroAluno);

  return NULL; // Retorna NULL se o aluno não for encontrado
}
