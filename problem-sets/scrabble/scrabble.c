#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string stringToLowercase(string unprocessedString);
int calculateStringScore(string playerString, int alphabetPoints[]);
void determineAndPrintWinner(int playerOneScore, int playerTwoScore);

int main(void)
{
  int alphabet[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

  string playerOneString = get_string("Player 1: ");
  string playerTwoString = get_string("Player 2: ");

  int playerOneScore = calculateStringScore(playerOneString, alphabet);
  int playerTwoScore = calculateStringScore(playerTwoString, alphabet);

  determineAndPrintWinner(playerOneScore, playerTwoScore);

  return 0;
}

string stringToLowercase(string unprocessedString)
{
  for (int i = 0, n = strlen(unprocessedString); i < n; i++)
  {
    if (isalpha(unprocessedString[i]))
    {
      unprocessedString[i] = tolower(unprocessedString[i]);
    }
  }

  return unprocessedString;
}

int calculateStringScore(string playerString, int alphabetPoints[])
{
  string playerStringToLowercase = stringToLowercase(playerString);

  int stringScore = 0;

  for (int i = 0, n = strlen(playerStringToLowercase); i < n; i++)
  {
    if (isalpha(playerStringToLowercase[i]))
    {
      int indexOfLetter = playerStringToLowercase[i] - 'a';

      stringScore += alphabetPoints[indexOfLetter];
    }
  }

  return stringScore;
}

void determineAndPrintWinner(int playerOneScore, int playerTwoScore)
{
  if (playerOneScore > playerTwoScore)
  {
    printf("Player 1 wins!\n");
  }
  else if (playerTwoScore > playerOneScore)
  {
    printf("Player 2 wins!\n");
  }
  else
  {
    printf("Tie!\n");
  }
}
