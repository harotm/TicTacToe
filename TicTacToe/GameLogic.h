#pragma once

// in memory  ->      Winner 
//      0      ->      draw
//      1      ->       X
//      2      ->       O
extern int winner;

void placeX(int row, int column);
void placeO(int row, int column);

void resetGame();

bool isGameWon();
bool isDraw();
