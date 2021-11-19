/**
 * @file player.hpp
 * @author MaloDaHood (malomr2002@gmail.com)
 * @brief The player class.
 * @date 2021-11-17
 */

#include <vector>
#include <numeric>
#include <iostream>

class Player
{
    public:
        std::vector<int> getCards();
        void newCard();
        int getCardsTotal();
        int getBet();
        void setBet();
    private:
        std::vector<int> m_cards;
        int m_bet;
};