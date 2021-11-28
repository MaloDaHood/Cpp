#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "input.hpp"
#include "monster.hpp"
#include "map.hpp"

class Player
{
    public:
        Player(std::string const &textureFile)
        {
            if(!this->m_texture.loadFromFile(textureFile))
            {
                std::cout << "Erreur chargement texture : " << textureFile << std::endl;
            }
            this->m_sprite.setTexture(this->m_texture);
            this->m_sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
            this->m_sprite.setOrigin((SPRITE_SIZE / 2), (SPRITE_SIZE / 2));
            this->m_sprite.setPosition(SPRITE_SIZE, SPRITE_SIZE);
        }

        sf::Texture getTexture()
        {
            return this->m_texture;
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

        sf::Sprite animate()
        {
            this->m_sprite.setTextureRect(sf::IntRect(this->m_heroAnim.x * SPRITE_SIZE, this->m_heroAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            if (this->m_animClock.getElapsedTime().asSeconds() > 0.1f)
            {
                if(this->m_heroAnim.x*SPRITE_SIZE >= int(this->m_texture.getSize().x) - SPRITE_SIZE)
                {
                    this->m_heroAnim.x = 0;
                    if(this->m_needResetAnim)
                    {
                        this->m_needResetAnim = false;
                        this->m_heroAnim.y -= 4;
                    }
                }
                else
                {
                    if(!this->m_idle || this->m_needResetAnim)
                        this->m_heroAnim.x++;
                }
                this->m_animClock.restart();
            }
            return this->m_sprite;
        }

        void handleInputs(Input const &input, std::vector<Slime> &slimes, Map &mapInstance, bool debug)
        {
            int hPosX {int(this->m_sprite.getPosition().x) / SPRITE_SIZE};
            int hPosY {int(this->m_sprite.getPosition().y) / SPRITE_SIZE};
            if(debug)
            {
                std::cout << levelLoaded[(hPosX + hPosY * COL_COUNT)] << std::endl;
                std::cout << hPosX << " , " << hPosY << std::endl;
            }

            if(!this->m_needResetAnim)
            {
                if (input.GetButton().left)
                {
                    this->m_heroAnim.y = Left;
                    hPosX = int(this->m_sprite.getPosition().x) / SPRITE_SIZE;
                    if(levelLoadedCollisions[(hPosX + hPosY * COL_COUNT)] == 0 && this->m_sprite.getPosition().x > 8)
                    {
                        this->m_sprite.move(-WALK_SPEED, 0);
                    }
                    this->m_idle = false;
                }
                else if (input.GetButton().right)
                {
                    this->m_heroAnim.y = Right;
                    hPosX = (int(this->m_sprite.getPosition().x) + (WALK_SPEED * 2)) / SPRITE_SIZE;
                    if(levelLoadedCollisions[(hPosX + hPosY * COL_COUNT)] == 0 && this->m_sprite.getPosition().x < WIN_WIDTH - 8)
                    {    
                        this->m_sprite.move(WALK_SPEED, 0);
                    }
                    this->m_idle = false;
                }
                else if (input.GetButton().up)
                {
                    this->m_heroAnim.y = Up;
                    hPosY = int(this->m_sprite.getPosition().y) / SPRITE_SIZE;
                    if(levelLoadedCollisions[(hPosX + hPosY * COL_COUNT)] == 0 && this->m_sprite.getPosition().y > 8)
                    {
                        this->m_sprite.move(0, -WALK_SPEED);
                    }
                    this->m_idle = false;
                }
                else if (input.GetButton().down)
                {
                    this->m_heroAnim.y = Down;
                    hPosY = (int(this->m_sprite.getPosition().y) + (WALK_SPEED * 6)) / SPRITE_SIZE;
                    if(levelLoadedCollisions[(hPosX + hPosY * COL_COUNT)] == 0 && this->m_sprite.getPosition().y < WIN_HEIGHT - 8)
                    {
                        this->m_sprite.move(0, WALK_SPEED);
                    }
                    this->m_idle = false;
                }
                else
                {
                    this->m_idle = true;
                }
                if (input.GetButton().attack)
                {
                    this->m_needResetAnim = true;
                    this->m_heroAnim.x = 0; 
                    this->m_heroAnim.y += 4;
                    if(levelLoaded[(hPosX + hPosY * COL_COUNT)] == 15 || levelLoaded[(hPosX + hPosY * COL_COUNT)] == 1)
                    {
                        levelLoaded[(hPosX + hPosY * COL_COUNT)] -= 1;
                        if(!mapInstance.load("res/tileset.png", sf::Vector2u(SPRITE_SIZE, SPRITE_SIZE), levelLoaded, COL_COUNT, ROW_COUNT))
                            std::cout << "Erreur lors du chargement de la map" << std::endl;
                    }
                    for(size_t i {0}; i < slimes.size(); i++)
                    {
                        if(slimes[i].getHitBox().intersects(this->getHitBox()) && slimes[i].isAlive())
                        {
                            std::cout << "hit" << std::endl;
                            slimes[i].takeDamage(1);
                        }  
                    }
                }
            }
        }

    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        int m_life {5};
        bool m_isAlive {true};
        enum Dir {Down, Right, Up, Left, Down_Atk, Right_Atk, Up_Atk, Left_Atk};
        sf::Vector2i m_heroAnim {0, Down};
        sf::Clock m_animClock;
        bool m_idle {true};
        bool m_needResetAnim {false};
};

#endif