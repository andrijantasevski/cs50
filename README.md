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

### Integer

The integer data type is used for variables that will store integers.

Integers always take up 4 bytes of memory or 32 bits, which means that the range of values they can store is limited to 32 bits worth of information.

The range is from -2^31 to 2^31-1 (the minus -1 is because we need a space for zero).

So the values that can fit in a 32-bit signed integer are:

-2,147,483,648 to 2,147,483,647

### Unsigned integer

Unsigned integers are not a separate type, but they are a modifier to the integer type.

Unsigned integers effectively double the range of the integer type, so the range is now from 0 to 4,294,967,295.

Now the values are 2^32-1 (the minus -1 is because we need a space for zero).

We use unsigned integers when the value wa want to store is positive and bigger than 2^31-1.

### Short integer

Short integers are a modifier to the integer type.

The short is lesser in size than the integer by 2 bytes (16 bits), so it can store values from -32,768 to 32,767.

There is also an unsigned short int, which effectively doubles the range of the short int.

### Long integer

Long integers are a modifier to the integer type.

Long integers are 64 bits, so they can store values from -2^63 to 2^63-1.

On 32-bit systems, the range is from -2^31 to 2^31-1.

On 64-bit systems, the range is from -2^63 to 2^63-1.

Sometimes, to get 64 bits, we need to use the **long long int** type.

### Char

The char data types is used for variables that will store single characters.

Characters are stored in 1 byte (8 bits) of memory.

The range of values that can be stored in a char is from -128 to 127.

With ASCII, there is a mapping between the characters and numbers from the positive side of the range. For example, the character 'A' is 65, and the character 'Z' is 90.

### Float

The float data types is used for variable that will store floating point values or also known as real numbers.

Floating point numbers always take up 4 bytes of memory.

It's hard to define the range of values that can be stored in a float. Some of the bits can be used for the integer part and the rest for the decimal. Beecause there is 32 bits, we are limited in how precise we can be as we cannot store more than 32 bits of information.

### Double

Doubles are used to store floating point values or real numbers. However, unlike floats, doubles can store more information, so they are more precise.

Doubles take up to 8 bytes (64 bits) of memory.

### Void

Void is not a data type, but it is a type that is used to indicate that a function does not return a value.

The parameter list of a function can also be void, which means that the function does not take any parameters.

```c
// Return type is void
void printHello(string name)
{
    printf("Hello, %s\n", name);
}

// Parameter list is void
int main(void)
{
    printHello("World");
}
```

### Bool

Bool is not a primary data type. In fact, it did not exist in C until C99.

It can take two values: true and false.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    bool isTrue = true;
    bool isFalse = false;

    printf("isTrue: %i\n", isTrue);
    printf("isFalse: %i\n", isFalse);
}
```

In C, every non-zero value is considered true, and zero is considered false.

### String

String does not exist as a data type in C, but it is provided by the CS50 library. It is used to store a series of characters.

A string in C is an array of characters. The array is terminated by a null character (\0).

A string is called a string because it is a string of characters.

### Structs

Structs are used to group data together.

We can use structs to create a new data type that can store multiple values.

For example, we can create a struct that can store a name and an age.

### Typedef

Typedefs are used to create data types that we need for our programs.

### Creating a variable

To create a variable, we need to give it a type and a name.

```c
int number;
```

We can also create multiple variables of the same time on the same line:

```c
int number, number2, number3;
```

### Declaring, assigning and initializing

So what we did above was declaring a variable, which means that we have a type and a name for the variable, but the variable is not assigned a value.

To assign a value to a variable, we need to use the **=** sign.

```c
// We declare a variable called number
int number;

// We assign a value to the variable number
number = 5;
```

We can also declare a variable and assign at a value at the same time, this is called **initializing**.

```c
int number = 5;
```

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

### Switch statement

The switch statement is a conditional statement that permits enumeration of discrete cases, instead of relying on Boolean expressions.

```c
int x = 3;

switch (x)
{
    case 1:
        printf("x is 1\n");
        break;
    case 2:
        printf("x is 2\n");
        break;
    case 3:
        printf("x is 3\n");
        break;
    default:
        printf("x is not 1, 2, or 3\n");
}
```

Basically, the switch statement compares the value of the expression (x) to the values of each case. If the value of the case matches the value of the expression, then the code inside the case is executed.

We need to be careful and use the break statement to break out of the switch statement because if we don't, we will fall through each case, unless that is the desired behavior.

What this means is that if we don't have a break statement, the case is going to be executed for every case even if the value of the expression is not the same as the value of the case. All the code is going to be executed unless it encounters a break statement.

```c
int x = 1;

switch (x)
{
    case 1:
        printf("x is 1\n");
    case 2:
        printf("x is 2\n");
    case 3:
        printf("x is 3\n");
        break;
    default:
        printf("x is not 1, 2, or 3\n");
}
```

In the example above, we are going to print out x is 1, x is 2, and x is 3, because the first break is in case 3.

### Ternary operator

The ternary operator is a conditional operator that is used to assign a value to a variable based on a condition.

```c
int isUnderAge = age < 18 ? 1 : 0;
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

### Do-while loops

Do-while loops are similar to while loops, but they first execute the code within the do statement and then check the condition, which means that the code within the do statement is executed at least once.

```c
do
{
    printf("meow\n");
} while (0);
```

