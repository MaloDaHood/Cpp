
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string> lire_fichier(std::string const & nom_fichier)
{
    std::vector<std::string> lignes {};
    std::string ligne { "" };

    std::ifstream fichier { nom_fichier };
    if (!fichier)
    {
        throw std::runtime_error("Fichier impossible à ouvrir.");
    }

    while (std::getline(fichier, ligne))
    {
        lignes.push_back(ligne);
    }

    return lignes;
}

int main()
{
    std::string nom_fichier { "" };
    std::cout << "Donnez un nom de fichier : ";
    std::cin >> nom_fichier;

    try
    {
        // Dans le try, on est assuré que toute exception levée
        // pourra être traitée dans le bloc catch situé après.

        auto lignes = lire_fichier(nom_fichier);
        std::cout << "Voici le contenu du fichier :" << std::endl;
        for (auto const & ligne : lignes)
        {
            std::cout << ligne << std::endl;
        }
    }
    // Notez qu'une exception s'attrape par référence constante.
    catch (std::runtime_error const & exception)
    {
        // On affiche la cause de l'exception.
        std::cout << "Erreur : " << exception.what() << std::endl;
    }

    return 0;
}