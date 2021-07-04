#ifndef FRACTION_HPP
#define FRACTION_HPP

struct Fraction
{
    double valeur_reelle() const noexcept;
    void simplification() noexcept;

    int numerateur, denominateur;
};

Fraction pow(Fraction const &fraction, int puissance);

#endif //FRACTION_HPP