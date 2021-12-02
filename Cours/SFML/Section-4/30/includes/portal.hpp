#ifndef PORTAL_HPP
#define PORTAL_HPP

#include "player.hpp"
#include "map.hpp"
#include "input.hpp"

std::vector<std::string> explode(std::string const &content, char const &delim)
{
    std::vector<std::string> result;
    std::istringstream iss(content);
    for(std::string token; std::getline(iss, token, delim);)
    {
        result.push_back(std::move(token));
    }
    return result;
}

void UpdateMap(Map &mapInstance)
{
    std::ifstream mapLvl("map/map" + std::to_string(actualMap) + ".lvl");
    std::string contentLvl;
    std::getline(mapLvl, contentLvl);
    std::vector<std::string> explodedLvl {explode(contentLvl, ' ')};
    mapLvl.close();
    std::ifstream mapCol("map/map" + std::to_string(actualMap) + ".col");
    std::string contentCol;
    std::getline(mapCol, contentCol);
    std::vector<std::string> explodedCol {explode(contentCol, ' ')};
    mapCol.close();
    std::cout << "Map chargée :\n" << contentLvl << std::endl;
    for(int i {0}; i < COL_COUNT*ROW_COUNT; i++)
    {
        levelLoaded[i] = std::stoi(explodedLvl[i]);
        levelLoadedCollisions[i] = std::stoi(explodedCol[i]);
    }
    if(!mapInstance.load("res/tileset.png", sf::Vector2u(SPRITE_SIZE, SPRITE_SIZE), levelLoaded, COL_COUNT, ROW_COUNT))
        std::cout << "Erreur lors du chargement de la map" << std::endl;
}

class Portal
{
    public:
        Portal(sf::Vector2f const &pos, int const &destination, sf::Vector2f const &posSortie)
        {
            float offsetX, offsetY {0};
            if(pos.x > 0) offsetX = 0.5;
            if(pos.y > 0) offsetY = 0.5;
            this->m_portal.setPosition((pos.x + offsetX) * SPRITE_SIZE, (pos.y + offsetY) * SPRITE_SIZE);
            this->m_destination = destination;
            this->m_posSortie = sf::Vector2f((posSortie.x + offsetX) * SPRITE_SIZE, (posSortie.y + offsetY) * SPRITE_SIZE);
            this->m_portal.setFillColor(sf::Color(0, 0, 250, 100));
            this->m_portal.setSize(sf::Vector2f(SPRITE_SIZE / 2, SPRITE_SIZE / 2));
            this->m_portal.setOrigin(SPRITE_SIZE / 4, SPRITE_SIZE / 4);
        }

        sf::RectangleShape getPortal()
        {
            return this->m_portal;
        }

        void checkCollisions(Player &player, Map &mapInstance)
        {
            if(player.getHitBox().intersects(this->m_portal.getGlobalBounds()) && this->m_destination != actualMap)
            {
                actualMap = this->m_destination;
                UpdateMap(mapInstance);
                player.setPosition(this->m_posSortie.x, this->m_posSortie.y);
            }
        }

    private:
        sf::RectangleShape m_portal;
        int m_destination {1};
        sf::Vector2f m_posSortie;
};

#endif