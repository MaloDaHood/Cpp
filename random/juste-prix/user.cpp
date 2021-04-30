#include "main.h"


void MainUser()
{
    int const nombreMax {Difficulte()};
    int const nombreMystere {NouveauNombre(nombreMax)};
    system("cls");
    GameUser(nombreMystere, nombreMax);
}

void GameUser(int const nombreMystere, int const max)
{
    int compteur {1};
    bool bonneReponse {false};
    do
    {
        int guess;
        bool bonneEntree {false};
        do
        {
            std::cout << "Quel est le nombre ?" << std::endl;
            std::cin >> guess;
            if(std::cin.fail()||guess<1||guess>max)
                ErreurEntree(max);
            else
                bonneEntree=true;
        } while (!bonneEntree);
        if(guess==nombreMystere)
        {
            std::cout << "Bravo vous avez le nombre mystere.\nC'etait " << nombreMystere << ".\nVous l'avez trouve en " << compteur << " coups." << std::endl;
            bonneReponse=true;
            continue;
        }
        else if(guess>nombreMystere)
        {
            system("cls");
            std::cout << "C'est moins !" << std::endl;
            compteur++;
            continue;
        }
        else
        {
            system("cls");
            std::cout << "C'est plus !" << std::endl;
            compteur++;
            continue;
        }
    } while (!bonneReponse);
}