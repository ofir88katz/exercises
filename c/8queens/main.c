#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
//#include "Source File/main.h"

#include <stdint.h>
#define N (8)
#define MAX_QUEENS (8)
#define QUEEN_MARK (-1)

typedef struct {
    int32_t x;
    int32_t y;
} QueenPosition;

void print_board(int32_t board[N][N]);
void calculate_threats(int32_t board[N][N], QueenPosition queens[MAX_QUEENS], size_t queen_count);


void print_board(int32_t board[N][N])
{
    for (size_t row = 0; row < N; row++)
    {
//        char first_line [N*2];
//        memset(first_line, '-', sizeof(first_line));
//        printf("%s\n", first_line);
        for (size_t i = 0; i < N; i++)
        {
            printf("----");
        }
        printf("\n");
        for (size_t col = 0; col < N; col++)
        {
            char print_ch;
            if (board[row][col] == QUEEN_MARK)
                print_ch = 'Q';
            else
                print_ch = board[row][col] + '0';
            printf("| %c ", print_ch);
        }
        printf("|\n");
    }
}


void calculate_threats(int32_t board[N][N], QueenPosition queens[MAX_QUEENS], size_t queen_count)
{

    int y = (queens[0].y);
    int32_t x = board[1][(int)queens[0].y];
    printf("%d, %d", x, y);

    for (size_t queen = 0; queen < queen_count; queen++)
    {
        // Adding 1 to all attacked rows below queen
        for (size_t row = (queens[queen].x) + 1; row < N; row++)
        {
            if (board[row][queens[queen].y] != -1)
                board[row][queens[queen].y]++;
            else
                break;
        }

        // Adding 1 to all attacked rows abow queen
        for (int row = (queens[queen].x) - 1; row > -1; row--)
        {
            if (board[row][queens[queen].y] != -1)
                board[row][queens[queen].y]++;
            else
                break;
        }

        // Adding 1 to all attacked colums to the right of the queen
        for (size_t col = (queens[queen].y) + 1; col < N; col++)
        {
            if (board[queens[queen].x][col] != -1)
                board[queens[queen].x][col]++;
            else
                break;
        }

        // Adding 1 to all attacked colums to the left of the queen
        for (int col = (queens[queen].y) - 1; col > -1; col--)
        {
            if (board[queens[queen].x][col] != -1)
                board[queens[queen].x][col]++;
            else
                break;
        }

        // Adding 1 to diagonal +x +y attacked by queen
        for (size_t i = 1; (queens[queen].x + i < N) && (queens[queen].y + i < N); i++)
        {
            if (board[queens[queen].x + i][queens[queen].y + i] != -1)
                board[queens[queen].x + i][queens[queen].y + i]++;
            else
                break;
        }

        // Adding 1 to diagonal +x -y attacked by queen
        for (int i = 1; (queens[queen].x + i < N) && (queens[queen].y - i > -1); i++)
        {
            if (board[queens[queen].x + i][queens[queen].y - i] != -1)
                board[queens[queen].x + i][queens[queen].y - i]++;
            else
                break;
        }

        // Adding 1 to diagonal -x +y attacked by queen
        for (int i = 1; (queens[queen].x - i > -1) && (queens[queen].y + i < N); i++)
        {
            if (board[queens[queen].x - i][queens[queen].y + i] != -1)
                board[queens[queen].x - i][queens[queen].y + i]++;
            else
                break;
        }

        // Adding 1 to diagonal -x -y attacked by queen
        for (int i = 1; (queens[queen].x - i > -1) && (queens[queen].y - i < N); i--)
        {
            if (board[queens[queen].x - i][queens[queen].y - i] != -1)
                board[queens[queen].x - i][queens[queen].y - i]++;
            else
                break;
        }
    }
}



int main() {
    int32_t board[N][N];
    const int queen_count = 2;
    QueenPosition queens[2];
    queens[0].x = 3;
    queens[0].y = 3;
    queens[1].x = 0;
    queens[1].y = 0;

    memset(board, 0, sizeof(board));

    // Adding the queens to the board
    for (size_t queen = 0; queen < queen_count; queen++)
        board[queens[queen].x][queens[queen].y] = -1;

    print_board(board);
    calculate_threats(board, queens, queen_count);
    printf("\n\n\n");
    print_board(board);
}