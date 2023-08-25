#include <stdio.h>
#include <math.h>

float calcularMedia(float nota1, float nota2, float nota3);
int calcularIdadeAtual(int anoNascimento, int anoAtual);
int calcularIdade2050(int anoNascimento);
float converterDolarParaReais(float valorDolar, float cotacaoDolar);
float calcularAreaLosango(float diagonalMaior, float diagonalMenor);
float calcularQuantidadeSalariosMinimos(float salarioFuncionario, float salarioMinimo);
float calcularHipotenusa(float cateto1, float cateto2);

int main()
{
    int comando;

    printf("Digite o comando da operacao desejada:\n"
           "1 - Calcular media\n"
           "2 - Calcular idade\n"
           "3 - Converter valor em dólares para reais\n"
           "4 - Calcular área de um losango\n"
           "5 - Calcular quantidade de salários mínimos\n"
           "6 - Calcular hipotenusa\n");

    scanf("%d", &comando);

    if (comando == 1)
    {
        float nota1, nota2, nota3;
        printf("Digite as tres notas: ");
        scanf("%f %f %f", &nota1, &nota2, &nota3);

        float media = calcularMedia(nota1, nota2, nota3);
        printf("A media aritmetica das notas eh: %.2f\n", media);
    }

    if (comando == 2)
    {
        int anoNascimento, anoAtual;
        printf("Digite o ano de nascimento: ");
        scanf("%d", &anoNascimento);

        printf("Digite o ano atual: ");
        scanf("%d", &anoAtual);

        int idadeAtual = calcularIdadeAtual(anoNascimento, anoAtual);
        int idade2050 = calcularIdade2050(anoNascimento);

        printf("A idade da pessoa no ano atual eh: %d anos\n", idadeAtual);
        printf("A idade da pessoa em 2050 sera: %d anos\n", idade2050);
    }

    if (comando == 3)
    {
        float cotacaoDolar, valorDolar;
        printf("Digite a cotacao do dolar em reais: ");
        scanf("%f", &cotacaoDolar);

        printf("Digite o valor em dolares: ");
        scanf("%f", &valorDolar);

        float valorEmReais = converterDolarParaReais(valorDolar, cotacaoDolar);
        printf("O valor em reais eh: %.2f\n", valorEmReais);
    }

    if (comando == 4)
    {
        float diagonalMaior, diagonalMenor;
        printf("Digite a diagonal maior do losango: ");
        scanf("%f", &diagonalMaior);

        printf("Digite a diagonal menor do losango: ");
        scanf("%f", &diagonalMenor);

        float areaLosango = calcularAreaLosango(diagonalMaior, diagonalMenor);
        printf("A área do losango é: %.2f\n", areaLosango);
    }

    if (comando == 5)
    {
        float salarioFuncionario, salarioMinimo;
        printf("Digite o valor do salário do funcionário: ");
        scanf("%f", &salarioFuncionario);

        printf("Digite o valor do salário mínimo: ");
        scanf("%f", &salarioMinimo);

        float quantidadeSalariosMinimos =
            calcularQuantidadeSalariosMinimos(salarioFuncionario, salarioMinimo);
        printf("O funcionário recebe %.2f salários mínimos.\n", quantidadeSalariosMinimos);
    }

    if (comando == 6)
    {
        float cateto1, cateto2;
        printf("Digite o valor do primeiro cateto: ");
        scanf("%f", &cateto1);

        printf("Digite o valor do segundo cateto: ");
        scanf("%f", &cateto2);

        float hipotenusa = calcularHipotenusa(cateto1, cateto2);
        printf("A hipotenusa do triângulo é: %.2f\n", hipotenusa);
    }

    return 0;
}
