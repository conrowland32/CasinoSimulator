#ifndef VPHEADER_H
#define VPHEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vpdeckcard {
    char suit[9];
    char value[7];
    int id;
    struct vpdeckcard* next;
} VPDeckCard;

typedef struct vphandcard{
    char suit[9];
    char value[7];
    int id;
    int hasBeenReplaced;
} VPHandCard;

VPDeckCard* VPShuffleDeck();
double videoPoker(double playerBalance);
void initializeVPHand(VPHandCard hand[]);
void VPInitialDeal(VPDeckCard** deck, VPHandCard hand[], int* numCards);
void VPDrawCard(VPDeckCard** deck, VPHandCard hand[], int* numCards, int index);
void printVPCards(VPHandCard hand[]);
int checkWinCondition(VPHandCard hand[]);
int checkPair(VPHandCard hand[]);
int checkTwoPair(VPHandCard hand[]);
int checkThreeOfAKind(VPHandCard hand[]);
int checkStraight(VPHandCard hand[]);
int checkFlush(VPHandCard hand[]);
int checkFullHouse(VPHandCard hand[]);
int checkFourOfAKind(VPHandCard hand[]);
int checkStraightFlush(VPHandCard hand[]);
int checkRoyalFlush(VPHandCard hand[]);
void printWinCondition(VPHandCard hand[]);
void waitFor(int seconds);
void printCardChangeStatus(VPHandCard hand[]);
void changeCardsMenu();
void replaceCards(VPDeckCard** deck, VPHandCard hand[], int* numCards);
void freeVPDeck(VPDeckCard* deck);
double handWinnings(VPHandCard hand[], double playerBet);

#endif // VPHEADER_H
