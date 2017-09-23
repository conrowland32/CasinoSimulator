#include "blackjackHeader.h"

int getStrategy(Card* playerHand[], Card* dealerHand[], Card* facedownCard) {

    int dealerValue;
    dealerValue = getFaceupCard(dealerHand, facedownCard);

    if(areAces(playerHand) == 0) {

        switch(getHandValue(playerHand)) {

            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                return 0;
                break;
            case 9:
                if(dealerValue == 2  ||  dealerValue >= 7) {
                    return 0;
                }
                else return 2;
                break;
            case 10:
                if(dealerValue <= 9)
                    return 2;
                else return 0;
                break;
            case 11:
                if(dealerValue <= 10)
                    return 2;
                else return 0;
                break;
            case 12:
                if(dealerValue <= 3  ||  dealerValue >= 7)
                    return 0;
                else return 1;
                break;
            case 13:
            case 14:
            case 15:
            case 16:
                if(dealerValue <= 6)
                    return 1;
                else
                    return 0;
                break;
            default:
                return 1;
                break;

       }

    }


    else {

        switch(getHandValue(playerHand)) {

            case 13:
            case 14:
                if(dealerValue <= 4  ||  dealerValue >= 7)
                    return 0;
                else return 2;
                break;
            case 15:
            case 16:
                if(dealerValue <= 3  ||  dealerValue >= 7)
                    return 0;
                else return 2;
                break;
            case 17:
                if(dealerValue <= 2  ||  dealerValue >= 7)
                    return 0;
                else return 2;
            case 18:
                if(dealerValue >= 3  &&  dealerValue <= 6)
                    return 2;
                else if(dealerValue <= 8)
                    return 1;
                else return 0;
                break;
            default:
                return 1;

        }

    }

}


int getFaceupCard (Card* hand[], Card* facedownCard) {

    int i = 0;
    Card* currentPtr = NULL;

    for(i = 0; i < 6; i++) {
        currentPtr = hand[i];
        while(currentPtr != NULL) {
            if(currentPtr != facedownCard)
                return currentPtr->number;
            currentPtr = currentPtr->next;
        }
    }

    return 0;
}




