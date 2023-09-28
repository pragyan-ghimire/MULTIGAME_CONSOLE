// Sumin Magar

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generate(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    else if ((c1 == 'r' && c2 == 's') || (c1 == 's' && c2 == 'p') || (c1 == 'p' && c2 == 'r'))
    {
        return 1; // computer jitney conditions
    }
    else
    {
        return 0;
    }
}

int main()
{

    int playerscore=0, compscore=0, temp=0;
    char playerchar, compchar;
    char signs[] = {'r', 'p', 's'};
    int i;
    char chose;

    printf("Welcome to rock,paper,scissor.\n");
    printf("Choose r for rock, p for paper,and  s for scissor.\n");

    for (i = 0; i < 3; i++)
    {
        printf("\n*ROUND%d*", i + 1);
        printf("\nUser's turn:");
    stop:
        scanf("%c", &chose);
        getchar(); // getchar ani space deko chha//
        switch (chose)
        {
        case 'r':
            temp = 1;
            break;

        case 'p':
            temp = 2;
            break;

        case 's':
            temp = 3;
            break;
        default:
            printf("Please enter your choice.\nr for rock, p for paper and s for scissor.\n");
            goto stop;
        }
        playerchar = signs[temp - 1];
        switch (playerchar)
        {
        case 'r':
            printf("player throws rock.\n");
            break;
        case 'p':
            printf("player throws paper.\n");
            break;
        default:
            printf("player throws scissors.\n");
        }

        temp = generate(3) + 1; // 3 is passed ani remainder is always less than 3, 4pass garya bhaye k hunthyo?
        compchar = signs[temp - 1];
        switch (compchar)
        {
        case 'r':
            printf("computer throw rock.\n");
            break;
        case 'p':
            printf("computer throws paper.\n");
            break;
        default:
            printf("computer throws scissors.\n");
        }

        if (greater(compchar, playerchar) == 1)
        {
            compscore += 1;
            printf("computer wins  ROUND %d.\n", i + 1);
        }
        else if (greater(compchar, playerchar) == -1)
        {
            compscore += 1;
            playerscore += 1;
            printf("ROUND %d is a draw.\n", i + 1);
        }
        else
        {
            playerscore += 1;
            printf("You won ROUND %d.\n", i + 1);
        }
        printf("__________________\n");
        printf("You:%d \t Computer:%d\n", playerscore, compscore);
        printf("________________");
    }

    if (compscore > playerscore)
    {
        printf("\ncomputer won the game");
    }
    else if (compscore < playerscore)
    {
        printf("\nplayer won the game");
    }
    else
    {
        printf("\nIt is a draw");
    }
}