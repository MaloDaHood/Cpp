#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>

class Input
{
    struct Button {bool left, right, up, down, attack, escape, space;};

    public:
        Input()
        {
            m_button.left = m_button.right = m_button.up = m_button.down = m_button.attack = m_button.escape = m_button.space = false;
        }
        Button GetButton(void) const
        {
            return m_button;
        }
        void InputHandler(sf::Event const &event, sf::RenderWindow &window)
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }

            if(event.type==sf::Event::KeyPressed)
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        m_button.escape=true;
                        break;
                    case sf::Keyboard::Left:
                        m_button.left=true;
                        break;
                    case sf::Keyboard::Right:
                        m_button.right=true;
                        break;
                    case sf::Keyboard::Up:
                        m_button.up=true;
                        break;
                    case sf::Keyboard::Down:
                        m_button.down=true;
                        break;
                    case sf::Keyboard::Space:
                        m_button.space=true;
                        break;
                    default:
                        break;
                }
            }

            if(event.type==sf::Event::KeyReleased)
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        m_button.escape=false;
                        break;
                    case sf::Keyboard::Left:
                        m_button.left=false;
                        break;
                    case sf::Keyboard::Right:
                        m_button.right=false;
                        break;
                    case sf::Keyboard::Up:
                        m_button.up=false;
                        break;
                    case sf::Keyboard::Down:
                        m_button.down=false;
                        break;
                    case sf::Keyboard::Space:
                        m_button.space=false;
                        break;
                    default:
                        break;
                }
            }

            if(event.type==sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button==sf::Mouse::Left)
                {
                    m_button.attack=true;
                }
            }

            if(event.type==sf::Event::MouseButtonReleased)
            {
                if(event.mouseButton.button==sf::Mouse::Left)
                {
                    m_button.attack=false;
                }
            }
        }
    private:
        Button m_button;
};

#endif