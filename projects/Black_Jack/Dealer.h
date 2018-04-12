
#ifndef DEALER_H
#define DEALER_H
//Include libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>

//Declare namespace
using std::cout;
using std::endl;
using std::cin;
using std::max;

class Dealer
{
public:
    Dealer();
    //Prototype functions.
    int CardValue(int card);
    void ShowCard(int card);
    void shuffle(int deck[], int size);
	void showCards(const int cards[], int numCards, bool hideFirstCard);
	void backdoorKenny(const int hand[]);
	void showRules();
	int getRandomNumber(int low, int high);

    
};



#endif

