#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    //If there are more than one command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        //./caesar is argv[0] and the command-line argument is argv[1]
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            //If there are any non-digit characters in the command-line argument
            if (! isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        //From string to int
        int key = atoi(argv[1]);

        string plain_text = get_string("Plain text: ");
        char cipher_text[strlen(plain_text)];

        int i = 0;

        while (plain_text[i] != '\0')
        {
            //If ith character is uppercase in the plain text
            if (isupper(plain_text[i]))
            {
                cipher_text[i] = (plain_text[i] - 65 + key) % 26 + 65;
            }
            //If ith character is lowercase in the plain text
            else if (islower(plain_text[i]))
            {
                cipher_text[i] = (plain_text[i] - 97 + key) % 26 + 97;
            }
            //If ith characters is not a letter
            else
            {
                cipher_text[i] = plain_text[i];
            }
            i++;
        }
        //With this, we make sure the cipher text ends with null
        cipher_text[i] = '\0';

        printf("Chiper text: %s\n", cipher_text);

    }
}