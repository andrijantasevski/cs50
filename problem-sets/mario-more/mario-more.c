#include <cs50.h>
#include <stdio.h>

int get_pyramid_rows();
void create_pyramid(int pyramidRows);
void printChar(char chararacter[], int times);

int main(void)
{
    int pyramidRows = get_pyramid_rows();

    create_pyramid(pyramidRows);
}

int get_pyramid_rows()
{
    int pyramidRows;
    do
    {
        pyramidRows = get_int("Please enter the height of the pyramid: ");
    } while (pyramidRows < 1 || pyramidRows > 8);

    return pyramidRows;
}
void create_pyramid(int pyramidRows)
{
    for (int i = 0; i < pyramidRows; i++)
    {
        int emptySpaces = pyramidRows - (i + 1);

        int hashes = i + 1;

        printChar(" ", emptySpaces);

        printChar("#", hashes);

        printChar(" ", 2);

        printChar("#", hashes);

        printf("\n");
    }
}

void printChar(char character[], int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("%s", character);
    }
}