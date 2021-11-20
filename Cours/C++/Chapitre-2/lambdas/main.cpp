#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <array>

int main()
{
    std::vector<std::string> const chaines {"Un mot", "Autre chose", "Du blabla", "Du texe", "Des lettres"};
    std::for_each(std::begin(chaines), std::end(chaines), [](std::string const & message) -> void
    {
        std::cout << "Message recu : " << message << std::endl;
    });

    std::array<double, 4u> tableau { 1, 3.1415, 2.1878, 1.5 };
    std::sort(std::begin(tableau), std::end(tableau), [](double a, double b) -> bool 
    {
        return a > b;
    });
    for(double nombre : tableau)
    {
        std::cout << nombre << std::endl;
    }

    std::vector<int> const nombres { 2, 4, 6, 8, 9, 10, 11, 13, 16 };
    auto iterateur {std::begin(nombres)};
    do
    {
        iterateur=std::find_if(iterateur, std::end(nombres), [](int nombre) -> bool 
        {
            return nombre%2!=0;
        });
        if(iterateur!=std::end(nombres))
        {
            std::cout << "Nombre impair : " << *iterateur << std::endl;
            iterateur++;
        }
    } while (iterateur!=std::end(nombres));
    

    return 0;
}