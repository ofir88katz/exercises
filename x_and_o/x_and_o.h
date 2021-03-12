#pragma once
#include <stdio.h>
#include <errno.h>
#define BOARD_SIZE 3
#define WINNING_SIZE 3
#define X_OR_O(turn_num) ((turn_num)%2==0 ? 'X' : 'O')

/// <summary>
/// init the board to all -.
/// </summary>
/// <param name="board"> the game board </param>
void initial_board(char board[BOARD_SIZE][BOARD_SIZE]);

/// <summary>
/// 
/// </summary>
/// <param name="input"></param>
/// <returns></returns>
int  check_input(const int input, int scanf_s_output);

/// <summary>
/// check if there is a win in all the rows
/// </summary>
/// <param name="board"> the board game </param>
/// <returns> return 'X' if X won, return 'O' if O won, return '-' if no one won</returns>
char check_winning_rows(const char board[BOARD_SIZE][BOARD_SIZE]);

/// <summary>
/// check if there is a win in all the columns
/// </summary>
/// <param name="board"> the board game </param>
/// <returns> return 'X' if X won, return 'O' if O won, return '-' if no one won</returns>
char check_winning_columns(const char board[BOARD_SIZE][BOARD_SIZE]);

/// <summary>
 /// check if there is a win in all the digonals
 /// </summary>
 /// <param name="board"> the board game </param>
 /// <returns> return 'X' if X won, return 'O' if O won, return '-' if no one won </returns>
char check_winning_digonals(const char board[BOARD_SIZE][BOARD_SIZE]);

/// <summary>
/// check if there is a win in the game
/// </summary>
/// <param name="board"> the board of the game </param>
/// <returns></returns>
char check_winning(const char board[BOARD_SIZE][BOARD_SIZE]);

/// <summary>
/// ask the player for there turn, and check there intput
/// </summary>
/// <param name="board">the board of the game</param>
/// <param name="turn">wich player is playing right now</param>
void player_turn(char board[BOARD_SIZE][BOARD_SIZE], char turn);

/// <summary>
/// print the board pretty
/// </summary>
/// <param name="board">the board of the game </param>
void print_board(const char[BOARD_SIZE][BOARD_SIZE]);