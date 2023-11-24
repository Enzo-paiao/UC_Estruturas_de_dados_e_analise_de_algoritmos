// ArvoreBinariaDePesquisa.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char TipoChave[20]; // Substitua 20 pelo valor desejado para n

typedef struct {
  TipoChave Chave;
  int Valor;
  char Descricao[100];
  /* Adicione mais componentes conforme necessário */
} Registro;

typedef struct Nodo_str *Apontador;

typedef struct Nodo_str {
  Registro Reg;
  Apontador Esq, Dir;
} Nodo;

typedef Apontador TipoDicionario;

void Antecessor(Apontador q, Apontador *r);

// Função para inicializar a árvore
void Inicia(TipoDicionario *Dicionario) { *Dicionario = NULL; }

// Função para inserir um elemento na árvore
void Insere(Registro x, Apontador *p) {
  if (*p == NULL) {
    *p = (Apontador)malloc(sizeof(Nodo));
    (*p)->Reg = x;
    (*p)->Esq = NULL;
    (*p)->Dir = NULL;
    return;
  }
  if (strcmp(x.Chave, (*p)->Reg.Chave) < 0) {
    Insere(x, &(*p)->Esq);
    return;
  }
  if (strcmp(x.Chave, (*p)->Reg.Chave) > 0) {
    Insere(x, &(*p)->Dir);
    return;
  } else {
    printf("Registro existente na árvore\n");
  }
}

// Função para pesquisar um elemento na árvore
int Pesquisa(Registro *x, Apontador p) {
  if (p == NULL) {
    return 0; // Registro não está na árvore
  }
  if (strcmp(x->Chave, p->Reg.Chave) < 0) {
    return Pesquisa(x, p->Esq);
  }
  if (strcmp(x->Chave, p->Reg.Chave) > 0) {
    return Pesquisa(x, p->Dir);
  }

  // Registro encontrado
  *x = p->Reg;
  return 1;
}

// Função para percorrer a árvore em ordem central
void Central(Apontador p) {
  if (p != NULL) {
    Central(p->Esq);
    printf("%s\n", p->Reg.Chave);
    Central(p->Dir);
  }
}

// Função para percorrer a árvore em pré-ordem
void PreOrdem(Apontador p) {
  if (p != NULL) {
    printf("%s\n", p->Reg.Chave);
    PreOrdem(p->Esq);
    PreOrdem(p->Dir);
  }
}

// Função para percorrer a árvore em pós-ordem
void PosOrdem(Apontador p) {
  if (p != NULL) {
    PosOrdem(p->Esq);
    PosOrdem(p->Dir);
    printf("%s\n", p->Reg.Chave);
  }
}

// Função para remover um elemento da árvore
int Retira(Registro x, Apontador *p) {
  Apontador Aux;
  if (*p == NULL) {
    return 0; // Registro não está na árvore
  }
  if (strcmp(x.Chave, (*p)->Reg.Chave) < 0) {
    return Retira(x, &(*p)->Esq);
  }
  if (strcmp(x.Chave, (*p)->Reg.Chave) > 0) {
    return Retira(x, &(*p)->Dir);
  }
  if ((*p)->Dir == NULL) {
    Aux = *p;
    *p = (*p)->Esq;
    free(Aux);
    return 1; // Registro removido com sucesso
  }
  if ((*p)->Esq != NULL) {
    Antecessor(*p, &(*p)->Esq);
    return 1; // Registro removido com sucesso
  }
  Aux = *p;
  *p = (*p)->Dir;
  free(Aux);
  return 1; // Registro removido com sucesso
}

// Função para encontrar o antecessor de um nó na árvore
void Antecessor(Apontador q, Apontador *r) {
  if ((*r)->Dir != NULL) {
    Antecessor(q, &(*r)->Dir);
    return;
  }
  q->Reg = (*r)->Reg;
  q = *r;
  *r = (*r)->Esq;
  free(q);
}

int main() {
  Registro x;
  TipoDicionario Dicionario;
  Inicia(&Dicionario);

  printf("Informe a chave (digite 0 para parar de acresentar chaves): ");
  scanf("%s", x.Chave);

  while (strcmp(x.Chave, "0") != 0) {
    Insere(x, &Dicionario);
    printf("Informe a chave:");
    scanf("%s", x.Chave);
  }

  printf("\nÁrvore em ordem central:\n");
  Central(Dicionario);

  printf("\nÁrvore em pré-ordem:\n");
  PreOrdem(Dicionario);

  printf("\nÁrvore em pós-ordem:\n");
  PosOrdem(Dicionario);

  printf("\nInforme a chave para pesquisa:");
  scanf("%s", x.Chave);

  if (Pesquisa(&x, Dicionario)) {
    printf("Registro encontrado: %s\n", x.Chave);
  } else {
    printf("Registro não encontrado.\n");
  }

  printf("\nInforme a chave para remoção:");
  scanf("%s", x.Chave);

  if (Retira(x, &Dicionario)) {
    printf("Registro removido.\n");
  } else {
    printf("Registro não encontrado.\n");
  }

  return 0;
}
