#include <_mingw_mac.h>
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

enum { SPOCK, SCISSORS, PAPER, ROCK, LIZARD, SHAPE_COUNT } player1, player2;

const char *SHAPE_STRINGS[] = {"🖖", "✂️", "️🗒️", "🪨", "🦎"};

int BotChoice();

int points_player; // Variable for keeping track of player points
int points_bot;    // Variable for keeping track of bot points
int result;        // Variable for keeping track of the result of each round

int main() {
  srand(time(NULL)); // Seed for random number generation based on time.
  puts("Hello, and welcome to a little game of Spock, Scissors, Paper, Rock, "
       "Lizard! \n");
  sleep(2);
  puts("The rules are simple:\n");
  sleep(2);
  for (size_t player1 = SPOCK; player1 < SHAPE_COUNT;
       ++player1) { // For displaying the rules
    for (size_t player2 = SPOCK; player2 < SHAPE_COUNT; ++player2) {
      switch ((player1 - player2 + SHAPE_COUNT) % SHAPE_COUNT) {
      case 0:
        printf("If player chooses: %s  and bot chooses: %s  => It's a tie!\n",
               SHAPE_STRINGS[player1], SHAPE_STRINGS[player2]);
        ;
        break;
      case 2:
      case 4:
      case 7:
      case 9:
        printf(
            "If player chooses: %s  and bot chooses: %s  => The player wins!\n",
            SHAPE_STRINGS[player1], SHAPE_STRINGS[player2]);
        break;
      case 1:
      case 3:
      case 6:
      case 8:
        printf(
            "If player chooses: %s  and bot chooses: %s  => The bot wins! \n",
            SHAPE_STRINGS[player1], SHAPE_STRINGS[player2]);
        break;
      }
    }
    puts("");
  }
  sleep(3);

  printf("First one to 5 points wins! \n");
  sleep(2);

  do {

    printf("Choose an option!: (0)%s, (1)%s, (2)%s, (3)%s, "
           "(4)%s\n",
           SHAPE_STRINGS[0], SHAPE_STRINGS[1], SHAPE_STRINGS[2],
           SHAPE_STRINGS[3], SHAPE_STRINGS[4]);

    scanf("%u", &player1); // gets the player's choice
    while (player1 >= SHAPE_COUNT) {
      printf("Was that one of the options? No?? Maybe pick one of them "
             "instead?: ");
      scanf("%u", &player1);
    } // While statement, for incase the input before is invalid

    printf("You chose %s\n", SHAPE_STRINGS[player1]);
    sleep(2);
    player2 = BotChoice(); // Gets the bot's choice and prints it
    result = (SHAPE_COUNT + player1 - player2) %
             SHAPE_COUNT; // Calculates the result of the round. Keeping it to
                          // non-negative numbers as a preference.

    switch (result) {
    case 0: // Incase of a tie
      puts("It's a tie!");
      puts("");
      break;
      // Multiple cases for when the player wins
    case 2:
    case 4:
    case 7:
    case 9:
      puts("You win this round!");
      points_player++;
      puts("");
      printf("Player points: %d\n", points_player);
      printf("Bot points: %d\n", points_bot);
      puts("");
      break;
      // Multiple cases for when the bot wins
    case 1:
    case 3:
    case 6:
    case 8:
      puts("Bot wins this round!");
      points_bot++;
      puts("");
      printf("Player points: %d\n", points_player);
      printf("Bot points: %d\n", points_bot);
      puts("");
      break;
    }
  } while (points_player < 5 && points_bot < 5);
  if (points_player == 5)
    puts("Well done! You win!");
  else
    puts("Bot wins, better luck next time!");
  return 0;
}

// Randomly generates the choice of our bot and prints it for repeat use
int BotChoice() {
  player2 = rand() % SHAPE_COUNT; // Randomly generates a number between 0 and 4
  printf("Bot chose %s\n", SHAPE_STRINGS[player2]);
  return player2;
}