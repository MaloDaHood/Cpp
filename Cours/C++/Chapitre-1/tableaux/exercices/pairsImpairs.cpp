#include <iostream>
#include <vector>

int main()
{
    std::vector<int> const entiers { 5, -2, 74, 455, -12 };
    std::vector<int> pairs;
    std::vector<int> impairs;
    for(int valeur : entiers)
    {
        if(valeur%2==0)
            pairs.push_back(valeur);
        else
            impairs.push_back(valeur);
    }
    std::cout << "Tableau pairs : ";
    for(int valeur : pairs)
    {
        std::cout << valeur << " | ";
    }
    std::cout << std::endl << "Tableau impairs : ";
    for(int valeur : impairs)
    {
        std::cout << valeur << " | ";
    }
}