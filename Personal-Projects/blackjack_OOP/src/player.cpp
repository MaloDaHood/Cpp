/**
 * @file player.cpp
 * @author MaloDaHood (malomr2002@gmail.com)
 * @brief The source code for the player class.
 * @date 2021-11-17
 */

#include "../include/player.hpp"

std::vector<int> Player::getCards()
{
    return m_cards;
}

void Player::newCard()
{
    m_cards.push_back((rand()%13)+1);
}

int Player::getCardsTotal()
{
    return std::accumulate(m_cards.begin(), m_cards.end(), 0);
}

int Player::getBet()
{
    return m_bet;
}

void Player::setBet()
{

}