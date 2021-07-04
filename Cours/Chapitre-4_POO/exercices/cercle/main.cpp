#include <cassert>
#include <iostream>
#include <cmath>
#include "cercle.hpp"
#include "point.hpp"

bool compare(double lhs, double rhs)
{
    return std::abs(lhs - rhs) < 0.001;
}

bool appartient(Cercle const cercle, Point const point)
{
    int distance {sqrt((cercle.centre.x-point.x)+(cercle.centre.y-point.y))};
    return distance<=cercle.rayon;
}

int main()
{
    Point const centre { 0, 0 };
    Cercle const c1 { 1, centre };

    std::cout << "Voici l'aire du cercle : " << c1.aire() << "\n";
    assert(compare(c1.aire(), 3.1415) && "L'aire du cercle c1 doit valoir pi.");

    std::cout << "Voici le périmètre du cercle : " << c1.perimetre() << "\n"; 
    assert(compare(c1.perimetre(), 3.1415 * 2) && "Le périmètre du cercle doit valoir pi * 2.");

    std::cout << std::boolalpha;
    Point const p1 { 2, -18 };
    std::cout << "Est-ce que le point p1 appartient au cercle c1 ? " << appartient(c1, p1) << "\n";
    assert(!appartient(c1, p1) && "Le point p1 n'appartient pas au cercle c1.");
    return 0;
}