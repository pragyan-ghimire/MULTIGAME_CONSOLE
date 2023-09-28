/* program of tic tac toe game created by:Pragyan Ghimire*/

// header files
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

// Global variables
char board[3][3]; // board
const char PLAYER = '0';
const char COMPUTER = 'X';
const char INVALIDMOVE = 'q'; // to prevent computer from invalid move
char winner = ' ';
int freespaces = 9;

// Functions
void printBoard();
void playerMove();
void computerMove();
char checkWinner();

// main function
int main()
{
    int i,j;
    printf("***************************************************************************************\n");
    printf("*                                                                                     *\n");
    printf("*                              Welcome to TIC TAC TOE:                                *\n");
    printf("*                                                                                     *\n");
    printf("***************************************************************************************\n");
    printf("\n\n");
    printf("\t\t\tPress any key to continue.\n");
    getch();
    printf("\tRules of TIC TAC TOE :\n");
    sleep(1);
    printf("\n\t1. You can only enter value of row and column from 1 to 3.");
    sleep(1);
    printf("\n\t2. If the cell is pre-occupied, you can't select that is occupied.");
    sleep(2);
    printf("\n\n\t! WARNING. ANY VIOLATION OF RULE RESULTS IN YOUR DEFEAT.\n\tHave great experience !\n\n\n");

     for(i=0;i<3;i++){
    	for(j=0;j<3;j++){
    		board[i][j]=' ';
		}
	}
    while (winner == ' ' && freespaces != 0)
    {
        printBoard();
        playerMove();
        winner = checkWinner();
        freespaces--;
        if (winner != ' ' || freespaces == 0)
            break;

        computerMove();
        freespaces--;
        winner = checkWinner();
    }

    printBoard();
    if (freespaces == 0 && winner == ' ')
    {
        printf("The game ended as draw. \n Better luck next time.");
    }
    else
    {
        printf("The winner is %c", winner);
        if (winner == '0')
        {
            printf("\nCongratulations! You won.");
        }
        else
        {
            printf("\nYou lost! Better luck next time.");
        }
    }

    return 0;
}

// for printing board
void printBoard()
{

    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n___|___|___\n");

    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n___|___|___\n");

    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n   |   |   \n");
    
   
}

// for player move
void playerMove()
{
    int row, col;
    printf("Enter row and column(1-3):");
    scanf("%d %d", &row, &col);
    row--;
    col--;
    if (board[row][col] == PLAYER || board[row][col] == COMPUTER)
    {
        printf("You performed invalid move.\n");
        printf("You lost. Better read rules before playing.");
        exit(0);
    }
    else if ((row < 0 || row > 2) || (col < 0 || col > 2))
    {
        printf("You can only enter from 1 to 3.\n");
        printf("Better read rules before playing.");
        exit(0);
    }
    else
    {
        board[row][col] = PLAYER;
    }
}

// for computer move
void computerMove()
{
    int i, j;
    srand(time(0));
    int row = rand() % 3;
    int col = rand() % 3;
    if (board[row][col] == PLAYER || board[row][col] == COMPUTER)
    {

        while (INVALIDMOVE == 'q')
        {
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (board[i][j] != PLAYER && board[i][j] != COMPUTER)
                    {
                        board[i][j] = COMPUTER;
                        goto next;
                    }
                }
            }
        next:
            break;
        }
    }
    else
    {
        board[row][col] = COMPUTER;
    }
}

// for checking winner
char checkWinner()
{
    int i, j, d;
    // check rows
    for (i = 0; i < 3; i++)
    {
        if ((board[i][0] == PLAYER || board[i][0] == COMPUTER) && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // check columns
    for (j = 0; j < 3; j++)
    {
        if ((board[0][j] == PLAYER || board[0][j] == COMPUTER) && board[0][j] == board[1][j] && board[0][j] == board[2][j])
        {
            return board[0][j];
        }
    }
    // check diagonals
    for (d = 0; d < 3; d++)
    {
        if ((board[0][0] == PLAYER || board[0][0] == COMPUTER) && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }
    }

    for (d = 0; d < 3; d++)
    {
        if ((board[0][2] == PLAYER || board[0][2] == COMPUTER) && board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return board[0][2];
        }
    }
    return ' ';
}
