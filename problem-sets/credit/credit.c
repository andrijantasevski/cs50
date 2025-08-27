#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INVALID 0
#define VISA 1
#define AMEX 2
#define MASTERCARD 3

long get_card();
int validate_card_type(long cardNumber);
int get_long_int_length(long longInteger);
string get_card_type(int cardLength);
long get_card_numbers(long cardNumber, int cardLength, int cardNumbers);
int sum_of_digits_of_int(int intToSum);
bool is_card_valid(long cardNumber);

int main(void)
{
    long card = get_card();

    int validatedCardType = validate_card_type(card);

    bool isCardValid = is_card_valid(card);

    if (isCardValid && validatedCardType)
    {
        printf("%s\n", get_card_type(validatedCardType));
    }
    else
    {
        printf("%s\n", "INVALID");
    }
}

long get_card()
{
    long cardNumber;
    do
    {
        cardNumber = get_long("Number: ");

    } while (!cardNumber);

    return cardNumber;
}

int validate_card_type(long cardNumber)
{
    int cardLength = get_long_int_length(cardNumber);
    int firstNumber = get_card_numbers(cardNumber, 1, cardLength);
    int firstTwoNumbers = get_card_numbers(cardNumber, 2, cardLength);

    if (cardLength == 13 && firstNumber == 4)
    {
        return VISA;
    }
    else if (cardLength == 15 && ((firstTwoNumbers == 34) || (firstTwoNumbers == 37)))
    {
        return AMEX;
    }
    else if (cardLength == 16 && firstNumber == 4)
    {
        return VISA;
    }
    else if (cardLength == 16 && ((firstTwoNumbers == 51) || (firstTwoNumbers == 52) || (firstTwoNumbers == 53) || (firstTwoNumbers == 54) || (firstTwoNumbers == 55)))
    {
        return MASTERCARD;
    }

    return INVALID;
}

int get_long_int_length(long longInteger)
{
    int cardLength = 0;

    do
    {
        longInteger /= 10;
        cardLength++;

    } while (longInteger > 0);

    return cardLength;
}

string get_card_type(int cardType)
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

bool is_card_valid(long cardNumber)
{
    int currentIteration = 0;
    int sumOfMultipliedNumbers = 0;
    int sumOfOddNumbers = 0;

    do
    {
        int currentNumber = cardNumber % 10;
        cardNumber /= 10;

        int number = (currentIteration + 1) % 2;

        if (number == 0)
        {

            sumOfMultipliedNumbers += sum_of_digits_of_int(currentNumber * 2);
        }
        else
        {
            sumOfOddNumbers += currentNumber;
        }

        currentIteration++;

    } while (cardNumber > 0);

    int sumOfEvenAndOddIntegers = sumOfMultipliedNumbers + sumOfOddNumbers;

    bool isCardValid = sumOfEvenAndOddIntegers % 10 == 0;

    return isCardValid;
}

int sum_of_digits_of_int(int intToSum)
{
    int sumOfDigits = 0;

    do
    {
        int currentDigit = intToSum % 10;
        sumOfDigits += currentDigit;
        intToSum /= 10;

    } while (intToSum > 0);

    return sumOfDigits;
}