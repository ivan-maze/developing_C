#include <stdio.h>

int main() {
    
    printf("\n");
    
    // imprime o cabeçalho do jogo
    printf("********************************************\n");
    printf("***** Bem vindo ao jogo de adivinhação *****\n");
    printf("******* O número está entre 0 a 100 ********\n");
    printf("********************************************\n");

    printf("\n");

    // definição de variáveis
    int numerosecreto = 42;
    int chute;
    int tentativas = 1;

    // loop até acertar ganhou = 1
    while (1) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if (acertou) {
            printf("Parabéns, você acertou! \n");
            break;
        }
        else if (maior) {
            printf("Você errou, o número secreto é menor que %d\n", chute);
        }
        else {
            printf("Você errou, o número secreto é maior que %d\n", chute);
        }
        tentativas++;
    }

    printf("Fim de jogo!\n");
    printf("Você acertou em %d tentativas\n", tentativas);
    printf("********************************************\n");
    printf("\n");

    return 0;
}