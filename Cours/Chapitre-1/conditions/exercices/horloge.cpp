#include <iostream>

int main()
{
    std::cout << "Quelle heure est-il ?" << std::endl;
    int heure;
    std::cin >> heure;
    if(heure<0||heure>24)
    {
        std::cout << "Elles sont bizarres tes heures toi !" << std::endl;
    }
    else if(heure>=8&&heure<12)
    {
        std::cout << "C'est le matin !" << std::endl;
    }
    else if(heure==12)
    {
        std::cout << "Il est midi !" << std::endl;
    }
    else if(heure>12&&heure<18)
    {
        std::cout << "C'est l'apres midi !" << std::endl;
    }
    else if(heure>=18&&heure<21)
    {
        std::cout << "C'est le soir !" << std::endl;
    }
    else if(heure==0)
    {
        std::cout << "Il est minuit !" << std::endl;
    }
    else
    {
        std::cout << "C'est la nuit !" << std::endl;
    }
    return 0;
}