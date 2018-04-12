#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>



//Prototype functions.
int getRandomNumber(int low, int high);
int CardValue(int card);
int getTopCard(int deck[]);
int getHandValue(const int hand[]);
int playAnotherHand(char);
//bool userWantsToDraw(char&);
void initializeDeck(int deck[]);
void dumpDeck(int deck[], int size);
void shuffle(int deck[], int size);
void ShowCard(int card);
void showCards(const int cards[], int numCards);//, bool hideFirstCard);
void whoWins(const int playerHand[], const int dealerHand[]);
void checkBust(const int playerHand[], const int dealerHand[], char Play);
void blackJack(const int playerHand[], const int dealerHand[], char Play);
void naturalBlackJack(const int playerHand[], const int dealerHand[], char Play);
void playOneHand();
void scoreBoard(const int playerHand[], const int dealerHand[]);
//void backdoorKenny(const int hand[]);
void checkSoftOrHard(int playerHand[]);
void softOrHardAI(int dealerHand[], int playerHand[]);
void chooseLevelOfDificulty();
void showRules();
void addToHand(int hand[], int cardToAdd);
void hitUntilStand(int dealerHand[], int deck[], int playerHand[]);

//Declare global Variables
int topCard = 0;
float win = 1.00;
int level;

int main()
{
   showRules();
   chooseLevelOfDificulty();
   playOneHand();
   return 0;
}


void showRules()
{
   //Display information.
  	printf("//////////////////////////////////////////////////////////\n");
  	printf("////        Welcome to the game of Twenty One!       /////\n");
  	printf("////              Level of Difficulty                /////\n");
  	printf("//// _______________________________________________ /////\n");
  	printf("//// | You may choose to play with a beginner or   | /////\n");
  	printf("//// | expert Dealer:                              | /////\n");
  	printf("//// | o (Beginner) - Dealer stands at a soft 17   | /////\n");
  	printf("//// |                and has no AI.               | /////\n");
  	printf("//// | o (Expert)   - Dealer hits at a soft 17     | /////\n");
  	printf("//// |                and has AI.                  | /////\n");
  	printf("//// |_____________________________________________| /////\n");
  	printf("//////////////////////////////////////////////////////////\n");

}


void chooseLevelOfDificulty()
{
   //Prompt user and store input
	printf("\n");
   	printf("Level of Difficulty: Beginner (1), Expert (2).");
   	scanf("%d", &level);
   //	scanf >> level;
   	printf("\n");

   //If input is not a 1..
   if(level != 1)
   {
       //...or a 2.
       if(level != 2)
       {
           //Clears input error flags and removes everything currently in the input buffer.
           //cin.clear();
           //cin.ignore(numeric_limits<streamsize>::max(), '\n');

           //Display error message and restart function.
       		printf("Please enter your level of difficulty using the number 1 or 2.\n ");
         //  cout << "" << endl;
           chooseLevelOfDificulty();
       }
   }          
}


