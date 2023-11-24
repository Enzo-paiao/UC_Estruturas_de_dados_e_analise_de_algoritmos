#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

// Definição da estrutura de elemento
typedef struct {
    char *palavra;
    char *sinonimo;
} elemento;

// Definição da estrutura de nodo para a pilha
typedef struct TipoNodo {
    elemento e;
    struct TipoNodo *prox;
} nodo;

// Definição do tipo pilha
typedef nodo *pilha;
typedef nodo *pt_topo;

// Funções relacionadas à pilha
void CriarPilha(pilha *p) {
    *p = NULL;
}

int PilhaVazia(pilha *p) {
    return (*p == NULL);
}

void Empilhar(pt_topo *topo, elemento *x) {
    pt_topo novo = (pt_topo)malloc(sizeof(nodo));
    novo->e = *x;
    novo->prox = *topo;
    *topo = novo;
}

elemento Desempilhar(pt_topo *topo) {
    elemento x;
    pt_topo p;
    p = *topo;
    *topo = (*topo)->prox;
    x = p->e;
    free(p);
    return x;
}

pt_topo* PesquisarPilha(pt_topo *topo, char *x) {
    pt_topo *p;
    p = NULL;

    while (*topo != NULL) {
        if (strcmp((*topo)->e.palavra, x) == 0) {
            p = topo;
            break;
        } else {
            topo = &((*topo)->prox);
        }
    }
    return p;
}

// Estrutura para a tabela hash
typedef struct {
    char *chave;
    pilha p;
} entrada;

// Definição do tipo hash
typedef entrada hash[TAM];

// Funções relacionadas à tabela hash
void CriarHash(hash h) {
    int i;
    for (i = 0; i < TAM; i++) {
        h[i].chave = NULL;
        CriarPilha(&(h[i].p));
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
    int i;
    i = FuncaoHash(chave);
    if (h[i].chave != NULL) {
        free(h[i].chave);
    }
    h[i].chave = (char*)malloc(sizeof(char) * (strlen(chave) + 1));
    strcpy(h[i].chave, chave);
    Empilhar(&(h[i].p), e);
}

pt_topo* PesquisarHash(hash h, char *chave) {
    int i;
    pt_topo *topo;
    i = FuncaoHash(chave);
    topo = &h[i].p;
    return PesquisarPilha(topo, chave);
}

elemento ExcluirHash(pt_topo *topo) {
    return Desempilhar(topo);
}

void LimparHash(hash h) {
    int i;
    pt_topo topo, aux;
    for (i = 0; i < TAM; i++) {
        if (!PilhaVazia(&(h[i].p))) {
            topo = h[i].p;
            while (topo != NULL) {
                aux = topo;
                topo = topo->prox;
                free(aux);
            }
            CriarPilha(&(h[i].p));
        }
        free(h[i].chave);
    }
}

// Funções relacionadas ao programa principal
void CadastrarDicionario(hash h) {
    char op, lixo, termo[256];
    int i = 0, tam;
    elemento e;
    do {
        printf("\n\n\n%d) Informe uma palavra: ", i);
        scanf("%s", termo);
        tam = strlen(termo) + 1;
        e.palavra = (char*)malloc(sizeof(char) * tam);
        strcpy(e.palavra, termo);

        printf("\n%d) Informe o sinonimo da palavra: ", i++);
        scanf("%s", termo);
        tam = strlen(termo) + 1;
        e.sinonimo = (char*)malloc(sizeof(char) * tam);
        strcpy(e.sinonimo, termo);

        InserirHash(h, e.palavra, &e);
        scanf("%c", &lixo);

        printf("\n\nDeseja inserir uma nova palavra (s/n)? ");
        scanf("%c", &op);
    } while (op == 's');
}

void PesquisarDicionario(hash h) {
    char op, lixo, palavra[256];
    pt_topo *topo;
    do {
        printf("\n\n\nInforme uma palavra: ");
        scanf("%s", palavra);
        scanf("%c", &lixo);
        topo = PesquisarHash(h, palavra);
        if (topo != NULL) {
            printf("\nPalavra: %s", (*topo)->e.palavra);
            printf("\nSinonimo: %s", (*topo)->e.sinonimo);
        } else {
            printf("\nPalavra nao encontrada!");
        }
        printf("\n\nDeseja realizar uma nova pesquisa (s/n)? ");
        scanf("%c", &op);
    } while (op == 's');
}

void ExcluirPalavra(hash h) {
    char op, lixo, palavra[256];
    int i = 0;
    elemento e;
    pt_topo *topo;
    do {
        printf("\n\n\n%d) Informe uma palavra: ", i++);
        scanf("%s", palavra);
        scanf("%c", &lixo);
        topo = PesquisarHash(h, palavra);
        if (topo != NULL) {
            e = ExcluirHash(topo);
            printf("\nPalavra: %s", e.palavra);
            printf("\nSinonimo: %s", e.sinonimo);
            printf("\nExclusao realizada com sucesso!");
        } else {
            printf("\nPalavra nao encontrada!");
        }
        printf("\n\nDeseja excluir uma nova palavra (s/n)? ");
        scanf("%c", &op);
    } while (op == 's');
}

int main() {
    hash h;
    CriarHash(h);

    printf("\nC A D A S T R O!\n\n\n");
    CadastrarDicionario(h);

    system("clear || cls");

    printf("\nP E S Q U I S A!\n\n\n");
    PesquisarDicionario(h);

    system("clear || cls");

    printf("\nE X C L U S A O!\n\n\n");
    ExcluirPalavra(h);

    LimparHash(h);

    printf("\n\n");
    system("pause");
    return 0;
}
