#ifndef RPS
#define RPS

#include <iostream>
#include <limits>
#include <time.h>
#include <array>

bool Game();
char getPlayerMove();
void InputError(int const max);
char getComputerMove();
bool PlayerWins(char const playerMove, char const computerMove);
void DisplayMoves(char const playerMove, char const computerMove);
bool PlayAgain();

#endif