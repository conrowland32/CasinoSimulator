#ifndef BLACKJACKHEADER_H
#define BLACKJACKHEADER_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct card
{
    char suit[9];
    char value[7];
    int number;
    struct card* next;
} Card;


typedef enum handtype{PLAYER, DEALER} handType;

Card* shuffleDeck (void);
void printDeck(Card* head, int numCards);
int hashFunction(char value[]);
void initializeHand(Card* array[]);
Card* drawCard(Card** deckPtr, Card* destination[], int* numCards, handType t, int* cardCount);
Card* initialDeal(Card* deck, Card* playerHand[], Card* dealerHand[], int numCards, int* cardCount);
int getHandValue(Card* array[]);
void dealerAction(Card** deckPtr, Card* array[], int* numCards, int* cardCount);
int areAces(Card* array[]);
int checkBust(Card* array[]);
void modifyAces(Card* array[]);
void waitFor(int seconds);
int printUserMenu(Card* array[]);
void printCards(Card* array[]);
void printDealerCards(Card* array[], Card* firstCard);
int checkBlackjack(Card* array[]);
int findWinner(Card* playerHand[], Card* dealerHand[]);
void payout(double* balance, int bet, int winner, Card* playerHand[]);
void freeHands(Card* playerHand[], Card* dealerHand[]);
void getCardCountAdvice(int cardCount);
int getResetNumber();
void freeDeck(Card* deck);
double blackjack(double playerBalance);
int getStrategy(Card* playerHand[], Card* dealerHand[], Card* facedownCard);
int getFaceupCard (Card* hand[], Card* facedownCard);
int countNumCards (Card* hand[]);

#endif // BLACKJACKHEADER_H
