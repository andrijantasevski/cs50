#include <stdio.h>

enum Direction
{
    LTR,
    RTL
};

int get_height(void);
void printHash(int sizeOfRow, int emptySpaces, enum Direction direction);
void createPyramid(int sizeOfPyramid);

int main(void)
{
    int sizeOfPyramid = get_height();

    createPyramid(sizeOfPyramid);
}

int get_height(void)
{
    int valid_height;
    do
    {
        valid_height = get_int("Height: ");
    } while (valid_height < 1 || valid_height >= 9);

    return valid_height;
}

void createPyramid(int sizeOfPyramid)
{
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