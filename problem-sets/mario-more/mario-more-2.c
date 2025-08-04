// #include <cs50.h>
#include <stdio.h>

int get_height(void);
void create_pyramid(int height);

int main(void)
{
    int height = get_height();

    create_pyramid(height);
}

// Function to get the height
// Accepts height from 1 to 8 inclusive

int get_height(void)
{
    int valid_height;
    do
    {
        valid_height = get_int("Height: ");
    } while (valid_height < 1 || valid_height >= 9);

    return valid_height;
}

// Function to create the pyramid
// Accepts height as its argument

void create_pyramid(int height)
{
    for (int rows = 0; rows < height; rows++)
    {
        int whitespace = height - rows - 1;

        for (int j = 0; j < whitespace; j++)
        {
            printf(" ");
        }

        for (int k = 0; k <= rows; k++)
        {
            printf("#");
        }

        for (int l = 0; l < 2; l++)
        {
            printf(" ");
        }

        for (int m = 0; m <= rows; m++)
        {
            printf("#");
        }

        printf("\n");
    }
}