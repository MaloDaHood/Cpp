/**
 * \file main.h
 * \brief Header pour le fichier main
 * \author Malo Massieu Rocabois
 * \version 1.0
 * \date 21/04/2021
 */

#ifndef MAIN
#define MAIN

#include <iostream>

/**
 * \brief Calcul le nombre de secondes
 * \param heures int Nombres d'heures - Obligatoire
 * \param minutes int Nombre de minutes - Facultatif
 * \param secondes int Nombre de secondes - Facultatif
 * \return Total de minutes
 */
int nombreDeSecondes(int heures, int minutes = 0, int secondes = 0);

#endif