#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*******************************\n");
	printf("*** Welcome to bingo game! ****\n");
	printf("******** 1.play 0.exit ********\n");
	printf("****** Designed by Kate *******\n");
	printf("*******************************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	Init_board(board, ROW, COL);
	Display_board(board, ROW, COL);
	while (1)
	{
		Playermove(board, ROW, COL);
		Display_board(board, ROW, COL);
		ret=Is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		Computermove(board, ROW, COL);
		Display_board(board, ROW, COL);
		ret=Is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
		printf("ƽ��\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>\n");
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
			printf("�˳���Ϸ\n");
			break;
		}
		default:
		{
			printf("ѡ�����������ѡ��\n");
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