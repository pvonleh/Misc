

//Include libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <limits>
#include "Player.h"
//Declare namespace

/*
Create a Class Diagram for, and implement a game of Blackjack! Do some research, figure out
the rules of a standard Blackjack table at a Casino, and implement them. You must use C++.
● Working Blackjack Game
○ Player can Hit and Stand. 15pts
○ Dealer “AI” works. 15pts
○ Proper deck of 52 cards. 10pts
● Object-Oriented Design. 25pts
● Documentation. 10pts
● Class Diagram. 25pts
*/
int main()
{
    Player game;
    game.showRules();
    game.chooseLevelOfDificulty();
    game.playOneHand();
    

    return 1;
}

