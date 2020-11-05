
#include"Board.h"

int winner = 0;

void placeValue(int row, int column, int value);

void placeX(int row, int column)
{
	placeValue(row, column, 1);
}
void placeO(int row, int column)
{
	placeValue(row, column, 2);
}
void placeValue(int row, int column, int value)
{
	int index;
	index = row * 3 + column;
	board[index] = value;
}

// Reset function

void resetGame()
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = 0;
	}

	winner = 0;
}

// Check functions
bool isDiag1Winner()
{
	bool foundDiag1Winner = false;

	if (board[0] != 0 && board[0] == board[4] && board[4] == board[8])
	{
		foundDiag1Winner = true;
		winner = board[0];
	}
	else
	{
		foundDiag1Winner = false;
	}

	return foundDiag1Winner;
}
bool isDiag2Winner()
{
	bool foundDiag2Winner = false;

	if (board[2] != 0 && board[2] == board[4] && board[4] == board[6])
	{
		foundDiag2Winner = true;
		winner = board[2];
	}
	else
	{
		foundDiag2Winner = false;
	}

	return foundDiag2Winner;
}

bool isRowWinner(int row)
{
	/*
	 row  = 0  -> 0, 1, 2
	 row  = 1  -> 3, 4, 5
	 row  = 2  -> 6, 7, 8

	 row = x   -> 3*x+0 , 3*x+1, 3*x+2
	*/

	int startIndex = row * 3;
	bool foundRowWinner = false;

	if (board[startIndex + 0] != 0 &&
			board[startIndex + 0] == board[startIndex + 1] &&
			board[startIndex + 1] == board[startIndex + 2])
	{
		foundRowWinner = true;
		winner = board[startIndex + 0];
	}
	else
	{
		foundRowWinner = false;
	}
	return foundRowWinner;
}
bool isRowWinner()
{
	for (int row = 0; row < 3; row++)
	{
		if (isRowWinner(row))
		{
			return true;
		}
	}
	return false;
}

bool isColumnWinner(int col)
{
	/*
	col = 0 -> 0,3,6
	col = 1 -> 1,4,7
	col = 2 -> 2,5,8

	col = x -> 0+x , 3+x, 6+x
	*/
	bool foundColWinner = false;

	if (board[3*0 + col] != 0 &&
			board[3*0 + col] == board[3*1 + col] &&
			board[3*1 + col] == board[3*2 + col])
	{
		foundColWinner = true;
		winner = board[3 * 0 + col];
	}
	else
	{
		foundColWinner = false;
	}
	return foundColWinner;
}
bool isColumnWinner()
{
	for(int col = 0; col < 3; col++)
	{
		if (isColumnWinner(col))
		{
			return true;
		}
	}
	return false;
}


bool isDraw();
bool isGameWon()
{
	bool weHaveAWinner = false;
	if (isRowWinner())
	{
		weHaveAWinner = true;
	}
	else
	{
		if (isColumnWinner())
		{
			weHaveAWinner = true;
		}
		else
		{
			if (isDiag1Winner())
			{
				weHaveAWinner = true;
			}
			else
			{
				if (isDiag2Winner())
				{
					weHaveAWinner = true;
				}
				else
				{
					if (isDraw())
					{
						weHaveAWinner = true;
					}
					else
					{
						weHaveAWinner = false;
					}
				}
			}
		}
	}

	return weHaveAWinner;
}

int getNumberOfPlacedPieces()
{
	int placedPieces = 0;
	for (int i = 0; i < 9; i++)
	{
		if (board[i] != 0)
		{
			placedPieces++;
		}
	}
	return placedPieces;
}
bool isDraw()
{
	bool boardIsFull;
	if (getNumberOfPlacedPieces() == 9)
	{
		boardIsFull = true;
	}
	else
	{
		boardIsFull = false;
	}
	return boardIsFull;
}