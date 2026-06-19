#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(const string text,const int textLen);
int count_words(const string text,const int textLen);
int count_sentences(const string text,const int textLen);

int main(void)
{
    // prompt user for text
    const string text = get_string("Text: ");
    const int textLen = strlen(text);
    // count letters
    const int letters = count_letters(text,textLen);
    // count words
    const int words = count_words(text,textLen);
    // count sentences
    const int sentences = count_sentences(text,textLen);

    const int L = ((float) letters / words) * 100;
    const int S = ((float) sentences / words) * 100;

    const float index = (0.0588 * L) - (0.296 * S) - 15.8;

    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }

}

int count_letters(const string text,const int textLen)
{
    int letters = 0;
    for(int i = 0; i < textLen; i++)
    {
        if((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(const string text,const int textLen)
{
    int spaces = 0;
    for(int i = 0; i < textLen; i++)
    {
        if(text[i] == 32)
        {
            spaces++;
        }
    }
    return spaces + 1;
}

int count_sentences(const string text,const int textLen)
{
    int sentences = 0;
    for(int i = 0; i < textLen; i++)
    {
        // 33 -> ! | 63 -> ? | 46 -> .
        if(text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            sentences++;
        }
    }
    return sentences;
}
