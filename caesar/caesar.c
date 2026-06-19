#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_positive_digit(const string text);
void encrypt_text(const int key, const int textLen , const string text, char cipherText[]);


int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    bool isDigit = is_positive_digit(argv[1]);
    if(!isDigit)
    {
        printf("Invalid key: Key should be a positive number.\n");
        return 1;
    }
    char *endptr;
    const int key = strtol(argv[1], &endptr, 10) % 26;

    const string plainText = get_string("Plain Text: ");
    const int textLen = strlen(plainText);

    char cipherText[textLen + 1];

    encrypt_text(key, textLen, plainText, cipherText);

    printf("Cipher Text: %s\n", cipherText);


}

bool is_positive_digit(const string text)
{
    const int textLen = strlen(text);
    if(text == NULL || textLen == 0)
    {
        return false;
    }
    for(int i = 0; i < textLen; i++)
    {
        if(!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

void encrypt_text(const int key, const int textLen , const string text, char cipherText[])
{
    for(int i = 0; i < textLen; i++)
    {
        if(text[i] >= 65 && text[i] <= 90)
        {
            int Pi = text[i] - 65;
            int Ci = (Pi + key) % 26;
            cipherText[i] = Ci + 65;
        }
        else if(text[i] >= 97 && text[i] <= 122)
        {
            int Pi = text[i] - 97;
            int Ci = (Pi + key) % 26;
            cipherText[i] = Ci + 97;
        }
        else
        {
            cipherText[i] = text[i];
        }
    }
    cipherText[textLen] = '\0';

}
