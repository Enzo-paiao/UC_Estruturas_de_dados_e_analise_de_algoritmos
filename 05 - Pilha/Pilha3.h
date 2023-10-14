#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_p3 3

typedef struct {
    char cpf_p3[12];
    char nome_p3[50];
    char endereco_p3[100];
    char telefone_contato_p3[15]; // Alteração do nome da variável
    char data_nascimento_p3[11];
    char data_admissao_p3[11];
    char departamento_p3[50];
    char cargo_p3[50];
    double salario_p3;
} Funcionario_p3;

typedef struct {
    Funcionario_p3 vet_p3[TAM_p3];
    int topo_p3;
} PilhaFuncionarios_p3;

void CriarPilhaFuncionarios(PilhaFuncionarios_p3 *p_p3) {
    p_p3->topo_p3 = 0;
}

int PilhaFuncionariosVazia(PilhaFuncionarios_p3 *p_p3) {
    return p_p3->topo_p3 == 0;
}

int PilhaFuncionariosCheia(PilhaFuncionarios_p3 *p_p3) {
    return p_p3->topo_p3 == TAM_p3;
}

void EmpilharFuncionario(PilhaFuncionarios_p3 *p_p3, Funcionario_p3 f_p3) {
    if (!PilhaFuncionariosCheia(p_p3)) {
        p_p3->vet_p3[p_p3->topo_p3] = f_p3;
        p_p3->topo_p3++;
    } else {
        printf("Erro: Pilha de funcionários cheia.\n");
    }
}

Funcionario_p3 DesempilharFuncionario(PilhaFuncionarios_p3 *p_p3) {
    Funcionario_p3 f_p3;
    if (!PilhaFuncionariosVazia(p_p3)) {
        p_p3->topo_p3--;
        f_p3 = p_p3->vet_p3[p_p3->topo_p3];
    } else {
        printf("Erro: Pilha de funcionários vazia.\n");
        memset(&f_p3, 0, sizeof(Funcionario_p3));
    }
    return f_p3;
}

void GravarFuncionariosEmArquivo(PilhaFuncionarios_p3 *p_p3, const char *nomeArquivo_p3) {
    FILE *arquivo_p3 = fopen(nomeArquivo_p3, "wb");
    if (arquivo_p3 == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(p_p3->vet_p3, sizeof(Funcionario_p3), p_p3->topo_p3, arquivo_p3);
    fclose(arquivo_p3);
}

void LerFuncionariosDeArquivo(PilhaFuncionarios_p3 *p_p3, const char *nomeArquivo_p3) {
    FILE *arquivo_p3 = fopen(nomeArquivo_p3, "rb");
    if (arquivo_p3 == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    p_p3->topo_p3 = 0;
    while (fread(&p_p3->vet_p3[p_p3->topo_p3], sizeof(Funcionario_p3), 1, arquivo_p3) == 1) {
        p_p3->topo_p3++;
    }

    fclose(arquivo_p3);
}

void ImprimirFuncionarios(PilhaFuncionarios_p3 *p_p3) {
    for (int i = 0; i < p_p3->topo_p3; i++) {
        Funcionario_p3 f_p3 = p_p3->vet_p3[i];
        printf("Funcionário %d:\n", i + 1);
        printf("CPF: %s\n", f_p3.cpf_p3);
        printf("Nome: %s\n", f_p3.nome_p3);
        printf("Endereço: %s\n", f_p3.endereco_p3);
        printf("Telefone de Contato: %s\n", f_p3.telefone_contato_p3);
        printf("Data de Nascimento: %s\n", f_p3.data_nascimento_p3);
        printf("Data de Admissão: %s\n", f_p3.data_admissao_p3);
        printf("Departamento: %s\n", f_p3.departamento_p3);
        printf("Cargo: %s\n", f_p3.cargo_p3);
        printf("Salário: %.2lf\n", f_p3.salario_p3);
        printf("\n");
    }
}