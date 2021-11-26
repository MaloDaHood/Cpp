#include "main.hpp"

int main()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    // Chargement visuel hero
    if(!heroTexture.loadFromFile("hero_sheet.png"))
    {
        std::cout << "Erreur chargement texture héros." << std::endl;
    }
    // On applique la texture à notre sprite
    heroSprite.setTexture(heroTexture);
    // On découpe pour afficher une case de 32x32 pixels
    heroSprite.setTextureRect(sf::IntRect(32, 4*32, 32, 32));

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }
        CheckButton();
        window.clear(sf::Color::Black);
        window.draw(heroSprite);
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