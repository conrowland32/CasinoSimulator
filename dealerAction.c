#include "blackjackHeader.h"

void dealerAction(Card** deckPtr, Card* array[], int* numCards, int* cardCount){
    int handValue;
    handValue = getHandValue(array);

    if(checkBust(array) == 1){
        if(areAces(array) == 1){
            modifyAces(array); //change 1 ace
            handValue = getHandValue(array);
        }
        else{
            printf("The dealer has busted.\n");
            return;
        }
    }


    if(handValue <= 16){
        printf("The dealer will hit\n");
        drawCard(deckPtr, array, numCards, DEALER, cardCount);
        waitFor(1);
        dealerAction(deckPtr, array, numCards, cardCount);
    }

    else{
        printf("The dealer will stay\n");
        return;
    }
}
