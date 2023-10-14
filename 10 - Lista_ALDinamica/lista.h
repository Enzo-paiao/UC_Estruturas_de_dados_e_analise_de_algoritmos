#ifndef LISTA_H
#define LISTA_H

// Definição da estrutura Aluno
typedef struct Aluno {
    int codigo;
    char nome[50];
    struct Aluno* proximo;
} Aluno;

// Função para comparar dois nomes de alunos
int CompararNomes(const char* nome1, const char* nome2);

// Função para comparar códigos de alunos
int CompararCodigos(int codigo1, int codigo2);

// Função para inserir um aluno na lista encadeada simples
Aluno* InserirAluno(Aluno* lista, int codigo, const char* nome);

// Função para listar todos os alunos
void ListarAlunos(Aluno* lista);

// Função para pesquisar um aluno na lista por nome
Aluno* PesquisarListaPorNome(Aluno* lista, const char* nome);

// Função para pesquisar um aluno na lista por código
Aluno* PesquisarListaPorCodigo(Aluno* lista, int codigo);

#endif
