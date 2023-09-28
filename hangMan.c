
// Nitesh Baniya
/*This is a basic hangman game created in C with the main purpose of demonstrating the
concepts of control structures and functions along with their usage.*/

/*This is a basic game where you have to guess a word letter by letter (although the order
doesn't matter).However the number of chances for wrong guess is limited.*/

// Header files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Global declaration
int i, j, wordlen, ans = 0, mistake = 0, flag = 0; // ans is number of correctly guessed letter`
int life;
char d = '_', guess, b[30], *words[5] = {"baniya", "ghimire", "teacher", "science", "theoretical"};

// functions used
void details();
int sleep(int); // if not declared; warning: implicit declaration of function is shown
void rules();
void game(char[], int);

void main()
{
    char ch;
    int turn;
    srand(time(0));    // takes time
    turn = rand() % 5; // generates random value
    wordlen = strlen(words[turn]);

    details();

    // game
    printf("\nEnter r to read rules, p to play game and e to exit.\n");
    ch = getch();
    if (ch == 'r')
    {
        rules();
    }
    else if (ch == 'p')
    {
        game(words[turn], wordlen);
    }
    else if (ch == 'e')
    {
        goto end;
    }
    else
    {
        printf("Enter a valid choice.");
    }
end:
    getch();
}

void details()
{
    printf("\t\t\t*** ***HANGMAN GAME*** ***\n\n");
    printf("\t\t\t\t\tCreated by - \n");
    printf("\t\t\t\t\t\t     NITESH BANIYA\n\n\n");
    printf("\t\t\t______________-----~~^~~-----______________");
}

void rules()
{
    printf("\n\t\t~ ~ ~ RULES ~ ~ ~");
    printf("\n\t 1. You have to guess a word letter by letter.");
    printf("\n\t 2. You can guess the letter in any order.");
    printf("\n\t 3. You have maximum five chances in case of wrong guess.");
    printf("\n\t 4. If you guess the word correctly, you win theb game.");
    printf("\n\t 5. If you guessed wrong letter five times, you lose the game.");
    printf("\n\t 6. Don't enter already entered letters.");
}
void game(char a[], int wordlen)
{
    printf("\nThe word is %d characters long.", wordlen);
    printf("\n\n");
    // Assigning another string  _ as values
    for (j = 0; j < wordlen; j++)
    {
        printf("%c\t", d);
        b[j] = d;
    }

    /*this loop is used to guess a letter from hidden word till the user guesses all the
    letters of the word(in any order) or the user has exceeded the number of wrong chances.*/

    while (mistake < 5)
    {
        if (mistake >= 0)
        {
            details();
        }
        printf("\n\n");
        flag = 0;
        printf("\nEnter a character : "); // reading a letter from user
        guess = getche();
        for (i = 0; i < wordlen; i++) // checking whether the guessed letter matches that of hidden word
        {
            if (guess == a[i]) // if guess matches then it is assigned to the correct location in string
            {
                b[i] = a[i];
                flag = 1;
                ans++;
            }
        }
        printf("\n\t\t~~~HANGMAN~~~\n");

        for (i = 0; i < wordlen; i++)
        {
            printf("%c\t", b[i]);
        }
        if (flag == 0) // if guessed letter is wrong
        {
            mistake++;
            printf("\n\n%c is a wrong guess.", guess);
            printf("\nYou have %d more chances left.", life = 5 - mistake);
        }
        else // if guessed letter is correct
        {
            printf("\n\nYou are correct.");
            printf("\nYou stil have %d chances.", life = 5 - mistake);
        }
        if (ans == wordlen)
        {
            break;
        }
        printf("\n");
        sleep(1);      // Here getch() is not used because it requires to enter a character
        system("cls"); // To print new workplace in terminal
    }
    if (strcmp(a, b) == 0)
    { // winning condition
        printf("\n\n\tYou won!!!");
    }
    else
    {
        printf("\n\t\t\tYou lost.");
        printf("\n\t\t\tYou are hanged.");
        printf("\n\t\t\tThe hidden word is ");
        puts(a);
    }
}