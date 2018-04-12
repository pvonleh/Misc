
#ifndef PLAYER_H
#define PLAYER_H
//Include libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Dealer.h"
//Declare namespace
using std::cout;
using std::endl;
using std::cin;
using std::max;

class Player : public Dealer
{
public:
    Player();
    //Prototype functions.
	
	
	int getTopCard(int deck[]);
	int getHandValue(const int hand[]);
	bool playAnotherHand(char&);
	bool userWantsToDraw(char&);
	void initializeDeck(int deck[]);
	void dumpDeck(int deck[], int size);
	
	void whoWins(const int playerHand[], const int dealerHand[]);
	void checkBust(const int playerHand[], const int dealerHand[], char Play);
	void blackJack(const int playerHand[], const int dealerHand[], char Play);
	void naturalBlackJack(const int playerHand[], const int dealerHand[], char Play);
	void playOneHand();
	void scoreBoard(const int playerHand[], const int dealerHand[]);
	void checkSoftOrHard(int playerHand[]);
	void softOrHardAI(int dealerHand[], int playerHand[]);
	void chooseLevelOfDificulty();
	void addToHand(int hand[], int cardToAdd);
	void hitUntilStand(int dealerHand[], int deck[], int playerHand[]);

//    ~Player();
    
};



#endif

