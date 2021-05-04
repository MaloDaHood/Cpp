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
            if(EstLettre(motMystere))
                bonneEntree=true;
            else
                std::cout << "Vous devez rentrer un mot constitue uniquement des 26 lettres de l'alphabet et sans accents." << std::endl;
        } while (!bonneEntree);
        Game(Majuscule(motMystere));
    }
    return  EXIT_SUCCESS;
}

bool EstLettre(std::string const mot)
{
    std::string const lettres {"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"};
    return mot.find_first_not_of(lettres) == std::string::npos;
}

std::string Majuscule(std::string mot)
{
    std::transform(mot.begin(), mot.end(), mot.begin(), ::toupper);
    return mot;
}

void Game(std::string const motMystere)
{
    std::vector<std::string> tableauLettres;
    std::string lettre;
    bool fini {false};
    do
    {
        AfficherMot(motMystere, tableauLettres);
        bool bonneEntree {false};
        do
        {
            std::cout << "\nProposez une lettre : ";
            std::getline(std::cin, lettre);
            if(EstLettre(lettre)&&lettre.length()==1)
                bonneEntree=true;
            else
                std::cout << "Vous ne devez rentrer qu'une seule lettre et pas de chiffre." << std::endl;
        } while (!bonneEntree);
        system("cls");
        lettre=Majuscule(lettre);
        tableauLettres.push_back(lettre);
        std::cout << "Lettres utilisees : ";
        for(std::string lettreTab : tableauLettres)
        {
            std::cout << lettreTab << " ";
        }
        std::cout << std::endl;
    } while (!fini);
}

/*void AfficherMot(std::string mot, std::string lettre)
{
    for(int i {0}; i<mot.length(); i++)
    {
        if((lettre.find_first_not_of(mot) == std::string::npos)==false)
            std::cout << "_ ";
        else
            std::cout << lettre << " ";
    }
}*/

void AfficherMot(std::string mot, std::vector<std::string> tableauLettres)
{
    for(std::string lettre : tableauLettres)
    {
        if((lettre.find_first_not_of(mot) == std::string::npos)==false)
            std::cout << "_ ";
        else
        {
            for(int i {0};i<=lettre.find_first_of(mot); i++)
            {
                std::cout << lettre << " ";
            }
        }
    }
}