In this case, the code within the do statement is executed once, because the condition is always false.

### When to use each loop

- while loops are used when we want to a loop to repeat an unknown number of times or possibly not at all.

- do-while loops are used when we want a loop to repeat an unkown number of times, but at least once.

- for loops are used to repeat a discrete number of times, though we may not know how many times when the program is compiled.

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

### Magic numbers

Magic numbers are constants that we directly write into our code.

For example, we can take a look at this function:

```c
card deal_cards(deck name)
{
    for (int i = 0; i < 52; i++)
    {
        // deal the card
    }
}
```

In the case above, the magic number is 52 because it is directly written into the code.

We can improve this code by using a variable to assign the value of 52 to.

```c
card deal_cards(deck name)
{
    int deck_size = 52;
    for (int i = 0; i < deck_size; i++)
    {
        // deal the card
    }
}
```

An issue with this code is that the variable can be changed, which means that we can't be sure that the value of the variable is 52.

C provides a preprocessor directive, also called a macro that can be used to create symbolic constants.

```c
#define NAME REPLACEMENT

// or the deck size can be defined as

#define DECK_SIZE 52

card deal_cards(deck name)
{
    for (int i = 0; i < DECK_SIZE; i++)
    {
        // deal the card
    }
}
```

At the time of compilation, #define goes through our code and replaces all instance of NAME with REPLACEMENT.

So, basically, #include behaves like a copy and paste, but #define is more like a find and replace.

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

## Week 2 - Arrays

### Cryptography

Cryptography is the art of scrambling information so we can communicate securely. For example, we can encrypt a message, a password, or a file.

This text UIJT JT DT50 is scrambled so that it is hard to read what it says, but it is still readable as it leaks information with the 50 and the size of the text because we can see it says THIS IS CS50, as we are doing this in the course.

Encryption is the act of hiding plain text from prying eyes.

Decryiption is the act of taking an encrypted piece of text and returning it to a human-readable form.

### Compiler

A compiler is a specialized computer program that converts source code into machine code that can be understood by a computer.

There are different compilers, some of the most known compilers for C are **clang** and **gcc**.

We need to install clang differently on each operating system. O

n Ubuntu, we can install it with:

```bash
sudo apt install clang
```

On Windows, we can install it with:

```bash
choco install llvm
```

On Mac, it usually comes with Xcode. The Apple version of clang is not the same as the public version of clang.

### clang

To compile a simple C program, we can use the clang comppiler.

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, World\n");
}
```

So, if we run the command clang and the name of the file, we get a file called **a.out** by default, which is **assembler output**

```bash
clang hello.c

ls

./a.out
```

So, a.out is just a default name for a file that is actually a binary executable.

To specify a custom file for the program, we can pass the **-o** flag to the compiler like so:

```bash
clang hello.c -o hello
```

The code above would create an executable called hello instead of a.out.

### Compiling

The process of turning the source code we write into a binary that is executable is called compiling.

Compiling in C involes four major steps:

- Preprocessing
- Compiling
- Assembling
- Linking

### Preprocessing

Preprocessing is the first step during the compilation process where the header files, designated by a # (such as #include <cs50.h>) are effectively copied and pasted into our file.

During this step, the code from stdio.h or cs50.h, for example is copied into our program.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name?");
    printf("Hello World!\n");
}
```

Essentially all the relevant code would be copied into our file like so:

```c
string get_string(string prompt) // this a prototype of the function
int printf(string format, ...) // another prototype of a function

int main(void)
{
    string name = get_string("What's your name?");
    printf("Hello World!\n");
}
```

### Compiling

During the compilation process, our program is converted to assembly code.

Assembly code is the code that is used to give instructions to the CPU.

```assembly
...
main:
    .cfi_startproc
# BB#0:
    pushq    %rbp
.Ltmp0:
    .cfi_def_cfa_offset 16
.Ltmp1:
    .cfi_offset %rbp, -16
    movq    %rsp, %rbp
.Ltmp2:
    .cfi_def_cfa_register %rbp
    subq    $16, %rsp
    xorl    %eax, %eax
    movl    %eax, %edi
    movabsq    $.L.str, %rsi
    movb    $0, %al
    callq    get_string
    movabsq    $.L.str.1, %rdi
    movq    %rax, -8(%rbp)
    movq    -8(%rbp), %rsi
    movb    $0, %al
    callq    printf
    ...
```

### Assembling

The assembling part converts our assembly code into machine code or binary, which can be visualized as follows:

```
01111111010001010100110001000110
00000010000000010000000100000000
00000000000000000000000000000000
00000000000000000000000000000000
00000001000000000011111000000000
00000001000000000000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
10100000000000100000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
01000000000000000000000000000000
00000000000000000100000000000000
00001010000000000000000100000000
01010101010010001000100111100101
01001000100000111110110000010000
00110001110000001000100111000111
01001000101111100000000000000000
00000000000000000000000000000000
00000000000000001011000000000000
11101000000000000000000000000000
00000000010010001011111100000000
00000000000000000000000000000000
00000000000000000000000001001000
...
```

### Linking

During the linking step, the code from our included libraries is also converted into machine code and it is combined with our code and then the final executable is outputted.

### Makefile

Makefiles help us automate the process of compiling our C/C++ programs.Specifically, they are used to help decide what parts of a large program need to be recompiled.

