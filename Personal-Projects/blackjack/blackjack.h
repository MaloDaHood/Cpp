#ifndef BLACKJACK
#define BLACKJACK

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

bool GagneOuPerdu(int total, bool joueur);
bool PiocherCarte();
int NouvelleCarte(int carteJoueur1, int carteJoueur2, int totalCartesJoueur, bool piocher, bool const joueur);
void PlusOuMoins(int cartesJoueur, int cartesCroupier);
bool Rejouer();

#endif