#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int get_key(int argc, string argv[]);
string cipher(string plaintext, int key, char alphabet[]);

int main(int argc, string argv[])
{
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j','k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
        't', 'u', 'v', 'w', 'x', 'y', 'z' };

    int key = get_key(argc, argv);
    if (key == -1)
    {
        printf("Error!");
        return 0;
    }

    if (!key)
    {
        printf("Usage %s key\n", argv[0]);
        return 0;
    }

    string plaintext = get_string("plaintext:  ");

    string ciphertext = cipher(plaintext, key, alphabet);

    printf("ciphertext: %s", plaintext);
}

int get_key(int argc, string argv[])
{
    if (argc != 2)
    {
        return -1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            return 0;
        }
    }

    return atoi(argv[1]);
}

string cipher(string plaintext, int key, char alphabet[])
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            bool shouldBeUpper = plaintext[i] >= 'A' && plaintext[i] <= 'Z';

            int charFromAlphabet = tolower(plaintext[i]) - 'a';

            int charToGet = (charFromAlphabet + key) % 26;

            plaintext[i] = shouldBeUpper ? toupper(alphabet[charToGet]) : alphabet[charToGet];
        }
    };

    return plaintext;
}
