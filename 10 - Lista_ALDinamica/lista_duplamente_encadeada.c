#include "lista_duplamente_encadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementações das funções da biblioteca lista_duplamente_encadeada.h
// (InserirAlunoDuplamenteEncadeada, ListarAlunosDuplamenteEncadeada, PesquisarListaPorNomeDuplamenteEncadeada, PesquisarListaPorCodigoDuplamenteEncadeada, CompararNomesDuplamenteEncadeada, CompararCodigosDuplamenteEncadeada, etc.)

// Função para comparar dois nomes de alunos
int CompararNomesDuplamenteEncadeada(const char* nome1, const char* nome2) {
    return strcmp(nome1, nome2);
}

// Função para comparar códigos de alunos
int CompararCodigosDuplamenteEncadeada(int codigo1, int codigo2) {
    if (codigo1 < codigo2) {
        return -1;
    } else if (codigo1 > codigo2) {
        return 1;
    } else {
        return 0;
    }
}

// Função para inserir um aluno na lista duplamente encadeada
AlunoDuplamenteEncadeada* InserirAlunoDuplamenteEncadeada(AlunoDuplamenteEncadeada* lista, int codigo, const char* nome) {
    AlunoDuplamenteEncadeada* novoAluno = (AlunoDuplamenteEncadeada*)malloc(sizeof(AlunoDuplamenteEncadeada));
    novoAluno->codigo = codigo;
    strcpy(novoAluno->nome, nome);

    novoAluno->proximo = lista;
    novoAluno->anterior = NULL;

    if (lista != NULL) {
        lista->anterior = novoAluno;
    }

    return novoAluno;
}

// Função para listar todos os alunos
void ListarAlunosDuplamenteEncadeada(AlunoDuplamenteEncadeada* lista) {
    if (lista == NULL) {
        printf("Lista de alunos duplamente encadeada vazia.\n");
        return;
    }

    while (lista != NULL) {
        printf("Código: %d, Nome: %s\n", lista->codigo, lista->nome);
        lista = lista->proximo;
    }
}

// Função para pesquisar um aluno na lista por nome
AlunoDuplamenteEncadeada* PesquisarListaPorNomeDuplamenteEncadeada(AlunoDuplamenteEncadeada* lista, const char* nome) {
    while (lista != NULL) {
        if (CompararNomesDuplamenteEncadeada(nome, lista->nome) == 0) {
            return lista;
        }
        lista = lista->proximo;
    }
    return NULL; // Retorna NULL se o aluno não for encontrado
}

// Função para pesquisar um aluno na lista por código
AlunoDuplamenteEncadeada* PesquisarListaPorCodigoDuplamenteEncadeada(AlunoDuplamenteEncadeada* lista, int codigo) {
    while (lista != NULL) {
        if (CompararCodigosDuplamenteEncadeada(codigo, lista->codigo) == 0) {
            return lista;
        }
        lista = lista->proximo;
    }
    return NULL; // Retorna NULL se o aluno não for encontrado
}