To create a makefile, we can run the following command in the termimal:

```bash
touch Makefile
```

We can add the following content to a Makefile:

```makefile
hello:
    echo "Hello World"
```

Now, if we run **make** in the terminal, we are going to get the following

```bash
make

echo "Hello World"
Hello World
```

Whenever we run **make**, we are going to get the exact same output.

### Makefile syntax

A Makefile consits of a set of rules. A rule looks like this:

```makefile
targets: prerequisites
    command
    command
    command
```

- The **targets** are the file names, separated by spaces. Typically, there is only one per rule.
- The **commands** are a series of steps typically used to make the target(s). They (the commands) need to start with a **tab character** and not spaces.
- The **prerequisites** are also file names, separated by spaces. These files need to exist before the commands for the target are run. These are called **dependencies**.

Let's take a look at the following example:

```makefile
hello:
    echo "Hello World"
    echo "This line will print if the file hello does not exist"
```

In this example, **hello** is a target, but since the target or file does not exist all, we are going to print the text in both the echo commands every time we run make.

The target hello in this case has no prerequisites or dependencies and it has two commands.

It is important to think about hello both as a target and a file because they are almost always tied together. Typically, when a target is run or rather the commands for the target are run, they will create a file with the same name as the target. However, in this case, no target file is created, which is why we run the command over and over again.

Before, we move on with the following example, we need to create a **hello.c** file that is just going to print out Hello World in the terminal.

Let's take a look at another example:

```makefile
hello:
    clang hello.c -o hello
```

In this example, our target is hello, we have no prerequisites/dependencies. However, we have a command that produces a file with the same name as the target, which is usually the intended behavior when using makefiles.

The first time that we run make, we produce the hello executable which is also the target file. If we run make for a second time, we get the following message:

```bash
make: `hello' is up to date.
```

We get this message because make has already produced that file and it knows that it shouldn't run the same command again. This is an issue, however, because if hello.c is modified, the code does not get compiled again.

This is why we need to introduce prerequisites:

```makefile
hello: hello.c
    clang hello.c -o hello
```

This means that whenever we run make, we check if hello.c has been changed, specifically it's timestamp. If it's been changed, then we recompile the program again.

To recap, in the case above, hello is the target/file, hello.c is the prerequisite and clang and everything that follows it is the command.

### Make clean

Clean is often used as a target that removes the output of other target.

It is not a special word in Make.

So, clean in this case is not a target that is the first and default and it is not a prerequisite. This means that it'll never run unless we explicitly call make clean.

```makefile
hello: hello.c
    clang hello.c -o hello

clean:
    rm -f hello
```

Clean is not intended to be a filename, if it appears as a filename, the target won't run.

So if we want to recompile the program without changing the dependency hello.c, we can just run make clean, which would remove the hello file and then we can run make again, which would recompile the program.

### Variables

We can initialize variables by using a name for the variable, then by using the assignment operators (= or :=) and assigning a value to the variable.

We get access to the variable by using $() or ${}.

```makefile
a := Hello World

hello:
    echo $(a)
```

### Simple Makefile

```makefile
CC := clang
CFLAGS = -Wall

main: main.o
    $(CC) $(CFLAGS) -o main main.o

main.o: main.c
    $(CC) $(CFLAGS) -c main.c

clean:
    rm -rf main.o main
```

### Debugging

One of the most useful ways to debug is by using **printf**, which is also called printf debugging.

With printf, we can print out whatever we have stored in memory.

### Setting up a debugger

### Memory

Inside our computers, we have a finite amount of memory available to us.

We can imagine the memory in our computers as a big matrix (rows with columns), where the column in each row is 1 byte (this is purely for explanation purposes). So, if we want to store a char, which is 1 byte, we would take up 1 column in a row. If we want to store an int, which requires 4 bytes, we would take up 4 columns of the row.

Types like int or char always take up **contiguous memory**, which means that the memory they take is back-to-back.

```c
int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;
}
```

When we run the program written above, we basically are asking the computer for 4 of the columns in the matrix/grid that we mentioned above for the first variable (score1), then another 4 bytes for the second variable (score2) and another 4 for the third variable (score3).

The value of each variable is stored in memory back-to-back. However, the variables themselves do not necessarily need to be stored back-to-back in memory. For example, score1 and score2 can be stored back-to-back, while score3 can be stored at a different
place/address.

What the computer does is store the patterns of bits in those pieces of memory, so for the score1 variable, it stores the pattern for the number 72 in 32 bits: 00000000000000000000000001001000. It does the same for the other 2 variables as well.

### Arrays

Arrays are a fundamental data structure.

Arrays are a sequence of values that are stored **back-to-back** in memory. This means that the values in an array are stored contiguosly in memory.

The values of an array need to be of the same type, for example, all values can be either int or char.

We can conclude that we use arrays to hold values of the same type at contiguous memory locations.

### Array indexing

In C, the elements of an array are indexed starting from 0, which is also one of the major reasons we count from zero.

We can then say that if an array consists of _n_ elements, the first element is located at 0 and the last element is located at n-1. For example, if our array consists of 50 elements, the first element is at index 0 and the last element is at index 49.

C is very lenient when it comes to accessing indices of arrays. At compile time, we are able to access elements that are outside of bounds of our array. At runtime, however, we would get a segmentation fault.

### Array declarations

Arrays are typically declared in the following manner:

```c
type name[size]
```

**Type** is the kind of variable each element of the array will be.

**Name** is what we want to call our array.

**Size** is how many elements we would like our array to contain.

Let's take a look at this example:

```c
int studentGrades[40];
```

The type of the elements of the array is going to be int. The name is studentGrades and its size is 40 elements or ints.

### Array instatiation

To instantiate an array at the same time while declaring it, we can use the following syntax:

```c
bool truthable[3] = { false, true, true };
```

We can also declare an array and then fill out the elements with values with the **individual element syntax**:

```c
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = false;
```

We can also declare an array without specifying the number of elements, but we have to instantiate the array immediately with all the elements its going to contain. This way the compiler knows the size of the array at compiletime.

```c
bool truthtable[] = { false, true, true };
```

Arrays can consist of more than a single dimension. In fact, we can have as many specifiers as we wish.

```c
bool battleship[10][10];
```

In the example above, we can think of the array as a 10x10 grid of cells, where we have 10 rows where each row has 10 columns.

In memory though, it's really just a 100-element one-dimensional array.

Multi-dimensional arrays are great abstractions to help visualize game boards or other complex representations.

### Array assignment

We can treat individual elements of arrays as variable. This means that we can assign indivudal elements of an array to a variable, like this:

```c
int number[3] = { 0, 1, 2 };

