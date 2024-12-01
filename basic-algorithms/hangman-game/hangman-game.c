#include <stdio.h>
#include <string.h>

// global variables
char secret_wolrd[20];
char kicks[26];
int attempts = 0;

// choose a word to be guessed
void chooseword() {
    sprintf(secret_wolrd, "HELLO");
}

// print the welcome message
void openning() {
    printf("************************************\n");
    printf("*   Welcome to the Hangman Game!   *\n");
    printf("************************************\n");
}
// print the word with the letters found
void kick() {
    char kick;
    printf("Which letter? ");
    scanf(" %c", &kick);
    kicks[attempts] = kick;
    attempts++;
}

// letter is in the kicks array? if yes, return 1, else return 0   
int already_kicked (char letter) {
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
void write_word( ) {
    for (size_t i = 0; i < strlen(secret_wolrd); i++) {
        int found = already_kicked(secret_wolrd[i]);
        if (found) {
            printf("%c ", secret_wolrd[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main () {

    int hit = 0;
    int hanged = 0;

    chooseword();
    openning();
    do { 
        write_word(); 
        kick();
    } while (!hit && !hanged);

}