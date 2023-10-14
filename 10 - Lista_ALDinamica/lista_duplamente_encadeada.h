#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H

// Definição da estrutura AlunoDuplamenteEncadeada
typedef struct AlunoDuplamenteEncadeada {
    int codigo;
    char nome[50];
    struct AlunoDuplamenteEncadeada* anterior;
    struct AlunoDuplamenteEncadeada* proximo;
} AlunoDuplamenteEncadeada;

// Função para comparar dois nomes de alunos
int CompararNomesDuplamenteEncadeada(const char* nome1, const char* nome2);

// Função para comparar códigos de alunos
int CompararCodigosDuplamenteEncadeada(int codigo1, int codigo2);

// Função para inserir um aluno na lista duplamente encadeada
AlunoDuplamenteEncadeada* InserirAlunoDuplamenteEncadeada(AlunoDuplamenteEncadeada* lista, int codigo, const char* nome);

// Função para listar todos os alunos
void ListarAlunosDuplamenteEncadeada(AlunoDuplamenteEncadeada* lista);

// Função para pesquisar um aluno na lista por nome
AlunoDuplamenteEncadeada* PesquisarListaPorNomeDuplamenteEncadeada(AlunoDuplamenteEncadeada* lista, const char* nome);

// Função para pesquisar um aluno na lista por código
AlunoDuplamenteEncadeada* PesquisarListaPorCodigoDuplamenteEncadeada(AlunoDuplamenteEncadeada* lista, int codigo);

#endif
