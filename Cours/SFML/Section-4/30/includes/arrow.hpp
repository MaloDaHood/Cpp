#ifndef ARROW_HPP
#define ARROW_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Arrow
{
    public:
        Arrow(std::string const &textureFile)
        {
            if(!this->m_texture.loadFromFile(textureFile))
            {
                std::cout << "Erreur chargement texture : " << textureFile << std::endl;
            }
            this->m_sprite.setTexture(this->m_texture);
            this->m_sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
        }

    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
};

#endif