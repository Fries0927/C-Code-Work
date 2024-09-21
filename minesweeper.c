#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> 
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

#define width 8
#define height 8
#define bomb 999
#define MAX_bombAmount 10

#define RESET "\033[0m"
#define CYAN "\033[36m" 
#define GREEN "\033[32m" 
#define RED "\033[31m" 
#define BLUE "\033[34m" 
#define PURPLE "\033[35m" 
#define YELLOW "\033[33m" 

int board[width][height] = {0};
bool foldedBoard[width][height] = {false};

void placeBomb(int placed,int* avoid)
{
    int BombPlaced = placed;
    int ifplace = 0;
    for(int o = 0 ; o < height ; o++)
    {
        for(int i = 0 ; i < width ; i++)
        {
            ifplace = rand()%8;
            if(ifplace == 1 && board[i][o] != bomb && &board[i][o]!=avoid)
            {
                board[i][o] = bomb;
                BombPlaced++;
            }
            if(BombPlaced >= MAX_bombAmount)
            {
                return;
            }
        }
    }
    if(BombPlaced < MAX_bombAmount)
    {
        placeBomb(BombPlaced,avoid);
    }
}

int placeNumber_bombCountNear(int i, int o)
{
    int bombCount = 0;
    for(int a = i-1; a <= i+1; a++)
    {
        for(int e = o-1; e <= o+1; e++)
        {
            if(a >= 0 && a < width && e >= 0 && e < height && board[a][e] == bomb)
            {
                bombCount++;
            }
        }
    }
    return bombCount;
}

void placeNumber(void)
{
    int bombCount = 0;
    for(int o = 0 ; o < height ; o++)
    {
        for(int i = 0 ; i < width ; i++)
        {
            if(board[i][o] != bomb)
            {
                bombCount = placeNumber_bombCountNear(i, o);
                board[i][o] = bombCount;
            }
        }
    }
}

void printBoard(bool lose)
{
    for(int o = 0 ; o < height; o++)
    {
        for(int i = 0 ; i < width ; i++)
        {
            if(foldedBoard[i][o] == true || lose == true)
            {
                switch(board[i][o])
                {
                    case(bomb):
                    printf("| bomb  ");
                    break;

                    case(0):
                    printf("|   %d   ", board[i][o]);
                    break;

                    case(1):
                    printf("|"CYAN"   %d   ", board[i][o]);
                    break;

                    case(2):
                    printf("|"GREEN"   %d   ", board[i][o]);
                    break;

                    case(3):
                    printf("|"RED"   %d   ", board[i][o]);
                    break;

                    case(4):
                    printf("|"BLUE"   %d   ", board[i][o]);
                    break;

                    case(5):
                    printf("|"PURPLE"   %d   ", board[i][o]);
                    break;

                    default:
                    printf("|"YELLOW"   %d   ", board[i][o]);
                    break;
                }
                printf(RESET);
            }
            else
            {
                printf("|       ");
            }
        }
        printf("|   %d\n\n", o+1);
    }
    for(int i = 1; i <= width; i++)
    {
        printf("   %c    ", i+64);
    }
}

void clearConosle(void)
{
    for(int i = 0 ; i < 10 ; i++)
    {
        printf("\n\n\n\n\n\n\n");
    }
}

void solutionSheet(void)
{
    FILE *fp;
    fp = fopen("solution.txt","w");
    for(int o = 0 ; o < height ; o++)
    {
        for(int i = 0 ; i < width ; i++)
        {
            if(board[i][o] == bomb)
            {
                fprintf(fp,"| bomb ");
            }
            else
            {
                fprintf(fp,"|   %d  ", board[i][o]);
            }
        }
        fprintf(fp,"|\n\n");
    }
    fclose(fp);
}

void clearbuffer(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

bool ifbomb(int *pos)
{
    return *pos == bomb;
}

void unfold_0(int row,int col)
{
    for(int i = row-1; i <= row + 1; i++)
    {
        for(int o = col-1; o <= col+1; o++)
        {
            if(i>=0 && o>=0 && i < height && o < width)
            {
                if(board[i][o]==0 && !(i == row && o==col) && foldedBoard[i][o] == false)
                {
                    foldedBoard[i][o] = true;
                    unfold_0(i,o);
                }
                else
                {
                    foldedBoard[i][o] = true;
                }
            }
        }
    }
}

bool ifwin(void)
{
    int counter=0;
    for(int i = 0; i < height; i++)
    {
        for(int o = 0; o < width; o++)
        {
            if(foldedBoard[i][o] == false)
            {
                counter++;
            }
        }
    }
    return counter == MAX_bombAmount;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    char answer[3];
    bool ibomb;
    int foldBoardcol;
    int foldBoardrow;
    bool initialized = false;
    bool win;

    while(1)
    {
        //clearConosle();
        printBoard(false);
        printf("\n\n");
        while(1)
        {
            printf("請輸入想挖的格子 (1A , 6E)\n> ");
            scanf(" %2s", answer);
            clearbuffer();
            if(answer[0] < '1' || answer[0] > '9' || toupper(answer[1]) < 'A' || toupper(answer[1]) > 'H')
            {
                printf("\n請輸入正確的格式!\n");
                continue;
            }
            else
            {
                foldBoardrow = answer[0] - '1';
                foldBoardcol = toupper(answer[1]) - 'A';
                break;
            }
        }
        foldedBoard[foldBoardcol][foldBoardrow] = true;
        if(!initialized)
        {
            placeBomb(0,&board[foldBoardcol][foldBoardrow]);
            placeNumber();
            solutionSheet();
            if(board[foldBoardcol][foldBoardrow] == 0)
            {
                unfold_0(foldBoardcol,foldBoardrow);
            }
            initialized = true;
            continue;
        }

        ibomb = ifbomb(&board[foldBoardcol][foldBoardrow]);
        if(ibomb)
        {
            printBoard(true);
            printf("\n你挖到地雷了!");
            exit(0);
        }
        else if(board[foldBoardcol][foldBoardrow] == 0)
        {
            unfold_0(foldBoardcol,foldBoardrow);
        }
        win = ifwin();
        if(win)
        {
            printBoard(false);
            printf("\n\nYou won!");
            exit(0);
        }
        else
        {
            continue;
        }
    }
    return 0;
}
