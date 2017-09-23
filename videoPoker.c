#include "VPHeader.h"

double videoPoker(double playerBalance){

    VPDeckCard* deck;
    VPHandCard playerHand[5];
    deck = VPShuffleDeck();
    int numCards;
    int selectMoreCards;
    int playAnotherHand = 1;
    double playerBet;

    printf("\n**********************************************************\n");
    printf("**                                                      **\n");
    printf("**                WELCOME TO VIDEO POKER                **\n");
    printf("**                                                      **\n");
    printf("**********************************************************\n");
    while(playAnotherHand == 1){
        deck = NULL;
        initializeVPHand(playerHand);
        deck = VPShuffleDeck();
        numCards = 52;

        printf("\nYou have $%.2lf\n", playerBalance);
        printf("Please enter a bet for this round: ");
        scanf("%lf", &playerBet);
        while(playerBet < 0.01 || playerBet > playerBalance){
            printf("Cannot place this bet. Make a bet between $0.01 and $%.2lf: \n", playerBalance);
            scanf("%lf", &playerBet);
        }
        printf("\nYou bet $%.2lf\n", playerBet);
        playerBalance -= playerBet;
        printf("\nHand is starting...\n\n");
        waitFor(1);
        VPInitialDeal(&deck, playerHand, &numCards);
        waitFor(1);
        printf("\nYour current best hand is: ");
        printWinCondition(playerHand);
        printf("\n\n\n");
        waitFor(1);
        selectMoreCards = -1;
        while(selectMoreCards != 0){
            printf("Status of your cards:\n\n");
            printCardChangeStatus(playerHand);
            waitFor(1);
            changeCardsMenu();
            scanf("%d", &selectMoreCards);
            while(selectMoreCards < 0 || selectMoreCards > 5){
                printf("\nInvalid input\n");
                changeCardsMenu();
                scanf("%d", &selectMoreCards);
            }
            switch(selectMoreCards){
                case 1:
                    if(playerHand[0].hasBeenReplaced == 0)
                        playerHand[0].hasBeenReplaced = 1;
                    else
                        playerHand[0].hasBeenReplaced = 0;
                    break;

                case 2:
                    if(playerHand[1].hasBeenReplaced == 0)
                        playerHand[1].hasBeenReplaced = 1;
                    else
                        playerHand[1].hasBeenReplaced = 0;
                    break;

                case 3:
                    if(playerHand[2].hasBeenReplaced == 0)
                        playerHand[2].hasBeenReplaced = 1;
                    else
                        playerHand[2].hasBeenReplaced = 0;
                    break;

                case 4:
                    if(playerHand[3].hasBeenReplaced == 0)
                        playerHand[3].hasBeenReplaced = 1;
                    else
                        playerHand[3].hasBeenReplaced = 0;
                    break;

                case 5:
                    if(playerHand[4].hasBeenReplaced == 0)
                        playerHand[4].hasBeenReplaced = 1;
                    else
                        playerHand[4].hasBeenReplaced = 0;
                    break;

                case 0:
                    printf("Replacing these cards...\n\n");
                    replaceCards(&deck, playerHand, &numCards);
                    break;
            }

        }
        printf("Your final hand is:\n\n");
        printVPCards(playerHand);
        waitFor(1);
        printf("\nYour best hand is: ");
        printWinCondition(playerHand);
        printf("\n\n");
        printf("You won $%.2lf\n", handWinnings(playerHand, playerBet));
        playerBalance = playerBalance + (handWinnings(playerHand, playerBet));
        printf("You now have $%.2lf\n\n", playerBalance);

        freeVPDeck(deck);
        waitFor(1);
        if(playerBalance > 0) {
            printf("Would you like to play another hand?\n1. Yes\n2. No\n");
            scanf("%d" , &playAnotherHand);
            if(playerBet != 0){
                while(playAnotherHand < 1 || playAnotherHand > 2){
                    printf("Invalid input.\n1. To play again\n2. To exit video poker\n");
                    scanf("%d", &playAnotherHand);
                }
            }
            else{
                playAnotherHand = 0;
            }
        }
        else
            playAnotherHand = 0;
    }

    return playerBalance;

}
