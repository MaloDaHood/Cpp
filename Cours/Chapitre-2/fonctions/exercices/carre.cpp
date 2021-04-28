#include <iostream>

void DessinerCarre(int longueur, int largeur);

int main()
{
    std::cout << "Quelle longeur ?" << std::endl;
    int longueur;
    std::cin >> longueur;
    std::cout << "Quelle largeur ?" << std::endl;
    int largeur;
    std::cin >> largeur;
    DessinerCarre(longueur, largeur);
    return 0;
}

void DessinerCarre(int longueur, int largeur)
{
    for(int i {0}; i<longueur; i++)
    {
        for(int j {0}; j<largeur; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}