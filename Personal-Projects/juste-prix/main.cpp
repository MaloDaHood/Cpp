#include "main.h"

int main()
{
    bool rejouer {true};
    while (rejouer)
    {
        system("cls");
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
    else if(max==-1)
    {
        system("cls");
        std::cout << "Vous devez rentrer soit '+', '-' ou '='." << std::endl;
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

int Difficulte()
{
    bool bonneEntree {false};
    do
    {
        std::cout << "Quel niveau de difficulté choisissez vous ?\n1. Facile(1/10)\n2. Moyen(1/100)\n3. Difficile(1/1000)" << std::endl;
        int choix;
        std::cin >> choix;
        if(std::cin.fail()||choix<1||choix>3)
            ErreurEntree(3);
        else if(choix==1) 
            return 10;
        else if(choix==2) 
            return 100;
        else 
            return 1000;
    } while (!bonneEntree);
}

int NouveauNombre(int const max, int min)
{
    srand ((unsigned)time(0));
    return rand()%((max+1)-min)+min;
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