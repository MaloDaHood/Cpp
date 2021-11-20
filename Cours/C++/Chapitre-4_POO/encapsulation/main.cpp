#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>

class Fraction 
{
    public:
        // Pas d'exception car on ne fait qu'initialiser deux entiers.
        Fraction(int numerateur, int denominateur) noexcept;
        double valeur_reelle() const noexcept;
        void simplification() noexcept;

    private:
        int m_numerateur {0};
        int m_denominateur {1};
};

// Le qualificateur noexcept se répète aussi ici.
Fraction::Fraction(int numerateur, int denominateur) noexcept
    : m_numerateur(numerateur), m_denominateur(denominateur)
{
    assert(m_denominateur != 0 && "Le dénominateur ne peut pas valoir 0.");
}

double Fraction::valeur_reelle() const noexcept
{
    return static_cast<double>(m_numerateur) / m_denominateur;
}

void Fraction::simplification() noexcept
{
    int const pgcd { std::gcd(m_numerateur, m_denominateur) };
    m_numerateur /= pgcd;
    m_denominateur /= pgcd;
}

int main()
{
    Fraction const f1 { 5, 2 };
    std::cout << "5/2 = " << f1.valeur_reelle() << "\n";
    return 0;  
}