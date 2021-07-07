#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <vector>

class Matrice
{
    public:
        Matrice(int lignes, int colonnes) noexcept;
        int nb_lignes();
        int nb_colonnes();
        //void show();
        void operator()(int const &lhs, int const &rhs) noexcept;
        void operator=(int const &rhs);
    private:
        int m_lignes;
        int m_colonnes;
        std::vector<int> m_matrice;
        int m_pos;
};

#endif //MATRICE_HPP