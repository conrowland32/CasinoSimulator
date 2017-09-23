#include "VPHeader.h"

VPDeckCard* VPShuffleDeck(){
    int i;
    VPDeckCard* new = NULL;
    VPDeckCard* previous = NULL;
    VPDeckCard* head = NULL;
    for(i = 0; i < 52; i++){
        new = malloc(sizeof(VPDeckCard));
        new->next = NULL;
        if(i < 13){
            strcpy(new->suit, "diamonds");
        }
        else if(i >= 13 && i < 26){
            strcpy(new->suit, "clubs");
        }
        else if(i >= 26 && i < 39){
            strcpy(new->suit, "hearts");
        }
        else{
            strcpy(new->suit, "spades");
        }

        if(i % 13 == 0){
            new->id = 2;
            strcpy(new->value, "two");
        }
        else if(i % 13 == 1){
            new->id = 3;
            strcpy(new->value, "three");
        }
        else if(i % 13 == 2){
            new->id = 4;
            strcpy(new->value, "four");
        }
        else if(i % 13 == 3){
            new->id = 5;
            strcpy(new->value, "five");
        }
        else if(i % 13 == 4){
            new->id = 6;
            strcpy(new->value, "six");
        }
        else if(i % 13 == 5){
            new->id = 7;
            strcpy(new->value, "seven");
        }
        else if(i % 13 == 6){
            new->id = 8;
            strcpy(new->value, "eight");
        }
        else if(i % 13 == 7){
            new->id = 9;
            strcpy(new->value, "nine");
        }
        else if(i % 13 == 8){
            new->id = 10;
            strcpy(new->value, "ten");
        }
        else if(i % 13 == 9){
            new->id = 11;
            strcpy(new->value, "jack");
        }
        else if(i % 13 == 10){
            new->id = 12;
            strcpy(new->value, "queen");
        }
        else if(i % 13 == 11){
            new->id = 13;
            strcpy(new->value, "king");
        }
        else{
            new->id = 14;
            strcpy(new->value, "ace");
        }

        if(i != 0){
            previous->next = new;
        }
        else{
            head = new;
        }

        previous = new;

        if(i == 51){
            new->next = head;
        }
    }
    return head;
}

void VPInitialDeal(VPDeckCard** deck, VPHandCard hand[], int* numCards){
    VPDrawCard(deck, hand, numCards, 0);
    VPDrawCard(deck, hand, numCards, 1);
    VPDrawCard(deck, hand, numCards, 2);
    VPDrawCard(deck, hand, numCards, 3);
    VPDrawCard(deck, hand, numCards, 4);
    printVPCards(hand);
}

void VPDrawCard(VPDeckCard** deck, VPHandCard hand[], int* numCards, int index){
    VPDeckCard* current = *deck;
    VPDeckCard* previous = NULL;
    int i;
    int numToStop = (rand()%(*numCards)) + 1;
    for(i = 0; i < numToStop; i++){
        previous = current;
        current = current->next;
    }

    if(current == (*deck)){
        *deck = current->next;
    }

    hand[index].id = current->id;
    strcpy(hand[index].value, current->value);
    strcpy(hand[index].suit, current->suit);

    previous->next = current->next;
    free(current);

    *numCards = *numCards - 1;
}

void printVPCards(VPHandCard hand[]){
    int i;
    for(i = 0; i < 5; i++){
        printf("%s of %s\n", hand[i].value, hand[i].suit);
    }
}

void printWinCondition(VPHandCard hand[]){
    int winCondition = checkWinCondition(hand);
    switch(winCondition){
        case 0:
            printf("nothing");
            break;

        case 1:
            printf("one pair (jacks or better)");
            break;

        case 2:
            printf("two pair");
            break;

        case 3:
            printf("three of a kind");
            break;

        case 4:
            printf("straight");
            break;

        case 5:
            printf("flush");
            break;

        case 6:
            printf("full house");
            break;

        case 7:
            printf("four of a kind");
            break;

        case 8:
            printf("straight flush");
            break;

        case 9:
            printf("royal flush");
            break;
    }
}

void replaceCards(VPDeckCard** deck, VPHandCard hand[], int* numCards){
    if(hand[0].hasBeenReplaced == 1){
        VPDrawCard(deck, hand, numCards, 0);
    }
    if(hand[1].hasBeenReplaced == 1){
        VPDrawCard(deck, hand, numCards, 1);
    }
    if(hand[2].hasBeenReplaced == 1){
        VPDrawCard(deck, hand, numCards, 2);
    }
    if(hand[3].hasBeenReplaced == 1){
        VPDrawCard(deck, hand, numCards, 3);
    }
    if(hand[4].hasBeenReplaced == 1){
        VPDrawCard(deck, hand, numCards, 4);
    }
}

void freeVPDeck(VPDeckCard* deck){
    VPDeckCard* current = deck;
    VPDeckCard* hold = NULL;
    while(current != NULL && current != deck){
        hold = current->next;
        free(current);
        current = hold;
    }
}

double handWinnings(VPHandCard hand[], double playerBet){
    int winCondition = checkWinCondition(hand);
    switch (winCondition){
        case 0:
            return 0;
            break;
        case 1:
            return playerBet;
            break;
        case 2:
            return playerBet * 2;
            break;
        case 3:
            return playerBet * 3;
            break;
        case 4:
            return playerBet * 4;
            break;
        case 5:
            return playerBet * 6;
            break;
        case 6:
            return playerBet * 9;
            break;
        case 7:
            return playerBet * 25;
            break;
        case 8:
            return playerBet * 50;
            break;
        case 9:
            return playerBet * 800;
            break;
    }
    return 0;
}












