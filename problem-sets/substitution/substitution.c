#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int INCORRECT_AMOUNT_ARGS = 1;
const int INCORRECT_KEY_LENGTH = 2;
const int INCORRECT_KEY = 3;

int are_elements_in_string_alpha(string string);
int are_elements_in_string_unique(string string);
int validate_key(int argc, string argv[]);
void cipher(string plaintext, string key);

int main(int argc, string argv[])
{
    int error = validate_key(argc, argv);

    if (error == INCORRECT_AMOUNT_ARGS || error == INCORRECT_KEY)
    {
        printf("Usage: %s key \n", argv[0]);
        return 1;
    }

    if (error == INCORRECT_KEY_LENGTH)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string key = argv[1];

    string plaintext = get_string("plaintext: ");

    cipher(plaintext, key);

    printf("ciphertext: %s\n", plaintext);
    return 0;
}

int are_elements_in_string_alpha(string string)
{
    for (int i = 0, n = strlen(string); i < n; i++)
    {
        if (!isalpha(string[i]))
        {
            return 0;
        }
    }

    return 1;
}

int are_elements_in_string_unique(string string)
{
    int n = strlen(string);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            };

            if (tolower(string[i]) == tolower(string[j]))
            {
                return 0;
            }
        }
    }

    return 1;
}

int validate_key(int argc, string argv[])
{
    if (argc != 2)
    {
        return INCORRECT_AMOUNT_ARGS;
    }

    if (strlen(argv[1]) != 26)
    {
        return INCORRECT_KEY_LENGTH;
    }

    if (!are_elements_in_string_alpha(argv[1]))
    {
        return INCORRECT_AMOUNT_ARGS;
    }

    if (!are_elements_in_string_unique(argv[1]))
    {
        return INCORRECT_KEY;
    }

    return 0;
}

void cipher(string plaintext, string key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            bool shouldBeUppercase = plaintext[i] >= 'A' && plaintext[i] <= 'Z';
            int charToGet = tolower(plaintext[i]) - 'a';

            plaintext[i] = shouldBeUppercase ? toupper(key[charToGet]) : tolower(key[charToGet]);
        }
    }
}
