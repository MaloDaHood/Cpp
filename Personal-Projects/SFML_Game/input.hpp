#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Input
{
    struct Button {bool z, s, up, down, escape;};

    public:
        Input();
        Button GetButton(void) const;
        void InputHandler(sf::Event const &event, sf::RenderWindow &window);
    private:
        Button m_button;
};

#endif