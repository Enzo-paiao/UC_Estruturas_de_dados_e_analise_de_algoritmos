#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define TAM 3

typedef struct palavra_sinonimo elemento;

void CadastrarDicionario(hash h);
void PesquisarDicionario(hash h);
void ExcluirPalavra(hash h);

int main() {
    hash h;
    CriarHash(h);
    printf("\nC A D A S T R O!\n\n\n");
    CadastrarDicionario(h);
    system("clear||cls");
    printf("\nP E S Q U I S A!\n\n\n");
    PesquisarDicionario(h);
    system("clear||cls");
    printf("\nE X C L U S A O!\n\n\n");
    ExcluirPalavra(h);
    LimparHash(h);
    printf("\n\n");
    return 0;
}

void CadastrarDicionario(hash h) {
    char op, lixo, termo[256];
    int i = 0, tam;
    elemento e;
    do {
        printf("\n\n\n%d) Informe uma palavra: ", i);
        scanf("%s", termo);
        tam = strlen(termo) + 1;
        e.palavra = (char *)malloc(sizeof(char) * tam);
        strcpy(e.palavra, termo);
        printf("\n%d) Informe o sinonimo da palavra: ", i++);
        scanf("%s", termo);
        tam = strlen(termo) + 1;
        e.sinonimo = (char *)malloc(sizeof(char) * tam);
        strcpy(e.sinonimo, termo);
        InserirHash(h, e.palavra, &e);
        scanf("%c", &lixo);
        printf("\n\nDeseja inserir uma nova palavra (s/n)? ");
        scanf(" %c", &op);
    } while (op == 's');
}

void PesquisarDicionario(hash h) {
    char op, lixo, palavra[256];
    pt_nodo *pt;
    do {
        printf("\n\n\nInforme uma palavra: ");
        scanf("%s", palavra);
        scanf("%c", &lixo);
        pt = PesquisarHash(h, palavra);
        if (pt) {
            printf("\nPalavra: %s", (*pt)->e.palavra);
            printf("\nSinonimo: %s", (*pt)->e.sinonimo);
        } else
            printf("\nPalavra nao encontrada!");
        printf("\n\nDeseja realizar uma nova pesquisa (s/n)? ");
        scanf(" %c", &op);
    } while (op == 's');
}

void ExcluirPalavra(hash h) {
    char op, lixo, palavra[256];
    int i = 0;
    elemento e;
    pt_nodo *pt;
    do {
        printf("\n\n\n%d) Informe uma palavra: ", i++);
        scanf("%s", palavra);
        scanf("%c", &lixo);
        pt = PesquisarHash(h, palavra);
        if (pt) {
            e = ExcluirHash(pt);
            printf("\nPalavra: %s", e.palavra);
            printf("\nSinonimo: %s", e.sinonimo);
            printf("\nExclusao realizada com sucesso!");
        } else
            printf("\nPalavra nao encontrada!");
        printf("\n\nDeseja excluir uma nova palavra (s/n)? ");
        scanf(" %c", &op);
    } while (op == 's');
}