int numberAtIndexZero = number[0];
```

It is not legal, however, to assign one array to another in C. For example, we can't do the following:

```c
int foo[3] = { 0, 1, 2 };
int bar[3];

bar = foo;
```

The assignment of bar to foo is not allowed. Instead, we need to copy the array into the other, by using a for loop, which can be a bit time consuming.

```c
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];

for (int i = 0; i < 5; i++)
{
    bar[j] = foo[j];
}
```

### Arrays as passed by reference

Most variables in C are **passed by value** in function calls, which means that the callee or the function call receives a copy of the value and not the actual value and where it is stored in memory.

Arrays do not follow this rule and we say that they are **passed by reference**. They receive the actual array and not a copy of it. The reason for this is so that our code is faster and we don't need to copy over all the time arrays with big amount of elements.

We need to be very careful when passing arrays to functions because if we change the value of an element in the array, we are changing the original array, which in a lot of cases may not be the desired result.

### Constants

If there is a value that we don't want to change and that is not going to be changed and is also going to be used across our whole program, we can define a constant.

Previously we took a look at macros and defining them at the top of our file. However, macros do not have a data type defined explicitly, whereas constants do.

We usually declare and initialize constants at the top of our file in capital letters.

```c
const int DAYS_IN_A_WEEK = 7;
```

### Strings

```c
#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c%c%c\n", c1, c2, c3);
}
```

In the example above, we have written each of the letters within single quotes because they are of type char.

When we print this out, we will get HI!. We are not printing it as a string, but rather as char, char, char.

```c
#include<stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%i %i %i\n");
}
```

When we print out the characters as integers to see their underlying implementation/value, we get the corresponding ASCII values of the characters, namely: 72, 73,33.

In memory, each character would take 1 byte because chars are 1 byte and in memory, we would actually store the pattern of bits for each number. For example, for H, we would need to get the pattern of bits for 72, which is: 01001000.

### Strings as sequences of characters.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!"
    printf("%s\n, s);
}
```

When we print this out, we would get HI! once again, however, this time, we store the string in contiguous memory as a sequence of characters or as **an array of characters**.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%c%c%c\n", s[0], s[1], s[2]);
}
```

If we print this out we get the exact same result, HI! because a string is an array of characters and we can access each character in the array by its index.

### String and NUL character

When strings are stored in memory, we need to know where the string ends. For this purpose we use the **NUL character**, which is an actual **0** that is attached to the end of each array of characters. So, the actual length of each array of characters for a string is the length of the string plus one byte to mark where the string ends with **00000000**.

Typically, we do not write the **0** as a **0**, but rather, we write **\0**, which is a convetion.

If we open up an ASCII chart, we can find the **sentinel** or **terminating** character NUL for the value 0.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}
```

In this case, if we print out the integer values behind the characters of the string HI!, we would get 72, 73, 33, 0. The **0** would be NUL character or the sign where the string is terminated.

### String length

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");

    int n = 0;

    while (name[n] != '\0')
    {
        n++;
    }

    printf("%i\n", n);
}
```

To check the length of a string, we can loop over a string with a while loop until we encounter the NUL character or where the string terminates. We can increment an int variable whenever we see a character.

We can also extract this functionality into a function since it is so common.

### string.h

There is a standard C library for working with strings, which we can use by including the header file **string.h**.

In this standard string library, there is such a function for checking the string length, which would be strlen.

Instead of writing such a common function to find out the string length, we can use **strlen**.

### ctype.h

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");

    for (int i = 0, length = strlen(s); i < length ;i++)
    {
        printf("%c", s[i]);
    }

    printf("\n");
}
```
In the code snippet above, we have introduced a new way of declaring and initializing a variable that we use in for-loops. We can inline a variable that is used as the boundary to which the loop should get to and we can use it in our condition.

