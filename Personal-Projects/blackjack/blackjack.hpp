#ifndef BLACKJACK
#define BLACKJACK

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <limits>
#include <string>

bool GagneOuPerdu(int const total, bool const joueur);
bool Piocher_Rejouer(bool const piocher);
int NouvelleCarte(int const carte1, int const carte2, bool piocher, bool const joueur);
void PlusOuMoins(int const cartesJoueur, int const cartesCroupier);
void ErreurEntree();
bool Game();
int AddCarte(std::vector<int>& tableauCartes, int totalCartes);

#endif