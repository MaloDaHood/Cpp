#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Monster
{
    struct Position {float x, y;};

    public:
        Monster(std::string const &textureFile)
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
            this->m_pos.x = x;
            this->m_pos.y = y;
            this->m_sprite.setPosition(sf::Vector2f(x, y));
        }

        Position getPosition()
        {
            return this->m_pos;
        }

        bool isAlive()
        {
            return this->m_isAlive;
        }

    protected:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        Position m_pos;
        bool m_isAlive {true};
        int m_life;
        sf::Clock m_animClock;
};

class Slime : public Monster
{
    public:
        Slime(std::string const &textureFile) : Monster(textureFile)
        {
            this->m_sprite.setScale(0.6f, 0.6f);
            this->m_life = 3;
        }

        void animate()
        {
            if (this->m_animClock.getElapsedTime().asSeconds() > 0.1f)
            {
                if(this->m_animCount <= 3)
                {
                    this->m_sprite.setTextureRect(sf::IntRect(this->m_anim * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
                    if(this->m_animCount < 2)
                        this->m_sprite.move(sf::Vector2f(0, 3));
                }
                else
                {
                    this->m_sprite.setTextureRect(sf::IntRect(3 * SPRITE_SIZE - (this->m_anim * SPRITE_SIZE), 0, SPRITE_SIZE, SPRITE_SIZE));
                    this->m_sprite.move(sf::Vector2f(0, -3));
                }
                this->m_anim++;
                this->m_animCount++;
                if(this->m_anim == 3)
                    this->m_anim = 0;
                if(this->m_animCount == 6)
                    this->m_animCount = 0;
                this->m_animClock.restart();
            }
        }

        void takeDamage(int const &damageValue)
        {
            if(damageValue <= 0)
            {
                std::cout << "Error : Low Value : slime.takeDamage()" << std::endl;
                return;
            }
            this->m_life -= damageValue;
            if(this->m_life <= 0)
            {
                this->m_isAlive = false;
            }
        }
    private:
        int m_anim {0};
        int m_animCount {0};
};

#endif