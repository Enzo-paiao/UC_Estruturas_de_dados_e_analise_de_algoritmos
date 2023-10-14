#include "pilhacircular.h"
#include <stdio.h>
#include <stdlib.h>

PilhaCircular *CriarPilha() {
  PilhaCircular *pilha = (PilhaCircular *)malloc(sizeof(PilhaCircular));
  if (pilha != NULL) {
    pilha->topo = -1;
    for (int i = 0; i < MAX_TAM; i++) {
      pilha->dados[i] = 0; // Inicializa com zero
    }
  }
  return pilha;
}

int PilhaVazia(PilhaCircular *pilha) { return (pilha->topo == -1); }

int PilhaCheia(PilhaCircular *pilha) {
  return ((pilha->topo + 1) % MAX_TAM == pilha->topo % MAX_TAM);
}

int Empilhar(PilhaCircular *pilha, int elemento) {
  if (PilhaCheia(pilha)) {
    printf("Erro: a pilha está cheia\n");
    return 0; // Falha
  }
  pilha->topo = (pilha->topo + 1) % MAX_TAM;
  pilha->dados[pilha->topo] = elemento;
  return 1; // Sucesso
}

int Desempilhar(PilhaCircular *pilha) {
  if (PilhaVazia(pilha)) {
    printf("Erro: a pilha está vazia\n");
    return -1; // Pilha vazia
  }
  int elemento = pilha->dados[pilha->topo];
  pilha->topo = (pilha->topo - 1 + MAX_TAM) % MAX_TAM;
  return elemento;
}
void CP(PILHAS *battery) { battery->topo = -1; }

int PV(PILHAS *battery) { return (battery->topo == -1); }

int PC(PILHAS *battery) { return (battery->topo == TAM - 1); }

void Empr(PILHAS *battery, elemento e) {
  if (!PC(battery)) {
    battery->elementos[++(battery->topo)] = e;
  }
}

elemento Dsep(PILHAS *battery) {
  if (!PV(battery)) {
    return battery->elementos[(battery->topo)--];
  }
  return -1; // Valor especial
}