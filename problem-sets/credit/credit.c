#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

long power(int base, int exponent);
long get_card();
string validate_card(long cardNumber);
int get_long_int_length(long longInteger);
int get_card_type(int cardLength);
long get_card_numbers(long cardNumber, int cardLength, int cardNumbers);

int main(void)
{
    long card = get_card();

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

long get_card()
{
    long cardNumber;
    bool isCardValid;
    do
    {
        cardNumber = get_long("Number: ");
        string cardType = validate_card(cardNumber);

    } while (!cardNumber || cardType == "INVALID");

    return cardNumber;
}

string validate_card(long cardNumber)
{
    int cardLength = get_long_int_length(cardNumber);
    int firstNumber = get_card_numbers(cardNumber, 1, cardLength);
    int firstTwoNumbers = get_card_numbers(cardNumber, 2, cardLength);

    if (cardLength == 13 && firstNumber == 4)
    {
        return "VISA";
    }
    else if (cardLength == 15 && firstNumber == 4)
    {
        return "AMEX";
    }
    else if (cardLength == 16 && firstNumber == 4)
    {
        return "VISA";
    }
    else if (cardLength == 16 && firstNumber == 5)
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