The variable is defined and inlined there so that the value gets calculated once, in this case the length of the string and we access only the value of the variable __length__.

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
           printf("%c", s[i] - ('a' - 'A');
        }
        else
        {
            printf("%c", s[i]);
        }
    }
}
```

In the code above we are printing out all of the letters of the string as uppercase.

The main logic is in the if-statement in the for-loop.

We know that each character in C is actually just the ASCII number/integer, in the if condition, we check if the letter is lowercase or rather, whether it is in the range of 97 to 122. If it is within that range, it means it is lowercase. If it is not, we print it out as it is.

To make it uppercase, however, we can calculate the difference between the lowercase letter and the uppercase letter, which is always 32.

We don't even need to hardcode the 32 itself as well, as we can calculate what is the distance between __lowercase a__ and __capital A__.

Even though it is great to know the underlying implementation of how we can make letters lowercase and uppercase, we can use the standard library in C called __ctype__. It has various functions, some of which are __toupper__ and __tolower__.

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");

    for (int i = 0; n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
}
```

This way we have simplified our code by using a standard library function that performs a similar function to what we had implemented previously.


### Command line arguments

Command line arguments are the arguments that are passed to our program at the command line. For example, all the statements that we type after __clang__ are considered command line arguments. We can also use these command line arguments in our own programs.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
```

In the code above, we run the program and after we run it, we prompt the user to enter some string, which in this case is their name. However, we can provide a value to the program even before we run it through command line arguments.

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}
```

So far in our code, we have been creating our functions with a void type for the argument list because we did not read or need the command line arguments.

The main function takes __2 arguments__, which are __argc__ and __argv__.

The argument __argc__ is of type __int__ and it gives us the amount of arguments that have been passed to the main function.

The argument __argv__ is an __array of strings__ and it gives us the values of the parameters that have been passed to the main function.

The __first parameter__ that is passed to the main function is _always_ the __name of the program__ whereas the other parameters are the ones we pass to the program as the users.

Technically, the parameters can be named anything we want to, but it is the convention to name them argc and argv.

The name __argc__ means __argument count__, which is associated with its use.

The name __argv__ means __argument vector__.

In our program above, we are checking if the number of argument is 2. This means that we passed only 1 argument becuase the first one is always the name of the program. If we have passed 2 arguments, we just print out hello and the value provided to the program in the first argument.

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}
```
In the example above, we are printing out all the arguments provided to a program by creating a for-loop based on the amount of arguments passed to the main function.

It is important not to overstep the bounds of the argv array because it is very likely that we get a __segmentation fault__.

### Exit status

The reason as to why the main function has a __return__ type of __int__ is because programs have a convention of returning an int when they finish, either successfully or unsuccessfully. The integers that they exit with are called __exit codes__ or an __exit status__.

By convention, whenever a program exits with the integer 0, it means that it has executed successfully and that there are no errors. When the program exits with an integer other than 0, it means that it has not executed successfully.

The reason for choosing this is because there are many different kinds of issues that we need to describe as errors, which is why its maybe counterintuitive that 0 (false) is the success code. For example, we have an error code 404 for not found in web browsers.

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command line argument\n");
        return 1;
    }

    printf("hello, %s\n", argv[1]);
    return 0;
}
```

In the program above, we return 1 if the number of arguments is different than 2, which means that the program did not execute successfully. If it executes successfully, it prints out the greeting and returns a status 0.

To check the exit status code of the most recently executed program, we can use the following command in the terminal: __echo $?__.

### Encryption

Encryption is the art of ciphering and deciphering a message.

Encryption is basically a process of __scrambling__ information but in a __reversible__ way, because it would be pointless if we scramble the information and then can't unscramble it back.

The input is what we call a __plaintext__ and the scrambled text is the __ciphertext__.

The function that scrambles the text or performs the action of ciphering is called __cipher__.

Ciphers rely on __keys__ or __secrets__, which are provided to the cipher as the second input besides the plaintext.

Caesar's cipher is a technique where we pass a plaintext and a number as a key, which would be the number of letters that we want to rotate each letter of the alphabet for. For example, for a very simple case, if we pass the plaintext __A__ and the key __one (1)__, we would rotate the letter 1 place and we would get the letter __B__ as the cipher text.

If we want to decrypt that message, we need to pass a key again, but in that case we would need to pass -1, which would rotate the letter of the alphabet one letter back and we would get the original text again, which was A.
### Functions

Nearly all languages have the concept of a function, but we can find that functions are named differently across languages.

In C, they are named functions, but we can find the names: **procedures**, **methods** (in object oriented programming languages), or **subroutines**.

Functions are essentially black boxes with a set of 0+ inputs and 1 output.

In this case again, there are languages that allow us to return multiple outputs. For example, the language Go allows for multiple return values.

```c
func(a, b, c);
```

In the example above, **func** is the name of the function and **a**, **b**, **c** are the inputs to the function.

```c
add(a, b, c);
add(3, 6, 7);
```

In the example above, we changed the inputs of a, b, c with actual values. The output is the result of the addition, which is 16.

### Functions as black boxes

Functions are called black boxes because if we are not writing the functions ourselves, we don't need to know the underlying implementation. Such an example is the **printf** function in C. We call the function very frequently with the necessary parameters, but we don't necesarilly need to know about the implementation.

That is also part of the contract of using functions. The behavior should typically be predictable based on the name of the function. That's why most functions should have clear, obvious names, and should be well-documented.

### Why use functions?

