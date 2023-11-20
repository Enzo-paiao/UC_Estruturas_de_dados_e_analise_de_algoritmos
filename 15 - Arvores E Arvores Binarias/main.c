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

int Altura(Apontador p) {
  if (p == NULL) {
    return -1;
  } else {
    int alturaEsq = Altura(p->Esq);
    int alturaDir = Altura(p->Dir);
    return (alturaEsq > alturaDir) ? alturaEsq + 1 : alturaDir + 1;
  }
}

int AlturaNo(Registro x, Apontador p) {
  if (p == NULL) {
    return -1;
  }
  if (x.Chave == p->Reg.Chave) {
    return Altura(p);
  } else if (x.Chave < p->Reg.Chave) {
    return AlturaNo(x, p->Esq);
  } else {
    return AlturaNo(x, p->Dir);
  }
}

int Profundidade(Apontador p) {
  if (p == NULL) {
    return -1;
  } else {
    int profundidadeEsq = Profundidade(p->Esq);
    int profundidadeDir = Profundidade(p->Dir);
    return (profundidadeEsq > profundidadeDir) ? profundidadeEsq + 1
                                               : profundidadeDir + 1;
  }
}

int ProfundidadeNo(Registro x, Apontador p) {
  if (p == NULL) {
    return -1;
  }
  if (x.Chave == p->Reg.Chave) {
    return Profundidade(p);
  } else if (x.Chave < p->Reg.Chave) {
    return ProfundidadeNo(x, p->Esq) + 1;
  } else {
    return ProfundidadeNo(x, p->Dir) + 1;
  }
}

int NivelNo(Registro x, Apontador p, int nivelAtual) {
  if (p == NULL) {
    return -1;
  }
  if (x.Chave == p->Reg.Chave) {
    return nivelAtual;
  } else if (x.Chave < p->Reg.Chave) {
    return NivelNo(x, p->Esq, nivelAtual + 1);
  } else {
    return NivelNo(x, p->Dir, nivelAtual + 1);
  }
}

int Grau(Apontador p) {
  if (p == NULL) {
    return 0;
  } else {
    int grauEsq = Grau(p->Esq);
    int grauDir = Grau(p->Dir);
    return (p->Esq != NULL) + (p->Dir != NULL) + grauEsq + grauDir;
  }
}

int GrauNo(Registro x, Apontador p) {
  if (p == NULL) {
    return 0;
  }
  if (x.Chave == p->Reg.Chave) {
    return Grau(p);
  } else if (x.Chave < p->Reg.Chave) {
    return GrauNo(x, p->Esq);
  } else {
    return GrauNo(x, p->Dir);
  }
}

void PercorrerLargura(Apontador raiz) {
  if (raiz == NULL) {
    return;
  }

  // Usaremos uma fila para percorrer em largura
  Apontador fila[100];
  int frente = -1, tras = -1;

  fila[++tras] = raiz;

  while (frente < tras) {
    Apontador atual = fila[++frente];
    printf("%d  ", atual->Reg.Chave);

    if (atual->Esq != NULL) {
      fila[++tras] = atual->Esq;
    }

    if (atual->Dir != NULL) {
      fila[++tras] = atual->Dir;
    }
  }
}

void PercorrerProfundidade(Apontador p) {
  if (p != NULL) {
    printf("%d  ", p->Reg.Chave);
    PercorrerProfundidade(p->Esq);
    PercorrerProfundidade(p->Dir);
  }
}

Apontador NoMaiorGrau(Apontador p) {
  if (p == NULL) {
    return NULL;
  }

  Apontador maiorGrau = p;

  Apontador noEsq = NoMaiorGrau(p->Esq);
  if (noEsq != NULL && Grau(noEsq) > Grau(maiorGrau)) {
    maiorGrau = noEsq;
  }

  Apontador noDir = NoMaiorGrau(p->Dir);
  if (noDir != NULL && Grau(noDir) > Grau(maiorGrau)) {
    maiorGrau = noDir;
  }

  return maiorGrau;
}

