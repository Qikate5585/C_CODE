#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 3
#define COL 3
void Init_board(char board[ROW][COL], int row, int col);
void Display_board(char board[ROW][COL], int row, int col);
void Playermove(char board[ROW][COL], int row, int col);
void Computermove(char board[ROW][COL], int row, int col);
char Is_win(char board[ROW][COL], int row, int col);