#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a, r, u, x1, x2, t, s, i;
    char g;
    a = rand();
    printf("enter your range\n");
    scanf("%d", &x1);
    printf("to\n");
    scanf("%d", &x2);
    if (x1 == x2)
    {
        printf("error same range");
        return 0;
    }
    if (x1 > x2)
    {
        t = x1;
        x1 = x2;
        x2 = x1;
    }

    r = a % (x2 - x1 + 1) + x1; // converts random int to range x1 to x2
    printf("Wanna guess?Y/N? \n");
    scanf("%c", &g);
    scanf("%c", &g);

    if (g == 'Y' || g == 'y')
    {
        printf("You have three guesses.");
        for (i = 1; i <= 3; i++)
        {
            if (i == 1)
                printf("What is your first guess?\n");
            else if (i == 2)
                printf("What is your second guess?\n");
            else
                printf("What is your third guess?\n");

            scanf("%d", &s);
            if (s == r)
            {
                printf("Congratulations! It is correct\n");
                break;
            }
            else
            {
                if (i < 3)
                {
                    printf("Sorry it is incorrect.%d chances remain.", 3 - i);
                    if (s > r)
                        printf("Guess lower\n");
                    else
                        printf("Guess higher\n");
                }
                else
                    printf("Sorry, You are out of chances. The number was %d \n", r);
            }
        }
    }
    else if (g == 'n' || g == 'N')
    {
        printf("the random number in range is %d\n", r);
    }

    return 0;
}
