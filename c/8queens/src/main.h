#ifndef MAIN
#define MAIN

//#include <stdint.h>
#define N (8)
#define MAX_QUEENS (8)
#define QUEEN_MARK (-1)

typedef struct {
    int32_t x;
    int32_t y;
} QueenPosition;


/**
*	This function prints a given board with it's threats
*	if the cell contains a queen, will write 'X' instead of the number of threats.
*/
void print_board(int32_t board[N][N]);

/**
* This function is called after all queens were added onto the board.
* The function will add the threats by all queens
*/
void calculate_threats(int32_t board[N][N], QueenPosition queens[MAX_QUEENS], size_t queen_count);

#endif //MAIN
