#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
  
struct Card 
{
  enum Suit { Spades, Clubs, Hearts, Diamonds } suit;
  int value;
  char * const name;
} 
Deck [52] = {
  {Spades, 2, "2"}, {Clubs, 2, "2"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 3, "3"}, {Clubs, 3, "3"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 4, "4"}, {Clubs, 4, "4"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 5, "5"}, {Clubs, 5, "5"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 6, "6"}, {Clubs, 6, "6"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 7, "7"}, {Clubs, 7, "7"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 8, "8"}, {Clubs, 8, "8"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 9, "9"}, {Clubs, 9, "9"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 10, "10"}, {Clubs, 10, "10"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 10, "Jack"}, {Clubs, 10, "Jack"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 10, "Queen"},  {Clubs, 10, "Queen"}, {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 10, "King"}, {Clubs, 10, "King"},  {Hearts, 2, "2"}, {Diamonds, 2, "2"},
  {Spades, 11, "Ace"},  {Clubs, 11, "Ace"}, {Hearts, 2, "2"}, {Diamonds, 2, "2"},

};

      /* 0 means the corresponding card hasn't been
         drawn; otherwise, the card has been drawn
       */
static char Cards_drawn [52];

      /* The number of cards that haven't been drawn yet */
static int Cards_left;



  /* Methods of the Cards "package"
   */
static void Cards_init(void)
{
  Cards_left = sizeof(Deck)/sizeof(Deck[0]);
  memset(Cards_drawn,0,sizeof(Cards_drawn));
}


static void Cards_print(const int index)
{
  const struct Card * cp;
  assert( index >= 0 && index < sizeof(Deck)/sizeof(Deck[0]) );
  cp = Deck + index;
  printf("Card %s of ",cp->name);
  switch(cp->suit)
  {
    case Spades:
   printf("spades");
   break;
   
    case Clubs:
   printf("clubs");
   break;
   
    case Hearts:
   printf("hearts");
   break;
   
    case Diamonds:
   printf("diamonds");
   break;
   
    default:
  assert(0 /*can't happen*/);
   }
}

      /* Draw a card and return its index */
static int Cards_draw(void)
{
  int offset;
  register int i;
  if( Cards_left < 1 )
    printf("\nNo cards left to draw!\n"), exit(4);
  
  offset = Cards_left == 1 ? 1 : 1 + (rand() % Cards_left);
  
      /* In the following loop, we search for a
          offset-th card in the deck that hasn't been drawn.
          In other words, we search for offseth-th zero element
          of an array Cards_drawn
       */
  for(i=0; i<sizeof(Deck)/sizeof(Deck[0]); i++)
    if( Cards_drawn[i] )
      continue;
    else if( --offset == 0 )
    {
      Cards_drawn[i] = 1;
      Cards_left--;
      return i;
    }
  assert( 0 /* Can't happen */);
}


    /* Given a card's index, return ints value  */
static int Cards_value(const int index)
{
  assert( index >= 0 && index < sizeof(Deck)/sizeof(Deck[0]) );
  return Deck[index].value;  
}


static int is_ace(const int value)
{ return value == 11; }


/*--------------
 *  A neuron that learns how to play. One neuron per player
 */

#define PERFECT_SCORE 21

struct Player
{
  int threshold;  /* A learning parameter */
  
  const char * name;  /* Player's name */
  int no_wins;    /* The total number of wins */
  
      /* The following are the current status of the hand */
  int score;    /* score so far, with aces counted as 11    */
  int no_aces;    /* The number of aces so far        */
} Player1 =
  {5, "player 1", 0, 0, 0},
  Player2 =
  {15, "player 2", 0, 0, 0};

      /* Have a given player take a card    */
static void take_card(struct Player * player)
{
  const int index = Cards_draw();
  const int value = Cards_value(index);
  player->score += value;
  if( is_ace(value) )
    player->no_aces++;
  printf("\n\t%s has drawn ",player->name); Cards_print(index);
}

      /* Give the best interpretation of the current  */
      /* hand. An ace can have the value 1 or 11  */
      /* We interpret as many aces as 11s as we can */
      /* keeping the score under PERFECT_SCORE  */
