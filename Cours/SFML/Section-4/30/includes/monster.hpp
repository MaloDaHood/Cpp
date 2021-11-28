#ifndef MONSTER_HPP
#define MONSTER_HPP

class Monster
{
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

        bool isAlive()
        {
            return this->m_isAlive;
        }

        void die()
        {
            if(!this->m_texture.loadFromFile("res/dead.png"))
            {
                std::cout << "Erreur chargement texture : [res/dead.png]" << std::endl;
            }
            this->m_sprite.setTexture(this->m_texture);
            this->m_sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE)); 
            this->m_sprite.setColor(sf::Color(0, 0, 0, 250));
        }

    protected:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
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

        sf::Sprite animate()
        {
            if(this->m_isAlive)
            {

                if(this->m_animClock.getElapsedTime().asSeconds() > 0.1f)
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
            else
            {
                float alpha {250.f / ((this->m_animClock.getElapsedTime().asSeconds() + 1) * 2.f)};
                if(alpha >= 0)
                    this->m_sprite.setColor(sf::Color(0, 0, 0, alpha));
            }
            return this->m_sprite;
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
                die();
            }
        }
    private:
        int m_anim {0};
        int m_animCount {0};
};

#endif