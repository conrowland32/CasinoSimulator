#include "blackjackHeader.h"
#include "projectHeader.h"
#include "VPHeader.h"

void initializeHand(Card* array[]){
    int i;
    for(i = 0; i < 6; i++){
        array[i] = NULL;
    }
    return;
}

void initializeVPHand(VPHandCard hand[]){
    int i;
    for(i = 0; i < 5; i++){
        strcpy(hand[i].suit, "");
        strcpy(hand[i].value, "");
        hand[i].id = 0;
        hand[i].hasBeenReplaced = 0;
    }
}

void printDeck(Card* head, int numCards){
    Card* current = head;
    int i;
    for(i = 0; i < numCards; i++){
        printf("%s of %s which has a value of %d\n" , current->value, current->suit, current->number);
        current = current->next;
    }
    return;
}

void waitFor(int seconds){
    int retTime = time(0) + seconds;
    while(time(0) < retTime);
    return;
}

void freeHands(Card* playerHand[], Card* dealerHand[]){
    int i;
    Card *pCurrent, *dCurrent, *hold;

    for(i = 0; i < 6; i++){
        pCurrent = playerHand[i];
        dCurrent = dealerHand[i];
        while(pCurrent != NULL){
            hold = pCurrent->next;
            free(pCurrent);
            pCurrent = hold;
            playerHand[i] = NULL;
        }

        while(dCurrent != NULL){
            hold = dCurrent->next;
            free(dCurrent);
            dCurrent = hold;
            dealerHand[i] = NULL;
        }
    }
    return;
}

int getResetNumber(){
    return (rand()%21 + 10); //get a number of hands to be played between 10-30
}

void freeDeck(Card* deck){
    Card* sentinel = deck;
    Card* current = deck;
    Card* hold = NULL;
    while(current != sentinel && current != NULL){
        hold = current->next;
        free(current);
        current = hold;
    }
}








