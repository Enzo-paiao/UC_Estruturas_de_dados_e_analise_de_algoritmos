#define VERDADEIRO 1
#define FALSO 0

struct palavra_sinonimo {
  char *palavra;
  char *sinonimo;
};

typedef struct palavra_sinonimo elemento;

typedef struct TipoNodo *fila;
typedef struct TipoNodo *pt_nodo;

typedef struct TipoNodo {
  elemento e;
  pt_nodo prox;
} nodo;

void CriarFila(fila *f);
int FilaVazia(fila *f);
void Enfileirar(fila *f, elemento *x);
elemento Desenfileirar(fila *f);
pt_nodo *PesquisarFila(fila *f, char *x);

void CriarFila(fila *f) { *f = NULL; }

int FilaVazia(fila *f) { return (*f == NULL); }

void Enfileirar(fila *f, elemento *x) {
  pt_nodo p, ultimo;

  p = (pt_nodo)malloc(sizeof(nodo));
  p->e = *x;
  p->prox = NULL;

  if (*f == NULL) {
    *f = p;
  } else {
    ultimo = *f;
    while (ultimo->prox != NULL) {
      ultimo = ultimo->prox;
    }
    ultimo->prox = p;
  }
}

elemento Desenfileirar(fila *f) {
  pt_nodo primeiro;
  elemento x;

  primeiro = *f;
  x = primeiro->e;
  *f = primeiro->prox;
  free(primeiro);

  return x;
}

pt_nodo *PesquisarFila(fila *f, char *x) {
  pt_nodo *p = f;

  while (*p != NULL) {
    if (strcmp((*p)->e.palavra, x) == 0) {
      return p;
    }
    p = &((*p)->prox);
  }

  return NULL;
}
