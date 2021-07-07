#include <iostream>
#include <cassert>
#include <algorithm>

class Fraction
{
    public:
        Fraction(std::string const &fraction) noexcept;
        double valeur_reelle() const noexcept;
    private:
        int m_numerateur;
        int m_denominateur;
};

Fraction::Fraction(std::string const &fraction) noexcept
{
    assert(!fraction.empty()&&"Aucun caractère fourni.");
    auto start {std::begin(fraction)};
    auto end {std::end(fraction)};
    assert(std::count(start, end, '/')==1&&"Il ne peut y avoir q'un seul separateur.");
    std::string const numerateur {start, start+1};
    assert(!numerateur.empty()&&"Pas de numérateur");
    m_numerateur=std::stoi(numerateur);
    auto slash {std::find(start, end, '/')};
    slash++;
    std::string const denominateur {slash, end};
    assert(!denominateur.empty()&&"Pas de denominateur");
    m_denominateur=std::stoi(denominateur);
    assert(m_denominateur!=0&&"Le denominateur ne peut pas etre egal a 0");

}

double Fraction::valeur_reelle() const noexcept
{
    return static_cast<double>(m_numerateur) / m_denominateur;
}

int main()
{
    // Doit compiler.
    Fraction f1 { "4/2" };
    assert(f1.valeur_reelle() == 2 && "La valeur réelle de f1 doit être 2.");
    
    // Doit générer une erreur.
    //Fraction f2 { "4\2" };
    
    // Doit générer une erreur.
    //Fraction f3 { "4///2" };

    // Doit générer une erreur.
    //Fraction f4 { "4/" };

    // Doit générer une erreur.
    //Fraction f5 { "/2" };

    // Doit générer une erreur.
    Fraction f6 { "4/0" }; 

    return 0;
}