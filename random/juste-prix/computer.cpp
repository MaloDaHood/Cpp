#include "main.h"

void MainComputer()
{
    int const nombreMax {Difficulte()};
    system("cls");
    GameComputer(nombreMax);
}


void GameComputer(int max)
{
    int copieMax {max};
    int compteur {1};
    int min {1};
    std::string feedback {""};
    do
    {
        //std::cout << "here" << std::endl;
        int guess {NouveauNombre(max, min)};
        //std::cout << "here2" << std::endl;
        bool bonneEntree {false};
        do
        {
            //std::cout << "min : " << min << "  max : " << max << std::endl;
            std::cout << "Est-ce que c'est " << guess << " ?\n'+' = C'est plus\n'-' = C'est moins\n'=' = C'est le bon nombre" << std::endl;
            std::cin >> feedback;
            if(std::cin.fail()||feedback!="+"&&feedback!="-"&&feedback!="=")
            {
                ErreurEntree(-1);
                continue;
            }
            else if(guess==1&&feedback=="-")
            {
                system("cls");
                std::cout << "Le minimum est de 1, vous ne pouvez pas aller plus bas." << std::endl;
                continue;
            }
            else if(guess==copieMax&&feedback=="+")
            {
                system("cls");
                std::cout << "Le maximum est de " << copieMax << ", vous ne pouvez pas aller au dessus." << std::endl;
                continue;
            }
            else
                bonneEntree=true;
        } while (!bonneEntree);
        if(feedback=="+")
        {
            min=guess+1;
            if(max<min) 
                max+=5;
                if(max>copieMax)
                    max=copieMax;
            compteur++;
            system("cls");
            if(min==max) 
                if(NombreFinal(guess+1)) 
                    feedback="=";
        }
        else if(feedback=="-")
        {
            max=guess-1;
            if(max<min) 
                min-=5;
                if(min<1)
                    min=1;
            compteur++;
            system("cls");
            if(min==max) 
                if(NombreFinal(guess-1)) 
                    feedback="=";
        }
    } while (feedback!="=");
    std::cout << "L'ordinateur a trouve votre nombre apres " << compteur << " tours." << std::endl;
}

bool NombreFinal(int const nombre)
{
    int bonNombre;
    bool bonneEntree {false};
    do
    {
        std::cout << "Ton nombre doit etre " << nombre << " ?\n1. OUI\n2. NON" << std::endl;
        std::cin >> bonNombre;
        if(std::cin.fail()||bonNombre<1||bonNombre>2) 
            ErreurEntree(2);
        else 
            bonneEntree=true;
    } while (!bonneEntree);
    if(bonNombre==1)
    {
        system("cls");
        std::cout << "J'en etais sur !" << std::endl;
        return true;
    }
    else
    {
        system("cls");
        std::cout << "Ah pourtant j'en etais sur ..." << std::endl;
        return false;
    }
}