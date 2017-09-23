#include "blackjackHeader.h"
#include "projectHeader.h"
#include "VPHeader.h"

int printUserMenu(Card* array[]){ //returns the users selection
    printf("\n\n1. Hit");
    printf("\n2. Stay");
    printf("\n3. Double");
    printf("\n4. View your cards");
    printf("\n5. View the dealer's cards");
    printf("\n6. Consult basic strategy");
    if(areAces(array) == 1){
        printf("\n\nYou have a soft %d", getHandValue(array));
    }
    else{
        printf("\n\nYou have a hard %d", getHandValue(array));
    }
    printf("\nMake a selection: ");

    int selection = 0;
    scanf("%d", &selection);
    while(selection < 1 || selection > 6){
        printf("\nPlease make a valid selection: ");
        scanf("%d", &selection);
    }

    return selection;
}

int printGameMenu(){
    printf("\n1. Blackjack");
    printf("\n2. Video Poker");
    printf("\n3. Exit Casino");
    printf("\n\nChoose a game to play: ");

    int selection = 0;
    scanf("%d", &selection);
    while(selection < 1 || selection > 3){
        printf("\nPlease make a valid selection: ");
        scanf("%d" , &selection);
    }

    return selection;
}

void printCards(Card* array[]){
    int i;
    Card* current;
    for(i = 0; i < 6; i++){
        current = array[i];
        while(current != NULL){
            printf("%s of %s\n", current->value, current->suit);
            current = current->next;
        }
    }
}

void printDealerCards(Card* array[], Card* firstCard){
    int i;
    Card* current;
    for(i = 0; i < 6; i++){
        current = array[i];
        while(current != NULL){
            if(current!= firstCard)
                printf("%s of %s\n", current->value, current->suit);
            current = current->next;
        }
    }
}

int findWinner(Card* playerHand[], Card* dealerHand[]){
    if(checkBust(playerHand) == 1){
        printf("Dealer won by player bust.\n");
        return 0;
    }

    else if(checkBust(playerHand) == 0 && checkBust(dealerHand) == 1){
        printf("You won by dealer bust.\n");
        return 1;
    }

    else{
        if(getHandValue(dealerHand) > getHandValue(playerHand)){
            printf("Dealer won %d to %d.\n", getHandValue(dealerHand), getHandValue(playerHand));
            return 0;
        }

        else if(getHandValue(dealerHand) < getHandValue(playerHand)){
            printf("You won %d to %d.\n", getHandValue(playerHand), getHandValue(dealerHand));
            return 1;
        }

        else{//values are equal
            printf("You and the dealer tied with %d. Hand is a push.\n", getHandValue(playerHand));
            return -1;
        }
    }
}

void payout(double* balance, int bet, int winner, Card* playerHand[]){
    if(winner == -1){
        printf("Your $%d bet was refunded.\n", bet);
    }

    else if(winner == 0){
        printf("The dealer collects your $%d bet.\n", bet);
        *balance = *balance - bet;
    }

    else{
        if (checkBlackjack(playerHand) == 1){
            printf("You win $%4.2lf.\n", (double)(bet*1.5));
            *balance = *balance + (double)(bet*1.5);
        }

        else{
            printf("You win $%d.\n", bet);
            *balance = *balance + bet;
        }
    }
}

void getCardCountAdvice(int cardCount){
    if(cardCount <= 0)
        printf("\nThe current count is: %d\n\n", cardCount);
    else
        printf("\nThe current count is: +%d\n\n", cardCount);
    waitFor(1);
    if(cardCount <= -2){
        printf("The card count doesn't look good for you...\n\n");
        waitFor(2);
        printf("... I wouldn't bet big if I were you.\n");
    }

    else if(cardCount > -2 && cardCount < 2){
        printf("The card count is neutral...\n\n");
        waitFor(2);
        printf("...I would bet normally.\n");
    }

    else if(cardCount >= 2 && cardCount < 5){
        printf("The card count looks pretty good for you...\n\n");
        waitFor(2);
        printf("...I would consider increasing your bet.\n");
    }

    else if(cardCount >= 5 && cardCount < 10){
        printf("The card count looks VERY good for you...\n\n");
        waitFor(2);
        printf("...I would definitely increase your bet here.\n");
    }

    else{
        printf("The card count is insane...\n\n");
        waitFor(2);
        printf("...Empty your pockets and clinch your butthole.\n");
    }
}

void changeCardsMenu(){
    printf("1: Change first card\n");
    printf("2: Change second card\n");
    printf("3: Change third card\n");
    printf("4: Change fourth card\n");
    printf("5: Change fifth card\n");
    printf("0: Finalize changes\n\n");
    printf("Enter your choice (changing the same card twice will keep it): ");
}

void printCardChangeStatus(VPHandCard hand[]){
    if(hand[0].hasBeenReplaced == 0){
        printf("%s of %s: keep\n", hand[0].value, hand[0].suit);
    }
    else{
        printf("%s of %s: replace\n", hand[0].value, hand[0].suit);
    }
    if(hand[1].hasBeenReplaced == 0){
        printf("%s of %s: keep\n", hand[1].value, hand[1].suit);
    }
    else{
        printf("%s of %s: replace\n", hand[1].value, hand[1].suit);
    }
    if(hand[2].hasBeenReplaced == 0){
        printf("%s of %s: keep\n", hand[2].value, hand[2].suit);
    }
    else{
        printf("%s of %s: replace\n", hand[2].value, hand[2].suit);
    }
    if(hand[3].hasBeenReplaced == 0){
        printf("%s of %s: keep\n", hand[3].value, hand[3].suit);
    }
    else{
        printf("%s of %s: replace\n", hand[3].value, hand[3].suit);
    }
    if(hand[4].hasBeenReplaced == 0){
        printf("%s of %s: keep\n\n", hand[4].value, hand[4].suit);
    }
    else{
        printf("%s of %s: replace\n\n", hand[4].value, hand[4].suit);
    }
}










