#pragma once

// in memory  ->      Output 
//      0      ->      ' '
//      1      ->       X
//      2      ->       O
extern int board[9];

void drawBoard();
void printWinner();
void clearScreen();