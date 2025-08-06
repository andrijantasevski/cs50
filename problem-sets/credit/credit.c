#include <stdio.h>

long power(int base, int exponent);
int get_long_int_length(long longInteger);
int get_card_type(int cardLength);
long get_card_numbers(long cardNumber, int cardLength, int cardNumbers);

int main(void)
{
    long card = 4003600000000014;

    int cardLength = get_long_int_length(card);

    long firstTwoCardNumbers = get_card_numbers(card, 2, cardLength);

    printf("%li", firstTwoCardNumbers);
}

long power(int base, int exponent)
{
    long powerOf = base;

    for (int i = 0; i < exponent; i++)
    {
        powerOf *= base;
    }

    return powerOf;
}

int get_long_int_length(long longInteger)
{
    long longIntegerCounter = longInteger;
    int cardLength = 0;

    do
    {
        longIntegerCounter /= 10;
        cardLength++;

    } while (longIntegerCounter > 0);

    return cardLength;
}

int get_card_type(int cardLength)
{
    switch (cardLength)
    {
    case 13:
        break;
    case 16:
        break;
    case 15:
        break;
    default:
        return 0;
    }
}

long get_card_numbers(long cardNumber, int cardNumbers, int cardLength)
{
    long longIntegerCounter = cardNumber;
    int shouldLookForNumbers = 1;
    int cardNumberCounter = 0;

    int stopAtLimit = cardLength - cardNumbers;

    if (stopAtLimit <= 0)
    {
        return 0;
    }

    while (cardNumberCounter != stopAtLimit)
    {
        longIntegerCounter /= 10;
        cardNumberCounter++;
    }

    return longIntegerCounter;
}