/*
 * Arquivo: pilha_P2.h
 * Biblicoteca de operações para pilha
 * implementada com vetor.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO_P2 1
#define FALSO_P2 0

struct tipo_pilha_P2 {
  elemento_P2 vet_P2[TAM_P2];
  int topo_P2;
};

typedef struct tipo_pilha_P2 pilha_P2;

// Cria pilha.
void CriarPilha_P2(pilha_P2 *p_P2) { (*p_P2).topo_P2 = 0; }

// Verifica se a pilha está vazia.
int PilhaVazia_P2(pilha_P2 *p_P2) { return ((*p_P2).topo_P2 == 0); }

// Verifica se a pilha está cheia.
int PilhaCheia_P2(pilha_P2 *p_P2) { return ((*p_P2).topo_P2 == TAM_P2); }

// Insere um elemento na pilha.
void Empilhar_P2(pilha_P2 *p_P2, elemento_P2 e_P2) {
  (*p_P2).vet_P2[(*p_P2).topo_P2] = e_P2;
  (*p_P2).topo_P2++;
}

// Retira um elemento na pilha.
elemento_P2 Desempilhar_P2(pilha_P2 *p_P2) {
  (*p_P2).topo_P2--;
  return (*p_P2).vet_P2[(*p_P2).topo_P2];
}