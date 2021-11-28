#ifndef ARROW_HPP
#define ARROW_HPP

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

        sf::Sprite getSprite()
        {
            return this->m_sprite;
        }

        void setPosition(float const &x, float const &y)
        {
            this->m_sprite.setPosition(sf::Vector2f(x, y));
        }

        sf::Vector2f getPosition()
        {
            return this->m_sprite.getPosition();
        }

        sf::FloatRect getHitBox()
        {
            return this->m_sprite.getGlobalBounds();
        }

    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
};

#endif