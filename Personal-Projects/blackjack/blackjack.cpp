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
    int totalCartesJoueur {CartesFigures(true, true, 0)};
    if(GagneOuPerdu(totalCartesJoueur, true, mise))
        return Piocher_Rejouer(false);
    if(Piocher_Rejouer(true))
    {
        /*totalCartesJoueur=*/NouvelleCarte(totalCartesJoueur, true, mise);
        if(totalCartesJoueur==-1)
            return Piocher_Rejouer(false);
    }
    int totalCartesCroupier {CartesFigures(false, true, 0)};
    if(GagneOuPerdu(totalCartesCroupier, false, mise))
        return Piocher_Rejouer(false);
    if(totalCartesCroupier<=15)
    {
        /*totalCartesCroupier=*/NouvelleCarte(totalCartesCroupier, false, mise);
        if(totalCartesCroupier==-1)
            return Piocher_Rejouer(false);
    }
    PlusOuMoins(totalCartesJoueur, totalCartesCroupier, mise);
    return Piocher_Rejouer(false);
}

bool GagneOuPerdu(int const &total, bool const joueur, int const &mise)
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

void NouvelleCarte(int &totalPremieresCartes, bool const joueur, int const &mise)
{
    if(joueur)
    {
        do
        {
            Sleep(1000);
            totalPremieresCartes=CartesFigures(joueur, false, totalPremieresCartes);
            if(GagneOuPerdu(totalPremieresCartes, joueur, mise))
            {
                totalPremieresCartes=-1;
                return;
            }
        }while(Piocher_Rejouer(true));
    }
    else
    {
        do
        {
            Sleep(1000);
            totalPremieresCartes=CartesFigures(joueur, false, totalPremieresCartes);
            if(GagneOuPerdu(totalPremieresCartes, joueur, mise))
            {
                totalPremieresCartes=-1;
                return;
            }
        } while (totalPremieresCartes<=15);
    }
}

void PlusOuMoins(int const &cartesJoueur, int const &cartesCroupier, int const &mise)
{
    std::cout << "Vous : " << cartesJoueur << "\nCroupier : " << cartesCroupier << std::endl;
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
    else if(cartesJoueur==cartesCroupier)
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

void Gain(int const &mise, bool const gagner)
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

int CartesFigures(bool const joueur, bool const initial, int totalCartes)
{
    int nombreCartes {0};
    if(initial)
        nombreCartes=2;
    else
        nombreCartes=1;
    srand ((unsigned)time(0));
    std::array<int, 2> premieresCartes {0, 0};
    for(int i {0}; i<nombreCartes; i++)
    {
        premieresCartes[i]=rand()%((11+1)-2)+2;
        totalCartes+=premieresCartes[i];
    }
    std::array<std::string, 12> const tableauFigures {"0", "0", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", " 10", " As"};
    std::array<std::string, 2> carte {"0", "0"};
    for(int i {0}; i<nombreCartes; i++)
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
    if(initial)
        AfficherCartes(carte[0], joueur, totalCartes, carte[1]);
    else
        AfficherCartes(carte[0], joueur, totalCartes);
    return totalCartes;
}

void AfficherCartes(std::string const &carte1, bool const &joueur, int const &totalcartes, std::string const carte2)
{
    if(joueur)
    {
        if(carte1==carte2)
            std::cout << "Vous tirez deux fois un" << carte1 << "." << std::endl;
        else if(carte2=="0")
            std::cout << "Vous tirez un" << carte1 << "." << std::endl;
        else
            std::cout << "Vous tirez un" << carte1 << " et un" << carte2 << "." << std::endl;
        std::cout << "Vous etes a " << totalcartes << "." << std::endl;
    }
    else
    {
        if(carte1==carte2)
            std::cout << "Le croupier tire deux fois un" << carte1 << "." << std::endl;
        else if(carte2=="0")
            std::cout << "Le croupier tire un" << carte1 << "." << std::endl;
        else
            std::cout << "Le croupier tire un" << carte1 << " et un" << carte2 << "." << std::endl;
        std::cout << "Il est a " << totalcartes << "." << std::endl;
    }
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