#include <iostream>
#include <vector>

int main()
{
    std::vector<int> tableau;
    bool positif {true};
    while(positif)
    {
        std::cout << "Entrez une valeur (negative pour arreter)" << std::endl;
        int valeur;
        std::cin >> valeur;
        if(valeur<0)
            positif=false;
        else
        {
            tableau.push_back(valeur);
        }
    }
    int total {0};
    for(int valeur : tableau)
    {
        total+=valeur;
    }
    int moyenne {total/tableau.size()};
    std::cout << "La moyenne est de : " << moyenne << std::endl;
    return EXIT_SUCCESS;
}