void playOneHand()
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
       printf("//////////////////////////////////////////////////////////");
       //cout <<  << endl;
       printf("\n");
       //cout << "\n" << endl;
       printf("The Dealer shuffled and dealt you each your cards. ");
     //  cout << "The Dealer shuffled and dealt you each your cards. ";
       //cout << "\n" << endl;
       printf("\n");


       //Check for an automatic win.
       naturalBlackJack(playerHand, dealerHand, 'y');
       blackJack(playerHand, dealerHand, 'Y');

       //Display Player and Dealer hands
       printf("Your hand:\n");
       //cout << "Your hand:" << endl;
       showCards(playerHand, 10);//, 0);
       printf("\n\nDealer's hand:\n");
     //  cout << "\n\nDealer's hand:" << endl;
       showCards(dealerHand, 10);//, 1);

       //If Player has an Ace, see if Player want's to have a soft or hard hand.
       checkSoftOrHard(playerHand);
   /*   
       //Check if user wants to hit
       while (userWantsToDraw(Draw))
       {
           //Deal Player a card
           //and display an explanation of what is happening
           addToHand(playerHand, getTopCard(deck));
           printf("The Dealer dealt you another card.\n\n");
           //cout << "The Dealer dealt you another card.\n" << endl;
          
           //Display Player's updated hand
           printf("Your hand:\n");
           //cout << "Your hand:" << endl;
           showCards(playerHand, 10, 0);

           //If Player has an Ace, see if Player want's to have a soft or hard hand.
           checkSoftOrHard(playerHand);

           //Check to see if anyone lost
           checkBust(playerHand, dealerHand, 'y');

           //Check to see if anyone won
           blackJack(playerHand, dealerHand, 'Y');
       }
      */
       //Dealer hits until at a soft 17
       hitUntilStand(dealerHand, deck, playerHand);
       printf("\n");
       //cout << endl;

       //Check to see if anyone lost
       checkBust(playerHand, dealerHand, 'Y');
  
       //Check to see if anyone won
       blackJack(playerHand, dealerHand, 'Y');

       //Compare scores and determine winner
       whoWins(playerHand, dealerHand);
       printf("\n");

       //Display updated winnings multiplier
       printf("%fWinnings multiplier:\n", win);
      // cout << "Winnings multiplier: " << win << endl;
   }
   while (playAnotherHand(Play));
}


void initializeDeck(int deck[])
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

void shuffle(int deck[], int size)
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


void ShowCard(int card)
{
   //Show nothing for non cards (ie.0)
   if(card == 0)
   {
   		printf(" ");
     //  cout << "";
   }
   //Define Ranks.
   else
   {
       switch(card % 100)
       {
           case 1:
           		printf("A");
             //  cout << "A";
               break;
           case 11:
           		printf("J");
             //  cout << "J";
               break;
           case 12:
           		printf("K");
              // cout << "K";
               break;
           case 13:
           		printf("Q");
              // cout << "Q";
               break;
           case 14://14 is a value created in checkSoftOrHard
           		printf("A");
               //cout << "A";
               break;

           //For non-face cards, just use their 10s value as rank.
           default:
           		printf("%d", card % 100 );
              // cout << card % 100;
       }
   }

   //Show nothing for non cards (ie.0)
   if(card == 0)
   {
   		printf(" ");
       //cout << "";
   }
   //Define Suits.
   else
   {
   		const char *num = "3456";
       //Hearts
       if((card >= 101) && (card <=114))
       {
       		printf("%c", num[0]);
          // cout << static_cast<char>(3);
       }

       //Diamonds
       else if ((card >= 201) && (card <= 214))
       {
       		printf("%c", num[1]);
          // cout << static_cast<char>(4);
       }

       //Clubs
       else if ((card >= 301) && (card <= 314))
       {
       		printf("%c", num[2]);
           //cout << static_cast<char>(5);
       }

       //Spades
       else if ((card >= 401) && (card <= 414))
       {
       		printf("%c", num[3]);
          // cout << static_cast<char>(6);
       }
   }
}


void showCards(const int deck[], int numCards)//, bool hideFirstCard)
{
   //Hide dealer's first card if true.
 //  if(hideFirstCard)
  // {
   		//printf("** ");
       //cout << "** ";
 //  }

   //Show dealer's first card if false.
   //else
  // {
       ShowCard(deck[0]);
       printf(" ");
       //cout << " ";
 //  }

   //Display all the cards in the deck or hand
   //by showing their rank and suit graphic.
   for(int i = 1; i < numCards; i++)
   {
       //Show cards
       if(deck[i] != 0)
       {
           ShowCard(deck[i]);
           printf(" ");
           //cout << " ";
       }
      
       //Show nothing for non cards (ie. 0).
       else
       {
       		printf(" ");
           //cout << "";
       }
   }
}


void dumpDeck(int deck[], int size)
{
   //loop through the deck array and print each value.
   for(int i = 0; i < size; i++)
   {
   		printf("%d",i+1 );
   		printf(".) ");
   		printf("%d\n",deck[i] );
     //  cout << i + 1 << ".) " << deck[i] << endl;
   }
}

