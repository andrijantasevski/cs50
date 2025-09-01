#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int is_punctuation_char(char character);
int get_letters(string text);
int get_words(string text);
int get_sentences(string text);
float calculate_coleman_liau_index(int letters, int words, int sentences);
void print_reading_level(double grade);

int main(void)
{
    string text = get_string("Text: ");

    int letters = get_letters(text);
    int words = get_words(text);
    int sentences = get_sentences(text);

    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;

    float colemanLiauIndex = calculate_coleman_liau_index(letters, words, sentences);

    double grade = round(colemanLiauIndex);

    print_reading_level(grade);

    return 0;
}

int is_punctuation_char(char character)
{
    if (character == '?' || character == '!' || character == '.')
    {
        return 1;
    }

    return 0;
}

int get_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int get_words(string text)
{
    int words = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int isLast = i == n - 1;

        bool isLastCharPunctuation = isLast && is_punctuation_char(text[i]);

        if (text[i] == ' ' || isLastCharPunctuation)
        {
            words++;
        }
    }

    return words;
}

int get_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (is_punctuation_char(text[i]))
        {
            sentences++;
        }
    }

    return sentences;
}

float calculate_coleman_liau_index(int letters, int words, int sentences)
{
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    return index;
}

void print_reading_level(double grade)
{
    if (grade < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", (int)grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
