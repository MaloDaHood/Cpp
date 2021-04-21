/**
 * \file tableauxStatiques.cpp
 * \brief Exemple de tableau statique
 * \author Malo Massieu Rocabois
 * \version 1.0
 * \date 21/04/2021
 */

#include "main.h"

using namespace std;

int main()
{
    int const tailleTableau(6);
    double tableau[tailleTableau]={18.88, 15.58, 16.31, 15.75, 16.72, 19.63};
    double moyenneFinale(moyenne(tableau, tailleTableau));

    cout << "La moyenne est de " << moyenneFinale << endl;

    return 0;
}

double moyenne(double tableau[], int tailleTableau)
{
    double moyenne(0);
    for(int i(0); i < tailleTableau; i++)
    {
        moyenne += tableau[i];
    }
    moyenne /= tailleTableau;
    return moyenne;
}