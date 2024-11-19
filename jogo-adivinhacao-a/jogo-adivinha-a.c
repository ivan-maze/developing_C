#include <stdio.h>

#define NUMERO_TENTATIVAS 5

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

    // loop para 3 tentativas
    for (int i = 1; i <= NUMERO_TENTATIVAS; i++) {

        printf("Tentativa %d de %d\n", i, NUMERO_TENTATIVAS);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos\n");
            printf("********************************************\n");
            printf("\n");
            i--;
            continue;
        }

        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        // regra condicional para verificar se o chute é igual ao número secreto
        if (acertou) {
            printf("Parabéns, você acertou! \n");
            printf("********************************************\n");
            printf("\n");
            break;
        }
        else if (maior) {
            printf("Você errou, o número secreto é menor que %d\n", chute);
        }
        else {
            printf("Você errou, o número secreto é maior que %d\n", chute);
        }

        printf("********************************************\n");
        printf("\n");
    }

    printf("Fim de jogo!\n");

    printf("\n");

    return 0;
}