#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    using namespace std::literals;
    std::unordered_map<std::string, std::string> dictionnaire
    {
        { "Clem"s, "La mascotte du site Zeste de Savoir, toute gentille et toute mignonne."s },
        { "mehdidou99"s, "Un des auteurs du tutoriel C++."s },
        { "informaticienzero"s, "Un des auteurs du tutoriel C++."s },
        { "Taurre"s, "Un super validateur !"s },
        { "Arius"s, "Un membre super sympa mais qui mord."s },
        { "Gants de vaisselle"s, "Objets présents sur le site et dont personne ne sait pourquoi."s }
    };
    // Insertion avec la fonction 'insert'.
    dictionnaire.insert({ "C++"s, "Le langage que vous apprenez."s });

    // Ajout d'une nouvelle paire avec les crochets.
    dictionnaire["nohar"] = "Un lama ancestral."s;

    // Utilisation des crochets pour modifier la valeur associée à une clé existante.
    dictionnaire["Taurre"] = "Un validateur vraiment cool !"s;

    // Accès en lecture.
    std::cout << "Qui est Taurre ? " << dictionnaire["Taurre"] << std::endl << std::endl;
    
    // Suppression par clé.
    dictionnaire.erase("Un truc"s);
    for(auto const &pair : dictionnaire)
    {
        std::cout << "Cle : " << pair.first << std::endl;
        std::cout << "Valeur : " << pair.second << std::endl;
    }
    return 0;
}