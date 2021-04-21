/**
 * \file tableauxVector.cpp
 * \brief Exemple de tableau dynamiques
 * \author Malo Massieu Rocabois
 * \version 1.0
 * \date 21/04/2021
 */

#include "main.h"

using namespace std;

int main()
{
    /**
     * \brief vector<type> nomTableau(tailleTableau, valeurDistribuée)
     */
    vector<int> tableau(3, 2);/**
    /**
     * \brief Rajoute une valeur à la fin du tableau
     */
    tableau.push_back(8);
    /**
     * \brief Supprime la dernière case du tableau 
     */
    tableau.pop_back();
    /**
     * \return la taille du tableau
     */
    int const taille(tableau.size());

    cout << taille << endl;

    return 0;
}