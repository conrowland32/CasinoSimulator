#include "VPHeader.h"

int checkWinCondition(VPHandCard hand[]){
    if(checkRoyalFlush(hand) == 1)
        return 9;
    if(checkStraightFlush(hand) == 1)
        return 8;
    if(checkFourOfAKind(hand) == 1)
        return 7;
    if(checkFullHouse(hand) == 1)
        return 6;
    if(checkFlush(hand) == 1)
        return 5;
    if(checkStraight(hand) == 1)
        return 4;
    if(checkThreeOfAKind(hand) == 1)
        return 3;
    if(checkTwoPair(hand) == 1)
        return 2;
    if(checkPair(hand) == 1)
        return 1;

    return 0;
}

int checkPair(VPHandCard hand[]){
    if(hand[0].id == hand[1].id){
        if(hand[0].id >= 11)
            return 1;
    }
    if(hand[0].id == hand[2].id){
        if(hand[0].id >= 11)
            return 1;
    }
    if(hand[0].id == hand[3].id){
        if(hand[0].id >= 11)
            return 1;
    }
    if(hand[0].id == hand[4].id){
        if(hand[0].id >= 11)
            return 1;
    }
    if(hand[1].id == hand[2].id){
        if(hand[1].id >= 11)
            return 1;
    }
    if(hand[1].id == hand[3].id){
        if(hand[1].id >= 11)
            return 1;
    }
    if(hand[1].id == hand[4].id){
        if(hand[1].id >= 11)
            return 1;
    }
    if(hand[2].id == hand[3].id){
        if(hand[2].id >= 11)
            return 1;
    }
    if(hand[2].id == hand[4].id){
        if(hand[2].id >= 11)
            return 1;
    }
    if(hand[3].id == hand[4].id){
        if(hand[3].id >= 11)
            return 1;
    }

    return 0;
}

int checkTwoPair(VPHandCard hand[]){
    if(hand[0].id == hand[1].id){
        if(hand[2].id == hand[3].id)
            return 1;
        if(hand[2].id == hand[4].id)
            return 1;
        if(hand[3].id == hand[4].id)
            return 1;
    }
    if(hand[0].id == hand[2].id){
        if(hand[1].id == hand[3].id)
            return 1;
        if(hand[1].id == hand[4].id)
            return 1;
        if(hand[3].id == hand[4].id)
            return 1;
    }
    if(hand[0].id == hand[3].id){
        if(hand[1].id == hand[2].id)
            return 1;
        if(hand[2].id == hand[4].id)
            return 1;
        if(hand[1].id == hand[4].id)
            return 1;
    }
    if(hand[0].id == hand[4].id){
        if(hand[1].id == hand[2].id)
            return 1;
        if(hand[2].id == hand[3].id)
            return 1;
        if(hand[1].id == hand[3].id)
            return 1;
    }
    if(hand[1].id == hand[2].id){
        if(hand[0].id == hand[3].id)
            return 1;
        if(hand[3].id == hand[4].id)
            return 1;
        if(hand[0].id == hand[4].id)
            return 1;
    }
    if(hand[1].id == hand[3].id){
        if(hand[0].id == hand[2].id)
            return 1;
        if(hand[2].id == hand[4].id)
            return 1;
        if(hand[0].id == hand[4].id)
            return 1;
    }
    if(hand[1].id == hand[4].id){
        if(hand[0].id == hand[2].id)
            return 1;
        if(hand[2].id == hand[3].id)
            return 1;
        if(hand[0].id == hand[3].id)
            return 1;
    }
    if(hand[2].id == hand[3].id){
        if(hand[0].id == hand[1].id)
            return 1;
        if(hand[1].id == hand[4].id)
            return 1;
        if(hand[0].id == hand[4].id)
            return 1;
    }
    if(hand[2].id == hand[4].id){
        if(hand[0].id == hand[1].id)
            return 1;
        if(hand[1].id == hand[3].id)
            return 1;
        if(hand[0].id == hand[3].id)
            return 1;
    }
    if(hand[3].id == hand[4].id){
        if(hand[0].id == hand[1].id)
            return 1;
        if(hand[1].id == hand[2].id)
            return 1;
        if(hand[0].id == hand[2].id)
            return 1;
    }

    return 0;
}

int checkThreeOfAKind(VPHandCard hand[]){
    if(hand[0].id == hand[1].id && hand[1].id == hand[2].id)
        return 1;
    if(hand[0].id == hand[1].id && hand[1].id == hand[3].id)
        return 1;
    if(hand[0].id == hand[1].id && hand[1].id == hand[4].id)
        return 1;
    if(hand[0].id == hand[2].id && hand[2].id == hand[3].id)
        return 1;
    if(hand[0].id == hand[2].id && hand[2].id == hand[4].id)
        return 1;
    if(hand[0].id == hand[3].id && hand[3].id == hand[4].id)
        return 1;
    if(hand[1].id == hand[2].id && hand[2].id == hand[3].id)
        return 1;
    if(hand[1].id == hand[2].id && hand[2].id == hand[4].id)
        return 1;
    if(hand[1].id == hand[3].id && hand[3].id == hand[4].id)
        return 1;
    if(hand[2].id == hand[3].id && hand[3].id == hand[4].id)
        return 1;

    return 0;
}

