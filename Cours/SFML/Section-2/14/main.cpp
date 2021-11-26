#include "main.hpp"

int main()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }
        CheckButton();
        window.clear(sf::Color::Black);
        window.display();
    }
    return 0;
}

void CheckButton()
{
    if(input.GetButton().left)
    {
        
    }
    if(input.GetButton().right)
    {
        
    }
    if(input.GetButton().up)
    {
        
    }
    if(input.GetButton().down)
    {
        
    }
    if(input.GetButton().attack)
    {
        
    }
    if(input.GetButton().escape)
    {
        window.close();
    }
}