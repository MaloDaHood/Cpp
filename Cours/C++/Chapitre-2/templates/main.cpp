#include <iostream>
#include <vector>

template <typename T>
void Afficher(std::vector<T> const &v) //type paramètre précis
{
    for(T const &e : v)
    {
        std::cout << e << std::endl;
    }
}

template <typename collection>
void AfficherCollection(collection const &iterable)
{
    for(auto const &e : iterable)
    {
        std::cout << e << std::endl;
    }
}


int main()
{
    std::vector<double> const tableau_entiers {1.2, 3.98465, 5.64, 7.84566, 9.9};
    Afficher(tableau_entiers);
    AfficherCollection(tableau_entiers);
    std::string str {"abcdef ghij klmn opqr stuv wxyz"};
    AfficherCollection(str);
    return 0;
}