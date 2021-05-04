#include "blackjack.hpp"

int main()
{
    system("cls");
    bool rejouer {true};
    while(rejouer)
        rejouer=Game();
    return EXIT_SUCCESS;
}

bool Game()
{
    std::cout << "Bienvenue dans une nouvelle partie de BlackJack" << std::endl;
    int const mise {Miser()};
    int totalCartesJoueur {CartesInitiales(true)};
    std::cout << "Vous etes a " << totalCartesJoueur << "." << std::endl;
    if(GagneOuPerdu(totalCartesJoueur, true, mise))
        return Piocher_Rejouer(false);
    if(Piocher_Rejouer(true))
        totalCartesJoueur=NouvelleCarte(totalCartesJoueur, true, true, mise);
        if(totalCartesJoueur==-1)
            return Piocher_Rejouer(false);
    int totalCartesCroupier {CartesInitiales(false)};
    std::cout << "Il est a " << totalCartesCroupier << "." << std::endl;
    if(GagneOuPerdu(totalCartesCroupier, false, mise))
        return Piocher_Rejouer(false);
    if(totalCartesCroupier<=15)
    {
        totalCartesCroupier=NouvelleCarte(totalCartesCroupier, false, false, mise);
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
            ErreurEntree(1, 2, false);
        else
            bonneEntree=true;
    } while (!bonneEntree);
    system("cls");
    if(reponse==1)
        return true;
    else
        return false;
}

int NouvelleCarte(int const totalPremieresCartes, bool piocher, bool const joueur, int const mise)
{
    int totalCartes;
    std::vector<int> tableauCartes {totalPremieresCartes};
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
    tableauCartes.push_back(rand()%((11+1)-2)+2);
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

void ErreurEntree(int const min, int const max, bool const as)
{
    if(max-min==1||as)
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
            ErreurEntree(1, miseTotale, false);
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

int CartesInitiales(bool const joueur)
{
    srand ((unsigned)time(0));
    int totalCartes {0};
    std::array<int, 2> premieresCartes {0, 0};
    for(int i {0}; i<2; i++)
    {
        premieresCartes[i]=rand()%((11+1)-2)+2;
        totalCartes+=premieresCartes[i];
    }
    std::array<std::string, 12> const tableauFigures {"0", "0", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", " 10", " As"};
    std::array<std::string, 2> carte {"0", "0"};
    for(int i {0}; i<2; i++)
    {
        carte[i]=tableauFigures[premieresCartes[i]];
        if(carte[i]==" 10")
        {
            std::array<std::string, 3> const ValetDameRoi {" Valet", "e Dame", " Roi"};
            carte[i]=ValetDameRoi[rand()%3];
        }
        if(joueur)
            if(carte[i]==" As")
                totalCartes+=As();
    }
    if(carte[0]==carte[1])
    {
        if(joueur)
            std::cout << "Vous tirez deux fois un" << carte[0] << "." << std::endl;
        else
            std::cout << "Le croupier tire deux fois un" << carte[0] << "." << std::endl;
    }
    else
    {
        if(joueur)
            std::cout << "Vous tirez un" << carte[0] << " et un" << carte[1] << "." << std::endl;
        else
            std::cout << "Le croupier tire un" << carte[0] << " et un" << carte[1] << "." << std::endl;
    }
    return totalCartes;
}

int As()
{
    int valeur;
    bool bonneEntree {false};
    do
    {
        std::cout << "Vous avez tire un As.\nVoulez-vous qu'il compte en tant que 1 ou 11 ? (1/11)" << std::endl;
        std::cin >> valeur;
        switch(valeur)
        {
            case 1:
                valeur=-10;
                bonneEntree=true;
                break;
            case 11:
                valeur=0;
                bonneEntree=true;
                break;
            default:
                ErreurEntree(1, 11, true);
                break;
        }
    } while (!bonneEntree);
    return valeur;
}