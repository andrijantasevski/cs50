#include <cs50.h>
#include <stdio.h>

#define QUARTER 25;
#define DIME 10;
#define NICKEL 5;
#define PENNY 1;

int get_change();
int get_quarters(int change);
int get_dimes(int change);
int get_nickels(int change);
int get_pennies(int change);

int main(void)
{
    int change = get_change();

    int quarters = get_quarters(change);

    int dimes = get_dimes(change);

    int nickels = get_nickels(change);

    int pennies = get_pennies(change);

    int cashOwed = quarters + dimes + nickels + pennies;

    printf("%i", cashOwed);
}

int get_quarters(int change)
{
    int quarters = change / QUARTER;

    return quarters;
}

int get_dimes(int change)
{
    int changeFromQuarters = change % QUARTER;
    int dimes = changeFromQuarters / DIME;

    return dimes;
}

int get_nickels(int change)
{
    int changeFromQuarters = change % QUARTER;
    int changeFromDimes = changeFromQuarters % DIME;

    int nickels = changeFromDimes / NICKEL;

    return nickels;
}

int get_pennies(int change)
{
    int changeFromQuarters = change % QUARTER;
    int changeFromDimes = changeFromQuarters % DIME;
    int changeFromNickels = changeFromDimes % NICKEL;

    return changeFromNickels;
}

int get_change()
{
    int change;

    do
    {
        change = get_int("Change owed: ");
    } while (change < 1 || change > 100);

    return change;
}