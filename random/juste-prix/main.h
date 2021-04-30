#ifndef MAIN
#define MAIN

#include <iostream>
#include <time.h>
#include <string>

// main.cpp
void ErreurEntree(int const max);
int Difficulte();
int NouveauNombre(int const max, int min);
bool Rejouer();

// user.cpp
void MainUser();
void GameUser(int const nombreMystere, int const max);

// computer.cpp
void MainComputer();
void GameComputer(int max);
bool NombreFinal(int const nombre);

#endif