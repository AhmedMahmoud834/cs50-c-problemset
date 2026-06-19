#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // prompt user for height
    int height;
    do
    {
        height = get_int("height: ");
    }
    while(height < 1);

    // print height
    for(int row = 0;row < height;row++)
    {
        for(int spaces = 0; spaces < height - row - 1;spaces++)
        {
            printf(" ");
        }
        for(int hashes = 0;hashes < row + 1;hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}