Functions should be used to **organize** complicated problems into more manageable subparts, especially when our code starts becoming very large in size.

Functions should be used to **simplify** our code as smaller components tend to be easier to design, implement, and debug. When our functions are simple and with a smaller scope, they can be also tested easily.

Function should be designed to be **reused**, which means that we need to write them once but we can use them as often as we need.

### Function declarations

The first step to creating a function is to declare it. This gives the compiler a heads-up that a user-written function appears in code.

Function declarations should always go to the top of our code, before we begin writing main().

There is a standard form that every function declaration follows:

```c
return-type name(argument-list);
```

The **return-type** is the kind of variable the function will output.

The **name** is what we want to call our function.

The **argument-list** is the comma-separated set of inputs to our function, each of which has a type and a name.

Below is a function that adds two integers:

```c
int add_two_integers(int a, int b);
```

The sum of the two integers is going to be an integer as well, which is why the return-type is int.

Based on what the function does, we give it an appropriate name, which in this case is adding two integers.

There are two inputs to this function. There's nothing important about these inputs as far as we know, so giving them simple names is all right.

### Function definitions

The second step to creating a function is to define it.

This allows for predictable behavior when the function is called with inputs.

First we declare our function above the main function.

```c
float multiple_two_reals(float x, float y);

int main(void)
{
    // some code
}
```

In the second step, we define our function somewhere below our main function with the actual implementation.

```c
float multiple_two_reals(float x, float y)
{
    float product = x * y;
    return product;
}
```

### Function calls

Now that we have declared and defined a function, we need to call it to use it.

To call a function and use it, we simply pass the appropriate arguments and assign its return value to something of the correct type.

```c
int main(void)
{
    float product = multiple_two_reals(3, 5);
}
```

### Functions and void

There are functions that take no inputs. When a function takes no input, we declare the function as having a **void** argument list.

```c
int get_random_number(void);
```

On the other hand, when functions don't have an output, we declare the function as having a **void** return type.

```c
void printName(string name);
```

### Practice problem - valid_triangle

```c
#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int a, int b, int c);

int main(void)
{
    bool isTriangleValid = valid_triangle(1, 3, 3);
}

bool valid_triangle(float x, float y, float z)
{
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }

    if ((x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }

    return true;
}
```

### Variable Scope

Scope is a characteristic of a variable that defines from which functions that variable may be accessed.

There can be **local** and **global** variables.

**Local variables** can only be accessed within the functions in which they are created. This means that they can't be used by other functions in our program.

**Global variables** can be accessed by any function in the program. This type of variable is declared outside of all the functions of our program, which enables us to use it in any of our functions of the program.

```c
int main(void)
{
    int result = triple(5);
}

int triple(int x)
{
    return x * 3;
}
```

In our case above the variable **result** is local to the main function. On the other hand, the variable **x** that is an argument in the triple function is local to the function itself and cannot be accessed by any other function in the program.

Let's take a look at another example:

```c
#include <stdio.h>

float global = 0.5050;

int main(void)
{
    triple();
    printf("%f\n", global);
}

void triple(void)
{
    global *= 3;
}
```

In the case above, we have a variable called global that has a global scope. We can access that variable within any function of our program, which is why we would print out to the console 1.515.

Declaring global functions and modifying them needs to be used carefully as it can lead to mistakes if the same variableis used across many different functions in our program. Mutating global variables can be a source of bugs.

We need to also be very careful when it comes to naming variables because we can have issues if we name variables with the same names in local and global scopes.

### Variables - passed by value

For the most part, local variables in C are **passed by value** in function calls.

When a variable is passed by value, the callee or the function that is called receives a copy of the passed variable andnot the variable itself. That means that the variable in the caller or the original function is **unchanged** unless we **overwrite** it.

Let's take a look at the example below:

```c
int main(void)
{
    int foo = 4;
    triple(foo);

}

int triple(int x)
{
    return x *= 3;
}
```

In the example above, we pass the value of the variable foo to the triple function or the callee. We don't pass the variable itself. We basically have a new copy of the variable in the triple function itself, which is why the variable in the caller function or main would remain unchanged.

```c
int main(void)
{
    int foo = 4;
    foo = triple(foo);
}

int triple(int x)
{
    return x *= 3;
}
```

In the example right above, we change the value of the foo variable because we overwrite it with the return value of thetriple function, however, the variable x still remains local and passed by value in the triple function.

## Week 3

### Linear search

Previously, we said that arrays are data structures that can store N-amount of elements of a certain type (int, char etc.) in contiguous memory or rather back-to-back.

```c
int numbers[] = {1, 2, 3};
```
For example, in this case, the numbers 1, 2 and 3 are stored one after the other in memory or contiguously.

If we want to find a specific number in that array, let's say the number 3, we as humans can just take a look at it and say that it is in the last position. However, the computer doesn't know that the number 3 is in the last position or the index 2 of the array.

We can therefore imagine that these values are hidden behind a closed door that we need to open so we can see their value and check if it is the one we are looking for, in this case, the int 3.

For the search of the value 3 to be effective and repeatable, we need to do it methodically with an algorithm.

One of the simplest methods for searching for an element in array is __linear search__.

In linear search, the idea of the algorithm is to iterate across the array from left to right, searching for a specified element.

In _pseudocode_ the algorithm would be as follows:

