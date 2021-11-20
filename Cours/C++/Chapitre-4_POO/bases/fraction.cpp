#include <cmath>
#include <numeric>
#include "fraction.hpp"

double Fraction::valeur_reelle() const noexcept
{
    return static_cast<double>(numerateur)/denominateur;
}

void Fraction::simplification() noexcept
{
    int const pgcd {std::gcd(numerateur, denominateur)};
    numerateur/=pgcd;
    denominateur/=pgcd;
}

Fraction pow(Fraction const & fraction, int puissance)
{
    Fraction copie {fraction};
    copie.numerateur=std::pow(fraction.numerateur, puissance);
    copie.denominateur=std::pow(fraction.denominateur, puissance);
    return copie;
}