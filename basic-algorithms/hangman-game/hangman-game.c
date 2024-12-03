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

// check if the player hit the word
int hit() {
    for(size_t i = 0; i < strlen(secret_wolrd); i++) {
        if(!already_kicked(secret_wolrd[i])) {
            return 0;
        }
    }
    return 1;
}

// check if the player hanged
int hanged() {
    int mistakes = 0;
    for(int i = 0; i < attempts; i++) {
        int exist = 0;
        for(size_t j = 0; j < strlen(secret_wolrd); j++) {
            if(kicks[i] == secret_wolrd[j]) {
                exist = 1;
                break;
            }
        }
        if(!exist) mistakes++;
    }
    return mistakes >= 5;
}

int main () {
    chooseword();
    openning();
    do { 
        write_word(); 
        kick();
    } while (!hit() && !hanged());

}