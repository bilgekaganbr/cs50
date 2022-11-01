#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Prototypes of functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //User input
    string text = get_string("Text: ");

    //Calculation of the Coleman-Liau index which written as CL_index = 0.0588 * L - 0.296 * S - 15.8 where
    //L is the average number of letters per 100 words in the text and S is the average number of sentences per 100 words in the text.
    float L = (count_letters(text) * 100.0) / count_words(text);
    float S = (count_sentences(text) * 100.0) / count_words(text);
    int CL_index = round(0.0588 * L - 0.296 * S - 15.8);

    //Results to be printed according to Coleman-Liau index
    if (round(CL_index >= 16))
    {
        printf("Grade 16+\n");
    }
    else if (round(CL_index < 1))
    {
        printf("Before grade 1\n");
    }
    else
    {
        printf("Grade %i\n", CL_index);
    }
}

//Function for number of letters
int count_letters(string text)
{
    int letters = 0;
    int i = 0;

    while(text[i] != '\0')
    {

        //isalpha to check if the symbol is alphabetic
        if (isalpha(text[i]))
        {
            letters += 1;
        }
        i++;
    }
    return letters;
}

//Function for number of words
int count_words(string text)
{
    int words = 1;
    int i = 0;

    while(text[i] != '\0')
    {
        //32 is the ascii value of space
        if (text[i] == 32)
        {
            words += 1;
        }
        i++;
    }
    return words;
}

//Function for number of sentences
int count_sentences(string text)
{
    int sentences = 0;
    int i = 0;

    while (text[i] != '\0')
    {
        //33 is the ascii value of exclamation mark, 46 is the ascii value of period, and 63 is the ascii value of question mark
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences += 1;
        }
        i++;
    }
    return sentences;
}