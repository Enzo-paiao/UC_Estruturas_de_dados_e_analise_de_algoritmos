#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para comparar dois nomes de alunos
int CompararNomes(const char* nome1, const char* nome2) {
    return strcmp(nome1, nome2);
}

// Função para comparar códigos de alunos
int CompararCodigos(int codigo1, int codigo2) {
    if (codigo1 < codigo2) {
        return -1;
    } else if (codigo1 > codigo2) {
        return 1;
    } else {
        return 0;
    }
}

// Função para inserir um aluno na lista encadeada simples
Aluno* InserirAluno(Aluno* lista, int codigo, const char* nome) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    novoAluno->codigo = codigo;
    strcpy(novoAluno->nome, nome);
    novoAluno->proximo = lista;
    return novoAluno;
}

// Função para listar todos os alunos
void ListarAlunos(Aluno* lista) {
    if (lista == NULL) {
        printf("Lista de alunos vazia.\n");
        return;
    }

    while (lista != NULL) {
        printf("Código: %d, Nome: %s\n", lista->codigo, lista->nome);
        lista = lista->proximo;
    }
}

// Função para pesquisar um aluno na lista por nome
Aluno* PesquisarListaPorNome(Aluno* lista, const char* nome) {
    while (lista != NULL) {
        if (CompararNomes(nome, lista->nome) == 0) {
            return lista;
        }
        lista = lista->proximo;
    }
    return NULL; // Retorna NULL se o aluno não for encontrado
}

// Função para pesquisar um aluno na lista por código
Aluno* PesquisarListaPorCodigo(Aluno* lista, int codigo) {
    while (lista != NULL) {
        if (CompararCodigos(codigo, lista->codigo) == 0) {
            return lista;
        }
        lista = lista->proximo;
    }
    return NULL; // Retorna NULL se o aluno não for encontrado
}
