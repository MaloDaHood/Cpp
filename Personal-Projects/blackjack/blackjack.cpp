#include "blackjack.hpp"

int main()
{
    system("cls");
    bool rejouer {true};
    while(rejouer)
    {
        rejouer=Game();
    }
    return EXIT_SUCCESS;
}

bool Game()
{
    std::cout << "Bienvenue dans une nouvelle partie de BlackJack" << std::endl;
    int const mise {Miser()};
    srand ((unsigned)time(0));
    int const carteJoueur1 {(1+(rand()%10))+1};
    int const carteJoueur2 {(1+(rand()%10))+1};
    int totalCartesJoueur {carteJoueur1+carteJoueur2};
    std::cout << "Vous tirez un " << carteJoueur1 << " et un " << carteJoueur2 << std::endl << "Vous etes a " << totalCartesJoueur << std::endl;
    if(GagneOuPerdu(totalCartesJoueur, true, mise))
        return Piocher_Rejouer(false);
    bool piocher {Piocher_Rejouer(true)};
    if(piocher)
        totalCartesJoueur=NouvelleCarte(carteJoueur1, carteJoueur2, piocher, true, mise);
        if(totalCartesJoueur==-1)
            return Piocher_Rejouer(false);
    int const carteCroupier1 {(1+(rand()%10))+1};
    int const carteCroupier2 {(1+(rand()%10))+1};
    int totalCartesCroupier {carteCroupier1+carteCroupier2};
    std::cout << "Le croupier tire un " << carteCroupier1 << " et un " << carteCroupier2 << std::endl << "Il est a " << totalCartesCroupier << std::endl;
    if(GagneOuPerdu(totalCartesCroupier, false, mise))
        return Piocher_Rejouer(false);
    if(totalCartesCroupier<=15)
    {
        totalCartesCroupier=NouvelleCarte(carteCroupier1, carteCroupier2, false, false, mise);
        if(totalCartesCroupier==-1)
            return Piocher_Rejouer(false);
    }
    PlusOuMoins(totalCartesJoueur, totalCartesCroupier, mise);
    return Piocher_Rejouer(false);
}

bool GagneOuPerdu(int const total, bool const joueur, int const mise)
{
    if(joueur)
    {
        if(total>21)
        {
            std::cout << "Vous perdez, vous avez plus de 21." << std::endl;
            Gain(mise, false);
        }
        else if(total==21)
        {
            std::cout << "Vous gagnez, vous avez atteint 21." << std::endl;
            Gain(mise, true);
        }
        else
            return false;
        return true;
    }
    else
    {
        if(total>21)
        {
            std::cout << "Le croupier perd, il a plus de 21." << std::endl;
            Gain(mise, true);
        }
        else if(total==21)
        {
            std::cout << "Le croupier gagne, il a atteint 21." << std::endl;
            Gain(mise, false);
        }
        else
            return false;
        return true;
    }
}

bool Piocher_Rejouer(bool const piocher)
{
    std::string finPhrase;
    if(piocher)
        finPhrase="tirer une autre carte ?";
    else
        finPhrase="rejouer ?";
    int reponse;
    bool bonneEntree {false};
    do
    {
        std::cout << "Voulez-vous " << finPhrase << std::endl << "1. OUI" << std::endl << "2. NON" << std::endl;
        std::cin >> reponse;
        if(std::cin.fail()||reponse<1||reponse>2)
            ErreurEntree(1, 2);
        else
            bonneEntree=true;
    } while (!bonneEntree);
    system("cls");
    if(reponse==1)
        return true;
    else
        return false;
}

int NouvelleCarte(int const carte1, int const carte2, bool piocher, bool const joueur, int const mise)
{
    int totalCartes;
    std::vector<int> tableauCartes {carte1, carte2};
    if(joueur)
    {
        do
        {
            totalCartes=AddCarte(tableauCartes, totalCartes);
            std::cout << "Vous tirez un " << tableauCartes.back() << ". Vous etes a " << totalCartes << std::endl;
            if(GagneOuPerdu(totalCartes, true, mise))
                return -1;
            piocher=Piocher_Rejouer(true);
        }while(piocher);
    }
    else
    {
        do
        {
            totalCartes=AddCarte(tableauCartes, totalCartes);
            std::cout << "Le croupier tire une autre carte." << std::endl << "Il tire un " << tableauCartes.back() << ". Il est maintenant a " << totalCartes << std::endl;
            if(GagneOuPerdu(totalCartes, false, mise))
                return -1;
        } while (totalCartes<=15);
    }
    return totalCartes;
}

int AddCarte(std::vector<int>& tableauCartes, int totalCartes)
{
    tableauCartes.push_back((1+(rand()%10))+1);
    totalCartes=0;
    for(int const cartePiochee : tableauCartes)
        totalCartes+=cartePiochee;
    return totalCartes;
}

void PlusOuMoins(int const cartesJoueur, int const cartesCroupier, int const mise)
{
    if(21-cartesJoueur<21-cartesCroupier)
    {
        std::cout << "Vous gagnez, vous etes le plus proche de 21." << std::endl;
        Gain(mise, true);
    }
    else if(21-cartesCroupier<21-cartesJoueur)
    {
        std::cout << "Vous perdez, le croupier est plus proche de 21." << std::endl;
        Gain(mise, false);
    }
    else
        std::cout << "Il y a egalite, personne ne gagne.\nVous conservez votre argent." << std::endl;
}

void ErreurEntree(int const min, int const max)
{
    if(max-min==1)
        std::cout << "Vous devez entrer soit " << min << ", soit " << max << "." << std::endl;
    else
        std::cout << "Vous devez entrer un nombre entre " << min << " et " << max << "." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

int Miser()
{
    std::ifstream fichierMise {"mise.txt"};
    int miseTotale {0};
    fichierMise >> miseTotale;
    int mise {0};
    bool bonneEntree {false};
    do
    {
        std::cout << "Vous possedez un total de " << miseTotale << " euros.\nCombien voulez-vous miser ?" << std::endl;
        std::cin >> mise;
        if(std::cin.fail()||mise<1||mise>miseTotale)
            ErreurEntree(1, miseTotale);
        else
            bonneEntree=true;
    } while (!bonneEntree);
    system("cls");
    std::cout << "Vous misez " << mise << " euros et le croupier fait de meme.\nIl vous reste " << miseTotale-mise << " euros." << std::endl;
    return mise;
}

void Gain(int const mise, bool const gagner)
{
    std::ifstream fichierMiseLecture {"mise.txt"};
    int miseTotale {0};
    fichierMiseLecture >> miseTotale;
    int gain {0};
    if(gagner)
    {
        gain=mise;
        std::cout << "Vous gagnez " << gain << " euros." << std::endl;
    }
    else
    {
        gain-=mise;
        std::cout << "Vous perdez " << abs(gain) << " euros." << std::endl;
    }
    gain+=miseTotale;
    if(gain==0)
    {
        std::cout << "Vous n'avez plus aucun argent !\nHeureusment pour vous votre compte est gracieusement credite de 500 euros.\nVous ferez mieux la prochaine fois !" << std::endl;
        gain=500;
    }
    std::ofstream fichierMiseEcriture {"mise.txt"};
    fichierMiseEcriture << gain;
}