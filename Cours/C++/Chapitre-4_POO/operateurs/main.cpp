#include <cassert>

class Fraction
{
    public:
        Fraction(int numerateur, int denominateur) noexcept;
        friend bool operator==(Fraction const &lhs, Fraction const &rhs) noexcept;
        friend bool operator<(Fraction const &lhs, Fraction const &rhs) noexcept;
        Fraction &operator+=(Fraction const &fraction) noexcept;

    private:
        int m_numerateur {0};
        int m_denominateur {1};
};

Fraction::Fraction(int numerateur, int denominateur) noexcept
    : m_denominateur(denominateur), m_numerateur(numerateur)
{
    assert(denominateur!=0&&"Le denominateur ne peut pas valoir 0.");
}

bool operator==(Fraction const &lhs, Fraction const &rhs) noexcept
{
    return lhs.m_numerateur==rhs.m_numerateur&&lhs.m_denominateur==lhs.m_denominateur;
}

bool operator!=(Fraction const &lhs, Fraction const &rhs)
{
    return !(lhs==rhs);
}

bool operator<(Fraction const &lhs, Fraction const &rhs) noexcept
{
    if(lhs.m_numerateur==rhs.m_numerateur)
    {
        return lhs.m_denominateur>rhs.m_denominateur;
    }
    else if(lhs.m_denominateur==rhs.m_denominateur)
    {
        return lhs.m_numerateur<rhs.m_numerateur;
    }
    else
    {
        Fraction const gauche {lhs.m_numerateur*rhs.m_denominateur, lhs.m_denominateur*rhs.m_denominateur};
        Fraction const droite {rhs.m_numerateur*lhs.m_denominateur, rhs.m_denominateur*lhs.m_denominateur};
        return gauche.m_numerateur<droite.m_numerateur;
    }
}

bool operator>(Fraction const &lhs, Fraction const &rhs)
{
    return !(lhs<rhs)&&lhs!=rhs;
}

bool operator<=(Fraction const &lhs, Fraction const &rhs)
{
    return lhs<rhs||lhs==rhs;
}

bool operator>=(Fraction const &lhs, Fraction const &rhs)
{
    return lhs>rhs||lhs==rhs;
}

Fraction& Fraction::operator+=(Fraction const &fraction) noexcept
{
    m_numerateur=m_numerateur*fraction.m_denominateur+fraction.m_numerateur*m_denominateur;
    m_denominateur*=fraction.m_denominateur;
    return *this;
}

Fraction operator+(Fraction lhs, Fraction const &rhs) noexcept
{
    lhs+=rhs;
    return lhs;
}