int checkStraight(VPHandCard hand[]){
    int handCopy[5];
    int i, j, hold;

    for(i = 0; i < 5; i ++){
        handCopy[i] = hand[i].id;
    }

    for(j = 0; j < 4; j++){
        for(i = 0; i < 5; i++){
            if(handCopy[i] > handCopy[i+1]){
                hold = handCopy[i+1];
                handCopy[i+1] = handCopy[i];
                handCopy[i] = hold;
            }
        }
    }

    if(handCopy[0] + 1 == handCopy[1]){
        if(handCopy[1] + 1 == handCopy[2]){
            if(handCopy[2] + 1 == handCopy[3]){
                if(handCopy[3]+ 1 == handCopy[4]){
                    return 1;
                }
            }
        }
    }

    return 0;
}

int checkFlush(VPHandCard hand[]){
    if(strcmp(hand[0].suit, hand[1].suit)== 0 && strcmp(hand[1].suit, hand[2].suit) == 0){
        if(strcmp(hand[2].suit, hand[3].suit) == 0 && strcmp(hand[3].suit, hand[4].suit) == 0){
            return 1;
        }
    }

    return 0;
}

int checkFullHouse(VPHandCard hand[]){
    if(hand[0].id == hand[1].id && hand[1].id == hand[2].id){
        if(hand[3].id == hand[4].id)
            return 1;
    }
    if(hand[0].id == hand[1].id && hand[1].id == hand[3].id){
        if(hand[2].id == hand[4].id)
            return 1;
    }
    if(hand[0].id == hand[1].id && hand[1].id == hand[4].id){
        if(hand[2].id == hand[3].id)
            return 1;
    }
    if(hand[0].id == hand[2].id && hand[2].id == hand[3].id){
        if(hand[1].id == hand[4].id)
            return 1;
    }
    if(hand[0].id == hand[2].id && hand[2].id == hand[4].id){
        if(hand[1].id == hand[3].id)
            return 1;
    }
    if(hand[0].id == hand[3].id && hand[3].id == hand[4].id){
        if(hand[1].id == hand[2].id)
            return 1;
    }
    if(hand[1].id == hand[2].id && hand[2].id == hand[3].id){
        if(hand[0].id == hand[4].id)
            return 1;
    }
    if(hand[1].id == hand[2].id && hand[2].id == hand[4].id){
        if(hand[0].id == hand[3].id)
            return 1;
    }
    if(hand[1].id == hand[3].id && hand[3].id == hand[4].id){
        if(hand[0].id == hand[2].id)
            return 1;
    }
    if(hand[2].id == hand[3].id && hand[3].id == hand[4].id){
        if(hand[0].id == hand[1].id)
            return 1;
    }


    return 0;
}

int checkFourOfAKind(VPHandCard hand[]){
    if(hand[0].id == hand[1].id){
        if(hand[1].id == hand[2].id){
            if(hand[2].id == hand[3].id){
                return 1;
            }
        }
    }
    if(hand[0].id == hand[1].id){
        if(hand[1].id == hand[2].id){
            if(hand[2].id == hand[4].id){
                return 1;
            }
        }
    }
    if(hand[0].id == hand[1].id){
        if(hand[1].id == hand[3].id){
            if(hand[3].id == hand[4].id){
                return 1;
            }
        }
    }
    if(hand[0].id == hand[2].id){
        if(hand[2].id == hand[3].id){
            if(hand[3].id == hand[4].id){
                return 1;
            }
        }
    }
    if(hand[1].id == hand[2].id){
        if(hand[2].id == hand[3].id){
            if(hand[3].id == hand[4].id){
                return 1;
            }
        }
    }
    return 0;
}

int checkStraightFlush(VPHandCard hand[]){
    if(checkStraight(hand) == 1 && checkFlush(hand) == 1)
        return 1;

    return 0;
}

int checkRoyalFlush(VPHandCard hand[]){
    if(checkFlush(hand) == 1){
        int handCopy[5];
        int i, j, hold;

        for(i = 0; i < 5; i ++){
            handCopy[i] = hand[i].id;
        }

        for(j = 0; j < 4; j++){
            for(i = 0; i < 5; i++){
                if(handCopy[i] > handCopy[i+1]){
                    hold = handCopy[i+1];
                    handCopy[i+1] = handCopy[i];
                    handCopy[i] = hold;
                }
            }
        }

        if(handCopy[0] == 10){
            if(handCopy[1] == 11){
                if(handCopy[2] == 12){
                    if(handCopy[3] == 13){
                        if(handCopy[4] == 14)
                            return 1;
                    }
                }
            }
        }
    }

    return 0;
}
















