#include "blackjackHeader.h"

double blackjack(double playerBalance){ //performs all of blackjack, returns playerbalance when the game is done

    printf("\n\n**********************************************************\n");
    printf("**********************************************************\n");
    printf("**                                                      **\n");
    printf("**                 WELCOME TO BLACKJACK!                **\n");
    printf("**                                                      **\n");
    printf("**               Here are the house rules:              **\n");
    printf("**                                                      **\n");
    printf("** (1) Dealer stays on 17 regardless of hard or soft    **\n");
    printf("** (2) This game is played with 4 decks of cards        **\n");
    printf("** (3) All other typical rules of BlackJack still apply **\n");
    printf("**                                                      **\n");
    printf("**********************************************************\n");
    printf("**********************************************************\n\n");

    Card* playerHand[6];
    Card* dealerHand[6];
    initializeHand(playerHand);
    initializeHand(dealerHand);

    Card* deck, *dealerFirstCard;
    deck = shuffleDeck();
    int menuSelection, numCards = 208, playerActionNeeded = 1;
    int winner; //winner is 1 if player wins, 0 if dealer wins, -1 if tie

    int playAnotherHand = 1, playerBet = 5, betMore, repeatBet, cardCount = 0, didDouble = 0, handCount = 0;
    //while loop for multiple hands
    printf("You have $%4.2lf in chips.\n", playerBalance);
    printf("The minimum bet for this table is $5. Would you like to bet more?\n");
    printf("1. Yes\n2. No\n");
    scanf("%d", &betMore);
    while(betMore < 1 || betMore > 2){
        printf("Not a valid input\n1. To bet more\n2. To bet minimum ($5)\n");
        scanf("%d", &betMore);
    }

    if(betMore == 1){
        printf("What bet would you like to place?\n");
        scanf("%d" , &playerBet);
        while(playerBet < 5 || playerBet > playerBalance){
            printf("Cannot place bet. Bet must be between $5-$%4.2lf." , playerBalance);
            printf(" Place a valid bet:\n");
            scanf("%d", &playerBet);
        }
    }

    int handsToResetDeck = getResetNumber();
    while(playAnotherHand == 1){
        if(handCount == handsToResetDeck){
            printf("\nWe have hit the cut card. Deck is being shuffled.\n\n");
            freeDeck(deck);
            deck = shuffleDeck();
            handsToResetDeck = getResetNumber();
            //printf("\n%d is how many hands to be played now before reset.\n", handsToResetDeck);
            handCount = 0;
            cardCount = 0;
            waitFor(1);
        }
        handCount++;
        printf("\nYou bet $%d. Hand starting soon.", playerBet);
        waitFor(1);
        printf(".");
        waitFor(1);
        printf(".");
        printf("\n\n");
        playerActionNeeded = 1;
        freeHands(playerHand, dealerHand);
        dealerFirstCard = initialDeal(deck, playerHand, dealerHand, numCards, &cardCount);
        if (checkBlackjack(dealerHand) == 1){
            waitFor(1);
            printf("\nThe dealer has Blackjack. Dealer wins.\n");
            winner = 0;
        }

        else if(checkBlackjack(playerHand) == 1){
            waitFor(1);
            printf("\nYou have Blackjack. You win.\n");
            winner = 1;
        }

        else{
            while(playerActionNeeded == 1){
                waitFor(1);
                menuSelection = printUserMenu(playerHand);
                waitFor(1);
                switch(menuSelection){
                    case 1: //hit
                        printf("\n");
                        drawCard(&deck, playerHand, &numCards, PLAYER, &cardCount);
                        if(checkBust(playerHand) == 1){
                            if(areAces(playerHand) == 1){
                                modifyAces(playerHand); //change 1 ace
                            }
                            else{
                                waitFor(1);
                                printf("You have busted.");
                                playerActionNeeded = 0;
                            }
                        }
                        break;

                    case 2: //stay
                        playerActionNeeded = 0;
                        break;

                    case 3: //double
                        if(playerBalance/2 < playerBet){
                            printf("\nYou do not have enough chips to double here\n.");
                            //ask hit or stay
                        }
                        else{
                            playerBet *= 2;
                            printf("\nDoubling your bet to $%d\n", playerBet);
                            drawCard(&deck, playerHand, &numCards, PLAYER, &cardCount);
                            waitFor(1);
                            didDouble = 1;
                            playerActionNeeded = 0;
                        }
                        break;

                    case 4: //view your cards
                        printf("\nYour cards are:\n");
                        printCards(playerHand);
                        break;

                    case 5: //view dealers cards
                        printf("\nThe dealer's cards are:\n");
                        printf("*facedown card*\n");
                        printDealerCards(dealerHand, dealerFirstCard);
                        break;

                    case 6: //basic strategy
                        if(getStrategy(playerHand, dealerHand, dealerFirstCard) == 0)
                            printf("\nBasic Strategy recommends hitting");
                        else if(getStrategy(playerHand, dealerHand, dealerFirstCard) == 1)
                            printf("\nBasic Strategy recommends standing");
                        else if(getStrategy(playerHand, dealerHand, dealerFirstCard) == 2) {
                            if(countNumCards(playerHand) == 2)
                                printf("\nBasic Strategy recommends doubling");
                            else if(getHandValue(playerHand) == 18)
                                printf("\nBasic Strategy recommends standing");
                            else printf("\nBasic Strategy recommends hitting");
                        }
                        break;
                }
            }
            printf("\n");
            waitFor(1);
            if(checkBust(playerHand) == 0){
                dealerAction(&deck, dealerHand, &numCards, &cardCount);
            }
            printf("\n");

            waitFor(1);
            printf("\n");
            winner = findWinner(playerHand, dealerHand);
        }
        waitFor(1);
        payout(&playerBalance, playerBet, winner, playerHand);

        if(didDouble == 1){
            playerBet /= 2;
            didDouble = 0;
        }

        waitFor(1);
        printf("\nYou now have $%4.2lf.\n", playerBalance);
        waitFor(2);

        if(playerBalance < 5){
            playAnotherHand = 0;
            printf("You do not have enough money to place the minimum bet.\n");
            printf("\nThank you for playing Blackjack!\n\n");
            waitFor(1);
        }
        else{
            printf("\nWould you like to play another hand?\n1. Yes\n2. No\n");
            scanf("%d", &playAnotherHand);
            while(playAnotherHand < 1 || playAnotherHand > 2){
                printf("Invalid input.\n1. To play another hand\n2. To quit\n");
                scanf("%d", &playAnotherHand);
            }
            if(playAnotherHand == 1){
                printf("\nWould you like to repeat your last bet of $%d?", playerBet);
                printf("\n1. Yes");
                printf("\n2. No");
                printf("\n3. View current card count\n");
                scanf("%d", &repeatBet);
                while(repeatBet < 1 || repeatBet > 3){
                    printf("Invalid input.\n1. To repeat bet of $%d\n2. To change bet\n3. View card count\n", playerBet);
                    scanf("%d", &repeatBet);
                }
                if(repeatBet == 1){
                    if(playerBet > playerBalance){
                        printf("You do not have enough money to place a bet of $%d.\n", playerBet);
                        repeatBet = 2;
                    }
                }
                if(repeatBet == 2){
                    printf("What bet would you like to place?\n");
                    scanf("%d" , &playerBet);
                    while(playerBet < 5 || playerBet > playerBalance){
                        printf("\nCannot place bet. Bet must be between $5-$%4.2lf.\n", playerBalance);
                        printf("Enter a valid bet:\n");
                        scanf("%d", &playerBet);
                    }
                }

                else if(repeatBet == 3){
                    getCardCountAdvice(cardCount);
                    waitFor(1);
                    printf("Would you like to repeat your last bet of $%d?", playerBet);
                    printf("\n1. Yes");
                    printf("\n2. No\n");
                    scanf("%d", &repeatBet);
                    while(repeatBet < 1 || repeatBet > 2){
                        printf("Invalid input.\n1. To repeat bet of $%d\n2. To change bet\n", playerBet);
                        scanf("%d", &repeatBet);
                    }
                    if(repeatBet == 1){
                        if(playerBet > playerBalance){
                            printf("You do not have enough money to place a bet of $%d.\n", playerBet);
                            repeatBet = 2;
                        }
                    }
                    if(repeatBet == 2){
                        printf("What bet would you like to place?\n");
                        scanf("%d" , &playerBet);
                        while(playerBet < 5 || playerBet > playerBalance){
                            printf("Cannot place bet. Bet must be between $5-$%4.2lf.\n", playerBalance);
                            printf("Enter a valid bet:\n");
                            scanf("%d", &playerBet);
                        }
                    }
                }
            }

            else{
                printf("\nThank you for playing Blackjack!\n\n");
            }
        }
    }//END while for multiple hands
    waitFor(2);
    return playerBalance;
}
