#include "main.hpp"

int main()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    LoadTexture();
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }
        CheckButton();
        heroSprite.setTextureRect(sf::IntRect(heroAnim.x*SPRITE_SIZE, heroAnim.y*SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
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
        heroAnim.y = Left;
        heroSprite.move(-WALK_SPEED, 0);
    }
    if(input.GetButton().right)
    {
        heroAnim.y = Right;
        heroSprite.move(WALK_SPEED, 0);
    }
    if(input.GetButton().up)
    {
        heroAnim.y = Up;
        heroSprite.move(0, -WALK_SPEED);
    }
    if(input.GetButton().down)
    {
        heroAnim.y = Down;
        heroSprite.move(0, WALK_SPEED);
    }
    if(input.GetButton().attack)
    {
        
    }
    if(input.GetButton().escape)
    {
        window.close();
    }
}

void LoadTexture()
{
    // Chargement visuel hero
    if(!heroTexture.loadFromFile("hero_sheet.png"))
    {
        std::cout << "Erreur chargement texture héros." << std::endl;
    }
    // On applique la texture à notre sprite
    heroSprite.setTexture(heroTexture);
}