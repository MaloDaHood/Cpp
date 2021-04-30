#include "main.h"

int main()
{
    system("cls");
    bool rejouer {true};
    while (rejouer)
    {
        std::cout << "Bienvenue dans une nouvelle partie du juste prix." << std::endl;
        bool bonneEntree {false};
        do
        {
            std::cout << "Voulez-vous deviner le nombre ou que l'ordinateur le devine ?\n1. Je veux deviner\n2. L'ordinateur devine." << std::endl;
            int choixJoueur;
            std::cin >> choixJoueur;
            if(std::cin.fail()||choixJoueur<1||choixJoueur>2)
            {
                ErreurEntree(2);
                continue;
            }
            else if(choixJoueur==1)
            {
                system("cls");
                MainUser();
                bonneEntree=true;
            }
            else
            {
                system("cls");
                MainComputer();
                bonneEntree=true;
            }
            rejouer=Rejouer();
        } while (!bonneEntree);
    }
    return EXIT_SUCCESS;
}

void ErreurEntree(int const max)
{
    if(max-1==1)
    {
        system("cls");
        std::cout << "Vous devez rentrer soit 1, soit " << max << "." << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    else
    {
        system("cls");
        std::cout << "Vous devez rentrer un chiffre entre 1 et " << max << "." << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
}

bool Rejouer()
{
    bool bonneEntree {false};
    do
    {
        std::cout << "Voulez-vous rejouer ?\n1. OUI\n2. NON" << std::endl;
        int rejouer;
        std::cin >> rejouer;
        if(std::cin.fail()||rejouer<1||rejouer>2)
            ErreurEntree(2);
        else if(rejouer==1)
            return true;
        else
            return false;
    } while (!bonneEntree); 
}