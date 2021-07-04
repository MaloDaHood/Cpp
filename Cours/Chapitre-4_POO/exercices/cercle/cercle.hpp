#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "point.hpp"

struct Cercle
{
    double aire() const noexcept;
    double perimetre() const noexcept;

    int rayon;
    Point const centre;
};

#endif //CERCLE_HPP