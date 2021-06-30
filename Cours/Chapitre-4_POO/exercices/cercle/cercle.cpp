#include "cercle.hpp"

double Cercle::aire() const noexcept
{
    return 3.1415*(rayon*rayon);
}

double Cercle::perimetre() const noexcept
{
    return 2*3.1415*rayon;
}