static int best_score(const struct Player * player)
{
  int score = player->score;
  int aces = player->no_aces;
  assert( score > 0 && aces >= 0 && aces <= 4 );
  while( aces>0 && score > PERFECT_SCORE )
    score -= 10, aces--;
  return score;
 }


static void note_victory(struct Player * player)
{
  printf("\n%s has won\n",player->name);
  player->no_wins++;
}
      /* Init the hand    */
static void hand_init(struct Player * player)
{
  player->score = 0;
  player->no_aces = 0;
}
 

      /* This is the goal function, which decides if */
      /* to continue to draw cards    */
static int q_continue(const struct Player * player)
{
  int score = player->score;
  int aces = player->no_aces;
  assert( score > 0 && aces >= 0 && aces <= 4 );
  return score - 2*aces < player->threshold;
}

      /* The following two functions implement the
         most trivial learning algorithm, which adjusts
         the threshold based on a loss
         Note that it is actually the most trivial
         implementation of a back-propagation
       */
static void learn_from_overdraft(struct Player * player)
{
  printf("\n%s has overdrew",player->name);
  player->threshold--;
  printf("  threshold is now %d\n",player->threshold);
}

static void learn_from_underdraft(struct Player * player)
{
  printf("\n%s should've continued\n",player->name);
  player->threshold++;
  printf("  threshold is now %d\n",player->threshold);
}

       
/*----------
 * Main module
 */
 
      /* Plays one game */
static void play_game(void)
{
  hand_init(&Player1);
  hand_init(&Player2);
  Cards_init();
  
          /* Each of the players draws initially */
          /* two cards      */
  take_card(&Player1);
  take_card(&Player1);
  take_card(&Player2);
  take_card(&Player2);
  for(;;)
  {
    const int score1 = best_score(&Player1);
    const int score2 = best_score(&Player2);
    const int wants_continue1 = q_continue(&Player1);
    const int wants_continue2 = q_continue(&Player2);

    printf("\n%s score is %d, %s score is %d",
          Player1.name, score1,  Player2.name, score2);
    if( score1 > PERFECT_SCORE && score2 > PERFECT_SCORE )
    {       /* both players overdrew  */
      learn_from_overdraft(&Player1);
      learn_from_overdraft(&Player2);
      return;       /* game is over   */
    }
    if( score1 > PERFECT_SCORE )
    {
      learn_from_overdraft(&Player1);
      note_victory(&Player2);
      return;
    }
    if( score2 > PERFECT_SCORE )
    {
      learn_from_overdraft(&Player2);
      note_victory(&Player1);
      return;
    }
    if( score1 == PERFECT_SCORE )
    {
      note_victory(&Player1);
      return;
    }
    if( score2 == PERFECT_SCORE )
    {
      note_victory(&Player2);
      return;
    }
    if( !wants_continue1 && !wants_continue2 )
    {     /* nobody wants to continue */
      if( score1 > score2 )
      {
        learn_from_underdraft(&Player2);
        note_victory(&Player1);
      }
      else
      {
        learn_from_underdraft(&Player1);
        note_victory(&Player2);
      }
      return;
    }
    if( wants_continue1 )
      take_card(&Player1);
    if( wants_continue2 )
      take_card(&Player2);
  }
}
    /* This is just a demo that draws some n cards  */
static void draw_some(void)
{
  const int n=10;
  register int i;
  
  srand(time(0));   /* Seed the random number generator
             with the current timestamp */
  Cards_init();
  
  printf("\nDraw %d cards at random\n",n);
  for(i=0; i<n; i++)
  {
    int index = Cards_draw();
    printf("Draw #%d: ",i+1);
    Cards_print(index);
    printf(" of value %d\n",Cards_value(index));
  }
  printf("\nDone\n");
}


void main(void)
{
  const int n=20;
  register int i;
  
  srand(time(0));   /* Seed the random number generator
             with the current timestamp */
  
  
  for(i=0; i<n; i++)
    play_game();
    
  printf("\n==>Total %d game played. %s won %d, %s won %d\n",
       n,Player1.name,Player1.no_wins,Player2.name,Player2.no_wins);
}