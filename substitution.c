#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    //If there are more than one comman-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //If the command-line argument have more than 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {

        //If the command-lin argument have digit characters
        if (! isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetical characters\n");
            return 1;
        }
        for (int j = 0; j < strlen(argv[1]); j++)
        {

            //If the command-line argument have repeated characters
            if (i != j && argv[1][i] == argv[1][j])
            {
                printf("Key must contain only one of each character\n");
                return 1;
            }
        }
    }

    string key = argv[1];

    string plain_text = get_string("Plain text: ");
    printf("Plain text: %s\n", plain_text);
    char cipher_text[strlen(plain_text)];

    int i = 0;

    while (plain_text[i] != '\0')
    {

        //If the character of plain text is alphabetical
        if (isalpha(plain_text[i]))
        {

            //If the alphabetical character of plain text is uppercase
            if (isupper(plain_text[i]))
            {

                //If the index corresponding to the plain text in the key is uppercase
                if (isupper(key[plain_text[i] - 65]))
                {
                    cipher_text[i] = key[plain_text[i] - 65];
                }

                //If the index corresponding to the plain text in the key is lowercase
                else
                {
                    cipher_text[i] = key[plain_text[i] - 65] - 32;
                }
            }

            //If the alphabetical character of plain text is lowercase
            else
            {

                //If the index corresponding to the plain text in the key is uppercase
                if (isupper(key[plain_text[i] - 97]))
                {
                    cipher_text[i] = key[plain_text[i] - 97] + 32;
                }

                //If the index corresponding to the plain text in the key is lowercase
                else
                {
                    cipher_text[i] = key[plain_text[i] - 97];
                }
            }

        }

        //If the character of plain text is non-alphabetical
        else
        {
            cipher_text[i] = plain_text[i];
        }
        i++;

    }

    //Make sure the cipher text ends with null
    cipher_text[i] = '\0';

    printf("Cipher text: %s\n", cipher_text);

}