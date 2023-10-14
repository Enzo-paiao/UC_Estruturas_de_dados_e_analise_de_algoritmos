#ifndef FUNC_H
#define FUNC_H

#define SIZE 10

struct data {
  int dia, mes, ano;
};

struct funcionario {
  char cpf[12];
  char nome[100];
  char endereco[100];
  char telefone[15];
  char celular[15];
  struct data nascimento;
  struct data admissao;
  char departamento[100];
  char cargo[100];
  float salario;
};

struct tipo_roll {
  struct funcionario vet[SIZE];
  int inicio, fim;
};
typedef struct tipo_roll roll;

void CF(roll *ff);
int FV(roll *ff);
int FC(roll *ff);
void EF(roll *ff, struct funcionario func);
struct funcionario DS(roll *ff);
void GravarEmArquivoBinario(roll *ff);
void LerDeArquivoBinario(roll *ff);
void PesquisarPorCPF(roll *ff, char cpf[12]);
void IF(roll *ff);

#endif