- Repeat starting at the first element
- If the first element is what you are looking for (the target), stop
- Otherwise, move to the next element

So, if we want to find the int 3 in the array of 1, 2, 3, we would take the following steps:

- Repeat starting at the first element
- Is element at index[0], its value is 1? No, it is not, move on to the next element.
- Is element at index[1], its value is 2? No, it is not, move on to the next element.
- Is element at index[2], its value is 3? Yes, the value is 3, the one we are looking for.

If we wanted to find the number 4 in the array of 1, 2, 3, we would have performed all the steps, but we wouldn't have found the number 4 as it is nonexistent. This doesn't mean that the algorithm failed, it just didnt't find the number we were looking for.

Therefore, the __worst-case scenario__ for linear search is that we have to look through the entire array of n elements, either because the target is the __last__ element or it doesn't exist in the array at all.

The __best-case scenario__, on the other hand, would be for the target element to be the __first__ element in the array, so we can stop looking immediately after we start.

We can say that the worst-case scenario takes __N amount of steps__, in this case, if the array is 500 elements, it would take 500 steps.

In the best-case scenario it would take __1 step__ no matter the size of the array if the element we are looking for is in the first place of the array.

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int linear_search_int(int array[], int target);

int main(int argc, char *argv[])
{
    int array[11] = {3, 4, 5, 6, 7, 1, 10, 20, 31, 41, 80};

    int isElementInArray = linear_search_int(array, 7);

    printf("Is element %i in array? %s\n", 7, isElementInArray ? "Yes" : "No");
}

int linear_search_int(int array[], int target)
{
    for (int i = 0; i < 11; i++)
    {
        if (array[i] == target)
        {
            return 1;
        }
    }

    return 0;
}
```

## Binary search

There are other more efficient algorithms for searching through an array, one of those algorithms is called __binary search__.

As opposed to linear search, binary search has a __precondition__: the array needs to be __sorted__. If the array is not sorted, then we cannot make assumptions about the array's contents.

The idea of the algorithm for binary search is __divide and conquer__.

A divide-and-conquer algorithm recursively breaks down a problem into two or more sub-problems of the same related type, until these become simple enough to be solved directly.

__Binary search__ works by reducing the search area by __half__ each time, trying to find a target number.

The __pseudocode__ for binary search is the following:

- Repeat until the (sub)array is of size 0:
- Calculate the middle point of the current (sub)array
- If the target is at the middle, stop
- Otherwise, if the target is less than what's at the middle, repeat, change the end point to be just to the left of the middle.
- Otherwise, if the target is greater than what's at the middle, repeat, changing the start point to be just to the right of the middle.

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int binary_search(int array[], int arraySize, int target);

int main(void)
{
    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 50, 60, 70, 90};

    int sortedArraySize = sizeof(sortedArray) / sizeof(int);

    int isTargetElementFound = binary_search(sortedArray, sortedArraySize, 10);

    printf("Is target element %i in array? %s\n", 10, isTargetElementFound ? "Yes" : "No");
}

int binary_search(int array[], int sortedArraySize, int target)
{
    int startingPoint = 0;
    int endingPoint = sortedArraySize - 1;

    while (startingPoint <= endingPoint)
    {
        int middlePoint = round((startingPoint + endingPoint) / 2.0);

        if (array[middlePoint] == target)
        {
            return 1;
        }
        else if (target < array[middlePoint])
        {
            endingPoint = middlePoint - 1;
        }
        else if (target > array[middlePoint])
        {
            startingPoint = middlePoint + 1;
        }
    }

    return 0;
}
```
### Binary search vs. linear search

So far we have seen that when we are searching for an element using linear search, the steps of the algorithm increase as the data increases. For example, if we have an array of 100 elements and the element is in last place, the algorithm would take 100 steps to complete as it would have to check every element in the array.

In contrast, we can notice that binary search eliminates half of the elements every time we perform a step of searching. So if we have an array of 100 elements, it would take us 7 steps in the worst case to find the element we are looking for.

The amount of steps performed when searching for an element with linear search always __grows linearly__ with the amount of elements of the dataset or array, as the name itself implies.

The amount of steps performed increases when searching for an element with __binary search__ as we __double__ the elements in the data set.

### Running time

When we write and design our algorithms, it is always important to consider their efficiency.

The efficiency of algorithms isn't measured in raw time, like in seconds or minutes because that can vary depending on the underlying hardware. For example, if we execute the same algorithm on hardware from 20 years ago and today, the execution might be faster on today's hardware, but that doesn't make the algorithm more efficient.

Instead, the efficiency of algorithms is measured in the number of steps an algorithm takes as the input increases.

### Asymptotic notation

To help quantify the efficiency of an algorithm, we use __asymptotic notation__ in computer science. Specifically, it is used to easy communication regarding __time complexity__.

There are mainly three asymptotic notations:

- Big-O Notation (O-notation)
- Omega Notation (Ω-notation)
- Theta Notation (Θ-notation)

Big-O notation is used for analyzing the worst-case complexity of an algorithm or the maximum number of steps it would take to complete it relative to the elements of the input.

Omega notation is used to analyze the best-case complexity of an algorithm.

Theta notation is used to analyze the average-case complexity of an algorithm.

### Big O

As previously mentioned Big-O notation is used for analyzing the worst-case complexity of an algorithm.

