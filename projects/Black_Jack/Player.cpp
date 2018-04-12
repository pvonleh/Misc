#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.h"
#include "Deck.h"

//Declare global Variables
int topCard = 0;
float win = 1.00;
int level;


Player::Player()
{

}


void Player::chooseLevelOfDificulty()
{
//Prompt user and store input
cout << "\n";
cout << "Level of Difficulty: Beginner (1), Advanced (2). ";
cin >> level;
cout << "\n";

//If input is not a 1..
if(level != 1)
{
    //...or a 2.
    if(level != 2)
    {
        //Clears input error flags and removes everything currently in the input buffer.
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //Display error message and restart function.
        cout << "Please enter your level of difficulty using the number 1 or 2." << endl;
        chooseLevelOfDificulty();
    }
}
}

void Player::playOneHand()
{
//Declare local variable
char Play = 'N';

//Start the game at least once and repeat while Player wants to.
do
{
    //Declare local variable
    char Draw = 'H';

    //Declare, initialize and shuffle the deck.
    int deck[52];
    initializeDeck(deck);
    shuffle(deck, 51);

    //Declare and initialize Player and Dealer hands.
    int playerHand[10] = {0};
    int dealerHand[10] = {0};

    //Deal first round
    addToHand(playerHand, getTopCard(deck));
    addToHand(dealerHand, getTopCard(deck));
    addToHand(playerHand, getTopCard(deck));
    addToHand(dealerHand, getTopCard(deck));

    //Display an explanation of what is happening
    cout << "//////////////////////////////////////////////////////////" << endl;
    cout << "\n" << endl;
    cout << "The Dealer shuffled and dealt you each your cards. ";
    cout << "\n" << endl;

    //Check for an automatic win.
    naturalBlackJack(playerHand, dealerHand, 'y');
    blackJack(playerHand, dealerHand, 'Y');

    //Display Player and Dealer hands
    cout << "Your hand:" << endl;
    showCards(playerHand, 10, false);
    cout << "\n\nDealer's hand:" << endl;
    showCards(dealerHand, 10, true);

    //If Player has an Ace, see if Player want's to have a soft or hard hand.
    checkSoftOrHard(playerHand);

    //Check if user wants to hit
    while (userWantsToDraw(Draw))
    {
        //Deal Player a card
        //and display an explanation of what is happening
        addToHand(playerHand, getTopCard(deck));
        cout << "The Dealer dealt you another card.\n" << endl;

        //Display Player's updated hand
        cout << "Your hand:" << endl;
        showCards(playerHand, 10, false);

        //If Player has an Ace, see if Player want's to have a soft or hard hand.
        checkSoftOrHard(playerHand);

        //Check to see if anyone lost
        checkBust(playerHand, dealerHand, 'y');

        //Check to see if anyone won
        blackJack(playerHand, dealerHand, 'Y');
    }

    //Dealer hits until at a soft 17
    hitUntilStand(dealerHand, deck, playerHand);
    cout << endl;

    //Check to see if anyone lost
    checkBust(playerHand, dealerHand, 'Y');

    //Check to see if anyone won
    blackJack(playerHand, dealerHand, 'Y');

    //Compare scores and determine winner
    whoWins(playerHand, dealerHand);
    cout << endl;

    //Display updated winnings multiplier
    cout << "Winnings multiplier: " << win << endl;
}
while (playAnotherHand(Play));
}


void Player::initializeDeck(int deck[])
{
//Declare local variables.
int RANK = 101;
int i = 0;
int HEARTS = 13;
int DIAMONDS = 26;
int CLUBS = 39;
int SPADES = 51;
//Hearts
for (i = 0 ; i<=HEARTS; i++)
{
    deck[i] = RANK++;
}

//Diamonds
for (i = HEARTS ; i<=DIAMONDS; i++)
{
    deck[i] = RANK++ + 100 - 14;
}

//Clubs
for (i = DIAMONDS ; i<=CLUBS; i++)
{
    deck[i] = RANK++ + 200 - 28;
}

//Spades
for (i = CLUBS ; i<=SPADES; i++)
{
    deck[i] = RANK++ + 300 - 42;
}
}


void Player::dumpDeck(int deck[], int size)
{
//loop through the deck array and print each value.
for(int i = 0; i < size; i++)
{
    cout << i + 1 << ".) " << deck[i] << endl;
}
}


int Player::getTopCard(int deck[])
{
//Loop through the deck
for(int i = 0; i < 51; i++)
{
    //Find a card that isn't empty
    if(deck[i] != 0)
    {
        //Clone card for safe keeping
        //Replace first card with the empty card value
        //Return the clone of the card
        topCard = deck[i];
        deck[i] = 0;
        return topCard;
    }
}
}

void Player::addToHand(int hand[], int cardToAdd)
{
//Loop through the hand
for(int i = 0; i < 9; i++)
{
    //If there is an empty card spot
    if(hand[i] == 0)
    {
        //Replace it with the card to add
        hand[i] = cardToAdd;
        break;//Only do this once by breaking the loop
    }
}
}


