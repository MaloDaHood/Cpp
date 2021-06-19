#include <iostream>
#include <string>

struct Fraction
{
    int numerateur;
    int denominateur;
};

Fraction operator+(Fraction const & a, Fraction const & b)
{
    int numerateur { a.numerateur * b.denominateur + b.numerateur * a.denominateur };
    int denominateur { a.denominateur * b.denominateur };
    return { numerateur, denominateur };
}

Fraction operator-(Fraction const & a, Fraction const & b)
{
    int numerateur { a.numerateur * b.denominateur - b.numerateur * a.denominateur };
    int denominateur { a.denominateur * b.denominateur };
    return { numerateur, denominateur };
}

int main()
{
    Fraction const un_demi { 1, 2 };
    Fraction const trois_quarts { 3, 4 };
    Fraction const deux_huitiemes { 2, 8 };
    Fraction const resultat { un_demi + trois_quarts - deux_huitiemes };
    std::cout << "1/2 + 3/4 - 2/8 font " << resultat.numerateur << "/" << resultat.denominateur << std::endl;

    return 0;
}