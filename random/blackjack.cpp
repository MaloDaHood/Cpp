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
        if(carteJoueur1>9||carteJoueur2>9)
        {

        }
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
            totalCartesJoueur=NouvelleCarte(carteJoueur1, carteJoueur2, totalCartesJoueur, piocher);
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
            int const carteCroupier3 {(1+(rand()%10))+1};
            totalCartesCroupier+=carteCroupier3;
            std::cout << "Le croupier pioche une autre carte." << std::endl << "C'est un " << carteCroupier3 << std::endl << "Il est maintenant a " << totalCartesCroupier << std::endl;
            fini=GagneOuPerdu(totalCartesCroupier, false);
            if(fini)
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
        int piocherInt;
        std::cin >> piocherInt;
        bool piocher;
        switch(piocherInt)
        {
            case 1:
                return piocher=true;
            case 2:
                return piocher=false;
            default:
                std::cout << "Vous devez entrer soit 1, soit 2." << std::endl;
        }
    } while (!bonneEntree);
}

int NouvelleCarte(int const carteJoueur1, int const carteJoueur2, int totalCartesJoueur, bool piocher)
{
    std::vector<int> tableauCartes {carteJoueur1, carteJoueur2};
    do
    {
        tableauCartes.push_back((1+(rand()%10))+1);
        totalCartesJoueur=0;
        for(int cartePiochee : tableauCartes)
        {
            totalCartesJoueur+=cartePiochee;
        }
        std::cout << "Vous tirez un " << tableauCartes.back() << ". Vous etes a " << totalCartesJoueur << std::endl;
        bool fini {GagneOuPerdu(totalCartesJoueur, true)};
        if(fini)
            return -1;
        piocher=PiocherCarte();
    }while(piocher);
    return totalCartesJoueur;
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

