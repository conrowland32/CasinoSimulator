#include "blackjackHeader.h"

//This function splits all possible cards into a hash table of size 6
//It also guarantees that the index that will hold "aces" will be unused by the other card types
//The remaining 12 card types are distributed relatively evenly amongst the remaining 5 hash indexes
int hashFunction(char value[]){
    int i;
    int length = strlen(value); //get length of string
    int total = 0;
    for(i = 0; i < length; i++){ //loop through all characters
        total += value[i]*(pow(5,i)); //this is the hashing, it multiplies the ASCII value of the char by 5 to the power i
    }

    int hashvalue = total % 6; //take the running total and split into 6 hash indexes
    //printf("\nThe hashvalue for %s is %d.", value, hashvalue); //testing purposes

    return hashvalue; //return
}

//pow(3,i) and modulus 7 gives only ace in a bin, but a bin is also unused
//pow(3,i) and modulus 8 gives only ace in a bin, but a bin is also unused
//pow(5,i) and modulus 6 gives only ace in a bin, and all other bins are used more than once
