#ifndef BLACKJACK
#define BLACKJACK

#include <iostream>
#include <time.h>
#include <vector>
#include <limits>
#include <string>
#include <fstream>
#include <cmath>

bool Game();
bool GagneOuPerdu(int const total, bool const joueur, int const mise);
bool Piocher_Rejouer(bool const piocher);
int NouvelleCarte(int const carte1, int const carte2, bool piocher, bool const joueur, int const mise);
int AddCarte(std::vector<int>& tableauCartes, int totalCartes);
void PlusOuMoins(int const cartesJoueur, int const cartesCroupier, int const mise);
void ErreurEntree(int const min, int const max);
int Miser();
void Gain(int const mise, bool const gagner);

#endif