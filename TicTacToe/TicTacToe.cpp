#include <iostream>

#include "Board.h"
#include "GameLogic.h"

int board[9] = {};

int main()
{
	bool gameIsWon = false;
	bool isXsTurn = true;
	int row, col;

	//resetGame();

	do
	{
		// clear screen
		clearScreen();
		// draw board
		drawBoard();
		

		if (isXsTurn)
		{
			//X's Turn
			// diplay message for player to put move
			std::cout << "Place X:\n";
			// read the player move
			std::cin >> row >> col;
			// put move on board
			placeX(row,col);

			// switch player
			isXsTurn = false;
		}
		else
		{
			// O's Turn 
			// diplay message for player to put move
			std::cout << "Place O:\n";
			// read the player move
			std::cin >> row >> col;
			// end of part


			// put move on board
			placeO(row, col);

			// switch player
			isXsTurn = true;
		}

		//check if game is won 
		gameIsWon = isGameWon();
		if (gameIsWon == true)
		{
			// clear screen
			clearScreen();
			// draw board
			drawBoard();
			// congratulate the winner
			printWinner();
		}
			
	} while (!gameIsWon);
}