/**
 * \file main.cpp
 * \brief Fichier main
 * \author Malo Massieu Rocabois
 * \version 1.0
 * \date 21/04/2021
 */

#include "main.h"

using namespace std;

int main()
{
    // Paramètres 2 et 3 = facultatifs
    cout << nombreDeSecondes(1, 10, 25) << endl;

    return 0;
}

int nombreDeSecondes(int heures, int minutes, int secondes)
{
    int total =0;

    total = heures * 60 * 60;
    total += minutes * 60;
    total += secondes;

    return total;
}