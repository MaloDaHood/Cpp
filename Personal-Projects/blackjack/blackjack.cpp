#include "blackjack.h"

int main()
{
    bool rejouer {true};
    while(rejouer)
    {
        std::cout << "Bienvenue dans une nouvelle partie de BlackJack" << std::endl;
        srand ((unsigned)time(0));
        int const carteJoueur1 {(1+(rand()%10))+1};
        int const carteJoueur2 {(1+(rand()%10))+1};
        int totalCartesJoueur {carteJoueur1+carteJoueur2};
        std::cout << "Vous tirez un " << carteJoueur1 << " et un " << carteJoueur2 << std::endl << "Vous etes a " << totalCartesJoueur << std::endl;
        bool fini {GagneOuPerdu(totalCartesJoueur, true)};
        if(fini)
        {
            rejouer=Rejouer();
            if(rejouer)
                continue;
            else
                exit(EXIT_SUCCESS);
        }
        bool piocher {PiocherCarte()};
        if(piocher)
            totalCartesJoueur=NouvelleCarte(carteJoueur1, carteJoueur2, totalCartesJoueur, piocher, true);
            if(totalCartesJoueur==-1)
            {
                rejouer=Rejouer();
                if(rejouer)
                    continue;
                else
                    exit(EXIT_SUCCESS);
            }
        int const carteCroupier1 {(1+(rand()%10))+1};
        int const carteCroupier2 {(1+(rand()%10))+1};
        int totalCartesCroupier {carteCroupier1+carteCroupier2};
        std::cout << "Le croupier tire un " << carteCroupier1 << " et un " << carteCroupier2 << std::endl << "Il est a " << totalCartesCroupier << std::endl;
        fini=GagneOuPerdu(totalCartesCroupier, false);
        if(fini)
        {
            rejouer=Rejouer();
            if(rejouer)
                continue;
            else
                exit(EXIT_SUCCESS);
        }
        if(totalCartesCroupier<=15)
        {
            totalCartesCroupier=NouvelleCarte(carteCroupier1, carteCroupier2, totalCartesCroupier, false, false);
            if(totalCartesCroupier==-1)
            {
                rejouer=Rejouer();
                if(rejouer)
                    continue;
                else
                    exit(EXIT_SUCCESS);
            }
        }
        PlusOuMoins(totalCartesJoueur, totalCartesCroupier);
        rejouer=Rejouer();
        if(rejouer)
            continue;
        else
            exit(EXIT_SUCCESS);
    }
    return EXIT_SUCCESS;
}

bool GagneOuPerdu(int const total, bool const joueur)
{
    if(joueur)
    {
        if(total>21)
        {
            std::cout << "Vous perdez, vous avez plus de 21." << std::endl;
            return true;
        }
        else if(total==21)
        {
            std::cout << "Vous gagnez, vous avez atteint 21." << std::endl;
            return true;
        }    
    }
    else
    {
        if(total>21)
        {
            std::cout << "Le croupier perd, il a plus de 21." << std::endl;
            return true;
        }
        else if(total==21)
        {
            std::cout << "Le croupier gagne, il a atteint 21." << std::endl;
            return true;
        }
    }
    return false;
}

bool PiocherCarte()
{
    bool bonneEntree {false};
    do
    {
        std::cout << "Voulez-vous tirer une autre carte ?" << std::endl << "1. OUI" << std::endl << "2. NON" << std::endl;
        int piocher;
        std::cin >> piocher;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }
        switch(piocher)
        {
            case 1:
                return true;
            case 2:
                return false;
            default:
                std::cout << "Vous devez entrer soit 1, soit 2." << std::endl;
        }
    } while (!bonneEntree);
}

int NouvelleCarte(int const carte1, int const carte2, int totalCartes, bool piocher, bool const joueur)
{
    std::vector<int> tableauCartes {carte1, carte2};
    if(joueur)
    {
        do
        {
            tableauCartes.push_back((1+(rand()%10))+1);
            totalCartes=0;
            for(int cartePiochee : tableauCartes)
            {
                totalCartes+=cartePiochee;
            }
            std::cout << "Vous tirez un " << tableauCartes.back() << ". Vous etes a " << totalCartes << std::endl;
            bool fini {GagneOuPerdu(totalCartes, true)};
            if(fini)
                return -1;
            piocher=PiocherCarte();
        }while(piocher);
    }
    else
    {
        do
        {
            tableauCartes.push_back((1+(rand()%10))+1);
            totalCartes=0;
            for(int cartePiochee : tableauCartes)
            {
                totalCartes+=cartePiochee;
            }
            std::cout << "Le croupier tire une autre carte." << std::endl << "Il tire un " << tableauCartes.back() << ". Il est maintenant a " << totalCartes << std::endl;
            bool fini {GagneOuPerdu(totalCartes, false)};
            if(fini)
                return -1;
        } while (totalCartes<=15);
        
    }
    
    return totalCartes;
}

void PlusOuMoins(int const cartesJoueur, int const cartesCroupier)
{
    if(21-cartesJoueur<21-cartesCroupier)
        std::cout << "Vous gagnez, vous etes le plus proche de 21." << std::endl;
    else if(21-cartesCroupier<21-cartesJoueur)
        std::cout << "Vous perdez, le croupier est plus proche de 21." << std::endl;
    else if(21-cartesJoueur==21-cartesCroupier)
        std::cout << "Il y a egalite, personne ne gagne." << std::endl;
}

bool Rejouer()
{
    bool bonneEntree {false};
    do
    {
        std::cout << "Voulez-vous rejouer ?" << std::endl << "1. OUI" << std::endl << "2. NON" << std::endl;
        int rejouer;
        std::cin >> rejouer;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }
        switch(rejouer)
        {
            case 1:
                return true;
            case 2:
                return false;
            default:
                std::cout << "Vous devez entrer soit 1, soit 2." << std::endl;
        }
    } while (!bonneEntree);
}