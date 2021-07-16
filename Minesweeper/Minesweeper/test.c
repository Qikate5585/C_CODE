#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*************************************\n");
	printf("****** Welcome to MineSweeper! ******\n");
	printf("********** 1.play   0.exit **********\n");
	printf("********* Designed by Kate **********\n");
	printf("*************************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	Init_board(mine, ROWS, COLS, '0');
	Init_board(show, ROWS, COLS, '*');
	//Dispaly_board(mine, ROW, COL);
	Display_board(show, ROW, COL);
	Setmine(mine, ROW, COL);
	//Display_board(mine, ROW, COL);
	Finemine(mine, show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("退出游戏\n");
			break;
		}
		default:
		{
			printf("输入错误，请重新输入\n");
			break;
		}
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}