#ifndef BLACKJACK
#define BLACKJACK

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <string>
#include <array>

bool GagneOuPerdu(int total, bool joueur);
bool PiocherCarte();
int NouvelleCarte(int carteJoueur1, int carteJoueur2, int totalCartesJoueur, bool piocher);
void PlusOuMoins(int cartesJoueur, int cartesCroupier);
bool Rejouer();

#endif