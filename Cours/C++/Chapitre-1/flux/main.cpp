#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream fichier {"entree.txt"};
    std::string ligne {""};

    while(std::getline(fichier, ligne))
    {
        std::cout << "Ligne lue : " << ligne << std::endl;
    }
    return 0;
}