#include "projectHeader.h"
#include "VPHeader.h"
#include "blackjackHeader.h"




int main(void){
    srand(time(NULL));
    double playerBalance = 200, initialBalance = 200;
    int gameSelection = 1;
    printf("\n**********************************************************\n");
    printf("**                                                      **\n");
    printf("**             WELCOME TO CASINO SIMULATOR              **\n");
    printf("**                                                      **\n");
    printf("**********************************************************\n");

    while(gameSelection != 3){
        if(playerBalance > 0)
            gameSelection = printGameMenu();
        else gameSelection = 3;
        switch(gameSelection){
            case 1: //blackjack
                playerBalance = blackjack(playerBalance);
                break;

            case 2: //video poker
                //printf("\nPlay video poker here.\n\n");
                playerBalance = videoPoker(playerBalance);
                break;

            case 3:
                printf("\n\nThank you for playing.\n");
                waitFor(2);
                if((playerBalance - initialBalance) > 0){
                    printf("You won $%4.2lf over the course of playing. Congratulations!\n\n" , (playerBalance-initialBalance));
                }
                else if((playerBalance - initialBalance) < 0){
                    printf("You lost $%4.2lf over the course of playing. Better luck next time!\n\n" , (initialBalance-playerBalance));
                }
                else{
                    printf("You did not make or lose any money over the course of playing.\n\n");
                }
                waitFor(1);
                printf("Now exiting...\n");
        }
    }
    return 0;
}

