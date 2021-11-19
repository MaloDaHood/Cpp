/**
 * @file croupier.hpp
 * @author MaloDaHood (malomr2002@gmail.com)
 * @brief The croupier class.
 * @date 2021-11-17
 */

#include <vector>

class Croupier
{
    public:
        std::vector<int> getCards();
        void newCard();
    private:
        std::vector<int> m_cards;
};