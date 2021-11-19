/**
 * @file main.cpp
 * @author MaloDaHood (malomr2002@gmail.com)
 * @brief The main file.
 * @date 2021-11-17
 */

#include <iostream>
#include <vector>
#include "../include/player.hpp"
#include <ctime>
#include <cstdlib>


int main()
{
    srand(unsigned(time(0)));
    Player player;
    for(int i {0}; i<13; i++)
    {
        player.newCard();
        std::vector<int> cards {player.getCards()};
        for(int card : cards)
            std::cout << card << std::endl;
        std::cout << '\n' << std::endl;
    }
    //std::cout << player.getCardsTotal() << std::endl;
    return EXIT_SUCCESS;
}