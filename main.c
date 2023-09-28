#include <stdio.h>
#include<stdlib.h>
int main()
{
    int choice;
    char choose;
    play: printf("Choose the game you want to play:\n ");
    printf("\n1: TIC TAC TOE");
    printf("\n2: ROCK PAPER SCISSOR");
    printf("\n3: HANGMAN");
    printf("\n4: GUESS THE NUMBER");
    printf("\n\n Enter your choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        /* code */
        system("ticTacToe.exe");
        break;
    case 2:
        /* code */
        system("rockPaperScissor.exe");
        break;
    case 3:
        /* code */
        system("hangMan.exe");
        break;
    case 4:
        /* code */
        system("guessNumber.exe");
        break;
    default:
        break;
    }
    printf("\n\nDo you wanna try other games ? y/n ");
    scanf(" %c",&choose);
    if(choose=='y' || choose=='Y')
    goto play;
    return 0;
}
