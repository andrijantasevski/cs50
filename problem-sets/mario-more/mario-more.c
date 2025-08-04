#include <stdio.h>

enum Direction
{
    LTR,
    RTL
};

void printHash(int sizeOfRow, int emptySpaces, enum Direction direction);

int main(void)
{
    int sizeOfPyramid = 2;

    for (int i = 0; i < sizeOfPyramid; i++)
    {
        int emptySpaces = sizeOfPyramid - (i + 1);

        printHash(sizeOfPyramid, emptySpaces, RTL);

        printf("  ");

        printHash(sizeOfPyramid, emptySpaces, LTR);

        printf("\n");
    }
}

void printHash(int sizeOfRow, int emptySpaces, enum Direction direction)
{
    if (direction == LTR)
    {
        for (int i = sizeOfRow; i > 0; i--)
        {
            if (i - emptySpaces > 0)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
    }
    else
    {
        for (int i = 0; i < sizeOfRow; i++)
        {
            if (i < emptySpaces)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
    }
}

// int main(void)
// {
//  int sizeOfPyramid = 4;

//  for (int i = 0; i < sizeOfPyramid; i++)
//  {
//      int sizeOfRow = (sizeOfPyramid * 2) + 1;

//      int emptySpaces = sizeOfPyramid - (i + 1);

//      for (int j = 0; j < sizeOfRow; j++)
//      {

//          if (j == sizeOfPyramid)
//          {
//              printf(" ");
//          }
//          else if (j > sizeOfPyramid)
//          {
//              printf("#");
//          }
//          else
//          {
//              if (j < emptySpaces)
//              {
//                  printf(" ");
//              }
//              else
//              {
//                  printf("#");
//              }
//          }
//      }

//      printf("\n");
//  }
// }
