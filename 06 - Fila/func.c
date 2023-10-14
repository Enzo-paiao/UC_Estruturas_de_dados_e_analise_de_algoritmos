#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CF(roll *ff) {
  (*ff).inicio = -1;
  (*ff).fim = -1;
}

int FV(roll *ff) { return ((*ff).inicio == -1); }

int FC(roll *ff) { return ((*ff).fim == SIZE - 1); }

void EF(roll *ff, struct funcionario func) {
  if (!FC(ff)) {
    if (FV(ff)) {
      (*ff).inicio = 0;
    }
    (*ff).vet[++(*ff).fim] = func;
  }
}

struct funcionario DS(roll *ff) {
  struct funcionario func;
  if (!FV(ff)) {
    func = (*ff).vet[(*ff).inicio];
    if ((*ff).inicio == (*ff).fim) {
      CF(ff);
    } else {
      (*ff).inicio++;
    }
  } else {
    strcpy(func.cpf, "");
  }
  return func;
}

void GravarEmArquivoBinario(roll *ff) {
  FILE *arquivo;
  arquivo = fopen("funcionarios.bin", "wb");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  while (!FV(ff)) {
    struct funcionario func = DS(ff);
    fwrite(&func, sizeof(struct funcionario), 1, arquivo);
  }

  fclose(arquivo);
}

void LerDeArquivoBinario(roll *ff) {
  FILE *arquivo;
  arquivo = fopen("funcionarios.bin", "rb");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  struct funcionario func;
  while (fread(&func, sizeof(struct funcionario), 1, arquivo) > 0) {
    EF(ff, func);
  }

  fclose(arquivo);
}

void PesquisarPorCPF(roll *ff, char cpf[12]) {
  roll temp;
  CF(&temp);

  while (!FV(ff)) {
    struct funcionario func = DS(ff);
    if (strcmp(func.cpf, cpf) == 0) {
      printf("Funcionário Encontrado:\n");
      printf("CPF: %s\n", func.cpf);
      printf("Nome: %s\n", func.nome);
      printf("Endereco: %s\n", func.endereco);
      printf("Telefone: %s\n", func.telefone);
      printf("Celular: %s\n", func.celular);
      printf("Data de Nascimento: %02d/%02d/%04d\n", func.nascimento.dia,
             func.nascimento.mes, func.nascimento.ano);
      printf("Data de Admissao: %02d/%02d/%04d\n", func.admissao.dia,
             func.admissao.mes, func.admissao.ano);
      printf("Departamento: %s\n", func.departamento);
      printf("Cargo: %s\n", func.cargo);
      printf("Salario: %.2f\n", func.salario);
      return;
    } else {
      EF(&temp, func);
    }
  }

  printf("Funcionário com CPF %s não encontrado.\n", cpf);

  while (!FV(&temp)) {
    struct funcionario func = DS(&temp);
    EF(ff, func);
  }
}

void IF(roll *ff) {
  printf("Funcionarios na Fila:\n");
  printf("=====================\n");

  if (FV(ff)) {
    printf("A roll de funcionarios esta vazia.\n");
    return;
  }

  int i;
  for (i = (*ff).inicio; i <= (*ff).fim; i++) {
    struct funcionario func = (*ff).vet[i];
    printf("CPF: %s\n", func.cpf);
    printf("Nome: %s\n", func.nome);
    printf("Endereco: %s\n", func.endereco);
    printf("Telefone: %s\n", func.telefone);
    printf("Celular: %s\n", func.celular);
    printf("Data de Nascimento: %02d/%02d/%04d\n", func.nascimento.dia,
           func.nascimento.mes, func.nascimento.ano);
    printf("Data de Admissao: %02d/%02d/%04d\n", func.admissao.dia,
           func.admissao.mes, func.admissao.ano);
    printf("Departamento: %s\n", func.departamento);
    printf("Cargo: %s\n", func.cargo);
    printf("Salario: %.2f\n", func.salario);
    printf("=====================\n");
  }
}
