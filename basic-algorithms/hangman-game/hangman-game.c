#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hangman-game.h"

// global variables
char secret_word[WORD_SIZE];
char kicks[26];
int attempts = 0;

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
        fscanf(f, "%s", secret_word);
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
void print_hang( ) {
    
    int mistakes = wrong_attempts();

    // hangman drawing
    // printf("  _______      \n");
    // printf(" |/      |     \n");
    // printf(" |      (_)    \n");
    // printf(" |      \\|/   \n");
    // printf(" |       |     \n");
    // printf(" |      / \\   \n");
    // printf(" |             \n");
    // printf("_|___          \n");
    // printf("\n\n");

    //using ternary operator (condition ? value_if_true : value_if_false)
    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n", (mistakes >= 1 ? '(' : ' '),
                                (mistakes >= 1 ? '_' : ' '),
                                (mistakes >= 1 ? ')' : ' '));
    printf(" |      %c%c%c \n", (mistakes >= 3 ? '\\' : ' '), 
                                (mistakes >= 2 ? '|' : ' '), 
                                (mistakes >= 3 ? '/' : ' '));
    printf(" |       %c    \n", (mistakes >= 2 ? '|' : ' '));
    printf(" |      %c %c  \n", (mistakes>= 4 ?  '/' : ' '), 
                                (mistakes >= 4 ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");
    
    for (size_t i = 0; i < strlen(secret_word); i++) {
        int found = already_kicked(secret_word[i]);
        if (found) {
            printf("%c ", secret_word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

// check if the player hit the word
int hit() {
    for(size_t i = 0; i < strlen(secret_word); i++) {
        if(!already_kicked(secret_word[i])) {
            return 0;
        }
    }
    return 1;
}

// check how many wrong attempts the player did
int wrong_attempts() {
    int mistakes = 0;
    for(int i = 0; i < attempts; i++) {
        int exist = 0;
        for(size_t j = 0; j < strlen(secret_word); j++) {
            if(kicks[i] == secret_word[j]) {
                exist = 1;
                break;
            }
        }
        if(!exist) mistakes++;
    } 
    return mistakes;
}

// check if the player hanged
int hanged() {
    return wrong_attempts() >= 5;
}

// add a new word in the game
void addnewword() {
    char add;
    printf("Do you want to add a new word in the game? (y/n)");
    scanf(" %c", &add);

    if (add == 'y') {
        char new_word[WORD_SIZE];
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

int main () {
    chooseword();
    openning();
    do { 
        print_hang(); 
        kick();
    } while (!hit() && !hanged());
    if(hit()){
        printf("Congratulations! You hit the word %s!\n", secret_word);
    } else {
        printf("You were hanged!\n");
        printf("The word was: %s\n", secret_word);
    } 
    addnewword();

}