int getRandomNumber(int low, int high) {
   //static bool firstTime=true;
   int randNum;
   static int firstTime =1;
   //if first time called, seed random number generator
   if (firstTime) {
       srand((time(NULL)) );
       //firstTime=false;
       firstTime=0;
   }

   //generate random number between given low and high values (inclusive)
   randNum = rand() % (high-low+1) + low;

   return randNum;
}

int CardValue(int card)
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

int getTopCard(int deck[])
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

void addToHand(int hand[], int cardToAdd)
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

void hitUntilStand(int dealerHand[], int deck[], int playerHand[])
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
           		printf("The Dealer stands.\n");
               //cout << "The Dealer stands." << endl;
               break;
           }
           //Dealer hit once to get to 17
           else if(i == 1)
           {
           		printf("The Dealer hit a card and stands.\n");
             //  cout << "The Dealer hit a card and stands." << endl;
               break;
           }
           //Dealer hit more than once to get to 17
           else
           {
           		printf("%dThe Dealer hit ", i);
           		printf("cards and stands.\n");
               //cout << "The Dealer hit " << i << " cards and stands." << endl;
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

int getHandValue(const int hand[])
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

int playAnotherHand(char Play)
{
   //Prompt user to see if they would like to play another hand.
	printf("\n\nWould you like to play another hand? (Y/N) ");
   //cout << endl << "\nWould you like to play another hand? (Y/N) ";
   scanf("%c", &Play);
   //cin >> Play;
   printf("\n\n");
   //cout << "\n" << endl;

   //Go back to the main game logic function to restart if they do.
   if(Play == 'y' || Play == 'Y')
   {
       playOneHand();
       return(1);
   }
   //If they don't, exit the program.
   else
   {
       return(0);
   }
}
/*
bool userWantsToDraw(char& Draw)
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
*/
void whoWins(const int playerHand[], const int dealerHand[])
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
   		printf("\n");
       //cout << "\n";
   		printf("You win!\n");
      // cout << "You win!" << endl;
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
          // cout << "\n";
           printf("\n");
           printf("Push in the Dealer's favor. 0:1 payout.\n");
           //cout << "Push in the Dealer's favor. 0:1 payout." << endl;
       }

       //loose
       //Display message and compute new winnings multiplier
       else
       {
       		printf("\n");
          // cout << "\n";
       		printf("You lose\n");
          // cout << "You lose." << endl;
           win--;
       }
   }
}

