#include <iostream>
#include <fstream>
#include <limits>
#include <string>

template <typename T>
T Input()
{
    T input {};
    while(!(std::cin >> input))
    {
        std::cout << "Entree invalide. Recommence." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}

struct infoPerso
{
    std::string nom;
    std::string prenom;
    std::string sexe;
    int age;
};

int main()
{
    infoPerso info{};
    std::ofstream fichier {"Prenom.Nom.csv"};
    std::cout << "Nom ? ";
    info.nom=Input<std::string>();
    std::cout << "Prenom ? ";
    info.prenom=Input<std::string>();
    std::cout << "Sexe ? ";
    info.sexe=Input<std::string>();
    std::cout << "Age ? ";
    info.age=Input<int>();
    fichier << info.nom << ',' << info.prenom << ',' << info.sexe << ',' << info.age;
    std::cout << "Ces donnees seront enregistrees dans le fichier " << info.nom << '.' << info.prenom << ".csv" << std::endl;
    std::ofstream fichierPerso {info.nom+'.'+info.prenom+".csv"};
    fichierPerso << info.nom << ',' << info.prenom << ',' << info.sexe << ',' << info.age;
    return 0;
}