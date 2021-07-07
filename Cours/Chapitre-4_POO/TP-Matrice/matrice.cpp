#include "matrice.hpp";
#include <cassert>
#include <iostream>

Matrice::Matrice(int lignes, int colonnes) noexcept
    : m_lignes(lignes), m_colonnes(colonnes)
{
    assert(m_lignes!=0&&"Le nombre de lignes ne peut etre égal à 0.");
    assert(m_colonnes!=0&&"Le nombre de colonnes ne peut etre égal à 0.");
    for(int i {0}; i<m_lignes*m_colonnes; i++)
    {
        m_matrice.push_back(0);
    }
}

int Matrice::nb_lignes()
{
    return m_lignes;
}

int Matrice::nb_colonnes()
{
    return m_colonnes;
}

void Matrice::operator()(int const &lhs, int const &rhs) noexcept
{
    m_pos=rhs*m_lignes;
}

void Matrice::operator=(int const &rhs)
{
    
}

/*void Matrice::show()
{
    for(int const &i : m_matrice)
    {
        std::cout << i << " | ";
    }
    std::cout << std::endl;
}*/