void Player::hitUntilStand(int dealerHand[], int deck[], int playerHand[])
{
//Loop through Dealer's hand
for(int i = 0; i < 9; i++)
{
    /*
    //If Player is an Expert
    if( level == 2)
    {
        //Loop through Dealer's hand
        for( int i = 0; i < 9; i++)
        {
            //Find a default Ace (11pts)
            if(CardValue(dealerHand[i]) == 11)
            {
                //Change Aces from default 11(soft) to 1(hard)
                dealerHand[i] = dealerHand[i] + 13; // A hard Ace (worth 1 point) has a background value ending in 14
            }
        }
    }

    //do nothing and clear this if of an else for the next if.
    else;
    */

    //If Dealer must hit
    if(getHandValue(dealerHand) < 17)
    {
        //If Player chose Beginner level dealer stands at soft 17
        if(level == 1)
        {
                //...add a card to the hand
                addToHand(dealerHand, getTopCard(deck));
        }

        //If Player chose Expert level dealer stands at Hard 17
        else if( level == 2)
        {
            //...add a card to the hand
            addToHand(dealerHand, getTopCard(deck));

            //Ensure Aces are handled intelligently to beat Player
            softOrHardAI(dealerHand, playerHand);
        }
    }
    //Display how many cards Dealer hit if Dealer has 17 or more points...
    else
    {
        //Dealer didn't hit to get to 17
        if(i == 0)
        {
            cout << "The Dealer stands." << endl;
            break;
        }
        //Dealer hit once to get to 17
        else if(i == 1)
        {
            cout << "The Dealer hit a card and stands." << endl;
            break;
        }
        //Dealer hit more than once to get to 17
        else
        {
            cout << "The Dealer hit " << i << " cards and stands." << endl;
            break;
        }
    }

    //Run dealer AI again if player chose to play Expert
    //This is called again for the sake of redundancy.
    if(level == 1);
    else if( level == 2)
    {
        softOrHardAI(dealerHand, playerHand);
    }
}
}

int Player::getHandValue(const int hand[])
{
//Declare local variables
int addCardValues = 0;

//Loop through the hand and add up the card values
for(int i = 0; i < 9; i++)
{
    addCardValues = addCardValues + CardValue(hand[i]);
}

//Give the sum of the card values as the hand value
return addCardValues;
}


bool Player::playAnotherHand(char& Play)
{
//Prompt user to see if they would like to play another hand.
cout << endl << "\nWould you like to play another hand? (Y/N) ";
cin >> Play;
cout << "\n" << endl;

//Go back to the main game logic function to restart if they do.
if(Play == 'y' || Play == 'Y')
{
    playOneHand();
    return(true);
}
//If they don't, exit the program.
else
{
    return(false);
}
}

bool Player::userWantsToDraw(char& Draw)
{
//Prompt user to see if they would like to enter a new time.
cout << endl << "\nWould you like to hit or stand? (H/S) ";
cin >> Draw;
cout << "\n";

//If they do, return true and start the loop to draw another card.
if(Draw == 'h' || Draw == 'H')
{
        return(true);
}
//If they don't, skip the loop.
else
{
    return(false);
}
}


void Player::whoWins(const int playerHand[], const int dealerHand[])
{
//Declare local variables
int playerScore = getHandValue(playerHand);
int dealerScore = getHandValue(dealerHand);

//Display the scoreboard
scoreBoard(playerHand, dealerHand);

//win tree
//If Player scores less than 22
if( (playerScore < 22)
    //If Player's score is better than Dealer's score
    && (playerScore > dealerScore)
    //If Player's score is under 22 but Dealer's score is over 21
    || ( (dealerScore > 21)
        && (playerScore < 22) ) )
{
    //Display message and compute new winnings multiplier
    cout << "\n";
    cout << "You win!" << endl;
    win++;
}
//loos tree
//If you don't win, you lose or tie.
else
{
    //Tie
    //Display message
    if(playerScore == dealerScore)
    {
        cout << "\n";
        cout << "Push in the Dealer's favor. 0:1 payout." << endl;
    }

    //loose
    //Display message and compute new winnings multiplier
    else
    {
        cout << "\n";
        cout << "You lose." << endl;
        win--;
    }
}
}


void Player::checkBust(const int playerHand[], const int dealerHand[], char Play)
{
//Define local variables.
int playerScore = getHandValue(playerHand);
int dealerScore = getHandValue(dealerHand);

//Check if Player busts.
//Display message, compute new winnings multiplier, ask to play another hand.
if(playerScore > 21)
{
    cout << "You bust with " << getHandValue(playerHand) << " points." << endl;
    cout << "\n" << endl;
    win--;
    cout << "Winnings multiplier: " << win << endl;
    playAnotherHand(Play);
}

//Check if Dealer busts.
//Display message, compute new winnings multiplier, ask to play another hand.
else if(dealerScore > 21)
{
    scoreBoard(playerHand, dealerHand);
    cout << "\n" << endl;
    cout << "The Dealer went bust. You Win!" << endl;
    cout << "\n" << endl;
    win++;
    cout << "Winnings multiplier: " << win << endl;
    playAnotherHand(Play);
}
}


