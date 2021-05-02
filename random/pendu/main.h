#ifndef MAIN
#define MAIN

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

bool EstLettre(std::string const mot);
std::string Majuscule(std::string mot);
void Game(std::string const motMystere);
//void AfficherMot(std::string mot, std::string lettre);
void AfficherMot(std::string mot, std::vector<std::string> tableauLettres);

#endif