#include "fila.h"

#define TAM 3

typedef struct TipoEntrada {
    char *chave;
    fila f;
} entrada;

typedef entrada hash[TAM];

void CriarHash(hash h);
int FuncaoHash(char *chave);
void InserirHash(hash h, char *chave, elemento *e);
pt_nodo *PesquisarHash(hash h, char *chave);
elemento ExcluirHash(pt_nodo *p);
void LimparHash(hash h);

void CriarHash(hash h) {
    int i;
    for (i = 0; i < TAM; i++) {
        h[i].chave = NULL;
        CriarFila(&(h[i].f));
    }
}

int FuncaoHash(char *chave) {
    int i, soma = 0;
    for (i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return (soma % TAM);
}

void InserirHash(hash h, char *chave, elemento *e) {
    int i, tam_chave;
    i = FuncaoHash(chave);
    tam_chave = strlen(chave) + 1;

    if (h[i].chave != NULL) {
        free(h[i].chave);
    }

    h[i].chave = (char *)malloc(sizeof(char) * tam_chave);
    strcpy(h[i].chave, chave);
    Enfileirar(&(h[i].f), e);
}

pt_nodo *PesquisarHash(hash h, char *chave) {
    int i;
    pt_nodo *pred;
    i = FuncaoHash(chave);
    pred = &(h[i].f);
    return PesquisarFila(pred, chave);
}

elemento ExcluirHash(pt_nodo *p) {
    return Desenfileirar(p);
}

void LimparHash(hash h) {
    int i;
    pt_nodo aux, aux2;

    for (i = 0; i < TAM; i++) {
        if (h[i].chave != NULL) {
            free(h[i].chave);
        }
        aux = h[i].f;

        while (aux != NULL) {
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
    }
}