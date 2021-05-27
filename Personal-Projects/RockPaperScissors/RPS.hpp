#ifndef RPS
#define RPS

#include <iostream>
#include <limits>
#include <time.h>
#include <array>

bool Game();
char GetPlayerMove();
void InputError(int const max);
char GetComputerMove();
bool PlayerWins(char const playerMove, char const computerMove);
void DisplayMoves(char const playerMove, char const computerMove);
bool PlayAgain();
int GetMax();

#endif