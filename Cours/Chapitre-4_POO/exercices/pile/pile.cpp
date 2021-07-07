#include "pile.hpp"

bool Pile::est_vide() const noexcept
{
    return m_pile.empty();
}

int Pile::taille() const noexcept
{
    return m_pile.size();
}

void Pile::ajouter(int const n)
{
    m_pile.push_back(n);
}

int Pile::premier() const
{
    return m_pile.front();
}

void Pile::supprimer()
{
    m_pile.pop_back();
}