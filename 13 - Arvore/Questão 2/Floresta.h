#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TipoChave;

typedef struct {
  TipoChave Chave;
  /* Outros componentes. */
} Registro;

typedef struct Nodo_str *Apontador;

typedef struct Nodo_str {
  Registro Reg;
  Apontador Esq, Dir;
} Nodo;

typedef Apontador TipoDicionario;

void Inicia(TipoDicionario *Dicionario) { *Dicionario = NULL; }

void Insere(Registro x, Apontador *p) {
  if (*p == NULL) {
    *p = (Apontador)malloc(sizeof(Nodo));
    (*p)->Reg = x;
    (*p)->Esq = NULL;
    (*p)->Dir = NULL;
    return;
  }
  if (x.Chave < (*p)->Reg.Chave) {
    Insere(x, &(*p)->Esq);
  } else if (x.Chave > (*p)->Reg.Chave) {
    Insere(x, &(*p)->Dir);
  } else {
    printf("Registro existente na árvore.\n");
  }
}

void Pesquisa(Registro *x, Apontador p) {
  if (p == NULL) {
    printf("Erro: Registro não está na árvore.\n");
    return;
  }
  if (x->Chave < p->Reg.Chave) {
    Pesquisa(x, p->Esq);
  } else if (x->Chave > p->Reg.Chave) {
    Pesquisa(x, p->Dir);
  } else {
    *x = p->Reg;
  }
}

void Central(Apontador p) {
  if (p != NULL) {
    Central(p->Esq);
    printf("%d  ", p->Reg.Chave);
    Central(p->Dir);
  }
}

void PreOrdem(Apontador p) {
  if (p != NULL) {
    printf("%d  ", p->Reg.Chave);
    PreOrdem(p->Esq);
    PreOrdem(p->Dir);
  }
}

void PosOrdem(Apontador p) {
  if (p != NULL) {
    PosOrdem(p->Esq);
    PosOrdem(p->Dir);
    printf("%d  ", p->Reg.Chave);
  }
}

void Antecessor(Apontador q, Apontador *r) {
  if ((*r)->Dir != NULL) {
    Antecessor(q, &(*r)->Dir);
  } else {
    q->Reg = (*r)->Reg;
    q = *r;
    *r = (*r)->Esq;
    free(q);
  }
}

void Retira(Registro x, Apontador *p) {
  Apontador Aux;

  if (*p == NULL) {
    printf("Erro: Registro não está na árvore.\n");
    return;
  }
  if (x.Chave < (*p)->Reg.Chave) {
    Retira(x, &(*p)->Esq);
  } else if (x.Chave > (*p)->Reg.Chave) {
    Retira(x, &(*p)->Dir);
  } else {
    if ((*p)->Dir == NULL) {
      Aux = *p;
      *p = (*p)->Esq;
      free(Aux);
    } else if ((*p)->Esq != NULL) {
      Antecessor(*p, &(*p)->Esq);
    } else {
      Aux = *p;
      *p = (*p)->Dir;
      free(Aux);
    }
  }
}

typedef struct Categoria {
  char nome[20];
  TipoDicionario arvore;
  struct Categoria *proxima;
} Categoria;

Categoria *floresta = NULL; // Inicializa a floresta

int contadorCategorias = 0;

void InserirCategoria(char nomeCategoria[20]) {
  Categoria *novaCategoria = (Categoria *)malloc(sizeof(Categoria));
  strcpy(novaCategoria->nome, nomeCategoria);
  novaCategoria->arvore = NULL;
  novaCategoria->proxima =
      NULL; // Define o próximo como NULL, já que será a primeira categoria

  if (floresta == NULL) {
    floresta = novaCategoria;
  } else {
    Categoria *tempCategoria = floresta;
    while (tempCategoria->proxima != NULL) {
      tempCategoria = tempCategoria->proxima;
    }
    tempCategoria->proxima = novaCategoria;
  }

  contadorCategorias++; 
}

void InserirNaCategoria(Registro x, Categoria *categoria) {
  Insere(x, &(categoria->arvore));
}

void PesquisarNaCategoria(Registro *x, Categoria *categoria) {
  Pesquisa(x, categoria->arvore);
}

void ExcluirDaCategoria(Registro x, Categoria *categoria) {
  Retira(x, &(categoria->arvore));
}

void PreOrdemCategoria(Categoria *categoria) { PreOrdem(categoria->arvore); }

void EmOrdemCategoria(Categoria *categoria) { Central(categoria->arvore); }

void PosOrdemCategoria(Categoria *categoria) { PosOrdem(categoria->arvore); }

void ImprimirArvore(Apontador p, int nivel) {
  if (p == NULL) {
    return;
  }
  ImprimirArvore(p->Dir, nivel + 1);
  for (int i = 0; i < nivel; i++) {
    printf("   ");
  }
  printf("%d\n", p->Reg.Chave);
  ImprimirArvore(p->Esq, nivel + 1);
}