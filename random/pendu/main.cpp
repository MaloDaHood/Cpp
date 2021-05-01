#include "main.h"

int main()
{
    bool rejouer {true};
    while(rejouer)
    {
        std::string motMystere {""};
        std::cout << "Bienvenue dans une nouvelle partie de pendu." << std::endl;
        bool bonneEntree {false};
        do
        {
            std::cout << "Choisissez un mot : " << std::endl;
            std::getline(std::cin, motMystere);
            if(EstNombre(motMystere))
                bonneEntree=true;
            else
                std::cout << "Vous devez rentrer un mot constitue uniquement des 26 lettres de l'alphabet." << std::endl;
        } while (!bonneEntree);
        std::cout << "mot : " << motMystere << std::endl;
    }
    return  EXIT_SUCCESS;
}

bool EstNombre(std::string const mot)
{
    std::string const lettres {"abcdefghijklmnopqrstuvwxyz"};
    return mot.find_first_not_of(lettres) == std::string::npos;
}