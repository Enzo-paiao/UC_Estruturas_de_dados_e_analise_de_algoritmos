#include <stdio.h>

int somaNaturais(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + somaNaturais(n - 1);
    }
}

int calcularPotencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    } else {
        return base * calcularPotencia(base, expoente - 1);
    }
}

int main() {
    int escolha;
    printf("Escolha uma opção:\n");
    printf("1. Calcular uma potência\n");
    printf("2. Calcular a soma dos primeiros n números naturais\n");
    
    scanf("%d", &escolha);

    switch (escolha) {
        case 2:
            {
                int n;
                printf("Digite um valor para n: ");
                scanf("%d", &n);

                if (n < 1) {
                    printf("O valor de n deve ser maior ou igual a 1.\n");
                } else {
                    int resultado = somaNaturais(n);
                    printf("A soma dos primeiros %d números naturais é: %d\n", n, resultado);
                }
            }
            break;

        case 1:
            {
                int base, expoente;
                printf("Digite a base e o expoente (números inteiros):\n");
                scanf("%d %d", &base, &expoente);

                if (expoente < 0) {
                    printf("O expoente deve ser um número inteiro não negativo.\n");
                } else {
                    int resultado = calcularPotencia(base, expoente);
                    printf("%d elevado a %d é igual a %d\n", base, expoente, resultado);
                }
            }
            break;

        default:
            printf("Opção inválida.\n");
    }

    return 0;
}
