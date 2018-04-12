
#ifndef DECK_H
#define DECK_H
//Include libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Dealer.h"
//#include "Player.h"
//Declare namespace
using std::cout;
using std::endl;
using std::cin;
using std::max;

class Deck : public Dealer//, public Player
{
public:
    Deck();
    //Prototype functions.
	

	void initializeDeck(int deck[]);
	void dumpDeck(int deck[], int size);
	

    
};



#endif

