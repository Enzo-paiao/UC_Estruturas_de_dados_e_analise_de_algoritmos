#ifndef PILHACIRCULAR_H
#define PILHACIRCULAR_H

#define TAM 5
typedef int elemento;

#define MAX_TAM 7

typedef struct {
  char dados[MAX_TAM];
  int topo;
} PilhaCircular;

PilhaCircular *CriarPilha();
int PilhaVazia(PilhaCircular *pilha);
int PilhaCheia(PilhaCircular *pilha);
int Empilhar(PilhaCircular *pilha, int elemento);
int Desempilhar(PilhaCircular *pilha);

typedef struct {
  elemento elementos[TAM];
  int topo;
} PILHAS;

void CP(PILHAS *battery);
int PV(PILHAS *battery);
int PC(PILHAS *battery);
void Empr(PILHAS *battery, elemento e);
elemento Dsep(PILHAS *battery);

#endif
