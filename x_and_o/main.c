#include <stdio.h>
#include <errno.h>
#include "x_and_o.h"

int main() {

    char board[BOARD_SIZE][BOARD_SIZE];
    initial_board(board);
    print_board(board);
    for (size_t i = 0; i < ((BOARD_SIZE * BOARD_SIZE)); i++)
    {
        char player = X_OR_O(i);
        printf("Player turn - %c\n", player);
        player_turn(board, player);
        print_board(board);
        printf("\n\n\n");
        if (i >= (BOARD_SIZE * 2) - 3)
        {
            char player_won = check_winning(board);
            if (player_won != '-') {
                printf("%c wonnnnnn !!!!!!!!", player_won);
                break;
            }
        }
        else if (i == ((BOARD_SIZE * BOARD_SIZE) - 1))
            printf("It is a tie!!");
    }

    return 0;
}