void Player::blackJack(const int playerHand[], const int dealerHand[], char Play)
{
//Define local Variables
int playerScore = getHandValue(playerHand);
int dealerScore = getHandValue(dealerHand);

//If Player has blackjack but Dealer doesn't.
if((playerScore == 21) && (dealerScore != 21))
{
    //Display message, compute new winnings multiplier, ask to play another hand.
    cout << "\n\n";
    scoreBoard(playerHand, dealerHand);
    cout << "\n";
    cout << "Blackjack! You win a 3:2 payout." << endl;
    win = win + 1.5;
    cout << "\n";
    cout << "Winnings multiplier: " << win << endl;
    backdoorKenny(playerHand);
    playAnotherHand(Play);
}
//If both Player and Dealer have blackjack.
else if((playerScore == 21) && (dealerScore == 21))
{
    //Display message, compute new winnings multiplier, ask to play another hand.
    scoreBoard(playerHand, dealerHand);
    cout << "\n";
    cout << "The Dealer and you both got Blackjack. Push in your favor at 1:1 payout!" << endl;
    win++;
    cout << "\n";
    cout << "Winnings multiplier: " << win << endl;
    playAnotherHand(Play);
}
}


void Player::naturalBlackJack(const int playerHand[], const int dealerHand[], char Play)
{
//Define local variables
int playerScore = getHandValue(playerHand);
int dealerScore = getHandValue(dealerHand);

//If Player has blackjack and Dealer doesnt
if((playerScore == 21) && (dealerScore != 21))
{
    //Display message, compute new winnings multiplier, ask to play another hand.
    scoreBoard(playerHand, dealerHand);
    cout << "\n";
    cout << "Natural Blackjack! You win a 3:2 payout.";
    win = win + 1.5;
    backdoorKenny(playerHand);
    playAnotherHand(Play);
}
}

void Player::scoreBoard(const int playerHand[], const int dealerHand[])
{
//Display Player's cards/hand value
 cout << "Player hand: ";
showCards(playerHand, 10, false);
cout << " ("<< getHandValue(playerHand) << "pts)."<<endl;

cout <<"V.S." << endl;

//Display Dealer's cards/hand value
cout << "Dealer hand: ";
showCards(dealerHand, 10, false);
cout << " ("<< getHandValue(dealerHand) << "pts)."<<endl;
}


void Player::checkSoftOrHard(int playerHand[])
{
//check cards in hand
for(int i=0; i<9; i++)
{
    //Define local variables.
    int checkAce = CardValue(playerHand[i]);
    int softOrHard;

    //If card in hand is an Ace prompt Player for input
    if(checkAce == 1 || checkAce == 11)
    {
        cout << "\n";
        cout << "\nWould you like your Ace to count as 1 or 11 points? (1/11): ";
        cin >> softOrHard;

        //If Player chooses 1
        if(softOrHard == 1)
        {
            if(checkAce == 11)
            playerHand[i] = playerHand[i] + 13;
        }

        //If Player chooses 11
        else if(softOrHard == 11)
        {
            if(checkAce == 1)
            {
                playerHand[i] = playerHand[i] - 13;
            }
        }

        //If player doesn't input 1 or 11
        else if (softOrHard != 1 || softOrHard != 11)
        {
            //Clears input error flags and removes everything currently in the input buffer.
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            //Display error message and restart the function
            cout << "\nPlease enter the number 1 or 11." << endl;
            checkSoftOrHard(playerHand);
        }
    }
}
}


void Player::softOrHardAI(int dealerHand[], int playerHand[])
{
//check cards in hand
for(int i=0; i<9; i++)
{
    //Find an Ace
    if(CardValue(dealerHand[i]) == 1 || CardValue(dealerHand[i]) == 11)
    {
        //If the Ace is worth 11 points...
        if(CardValue(dealerHand[i]) == 11)
        {
            //...change it to 1 point if that will beat player...
            if (getHandValue(dealerHand) - CardValue(dealerHand[i]) + 1 > getHandValue(playerHand))
            {
                //...and not bust.
                if (getHandValue(dealerHand) - CardValue(dealerHand[i]) + 1 < 22)
                {
                    dealerHand[i] = dealerHand[i] + 13;
                }
            }

            //Else if hand is a bust at 11, make it 1
            else if (getHandValue(dealerHand) > 21)
            {
                dealerHand[i] = dealerHand[i] + 13;
            }
        }

        //Else Ace is worth 1 point.
        else
        {
            //Change it to 11 points if that will beat player...
            if (getHandValue(dealerHand) - CardValue(dealerHand[i]) + 11 > getHandValue(playerHand))
            {
                //...and not bust.
                if (getHandValue(dealerHand) - CardValue(dealerHand[i]) + 11 < 22)
                {
                    dealerHand[i] = dealerHand[i] - 13;
                }
            }
        }
    }
}
}

#endif