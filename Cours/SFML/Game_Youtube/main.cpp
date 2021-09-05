#include "game.hpp"

int main()
{
    options.antialiasingLevel=8;
    Game game;
    while(game.running())
    {
        game.update();
        game.render();
    }
    return 0;
}