void checkBust(const int playerHand[], const int dealerHand[], char Play)
{
   //Define local variables.
   int playerScore = getHandValue(playerHand);
   int dealerScore = getHandValue(dealerHand);

   //Check if Player busts.
   //Display message, compute new winnings multiplier, ask to play another hand.
   if(playerScore > 21)
   {	printf("%dYou bust with ",getHandValue(playerHand) );
		printf(" points\n");
     //  cout << "You bust with " << getHandValue(playerHand) << " points." << endl;
      	printf("\n\n");
     //  cout << "\n" << endl;
       win--;
       printf("%f\n", win);
       printf("\n");
       //cout << "Winnings multiplier: " << win << endl;
       playAnotherHand(Play);
   }

   //Check if Dealer busts.
   //Display message, compute new winnings multiplier, ask to play another hand.
   else if(dealerScore > 21)
   {
       scoreBoard(playerHand, dealerHand);
       printf("\n\n");
       //cout << "\n" << endl;
       //cout << "The Dealer went bust. You Win!" << endl;
       printf("The Dealer went bust. You Win!\n");
       printf("\n\n");
       //cout << "\n" << endl;
       win++;
       printf("%fWinnings multiplier: ",win );
       printf("\n");
       //cout << "Winnings multiplier: " << win << endl;
       playAnotherHand(Play);
   }
}
/*
void backdoorKenny(const int hand[])
{
   //If index 0 is a 10 and index 1 is an ace
   if((CardValue(hand[0])%100 == 10)&&(CardValue(hand[1])%100 == 11))//I did not use 1 as an argument because 11 is the default
                                                                      //value and this happens before the user can choose.
   {
       //Display message and compute new winnings multiplier.
       cout << "\n\n";
       cout << "You pulled a Backdoor Kenny!\n" << endl;
       cout << "Win an additional 1:4 payout\n" << endl;
       win = win + .25;
       cout << "Winnings multiplier: " << win << endl;
   }
}
*/
void blackJack(const int playerHand[], const int dealerHand[], char Play)
{
   //Define local Variables
   int playerScore = getHandValue(playerHand);
   int dealerScore = getHandValue(dealerHand);

   //If Player has blackjack but Dealer doesn't.
   if((playerScore == 21) && (dealerScore != 21))
   {
       //Display message, compute new winnings multiplier, ask to play another hand.
       //cout << "\n\n";
       printf("\n\n");
       scoreBoard(playerHand, dealerHand);
       printf("\n");
       //cout << "\n";
       printf("Blackjack! You win a 3:2 payout.\n");
       //cout << "Blackjack! You win a 3:2 payout." << endl;
       win = win + 1.5;
       printf("\n");
      // cout << "\n";
       printf("%fWinnings multiplier: ", win );
       printf("\n");
       //cout << "Winnings multiplier: " << win << endl;
      // backdoorKenny(playerHand);
       playAnotherHand(Play);
   }
   //If both Player and Dealer have blackjack.
   else if((playerScore == 21) && (dealerScore == 21))
   {
       //Display message, compute new winnings multiplier, ask to play another hand.
       scoreBoard(playerHand, dealerHand);
       printf("\n");
       //cout << "\n";
       printf("The Dealer and you both got Blackjack. Push in your favor at 1:1 payout!\n");
       //cout << "The Dealer and you both got Blackjack. Push in your favor at 1:1 payout!" << endl;
       win++;
       printf("\n");
       printf("%fWinnings multiplier:  ", win);
       printf("\n");
       //cout << "Winnings multiplier: " << win << endl;
       playAnotherHand(Play);
   }
}

void naturalBlackJack(const int playerHand[], const int dealerHand[], char Play)
{
   //Define local variables
   int playerScore = getHandValue(playerHand);
   int dealerScore = getHandValue(dealerHand);

   //If Player has blackjack and Dealer doesnt
   if((playerScore == 21) && (dealerScore != 21))
   {
       //Display message, compute new winnings multiplier, ask to play another hand.
       scoreBoard(playerHand, dealerHand);
       printf("\n");
     //  cout << "\n";
       printf("Natural Blackjack! You win a 3:2 payout.");
       //cout << "Natural Blackjack! You win a 3:2 payout.";
       win = win + 1.5;
     //  backdoorKenny(playerHand);
       playAnotherHand(Play);
   }
}

void scoreBoard(const int playerHand[], const int dealerHand[])
{
   //Display Player's cards/hand value
    //cout << "Player hand: ";
    printf("Player hand: ");
   showCards(playerHand, 10);//, false);
   //cout << " ("<< getHandValue(playerHand) << "pts)."<<endl;
   printf(" %d(", getHandValue(dealerHand));
   printf("pts).\n");

   printf("V.S.\n");
  // cout <<"V.S." << endl;

   //Display Dealer's cards/hand value
   printf("Dealer hand: ");
   //cout << "Dealer hand: ";
   showCards(dealerHand, 10);//, false);
   printf(" %d(", getHandValue(dealerHand));
   printf("pts).\n");
   //cout << " ("<< getHandValue(dealerHand) << "pts)."<<endl;
}

void checkSoftOrHard(int playerHand[])
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
       		printf("\n");
          // cout << "\n";
       		printf("\nWould you like your Ace to count as 1 or 11 points? (1/11): ");
           //cout << "\nWould you like your Ace to count as 1 or 11 points? (1/11): ";
          // cin >> softOrHard;
       		scanf("%d", &softOrHard);
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
               //cin.clear();
             // cin.ignore(numeric_limits<streamsize>::max(), '\n');
              
               //Display error message and restart the function
            //   cout << "\nPlease enter the number 1 or 11." << endl;
               printf("\nPlease enter the number 1 or 11.\n");
               checkSoftOrHard(playerHand);
           }
       }
   }
}

void softOrHardAI(int dealerHand[], int playerHand[])
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

