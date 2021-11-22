#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>

class Input
{
    struct Button {bool left, right, up, down, attack, escape;};

    public:
        Input();
        Button GetButton(void) const;
        void InputHandler(sf::Event const &event, sf::RenderWindow &window);
    private:
        Button m_button;
};

#endif