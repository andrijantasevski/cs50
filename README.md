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
