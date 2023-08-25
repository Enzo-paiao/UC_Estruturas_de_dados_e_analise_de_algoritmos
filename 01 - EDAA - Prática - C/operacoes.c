#include "operacoes.h"
#include <math.h>

float calcularMedia(float nota1, float nota2, float nota3) {
    return (nota1 + nota2 + nota3) / 3;
}

int calcularIdadeAtual(int anoNascimento, int anoAtual) {
    return anoAtual - anoNascimento;
}

int calcularIdade2050(int anoNascimento) {
    return 2050 - anoNascimento;
}

float converterDolarParaReais(float valorDolar, float cotacaoDolar) {
    return valorDolar * cotacaoDolar;
}

float calcularAreaLosango(float diagonalMaior, float diagonalMenor) {
    return (diagonalMaior * diagonalMenor) / 2;
}

float calcularQuantidadeSalariosMinimos(float salarioFuncionario, float salarioMinimo) {
    return salarioFuncionario / salarioMinimo;
}

float calcularHipotenusa(float cateto1, float cateto2) {
    return sqrt(cateto1 * cateto1 + cateto2 * cateto2);
}