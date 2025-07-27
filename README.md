# cs50

## Week 0

## Week 1 — C

### Source code

Computers understand binary, so we need to compile our code to binary so that our computer can understand it and execute it. That is called machine code. The code that we write ourselves is called source code.

> source code -> compiler -> machine code

The patterns of bits (0s and 1s) have meanings behind them (e.g. ASCII).

### Hello, World

```bash
# create the file for the program
touch hello.c

# open the program in VSCode
code hello.c
```

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

```bash
# compile our program
make hello

# execute our program
./hello
```

### New-line break

To create a new line when printing out to the console, we use the **\n** sign.

```c
// creates three empty lines after printing out hello, world
printf("hello, world\n\n\n")
```

This is called an **escape sequence**. Escape sequences usually begin with a backslash (\\), which acts as an escape character and tells us that the following characters need to be interpreted a bit differently.

For example, \\n means newline, \\t means tab character etc.

To print out a double quote, we can also use an escape character (\\"):

```c
printf("hello, world\"");
```

### Functions and side effects

Functions take arguments, they do some processing and can produce a side effect. Side effects in this case can be defined as something that happens on the screen.

### Header files

Any file that ends in **.h** is called a **header file**.

For example, the **stdio.h** is a header file. If we don't include the stdio header file, we won't have access to the stdio library and we won't be able to call printf, for example.

A library is a collection of code that we or somebody else has written.

### Manual pages

Manual pages are documentation for the header files or standard libraries for C.

Manual pages are also referred to as man pages.

CS50 provides https://manual.cs50.io

### Hello, You

With the helper function get_string provided by cs50.h, we can prompt the user to enter their name in the terminal.

We need to declare a variable that is going to get the return value and type it as string because we are going to get a string.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");

    printf("Hello, %s\n", name);
}
```

### Types

Some types in C are:

- bool (true or false)
- char (single character)
- double (real numbers, with decimal points)
- float (real numbers, with decimal points)
- int
- long (larger integers)
- string

### Format codes

When we are using printf to print out values to the screen, we need to choose the correct format code that we want to print our value in. In our earlier example, we used %s, which is a format code or a placeholder for a string.
When we have a character or an integer, we need to use %c or %i respectively.

```c
char c = 'C';

printf('%c', c)
```

### Conditionals

```c
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else if (x == y)
{
    printf("x is equal to y\n");
}
```

An improved version of this code would be to add an else, because the final option is that x is equal to y.

```c
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}
```

### Comparison operators

Comparison operators in C are:

- == (equal to)
- != (not equal)
- \> (greater than)
- < (less than)
- \>= (greater than or equal to)
- <= (less than or equal to)

### Operators

- - (addition)
- - (subtraction)
- - (multiplication)
- / (division)
- % (modulo/remainder)

### Variables

To declare a variable in C, we need to define its type, name. We can, but we don't need to assign it a value.

```c
int counter = 0;

// to take the previous value of counter and increment it by 1.
counter = counter + 1;

// the above line can be written more succintly as
counter += 1;

// or even further simplified to
counter++;

// The same logic can be applied for decrementing:
counter--;
```

### Compare

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's x?");
    int y = get_int("What's y?");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}
```

### Agree

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? ");

    if (c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Disagreed.\n");
    }
}
```

### Strings vs chars in C

Strings are written in double quotes in C and chars are written in single quotes.

```c
char character = 'C';

string myString = "string";
```

### Logical operators

- && (AND)
- || (OR)
- ! (NOT)

### Loops

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 3;
    while (i > 0)
    {
        printf("meow\n");
        i--;
    }
}
```

We usually, however, count up instead of counting down:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
}
```

If we want to create an infinite loop, we can do the following:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    while (true)
    {
        printf("meow\n");
    }
}
```

### For-loops

```c
#include <cs50.h>
#include <stdio.h>

// the function returns nothing and accepts no arguments
void meow(void)
{
    printf("meow\n");
}

int main(void)
{
    for (int i = 0; i < 3; i++) {
        meow();
    }
}
```

### Functions and declaring prototypes

In this case, if we want to declare the function after it's called, we need to define the prototype of the function before it is called at the top of the file.

This gives the compiler a hint that there is going to be a function called meow that takes no input and returns nothing.

```c
#include <cs50.h>
#include <stdio.h>

void meow(void);

int main(void)
{
    for (int i = 0; i < 3; i++) {
        meow();
    }
}

void meow(void)
{
    printf("meow\n");
}
```

We can parametrize this function and abstract it away, by passing it only the amount of times we want to meow:

```c
#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
    meow(3);
}

void meow(int n)
{
    for (int i = 0; i < n; i++) {
        printf("meow\n");
    }
}
```

We can also prompt the user until they provide a positive number for how many times they want the cat to meow:

```c
#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);

    meow(n);
}

void meow(int n)
{
    for (int i = 0; i < n; i++) {
        printf("meow\n");
    }
}
```

### Integer overflow

```c
#include <cs50.h>
#include <stdio.h>

int dollars = 1;
while (true)
{
    char c = get_char("Here's $%i. Double it and give it to the next person? ", dollars);
    if (c == 'y')
    {
        dollars *= 2;
    }
    else
    {
        break;
    }
    printf("Here's $%i.\n", dollars);
}
```

In this program, if we keep doubling the value, we wil reach to a point where our integer value will not be able to store the value as the higest value
of an integer value in C can be 4294967295 (or 4294967296 for an unsigned integer). An integer contains 32 bits.

To fix or avoid this behavior, we can use the **long** type, but that is also not very helpful because it has a limit as well. The size of a long is 64 bits.

### Truncation

In the case below, whenever we divide two numbers that have a remainder, the decimal number is truncated. The reason for the truncation is that we are dividing an integer with an integer. Integers truncate decimal values.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", x / y);
}
```

To fix this, we can use the type **float** instead. However, there is another method called **casting**, which lets the user enter an integer, but still show the user the decimal number that is the result of the division between the two integers.

#### Casting

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%f\n", (float) x / y);
}
```

### Showing significant digits

To choose how many **significant digits** we want to show the user, we can use the following syntax:

```c
// formatted to 5 significant digits, i.e. 0.33333
printf("%.5f\n", (float) x / y);

// formatted to 50 significant digits
printf("%.50f\n", (float) x / y);
```

### Floating-point imprecision

The same issue arises when dividing num

### Mario-less

```c
#include <cs50.h>
#include <stdio.h>

int main()
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        // for (int j = 0; j < n - i - 1; j++)
        // {
        //    printf(" ");
        // }

        // for (int k = 0; k <= i; k++)
        // {
        //     printf("#");
        // }

        // printf("\n");

        int numberOfSpaces = n - (i + 1);
        int numberOfSpacesCreated = 0;
        // printf("%i", numberOfSpaces);
        // printf("\n");

        for(int j = 0; j < n; j++)
        {
            if (numberOfSpacesCreated < numberOfSpaces)
            {
                printf(" ");
                numberOfSpacesCreated = numberOfSpacesCreated + 1;
            } else
            {
                printf("#");
            }
        }

        printf("\n");
    };
}
```

## Week 2
