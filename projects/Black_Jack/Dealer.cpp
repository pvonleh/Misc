#ifndef DEALER_CPP
#define DEALER_CPP

#include "Dealer.h"


//Declare global Variables
//int topCard = 0;
float dealer_win = 1.00;
//int level;

Dealer::Dealer()
{

}


void Dealer::showRules()
{
    //Display information.
    cout << "//////////////////////////////////////////////////////////" << endl;
    cout << "////        Welcome to the game of Blackjack!        /////" << endl;
    cout << "////              Choose Level of Difficulty         /////" << endl;
    cout << "//// _____________________________________________   /////" << endl;
    cout << "//// | You may choose to play with a beginner or   | /////" << endl;
    cout << "//// | expert Dealer:                              | /////" << endl;
    cout << "//// | o (Beginner) - Dealer stands at a soft 17   | /////" << endl;
    cout << "//// |                and has no AI.               | /////" << endl;
    cout << "//// | o (Advanced)   - Dealer hits at a soft 17   | /////" << endl;
    cout << "//// |                and has AI.                  | /////" << endl;
    cout << "//// |_____________________________________________| /////" << endl;
    cout << "//////////////////////////////////////////////////////////" << endl;
}


int Dealer::getRandomNumber(int low, int high) {
    static bool firstTime=true;
    int randNum;

    //if first time called, seed random number generator
    if (firstTime) {
        srand( static_cast<unsigned int>(time(NULL)) );
        firstTime=false;
    }

    //generate random number between given low and high values (inclusive)
    randNum = rand() % (high-low+1) + low;

    return randNum;
}


void Dealer::shuffle(int deck[], int size)
{
//Loop through deck an absurd amount of loops.
for(int i = 0; i < 500; i++)
{
    //Define local variables
    int T1 = 0;
    int R1 = getRandomNumber(0, size);
    int R2 = getRandomNumber(0, size);

    //Clone first card for safe keeping
    //Replace first card with a new card
    //Replace the new card with the old card clone
    T1   = deck[R1];
    deck[R1] = deck[R2];
    deck[R2] = T1;
}
}


int Dealer::CardValue(int card)
{
//Declare local variable
int cardVal;

//Get the card's background 10s value and assign the card a point value
switch(card % 100)
{
    case 1:
        cardVal = 11;
        break;
    case 11:
    case 12:
    case 13:
        cardVal = 10;
        break;
    case 14:
        cardVal = 1;
        break;
    //For non-face cards, just use their backround 10s value as point value.
    default:
    cardVal = (card % 100);
}
return cardVal;
}



void Dealer::ShowCard(int card)
{
//Show nothing for non cards (ie.0)
if(card == 0)
{
    cout << "";
}
//Define Ranks.
else
{
    switch(card % 100)
    {
        case 1:
            cout << "A";
            break;
        case 11:
            cout << "J";
            break;
        case 12:
            cout << "K";
            break;
        case 13:
            cout << "Q";
            break;
        case 14://14 is a value created in checkSoftOrHard
            cout << "A";
            break;

        //For non-face cards, just use their 10s value as rank.
        default:
            cout << card % 100;
    }
}

//Show nothing for non cards (ie.0)
if(card == 0)
{
    cout << "";
}
//Define Suits.
else
{
    //Hearts
    if((card >= 101) && (card <=114))
    {
        cout << static_cast<char>(3);
    }

    //Diamonds
    else if ((card >= 201) && (card <= 214))
    {
        cout << static_cast<char>(4);
    }

    //Clubs
    else if ((card >= 301) && (card <= 314))
    {
        cout << static_cast<char>(5);
    }

    //Spades
    else if ((card >= 401) && (card <= 414))
    {
        cout << static_cast<char>(6);
    }
}
}


void Dealer::showCards(const int deck[], int numCards, bool hideFirstCard)
{
//Hide dealer's first card if true.
if(hideFirstCard)
{
    cout << "** ";
}

//Show dealer's first card if false.
else
{
    ShowCard(deck[0]);
    cout << " ";
}

//Display all the cards in the deck or hand
//by showing their rank and suit graphic.
for(int i = 1; i < numCards; i++)
{
    //Show cards
    if(deck[i] != 0)
    {
        ShowCard(deck[i]);
        cout << " ";
    }

    //Show nothing for non cards (ie. 0).
    else
    {
        cout << "";
    }
}
}



void Dealer::backdoorKenny(const int hand[])
{
    //If index 0 is a 10 and index 1 is an ace
    if((CardValue(hand[0])%100 == 10)&&(CardValue(hand[1])%100 == 11))//I did not use 1 as an argument because 11 is the default
                                                                       //value and this happens before the user can choose.
    {
        //Display message and compute new winnings multiplier.
        cout << "\n\n";
        cout << "You pulled a Backdoor Kenny!\n" << endl;
        cout << "Win an additional 1:4 payout\n" << endl;
        dealer_win = dealer_win + .25;
        cout << "Winnings multiplier: " << dealer_win << endl;
    }
}









#endif