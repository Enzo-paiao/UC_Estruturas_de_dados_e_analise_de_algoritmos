#include <math.h>
#include <stdio.h>

float calcularMedia(float nota1, float nota2, float nota3);
int calcularIdadeAtual(int anoNascimento, int anoAtual);
int calcularIdade2050(int anoNascimento);
float converterDolarParaReais(float valorDolar, float cotacaoDolar);
float calcularAreaLosango(float diagonalMaior, float diagonalMenor);
float calcularQuantidadeSalariosMinimos(float salarioFuncionario,
                                        float salarioMinimo);
float calcularHipotenusa(float cateto1, float cateto2);

int main()
{
    int comando;

    printf("Digite o comando da operacao desejada:\n"
           "1 - Calcular média aritmética entre três notas\n"
           "2 - Calcular idade\n"
           "3 - Converter valor em dólares para reais\n"
           "4 - Calcular aumento de sálario\n"
           "5 - Calcular área de um losango\n"
           "6 - Convetor de Celsius para Fahrenheit.\n"
           "7 - Calcular quantidade de salários mínimos recebidos\n"
           "8 - Calcular o peso de uma pessoa se ela engordar ou emagrecer\n"
           "9 - Calcular a hipotenusa\n"
           "10 - Calcular o comprimento, a área e o volume de uma esfera\n"
           "11 - Calcular Tabuada\n");

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

    if (comando == 5)
    {
        float diagonalMaior, diagonalMenor;
        printf("Digite a diagonal maior do losango: ");
        scanf("%f", &diagonalMaior);

        printf("Digite a diagonal menor do losango: ");
        scanf("%f", &diagonalMenor);

        float areaLosango = calcularAreaLosango(diagonalMaior, diagonalMenor);
        printf("A área do losango é: %.2f\n", areaLosango);
    }

    if (comando == 7)
    {
        float salarioFuncionario, salarioMinimo;
        printf("Digite o valor do salário do funcionário: ");
        scanf("%f", &salarioFuncionario);

        printf("Digite o valor do salário mínimo: ");
        scanf("%f", &salarioMinimo);

        float quantidadeSalariosMinimos =
            calcularQuantidadeSalariosMinimos(salarioFuncionario, salarioMinimo);
        printf("O funcionário recebe %.2f salários mínimos.\n",
               quantidadeSalariosMinimos);
    }

    if (comando == 9)
    {
        float cateto1, cateto2;
        printf("Digite o valor do primeiro cateto: ");
        scanf("%f", &cateto1);

        printf("Digite o valor do segundo cateto: ");
        scanf("%f", &cateto2);

        float hipotenusa = calcularHipotenusa(cateto1, cateto2);
        printf("A hipotenusa do triângulo é: %.2f\n", hipotenusa);
    }

    if (comando == 4)
    {
        float salario, final;
        printf("Informe o seu salário: ");
        scanf("%f", &salario);
        final =
            (salario * 0.25) + salario; // pega 25% do salario e soma com o salario.
        printf("O salário final é: %.2f", final);
    }

    if (comando == 6)
    {
        float celsius, fahrenheit;

        printf("Celsius = ");
        scanf("%f", &celsius);

        fahrenheit = (9 * celsius + 160) / 5;

        printf("Fahrenheit = %2.f", fahrenheit);
    }

    if (comando == 8)
    {
        float peso, p1, p2, pfinal;
        printf("Informe o seu peso: ");
        scanf("%f", &peso);

        p1 = (peso * 0.15) + peso;
        printf("O peso caso engorde 15%: %.2f", p1);

        p2 = (peso * 0.20);
        pfinal = peso - p2;
        printf("\nO peso caso emagreça 20%: %.2f", pfinal);
    }

    if (comando == 10)
    {
        float raio, comprimento, area, volume;
        printf("Informe o raio de uma esfera: ");
        scanf("%f", &raio);

        comprimento = 2 * 3.14 * raio;
        printf("O comprimento da esfera é: %.2f", comprimento);

        area = 3.14 * pow(raio, 2);
        printf("\nA area da esfera é: %.2f", area);

        volume = (3 * 3.14 * pow(raio, 3)) / 4;
        printf("\nO volume da esfera é: %.2f", volume);
    }

    if (comando == 11)
    {
        int numero, i;

        do
        {
            printf("Informe um número: ");
            scanf("%d", &numero);
        }

        while (numero < 1 || numero > 10);

        for (i = 1; i <= 10; i++)
            printf("%d * %d = %d\n", numero, i, numero * i);
    }

    return 0;
}
