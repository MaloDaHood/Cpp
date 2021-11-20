#include <vector>

class Pile
{
    public:
        bool est_vide() const noexcept;
        int taille() const noexcept;
        void ajouter(int const n);
        int premier() const;
        void supprimer();
    private:
        std::vector<int> m_pile;
};