#include <stdio.h>
#include <errno.h>
#include "x_and_o.h"

void initial_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (size_t rows = 0; rows < sizeof(*board); rows++)
        for (size_t column = 0; column < sizeof(board[rows]); column++)
            board[rows][column] = '-';
}

int check_input(int input, int scanf_s_output)
{
    while ((!(0 <= input && input < BOARD_SIZE)) || scanf_s_output != 1) {
        printf("\n");
        printf("Please enter a number bitween 0 to %d - ", (BOARD_SIZE - 1));
        scanf_s_output = scanf_s("%d", &input);
    }
    return input;
}

char check_winning_rows(const char board[BOARD_SIZE][BOARD_SIZE])
{
    int o_nums = 0;
    int x_nums = 0;
    for (size_t rows = 0; rows < sizeof(*board); rows++)
    {
        o_nums = 0;
        x_nums = 0;
        for (size_t colums = 0; colums < sizeof(board[rows]); colums++)
        {
            if (board[rows][colums] == 'X')
                x_nums += 1;
            else if (board[rows][colums] == 'O')
                o_nums += 1;
        }
        if (x_nums == WINNING_SIZE)
            return 'X';
        else if (o_nums == WINNING_SIZE)
            return 'O';
    }
    return '-';
}


char check_winning_columns(const char board[BOARD_SIZE][BOARD_SIZE])
{
    int o_nums = 0;
    int x_nums = 0;
    for (size_t i = 0; i < sizeof(*board); i++)
    {
        o_nums = 0;
        x_nums = 0;
        for (size_t j = 0; j < sizeof(board[i]); j++)
        {
            if (board[j][i] == 'X')
                x_nums += 1;
            else if (board[j][i] == 'O')
                o_nums += 1;
        }
        if (x_nums == WINNING_SIZE)
            return 'X';
        else if (o_nums == WINNING_SIZE)
            return 'O';
    }
    return '-';
}


char check_winning_digonals(const char board[BOARD_SIZE][BOARD_SIZE])
{
    int o_nums = 0;
    int x_nums = 0;
    // Check digonal top right to butt left.
    for (size_t i = 0; i < sizeof(*board); i++)
    {
        if (board[i][i] == 'X')
            x_nums += 1;
        else if (board[i][i] == 'O')
            o_nums += 1;
    }
    if (x_nums == WINNING_SIZE)
        return 'X';
    else if (o_nums == WINNING_SIZE)
        return 'O';

    o_nums = 0;
    x_nums = 0;
    // Check digonal top left to butt right.
    for (size_t i = 0; i < sizeof(*board); i++)
    {
        if (board[i][sizeof(*board) - (i + 1)] == 'X')
            x_nums += 1;
        else if (board[i][sizeof(*board) - (i + 1)] == 'O')
            o_nums += 1;
    }
    if (x_nums == WINNING_SIZE)
        return 'X';
    else if (o_nums == WINNING_SIZE)
        return 'O';
    return '-';
}

char check_winning(const char board[BOARD_SIZE][BOARD_SIZE]) {
    char win_rows = check_winning_rows(board);
    char win_columns = check_winning_columns(board);
    char win_digonals = check_winning_digonals(board);
    if (win_rows == 'X' || win_columns == 'X' || win_digonals == 'X')
    {
        printf("X is winning");
        return 'X';
    }

    else if (win_rows == 'O' || win_columns == 'O' || win_digonals == 'O')
        return 'O';
    else
        return '-';
}

void player_turn(char board[BOARD_SIZE][BOARD_SIZE], char turn) {

    int row = 0;
    int column = 0;
    int scanf_s_output;
    printf("\nChoose row - ");
    scanf_s_output = scanf_s("%d", &row);
    row = check_input(row, scanf_s_output);
    printf("Choose column - ");
    scanf_s_output = scanf_s("%d", &column);
    column = check_input(column, scanf_s_output);

    while (!(board[row][column] == '-'))
    {
        fflush(stdin);
        fflush(stdin);
        printf("Please choose an empty place!!!!\n\n");
        printf("Choose row - ");
        scanf_s_output = scanf_s("%d", &row);
        printf("\noutput of scanf_s -------- %d\n", scanf_s_output);
        row = check_input(row, scanf_s_output);
        printf("Choose column - ");
        scanf_s_output = scanf_s("%d", &column);
        printf("\noutput of scanf_s -------- %d\n", scanf_s_output);
        column = check_input(column, scanf_s_output);
    }
    board[row][column] = turn;
}


void print_board(const char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (size_t i = 0; i < BOARD_SIZE; i++)
        printf("  %d  ", i);
    printf("\n  ---------------\n");

    for (int i = 0; i < sizeof(*board); i++)
    {
        printf("%d ", i);
        for (int j = 0; j < sizeof(board[i]); j++)
            printf("| %c |", board[i][j]);
        printf("\n  ---------------\n");
    }
}