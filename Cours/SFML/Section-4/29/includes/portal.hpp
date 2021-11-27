#ifndef PORTAL_HPP
#define PORTAL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.hpp"

void UpdateMap();

sf::Sprite heroSprite;
// Transition map
Map mapInstance;
int actualMap {1};
sf::FloatRect heroHitBox;
sf::RectangleShape goToMap1(sf::Vector2f(32, 32));
sf::FloatRect goToMap1HitBox;
sf::RectangleShape goToMap2(sf::Vector2f(32, 32));
sf::FloatRect goToMap2HitBox;
sf::Vector2i goToMap1Coord {32 * 17, 32 * 17};
sf::Vector2i goToMap2Coord {32 * 17, 0};

void SimpleCollisions()
{
    goToMap1HitBox = goToMap1.getGlobalBounds();
    goToMap2HitBox = goToMap2.getGlobalBounds();
    heroHitBox = heroSprite.getGlobalBounds();
    if(heroHitBox.intersects(goToMap2HitBox) && actualMap == 1)
    {
        actualMap = 2;
        UpdateMap();
        heroSprite.setPosition(heroSprite.getPosition().x, heroSprite.getPosition().y + (15 * 32));
    }
    if(heroHitBox.intersects(goToMap1HitBox) && actualMap == 2)
    {
        actualMap = 1;
        UpdateMap();
        heroSprite.setPosition(heroSprite.getPosition().x, heroSprite.getPosition().y - (15 * 32));
    }
}


#endif