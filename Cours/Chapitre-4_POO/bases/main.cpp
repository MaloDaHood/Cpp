#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction const f1 {5,2};
    std::cout << "5/2 = " << f1.valeur_reelle() << "\n";
    return 0;
}