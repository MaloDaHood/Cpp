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
#include <windows.h>

bool Game();
bool GagneOuPerdu(int const &total, bool const joueur, int const &mise);
bool Piocher_Rejouer(bool const piocher);
void NouvelleCarte(int &totalPremieresCartes, bool const joueur, int const &mise);
void PlusOuMoins(int const &cartesJoueur, int const &cartesCroupier, int const &mise);
void ErreurEntree(int const min, int const max, bool const as);
int Miser();
void Gain(int const &mise, bool const gagner);
int CartesFigures(bool const joueur, bool const initial, int totalCartes);
void AfficherCartes(std::string const &carte1, bool const &joueur, int const &totalcartes, std::string const carte2="0");
int As();

#endif