#include <stdio.h>
#include <stdlib.h>
#define size 9

char board[size] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int isWin(int turn)
{
    int winBoard[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (int i = 0; i < 8; i++)
    {
        int index_1 = winBoard[i][0];
        int index_2 = winBoard[i][1];
        int index_3 = winBoard[i][2];

        if (board[index_1] == board[index_2] && board[index_2] == board[index_3])
        {
            printf("Index 1: %d, Index 2: %d, Index 3: %d\n", index_1, index_2, index_3);
            return 1;
        }
    }
    if (turn == 9)
    {
        return -1;
    }
    return 0;
}

void printBoard()
{
    system("clear");
    printf("|   TIC TAC TOE!  |\n");
    printf("|-----------------|\n");
    for (int i = 0; i < size; i += 3)
    {
        printf("|  %c  |  %c  |  %c  |\n", board[i], board[i + 1], board[i + 2]);
        printf("|-----------------|\n");
    }
}

void playerMove(int turn)
{
    int move;
    int player;
    char mark;

    //Choose mark
    if (turn % 2 == 0)
    {
        player = 2;
        mark = 'X';
    }
    else
    {
        player = 1;
        mark = 'O';
    }
    do
    {
        printf("Player %d, enter your move: ", player);
        scanf("%d", &move);

        move -= 1;

        if (board[move] != (move + '1'))
        {
            printf("Its Already Occupied !\n");
            move = 100;
        }
        else
        {
            board[move] = mark;
        }

    } while (move > 8 || move < 0 && board[move] == (move + '1'));
}

int main()
{
    int turn = 1;
    int winStatus;
    printBoard();
    for (turn = 1; turn < 10; turn++)
    {
        playerMove(turn);
        printBoard();

        winStatus = isWin(turn);

        if (winStatus != 0)
        {
            break;
        }
    }
    if (winStatus == 1)
    {
        if (turn % 2 == 1)
            printf("Player 1 Wins!\n");
        else
            printf("Player 2 Wins!\n");
    }
    else if (winStatus == -1)
        printf("Draw!\n");

    return 0;
}