int DiametroArvore(Apontador p) {
  if (p == NULL) {
    return 0;
  }

  int diametroEsq = DiametroArvore(p->Esq);
  int diametroDir = DiametroArvore(p->Dir);

  int alturaEsq = Altura(p->Esq);
  int alturaDir = Altura(p->Dir);

  int diametroAtravessandoRaiz = alturaEsq + alturaDir + 2;

  return (diametroEsq > diametroDir) ? (diametroEsq > diametroAtravessandoRaiz
                                            ? diametroEsq
                                            : diametroAtravessandoRaiz)
                                     : (diametroDir > diametroAtravessandoRaiz
                                            ? diametroDir
                                            : diametroAtravessandoRaiz);
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
  novaCategoria->proxima = floresta;
  floresta = novaCategoria;
  contadorCategorias++; // Incrementa o contador de categorias ao adicionar uma
                        // nova categoria
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

int main() {
  int escolha;
  char nomeCategoria[20];
  int categoriaEscolhida = 0;
  Registro reg;
  Categoria *categoriaAtual = NULL;

  while (1) {
    printf("\nOperações:\n");
    printf("1 - Inserir categoria\n");
    printf("2 - Escolher categoria\n");
    printf("3 - Inserir registro na categoria\n");
    printf("4 - Pesquisar registro na categoria\n");
    printf("5 - Excluir registro na categoria\n");
    printf("6 - Imprimir categoria em ordem\n");
    printf("7 - Imprimir categoria pré-ordem\n");
    printf("8 - Imprimir categoria pós-ordem\n");
    printf("9 - Imprimir representação visual da árvore\n");
    printf("10 - Verificar se a árvore está vazia\n");
    printf("11 - Remover um nó da árvore\n");
    printf("12 - Pesquisar ocorrência de um valor em algum nó da árvore\n");
    printf("13 - Informar a altura da árvore\n");
    printf("14 - Informar a altura de um nó\n");
    printf("15 - Informar a profundidade da árvore\n");
    printf("16 - Informar a profundidade de um nó\n");
    printf("17 - Informar o nível de um nó\n");
    printf("18 - Informar o grau da árvore\n");
    printf("19 - Informar o grau de um nó\n");
    printf("20 - Informar o nó de maior grau\n");
    printf("21 - Informar o diâmetro da árvore\n");
    printf("22 - Percorrer a árvore em largura (nível)\n");
    printf("23 - Percorrer a árvore em profundidade\n");

    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    if (escolha == 1) {
      printf("Digite o nome da categoria a ser inserida: ");
      scanf("%s", nomeCategoria);
      InserirCategoria(nomeCategoria);
      printf("Categoria inserida.\n");
    } else if (escolha == 2) {
      printf("Escolha a categoria (0 para a primeira): ");
      scanf("%d", &categoriaEscolhida);

      Categoria *tempCategoria = floresta;
      for (int i = 0; i < categoriaEscolhida && tempCategoria != NULL; i++) {
        tempCategoria = tempCategoria->proxima;
      }

      if (tempCategoria != NULL) {
        categoriaAtual = tempCategoria;
        printf("Categoria escolhida: %s\n", categoriaAtual->nome);
      } else {
        printf("Categoria não encontrada.\n");
      }
    } else if (escolha == 3) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Digite o valor do registro a ser inserido: ");
      scanf("%d", &reg.Chave);
      InserirNaCategoria(reg, categoriaAtual);
      printf("Registro inserido na categoria.\n");
    } else if (escolha == 4) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Digite o valor do registro a ser pesquisado: ");
      scanf("%d", &reg.Chave);
      PesquisarNaCategoria(&reg, categoriaAtual);
      printf("Resultado da pesquisa: %d\n", reg.Chave);
    } else if (escolha == 5) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Digite o valor do registro a ser excluído: ");
      scanf("%d", &reg.Chave);
      ExcluirDaCategoria(reg, categoriaAtual);
      printf("Registro excluído da categoria.\n");
    } else if (escolha == 6) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Categoria em ordem: ");
      EmOrdemCategoria(categoriaAtual);
      printf("\n");
    } else if (escolha == 7) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Categoria pré-ordem: ");
      PreOrdemCategoria(categoriaAtual);
      printf("\n");
    } else if (escolha == 8) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Categoria pós-ordem: ");
      PosOrdemCategoria(categoriaAtual);
      printf("\n");
    } else if (escolha == 9) {
      if (categoriaAtual == NULL) {
        printf("Escolha uma categoria primeiro.\n");
        continue;
      }
      printf("Representação visual da árvore:\n");
      ImprimirArvore(categoriaAtual->arvore, 0);
    } else if (escolha == 10) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("A árvore está vazia.\n");
      } else {
        printf("A árvore não está vazia.\n");
      }
    } else if (escolha == 11) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Digite o valor do registro a ser removido: ");
      scanf("%d", &reg.Chave);
      Retira(reg, &(categoriaAtual->arvore));
      printf("Registro removido da árvore.\n");
    } else if (escolha == 12) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Digite o valor do registro a ser pesquisado: ");
      scanf("%d", &reg.Chave);
      Pesquisa(&reg, categoriaAtual->arvore);
      printf("Resultado da pesquisa: %d\n", reg.Chave);
    } else if (escolha == 13) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Altura da árvore: %d\n", Altura(categoriaAtual->arvore));
    } else if (escolha == 14) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Digite o valor do nó: ");
      scanf("%d", &reg.Chave);
      printf("Altura do nó: %d\n", AlturaNo(reg, categoriaAtual->arvore));
    } else if (escolha == 15) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Profundidade da árvore: %d\n",
             Profundidade(categoriaAtual->arvore));
    } else if (escolha == 16) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Digite o valor do nó: ");
      scanf("%d", &reg.Chave);
      printf("Profundidade do nó: %d\n",
             ProfundidadeNo(reg, categoriaAtual->arvore));
    } else if (escolha == 17) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Digite o valor do nó: ");
      scanf("%d", &reg.Chave);
      int nivel = NivelNo(reg, categoriaAtual->arvore, 0);
      if (nivel != -1) {
        printf("Nível do nó: %d\n", nivel);
      } else {
        printf("Nó não encontrado.\n");
      }
    } else if (escolha == 18) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Grau da árvore: %d\n", Grau(categoriaAtual->arvore));
    } else if (escolha == 19) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Digite o valor do nó: ");
      scanf("%d", &reg.Chave);
      printf("Grau do nó: %d\n", GrauNo(reg, categoriaAtual->arvore));
    } else if (escolha == 20) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      Apontador noMaiorGrau = NoMaiorGrau(categoriaAtual->arvore);
      if (noMaiorGrau != NULL) {
        printf("Nó de maior grau: %d\n", noMaiorGrau->Reg.Chave);
      } else {
        printf("Árvore vazia.\n");
      }
    } else if (escolha == 21) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Diâmetro da árvore: %d\n",
             DiametroArvore(categoriaAtual->arvore));
    } else if (escolha == 22) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Percorrer árvore em largura (nível): ");
      PercorrerLargura(categoriaAtual->arvore);
      printf("\n");
    } else if (escolha == 23) {
      if (categoriaAtual == NULL || categoriaAtual->arvore == NULL) {
        printf("Escolha uma categoria e inicie a árvore primeiro.\n");
        continue;
      }
      printf("Percorrer árvore em profundidade: ");
      PercorrerProfundidade(categoriaAtual->arvore);
      printf("\n");
    } else {
      printf("Opção inválida. Tente novamente.\n");
    }
  }

  return 0;
}
