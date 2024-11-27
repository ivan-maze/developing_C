#include <stdio.h>
#include <string.h>

// choose a word to be guessed
void chooseword(char secret_wolrd[20]) {
    sprintf(secret_wolrd, "HELLO");
}

// print the welcome message
void openning() {
    printf("************************************\n");
    printf("*   Welcome to the Hangman Game!   *\n");
    printf("************************************\n");
}
// print the word with the letters found
void kick(char kicks[26], int* attempts) {
    char kick;
    printf("Which letter? ");
    scanf(" %c", &kick);
    kicks[(*attempts)] = kick;
    (*attempts)++;
}

// letter is in the kicks array? if yes, return 1, else return 0   
int already_kicked (char letter, char kicks[26], int attempts) {
    int found = 0;     
    for(int j = 0; j < attempts; j++) {
        if (kicks[j] == letter) {
            found = 1;
            break;
        }
    }
    return found;
}
// print the word with the letters found
void printhang(char secret_wolrd[20], char kicks[26], int attempts) {
    for (size_t i = 0; i < strlen(secret_wolrd); i++) {
        if (already_kicked(secret_wolrd[i], kicks, attempts)) {
            printf("%c ", secret_wolrd[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main () {

    char secret_wolrd[20];

    int hit = 0;
    int hanged = 0;

    char kicks[26];
    int attempts = 0;

    chooseword(secret_wolrd);
    openning();

    do { 
       
        printhang(secret_wolrd, kicks, attempts); 
        kick(kicks, &attempts);

    } while (!hit && !hanged);


}