#include "blackjackHeader.h"

Card* shuffleDeck(void){
    int i;
    Card* new;
    Card* head;
    Card* previous = NULL;
    for(i = 0; i < 208; i++)
    {
        new = malloc(sizeof(Card));
        new->next = NULL;

        if(i < 52)
        {
            strcpy(new->suit, "diamonds");
        }
        else if(i >= 52 && i < 104)
        {
            strcpy(new->suit, "clubs");
        }
        else if(i >= 104 && i < 156)
        {
            strcpy(new->suit, "hearts");
        }
        else
        {
            strcpy(new->suit, "spades");
        }

        if(i % 13 == 0)
        {
            new->number = 2;
            strcpy(new->value, "two");
        }
        else if(i % 13 == 1)
        {
            new->number = 3;
            strcpy(new->value, "three");
        }
        else if(i % 13 == 2)
        {
            new->number = 4;
            strcpy(new->value, "four");
        }
        else if(i % 13 == 3)
        {
            new->number = 5;
            strcpy(new->value, "five");
        }
        else if(i % 13 == 4)
        {
            new->number = 6;
            strcpy(new->value, "six");
        }
        else if(i % 13 == 5)
        {
            new->number = 7;
            strcpy(new->value, "seven");
        }
        else if(i % 13 == 6)
        {
            new->number = 8;
            strcpy(new->value, "eight");
        }
        else if(i % 13 == 7)
        {
            new->number = 9;
            strcpy(new->value, "nine");
        }
        else if(i % 13 == 8)
        {
            new->number = 10;
            strcpy(new->value, "ten");
        }
        else if(i % 13 == 9)
        {
            new->number = 10;
            strcpy(new->value, "jack");
        }
        else if(i % 13 == 10)
        {
            new->number = 10;
            strcpy(new->value, "queen");
        }
        else if(i % 13 == 11)
        {
            new->number = 10;
            strcpy(new->value, "king");
        }
        else
        {
            new->number = 11;
            strcpy(new->value, "ace");
        }

        if(i != 0)
        {
            previous->next = new;
        }
        else
        {
            head = new;
        }
        previous = new;

        if(i == 207)
        {
            new->next = head;
        }
    }

    return head;
}

Card* drawCard(Card** deckPtr, Card* destination[], int* numCards, handType t, int* cardCount){ //destination is the hash array that the drawn card will be insterted into
    int randomNumber, i, flag = 0;
    Card* current, *previous, *utility, *dealerFirstCard;

    waitFor(1);
    for(i = 0; i < 6; i++){ //determine if it is the dealers first card
        if(destination[i]!= NULL)
            flag = 1;
    }

    randomNumber = rand() % (*numCards) + 1; //add 1 because we do not want to stay on the current card
    current = *deckPtr;
    previous = NULL;
    for(i = 0; i < randomNumber; i++){
        previous = current;
        current = current->next;
    }
    if(current == *deckPtr){
        *deckPtr = current->next;
    }
    int hashValue = hashFunction(current->value);
    if(destination[hashValue] == NULL){ //first card in specific bin
        destination[hashValue] = current;
        previous->next = current->next;
        current->next = NULL;
    }
    else{
        utility = destination[hashValue];
        while(utility->next != NULL){
            utility = utility->next;
        }
        utility->next = current;
        previous->next = current->next;
        current->next = NULL;
    }

    if(t == 0){//player
        if(strcmp(current->value, "eight") == 0 || strcmp(current->value, "ace") == 0)
            printf("You drew an %s of %s\n", current->value, current->suit);
        else
            printf("You drew a %s of %s\n", current->value, current->suit);
    }

    else{ //dealer
        if(flag == 0){//dealer's first card
            printf("The dealer received their face-down card\n");
            dealerFirstCard = current;
            *numCards = *numCards - 1;
            return dealerFirstCard;
        }
        else{ //not the dealer's first card
            if(strcmp(current->value, "eight") == 0 || strcmp(current->value, "ace") == 0)
                printf("The dealer drew an %s of %s\n", current->value, current->suit);
            else
                printf("The dealer drew a %s of %s\n", current->value, current->suit);
        }
    }
    *numCards = *numCards - 1;
    if(flag != 0){
        if(current->number >=2 && current->number <=6){
            *cardCount = *cardCount + 1;
        }
        else if(current->number >=7 && current->number <=9){
            //do nothing
        }
        else{
            *cardCount = *cardCount - 1;
        }
    }

    return NULL;
}

int areAces(Card* array[]){
    if (array[2] == NULL) //no aces
        return 0;

    Card* current = array[2]; //see if any left with value 11
    while(current != NULL){
        if(current->number == 11){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

Card* initialDeal(Card* deck, Card* playerHand[], Card* dealerHand[], int numCards, int* cardCount){
    Card* dealerFirstCard = NULL;

    drawCard(&deck, playerHand, &numCards, PLAYER, cardCount);
    //waitFor(1);
    dealerFirstCard = drawCard(&deck, dealerHand, &numCards, DEALER, cardCount);
    //waitFor(1);
    drawCard(&deck, playerHand, &numCards, PLAYER, cardCount);
    //waitFor(1);
    drawCard(&deck, dealerHand, &numCards, DEALER, cardCount);
    //waitFor(1);
    return dealerFirstCard;
}

int getHandValue(Card* array[]){
    Card* current;
    int i, total = 0;

    for(i = 0; i < 6; i++){
        current = array[i];
        while(current!=NULL){
            total += current->number;
            current = current->next;
        }
    }

    return total;
}

int checkBust(Card* array[]){
    int value = getHandValue(array);
    if(value > 21)
        return 1;
    else
        return 0;
}

void modifyAces(Card* array[]){ //change the first ace it hits
    Card* current = array[2];
    while(current->number != 11){//do not need to check for end of list because this function can only be called if at least 1 value in the chain has value 11
        current = current->next;
    }

    current->number = 1;

}

int checkBlackjack(Card* array[]){
    int handValue, i, counter = 0;
    handValue = getHandValue(array);
    Card* current = NULL;
    for(i = 0; i < 6; i++){
        current = array[i];
        while(current != NULL){
            counter++;
            current = current->next;
        }
    }

    if(handValue == 21 && counter == 2){
        return 1;
    }
    else{
        return 0;
    }
}

int countNumCards (Card* hand[]) {

    int i = 0;
    int num = 0;
    Card* currentPtr = NULL;

    for(i = 0; i < 6; i++) {
        currentPtr = hand[i];
        while(currentPtr != NULL) {
            num++;
            currentPtr = currentPtr->next;
        }
    }

    return num;
}

