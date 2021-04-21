/**
 * \file main.cpp
 * \brief Programme permettant de dessiner un rectangle en console
 * \author Malo Massieu Rocabois
 * \version 1.0
 * \date 21/04/2021
 */

#include "main.h"

//utilisation librairie standard
using namespace std;

int main()
{
    bool good(false);
    int largeur, hauteur;
    char symbol;
    while(!good)
    {
        cout << "Quelle est la largeur ?" << endl;
        cin >> largeur;
        cout << "Quelle est le hauteur ?" << endl;
        cin >> hauteur;
        if(largeur < 0 || hauteur < 0)
        {
            cout << "Les valeurs doivent etre positives" << endl;
        }
        else
        {
            cout << "Quel symbol doit etre utilise ?" << endl;
            cin >> symbol;
            good = true;
        }
    }
    
    dessinerRectangle(largeur, hauteur, symbol);

    return 0;
}