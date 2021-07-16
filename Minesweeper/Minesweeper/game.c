#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void Init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void Display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void Setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand()%row+1;
		int y = rand()%col+1;
		mine[x][y] = '1';
		count--;
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x-1][y-1] +
		mine[x-1][y] + mine[x-1][y+1] +
		mine[x][y-1] + mine[x][y+1] +
		mine[x+1][y-1] + mine[x+1][y] +
		mine[x+1][y+1] - 8 * '0';
}
void Finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入想排雷的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("踩雷，你被炸死了\n");
				Display_board(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(mine,x,y);
				show[x][y]=count + '0';
				Display_board(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}