It aims to give an answer to the following question: _if there are N data elements, how many steps will the algorithm take?_

Let's apply this question to linear search.

For an array or data set of __N data elements__, linear search would take __N amount of steps__.

In other words, we can say that linear search is O(N) or __Big O of N__. It can also be referred to as __Order of N__.

If an algorithm has an O(N), we can also say that it has __linear time__.

The most common Big-O notations are the following:

- 𝑂(𝑛^2)
- O(nlogn)
- O(n)
- O(logn)
- O(1)

### O(1)

When we read elements from an array by their index, we can say that the algorithm takes __1 step__ regardless of the amount of data elements. Expressed in Big-O notation, we can say that it would take __O(1)__.

So, now if we ask the question from above again, _if there are N data elements, how many steps will the algorithm take?_, the answer would be that the reading takes only one step.

We can observe from this example that the answer has nothing to do with N. In fact, as the input scales, the reading from the array will __always__ take __one step__. This makes O(1) the fastest kind of algorithm because there is only 1 step no matter the size of the input.

We also refer to algorithms that have O(1) as algorithms with a __constant time__.

Based on what we have said about algorithms that have a constant time, if an algorithm consitutes of 3 steps regardless of the amount of N data elements, we might say that that algorithm is O(3). However, that is __wrong__.

The notation O(1) does not intended to describe the amount of steps that an algorithm would take, but instead, it intends to show that the time of the algorithm is constant or rather that the number of steps does not increase as the input scales. Based on this knowledge, we can say that when an algorithm has a fixed amount of steps or has a constant time, we always mark it with O(1).

In other words, algorithms that take 1 step, 3 steps or 100 steps are the same kind of algorithms, because they have a constant time.

### O(N)

O(N) type of algorithms are different from O(1) algorithms because their performance is affected as the input increases. More specifically, it's a kind of algorithm whose steps increase __in direct proportion__ to the data as the data increases.

O(N) algorithms tell us about the proportional relationship between the data and the algorithm's efficiency. It describes how the number of steps increase as the data increases.

### O(N) vs. O(1)

Let's take a look at two algorithms.

One algorithm has a constant time and takes 100 steps.

The second algorithm has an O(N).

Which one of these two algorithms would be faster?

We can say that up until 100 elements, the algorithm with a running time of O(N) is faster, but for arrays or data sets that are larger than 100, we can say that the O(1) is faster.

The same logic applies regardless of the amount of steps an algorithm with a constant time has. For example, if an algorithm with a running time O(1) takes 1 million steps, we can say that O(N) will be faster as long as the data set is not bigger than 1 million elements. However, once the input is bigger than 1 million, then O(1) is faster.

As previously mentioned, Big-O notation is concerned with the worst-case scenarios of an algorithm, so we can say that an O(1) algorithm is always faster than a O(N) algorithm.

### Binary search and O(log N)

When talking about binary search, we mentioned that the base condition to use binary search is to have an ordered array.

We also established that a binary search is faster than linear search because the elements for searching in the dataset are halved with each step.

So far, we have mentioned two types of algorithms: O(N) and O(1).

Binary search __cannot__ fit into O(N) because the number of steps doesn't linearly increase with the number of data elements in an array.

Binary search __cannot__ fit into O(1) because it doesn't have a constant time or in other words, the number of steps increases as the number of data elements increases.

Binary search falls somewhere in between O(1) and O(N). In terms of Big-O notation, we can say that it has a time complexity of __O(log N)__.

This type of algorithm is also known as having a time complexity of __log time__.

In other words, O(log N) describes an algorithm that __increases one step each time the data is doubled__.

### Logarithms

To better understand the algorithm with time complexity of O(log N) we need to understand __logarithms__.

Logarithms are a mathematical concept. They are the __inverse of exponents__.

Exponents are the following:

2^3 = 2 * 2 * 2

which is 8.

An example of a logarithm would be log~2 8. This is the converse to an exponent. Namely, how many times do we have to multiple 2 by itself to get 8?

Because we have to multiply 2 by itself 3 times to get 8, we can say log~2 8 = 3.

Another way to calculate the result of a logarithm is the following:

Given a logarithm of log~2 64 we need to, __divide 64 by 2 until we get 1 (one)__:

64 / 2 / 2 / 2 / 2 / 2 / 2 = 1

Since there are six 2s, we can say that log~2 64 = 6.

### O(log N)

In terms of Big-O notation in computer science, whenever we say O(log N), we actually mean O(log~2 N). The small/subscript 2 is __omitted__ for convenience.

So if we go back to the original question, _if there are N data elements, how many steps will an algorithm take?_

We can say that the algorithm O(log N) would take __log~2 N steps__. So, if there are 8 elements, the algorithm would take 3 steps because __log~2 8 = 3\__.

To put it in other words, if we keep dividing the 8 elements in half, it would take us three steps to end up with 1 element. We basically divide the array in half until we narrow our search down to the correct number.

We can then conclude that __O(log N) algorithm takes as many steps as it takes to keep halving the data elements until we remain with 1.__

N elements  O(N)  O(log N)
8           8     3
16          16    4
32          32    5
64          64    6
128         128   7
256         256   8
512         512   9
1024        1024  10

From the data above we can once again say that the O(N) algorithm takes as many steps as there are data elements and the O(log N) algorithm takes only 1 step extra as the data doubles.
