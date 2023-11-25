/* Arquivo: main.c
 * Programa para um dicionário de sinônimos.
 */
#include <stdio.h>  // printf (), scanf().
#include <stdlib.h> // system ().
#include <string.h> // strcmp ().

#define TAM 3

typedef struct TipoNodo *arvore;
typedef struct TipoNodo *pt_nodo;
typedef struct TipoNodo {
    char *palavra;
    char *sinonimo;
    pt_nodo esquerda;
    pt_nodo direita;
} nodo;

typedef struct TipoEntrada {
    char *chave;
    arvore a;
} entrada;

typedef entrada hash[TAM];

typedef struct palavra_sinonimo {
    char *palavra;
    char *sinonimo;
} elemento;

void CriarArvore(arvore *a) {
    *a = NULL;
}

void InserirArvore(arvore *a, elemento *e) {
    if (*a == NULL) {
        *a = (pt_nodo)malloc(sizeof(nodo));
        (*a)->palavra = (char *)malloc(strlen(e->palavra) + 1);
        strcpy((*a)->palavra, e->palavra);
        (*a)->sinonimo = (char *)malloc(strlen(e->sinonimo) + 1);
        strcpy((*a)->sinonimo, e->sinonimo);
        (*a)->esquerda = NULL;
        (*a)->direita = NULL;
    } else {
        if (strcmp(e->palavra, (*a)->palavra) < 0)
            InserirArvore(&(*a)->esquerda, e);
        else if (strcmp(e->palavra, (*a)->palavra) > 0)
            InserirArvore(&(*a)->direita, e);
    }
}

pt_nodo *PesquisarArvore(arvore *a, char *x) {
    if (*a == NULL || strcmp(x, (*a)->palavra) == 0) {
        return a;
    } else if (strcmp(x, (*a)->palavra) < 0) {
        return PesquisarArvore(&(*a)->esquerda, x);
    } else {
        return PesquisarArvore(&(*a)->direita, x);
    }
}

void CriarHash(hash h) {
    int i;
    for (i = 0; i < TAM; i++)
        CriarArvore(&(h[i].a));
}

int FuncaoHash(char *chave) {
    int i, soma = 0;
    for (i = 0; chave[i] != '\0'; i++)
        soma += chave[i];
    return (soma % TAM);
}

void InserirHash(hash h, char *chave, elemento *e) {
    int i;
    i = FuncaoHash(chave);
    h[i].chave = (char *)malloc(strlen(chave) + 1);
    strcpy(h[i].chave, chave);
    InserirArvore(&(h[i].a), e);
}

pt_nodo *PesquisarHash(hash h, char *chave) {
    int i;
    pt_nodo *pred;
    i = FuncaoHash(chave);
    pred = &(h[i].a);
    return PesquisarArvore(pred, chave);
}

elemento ExcluirHash(pt_nodo *p) {
    elemento x;

    if (*p == NULL) {
        // Caso o nó não exista, retornar uma estrutura vazia
        x.palavra = NULL;
        x.sinonimo = NULL;
        return x;
    }

    // Copiar os dados do nó que será excluído
    x.palavra = (char *)malloc(strlen((*p)->palavra) + 1);
    strcpy(x.palavra, (*p)->palavra);
    x.sinonimo = (char *)malloc(strlen((*p)->sinonimo) + 1);
    strcpy(x.sinonimo, (*p)->sinonimo);

    pt_nodo temp;

    // Caso 1: Nó folha (sem filhos)
    if ((*p)->esquerda == NULL && (*p)->direita == NULL) {
        free((*p)->palavra);
        free((*p)->sinonimo);
        free(*p);
        *p = NULL;
    }
    // Caso 2: Nó com um filho (esquerda ou direita)
    else if ((*p)->esquerda == NULL) {
        temp = *p;
        *p = (*p)->direita;
        free(temp->palavra);
        free(temp->sinonimo);
        free(temp);
    } else if ((*p)->direita == NULL) {
        temp = *p;
        *p = (*p)->esquerda;
        free(temp->palavra);
        free(temp->sinonimo);
        free(temp);
    }
    // Caso 3: Nó com dois filhos
    else {
        pt_nodo pai = *p;
        pt_nodo substituto = (*p)->esquerda;

        // Encontrar o nó mais à direita na subárvore esquerda
        while (substituto->direita != NULL) {
            pai = substituto;
            substituto = substituto->direita;
        }

        // Substituir os dados do nó pelo nó mais à direita
        free((*p)->palavra);
        free((*p)->sinonimo);
        (*p)->palavra = (char *)malloc(strlen(substituto->palavra) + 1);
        strcpy((*p)->palavra, substituto->palavra);
        (*p)->sinonimo = (char *)malloc(strlen(substituto->sinonimo) + 1);
        strcpy((*p)->sinonimo, substituto->sinonimo);

        // Excluir o nó mais à direita (pode ser um nó folha ou ter um filho à esquerda)
        if (pai != *p) {
            pai->direita = substituto->esquerda;
        } else {
            pai->esquerda = substituto->esquerda;
        }

        free(substituto->palavra);
        free(substituto->sinonimo);
        free(substituto);
    }

    return x;
}


void LimparArvore(arvore *a) {
    if (*a != NULL) {
        LimparArvore(&(*a)->esquerda);
        LimparArvore(&(*a)->direita);
        free((*a)->palavra);
        free((*a)->sinonimo);
        free(*a);
    }
}

void LimparHash(hash h) {
    int i;
    for (i = 0; i < TAM; i++) {
        if (h[i].a != NULL) {
            LimparArvore(&(h[i].a));
            free(h[i].chave);
        }
    }
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
        scanf("%c", &op);
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
        if (pt && *pt) {
            printf("\nPalavra: %s", (*pt)->palavra);
            printf("\nSinonimo: %s", (*pt)->sinonimo);
        } else
            printf("\nPalavra nao encontrada!");

        printf("\n\nDeseja realizar uma nova pesquisa (s/n)? ");
        scanf("%c", &op);
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
        if (pt && *pt) {
            // A função ExcluirHash deverá ser adaptada para manipular a árvore.
            // Implemente conforme necessário.
            e = ExcluirHash(pt);
            printf("\nPalavra: %s", e.palavra);
            printf("\nSinonimo: %s", e.sinonimo);
            printf("\nExclusao realizada com sucesso!");
        } else
            printf("\nPalavra nao encontrada!");

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
