/*
 * Arquivo: pilha.h
 * Biblioteca de operações para pilha
 * implementada com vetor.
 */
#define VERDADEIRO 1
#define FALSO 0
#define mxTAM 3 // Tamanho máximo da pilha

struct tipo_pilha {
  elment vet[mxTAM];
  int topo;
};
typedef struct tipo_pilha pilha;

// Cria pilha e inicializa o topo com -1
void CreatePile(pilha *ppp) { (*ppp).topo = -1; }

// Verifica se a pilha está vazia.
int EmptyPile(pilha *ppp) { return ((*ppp).topo == -1); }

// Verifica se a pilha está cheia.
int Fullpile(pilha *ppp) { return ((*ppp).topo == mxTAM - 1); }

// Insere um elment na pilha.
void Mount(pilha *ppp, elment e) {
  if (Fullpile(ppp)) {
    printf("Erro: Pilha cheia\n");
  } else {
    (*ppp).topo++;
    (*ppp).vet[(*ppp).topo] = e;
  }
}

// Retira um elment da pilha.
elment Unmount(pilha *ppp) {
  if (EmptyPile(ppp)) {
    printf("Erro: Pilha vazia\n");
    return -1; // Valor de erro, você pode escolher outro valor se desejar
  } else {
    elment e = (*ppp).vet[(*ppp).topo];
    (*ppp).topo--;
    return e;
  }
}

// Imprime o conteúdo da pilha.
void Printpile(pilha *ppp) {
  printf("Conteudo da pilha:\n");
  if (EmptyPile(ppp)) {
    printf("Pilha vazia\n");
  } else {
    for (int i = 0; i <= (*ppp).topo; i++) {
      printf("%d\n", (*ppp).vet[i]);
    }
  }
}
