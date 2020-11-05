#include <iostream>
#include "Board.h"
#include "GameLogic.h"

char drawXO(int value);

void drawBoard()
{
	std::cout << drawXO(board[0]) << "|" << drawXO(board[1]) << "|" << drawXO(board[2]) << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << drawXO(board[3]) << "|" << drawXO(board[4]) << "|" << drawXO(board[5]) << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << drawXO(board[6]) << "|" << drawXO(board[7]) << "|" << drawXO(board[8]) << std::endl;
}
char drawXO(int value)
{
	if (value == 1)
	{
		return 'X';
	}
	else
	{
		if (value == 2)
		{
			return 'O';
		}
		else
		{
			return ' ';
		}
	}
}


void printWinner()
{
	if (winner == 1)
	{
		std::cout << " X won the game! " << std::endl;
	}
	else
	{
		if (winner == 2)
		{
			std::cout << " O won the game! " << std::endl;
		}
		else
		{
			std::cout << " Draw game! " << std::endl;
		}
	}	
}
void clearScreen()
{
	system("cls");
}