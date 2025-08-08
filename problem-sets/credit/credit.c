#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

#define INVALID 0
#define VISA 1
#define AMEX 2
#define MASTERCARD 3

long get_card();
short validate_card(long cardNumber);
int get_long_int_length(long longInteger);
string get_card_type(short cardLength);
long get_card_numbers(long cardNumber, int cardLength, int cardNumbers);

int main(void)
{
    long card = get_card();

    int cardLength = get_long_int_length(card);

    long firstTwoCardNumbers = get_card_numbers(card, 2, cardLength);
}

long get_card()
{
    long cardNumber;
    int cardType;

    do
    {
        cardNumber = get_long("Number: ");
        cardType = validate_card(cardNumber);

    } while (!cardNumber || !cardType);

    return cardNumber;
}

short validate_card(long cardNumber)
{
    int cardLength = get_long_int_length(cardNumber);
    int firstNumber = get_card_numbers(cardNumber, 1, cardLength);

    if (cardLength == 13 && firstNumber == 4)
    {
        return VISA;
    }
    else if (cardLength == 15 && firstNumber == 3)
    {
        return AMEX;
    }
    else if (cardLength == 16 && firstNumber == 4)
    {
        return VISA;
    }
    else if (cardLength == 16 && firstNumber == 5)
    {
        return MASTERCARD;
    }

    return INVALID;
}

string get_card_type(short cardType)
{
    if (cardType == VISA)
    {
        return "VISA";
    }
    else if (cardType == AMEX)
    {
        return "AMEX";
    }
    else if (cardType == MASTERCARD)
    {
        return "MASTERCARD";
    }

    return "INVALID";
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