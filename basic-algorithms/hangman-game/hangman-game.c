#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hangmangame.h"

// global variables
char secret_wolrd[20];
char kicks[26];
int attempts = 0;

void addnewword() {
    char add;
    printf("Do you want to add a new word in the game? (Y/N)");
    scanf(" %c", &add);

    if (add == 'Y') {
        char new_word[20];
        printf("Type the new word: ");
        scanf("%s",new_word);
        FILE* f = fopen("../words.txt", "r+");
        if (f == 0) {
            printf("File not found\n\n");
           exit(1);
        }
        int quantity;
        fscanf(f, "%d", &quantity);
        quantity++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", quantity);
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", new_word);
        fclose(f);
    }
}

// choose a word to be guessed
void chooseword() {
    FILE* f = fopen("../words.txt", "r");
    if (f == 0) {
        printf("File not found\n\n");
        exit(1);
    }
    int words_count;
    fscanf(f, "%d", &words_count);
    srand(time(0));
    int random = rand() % words_count; 
    for(int i = 0; i <= random; i++) {
        fscanf(f, "%s", secret_wolrd);
    }
    fclose(f);
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
    return mistakes >= 10;
}

int main () {
    chooseword();
    openning();
    do { 
        write_word(); 
        kick();
    } while (!hit() && !hanged());
    addnewword();
}