#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

int constexpr WIDTH {1280};
int constexpr HEIGHT {720};

class Game
{
    public:
        Game();
        ~Game();

        bool running() const;

        void update();
        void render();
        void pollEvents();

    private:
        void initVariables();
        void initWindow();

        sf::RenderWindow *window;
        sf::VideoMode videoMode;
        sf::Event event;
};

#endif