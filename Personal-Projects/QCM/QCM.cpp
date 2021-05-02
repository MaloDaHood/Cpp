#include "QCM.h"

int main()
{
    bool rejouer {true};
    while(rejouer)
    {
        int premiereQuestion {QuestionUne()};
        if(premiereQuestion==1)
        {
            QuestionC();
            rejouer=Rejouer();
            continue;
        }
        else if(premiereQuestion==2)
        {
            QuestionPython();
            rejouer=Rejouer();
            continue;
        }
        else if(premiereQuestion==3)
        {
            QuestionJava();
            rejouer=Rejouer();
            continue;
        }
        else
        {
            QuestionCpp();
            rejouer=Rejouer();
            continue;
        }
    }
    return EXIT_SUCCESS;   
}

int QuestionUne()
{
    bool bonneEntree {false};
    do
    {
        std::cout << "Quel est ton languages prefere ?\n1. C\n2. Python\n3. Java\n4. C++" << std::endl;
        int reponse;
        std::cin >> reponse;
        if(std::cin.fail()||reponse<1||reponse>4)
            ErreurEntree(1, 4);
        else    
            return reponse;
    } while (!bonneEntree);
}

void ErreurEntree(int const min, int const max)
{
    int difference {max-min};
    if(difference==1)
    {
        std::cout << "Vous devez entrer soit " << min << ", soit " << max << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    else
    {
        std::cout << "Vous devez entrer un chiffre entre " << min << " et " << max << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
}
    

void QuestionC()
{
    std::cout << "D'accord." << std::endl;
    bool bonneEntree {false};
    do
    {
        std::cout << "A quoi sert la fonction 'malloc()' ?\n1. Elle permet de connaitre la taille d'une variable en memoire.\n2. Elle permet d'allouer un bloc memoire.\n3. Elle permet de changer la cible d'un pointeur." << std::endl;
        int reponse;
        std::cin >> reponse;
        if(std::cin.fail()||reponse<1||reponse>3)
            ErreurEntree(1, 3);
        else if(reponse==2)
        {
            BonneReponse();
            bonneEntree=true;
        }
        else
        {
            MauvaiseReponse();
            bonneEntree=true;
        }
    } while (!bonneEntree);
}

void QuestionPython()
{
    std::cout << "D'accord." << std::endl;
    bool bonneEntree {false};
    do
    {
        std::cout << "Que fait cette methode ? => '.capitalize()'\n1. Elle met tous les caracteres en majuscule.\n2. Elle met la premiere lettre de chaque mot en majuscule.\n3. Elle met une majuscule au debut de la phrase." << std::endl;
        int reponse;
        std::cin >> reponse;
        if(std::cin.fail()||reponse<1||reponse>3)
            ErreurEntree(1, 3);
        else if(reponse==3)
        {
            BonneReponse();
            bonneEntree=true;
        }
        else
        {
            MauvaiseReponse();
            bonneEntree=true;
        }
    } while (!bonneEntree);
}

void QuestionJava()
{
    std::cout << "D'accord." << std::endl;
    bool bonneEntree {false};
    do
    {
        std::cout << "Une class accessible uniquement dans le contexte dans lequel les variables sont definies est definie par ?\n1. 'package-protected'.\n2. 'private'.\n3. 'protected'." << std::endl;
        int reponse;
        std::cin >> reponse;
        if(std::cin.fail()||reponse<1||reponse>3)
            ErreurEntree(1, 3);
        else if(reponse==2)
        {
            BonneReponse();
            bonneEntree=true;
        }
        else
        {
            MauvaiseReponse();
            bonneEntree=true;
        }
    } while (!bonneEntree);
}

void QuestionCpp()
{
    std::cout << "D'accord." << std::endl;
    bool bonneEntree {false};
    do
    {
        std::cout << "Un tableau dynamique est defini par ?\n1. 'std::vector'\n2. 'std::array'\n3. 'std::dictionary'" << std::endl;
        int reponse;
        std::cin >> reponse;
        if(std::cin.fail()||reponse<1||reponse>3)
            ErreurEntree(1, 3);
        else if(reponse==1)
        {
            BonneReponse();
            bonneEntree=true;
        }
        else
        {
            MauvaiseReponse();
            bonneEntree=true;
        }
    } while (!bonneEntree);
}

void BonneReponse()
{
    std::cout << "Bravo c'est la bonne reponse !" << std::endl;
}

void MauvaiseReponse()
{
    std::cout << "Desole mais c'est la mauvaise reponse, tu fera mieux la procahine fois." << std::endl;
}

bool Rejouer()
{
    bool bonneEntree {false};
    do
    {
        std::cout << "Tu veux rejouer ?\n1. OUI\n2. NON" << std::endl;
        int rejouer;
        std::cin >> rejouer;
        if(std::cin.fail()||rejouer<1||rejouer>2)
            ErreurEntree(1, 2);
        else if(rejouer==1)
            return true;
        else
            return false;
    } while (!bonneEntree);
}