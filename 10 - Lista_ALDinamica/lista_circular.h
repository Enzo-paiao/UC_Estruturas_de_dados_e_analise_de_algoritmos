#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

// Definição da estrutura AlunoCircular
typedef struct AlunoCircular {
    int codigo_circular;
    char nome_circular[50];
    struct AlunoCircular* proximo_circular;
} AlunoCircular;

// Função para comparar dois nomes de alunos
int CompararNomesCircular(const char* nome1, const char* nome2);

// Função para comparar códigos de alunos
int CompararCodigosCircular(int codigo1, int codigo2);

// Função para inserir um aluno na lista encadeada circular
AlunoCircular* InserirAlunoCircular(AlunoCircular* lista_circular, int codigo, const char* nome);

// Função para listar todos os alunos
void ListarAlunosCircular(AlunoCircular* lista_circular);

// Função para pesquisar um aluno na lista por nome
AlunoCircular* PesquisarListaPorNomeCircular(AlunoCircular* lista_circular, const char* nome);

// Função para pesquisar um aluno na lista por código
AlunoCircular* PesquisarListaPorCodigoCircular(AlunoCircular* lista_circular, int codigo);

#endif
