#include <stdio.h>
#include <stdlib.h>

int main() {
    
     // print the welcome message
    printf("\n");
    printf("************************************************************\n");
    printf("***************** Welcome to guessing game *****************\n");
    printf("************** The number is between 1 to 100 **************\n");
    printf("************* You start with 1000 total points *************\n");
    printf("********* Do your best to keep the maximum points **********\n");
    printf("************************************************************\n");
    printf("\n");

    // define the variables
    int secret_number = 42;
    int guess;
    int attempts = 1;
    double points = 1000;

    // loop until the user guess the number 
    while (1) {

        printf("Attempt %d\n", attempts);
        printf("What is your guess? ");
        scanf("%d", &guess);

        if (guess < 0) {
            printf("You can't guess negative numbers \n");
            printf("************************************************************\n");
            printf("\n");
            continue;
        }

        int got_it = (guess == secret_number);
        int bigger = (guess > secret_number);

        if (got_it) {
            printf("\n");
            printf("WELL DONE! You got it right! \n");
            printf("\n");
            break;
        }
        else if (bigger) {
            printf("You got it wrong, the secret number is smaller than %d\n", guess);
            printf("************************************************************\n");
            printf("\n");
        }
        else {
            printf("You got it wrong, the secret number is greater than %d\n", guess);
            printf("************************************************************\n");
            printf("\n");
        }
        attempts++;

        // calculate the points with abs function to get the absolute value and cast to double
        double lost_points = abs(guess - secret_number) / (double)2;
        points = points - lost_points;
    }

    printf("End of game!\n");
    printf("\n");
    printf("You got it right in %d attempts \n", attempts);
    printf("Your total points: %.1f\n", points);
    printf("\n");
    printf("************************************************************\n");
    printf("\n");

    return 0;
}