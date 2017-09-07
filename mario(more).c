#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        printf("Height: ");
        h = get_int();
    }
    while(h < 0 || h > 23);
    
    for(int i = 0; i < h; i++) //loop h times, each loop is a row
    {
        for(int j = i + 1; j < h; j++) //print all ' ' infront of first '#' at each row. When outer loop finish one turn, i++, j will be closer to h, ' ' will be diminished.
        {
            printf(" ");
        }
        for(int k = 0; k < i + 1; k++) //printf left half mountain '#'
        {
            printf("#");
        }
        
        printf("  "); //the valley
        
        for(int n = 0; n < i + 1; n++)
        {
            printf("#"); //printf right half mountain '#'
        }
        
        printf("\n"); //end-of-line
    }
}