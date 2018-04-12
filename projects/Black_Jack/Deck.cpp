#ifndef DECK_CPP
#define DECK_CPP

#include "Deck.h"


//Declare global Variables


Deck::Deck()
{

}


void Deck::initializeDeck(int deck[])
{
//Declare local variables.
int Rank = 101;
int i = 0;

//Hearts
for (i = 0 ; i<=13; i++)
{
    deck[i] = Rank++;
}

//Diamonds
for (i = 13 ; i<=26; i++)
{
    deck[i] = Rank++ + 100 - 14;
}

//Clubs
for (i = 26 ; i<=39; i++)
{
    deck[i] = Rank++ + 200 - 28;
}

//Spades
for (i = 39 ; i<=51; i++)
{
    deck[i] = Rank++ + 300 - 42;
}
}



void Deck::dumpDeck(int deck[], int size)
{
//loop through the deck array and print each value.
for(int i = 0; i < size; i++)
{
    cout << i + 1 << ".) " << deck[i] << endl;
}
}


#endif