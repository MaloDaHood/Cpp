/**
 * \file dessinerRectangle.cpp
 * \brief Fichier contenant la fonction permettant de dessiner
 * \author Malo Massieu Rocabois
 * \version 1.0
 * \date 21/04/2021
 */

#include "dessinerRectangle.h"

using namespace std;

void dessinerRectangle(int largeur, int hauteur, char symbol)
{
    for(int ligne(0); ligne < hauteur; ligne++)
    {
        for(int colonne(0); colonne < largeur; colonne++)
        {
            cout << symbol;
        }
        cout << endl;
    }
}