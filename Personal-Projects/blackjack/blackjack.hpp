#ifndef BLACKJACK
#define BLACKJACK

#include <iostream>
#include <time.h>
#include <vector>
#include <limits>
#include <string>
#include <fstream>
#include <cmath>
#include <array>

bool Game();
bool GagneOuPerdu(int const total, bool const joueur, int const mise);
bool Piocher_Rejouer(bool const piocher);
int NouvelleCarte(int const totalPremieresCartes, bool piocher, bool const joueur, int const mise);
int AddCarte(std::vector<int>& tableauCartes, int totalCartes);
void PlusOuMoins(int const cartesJoueur, int const cartesCroupier, int const mise);
void ErreurEntree(int const min, int const max, bool const as);
int Miser();
void Gain(int const mise, bool const gagner);
int CartesInitiales(bool const joueur);
int As();

#endif