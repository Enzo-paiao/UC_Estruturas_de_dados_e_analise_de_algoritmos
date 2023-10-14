#ifndef LISTA_CIRCULAR_DUPLA_H
#define LISTA_CIRCULAR_DUPLA_H

// Definição da estrutura AlunoCircularDupla
typedef struct AlunoCircularDupla {
  int codigo;
  char nome[50];
  struct AlunoCircularDupla *proximo;
  struct AlunoCircularDupla *anterior;
} AlunoCircularDupla;

// Função para comparar dois nomes de alunos
int CompararNomesCircularDupla(const char *nome1, const char *nome2);

// Função para comparar códigos de alunos
int CompararCodigosCircularDupla(int codigo1, int codigo2);

// Função para inserir um aluno na lista duplamente encadeada circular
AlunoCircularDupla *InserirAlunoCircularDupla(AlunoCircularDupla *lista,
                                              int codigo, const char *nome);

// Função para listar todos os alunos
void ListarAlunosCircularDupla(AlunoCircularDupla *lista);

// Função para pesquisar um aluno na lista por nome
AlunoCircularDupla *
PesquisarListaPorNomeCircularDupla(AlunoCircularDupla *lista, const char *nome);

// Função para pesquisar um aluno na lista por código
AlunoCircularDupla *
PesquisarListaPorCodigoCircularDupla(AlunoCircularDupla *lista, int codigo);

#endif
