#include <stdio.h>
#include <string.h>

int main () {

    char secret_wolrd[20];
    sprintf(secret_wolrd, "HELLO");

    int hit = 0;
    int hanged = 0;

    char kicks[26];
    int attempts = 0;

    do {
        
        for (size_t i = 0; i < strlen(secret_wolrd); i++) {
            int found = 0;
            
            for(int j = 0; j < attempts; j++) {
                if (kicks[j] == secret_wolrd[i]) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                printf("%c ", secret_wolrd[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");
        
        char kick;
        scanf(" %c", &kick);

        kicks[attempts] = kick;
        attempts++;

    } while (!hit && !hanged);


}