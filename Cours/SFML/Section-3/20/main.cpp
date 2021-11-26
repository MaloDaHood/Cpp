#include "main.hpp"

int main()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    LoadTexture();

    // Cube pour collision
    cube.setFillColor(sf::Color::Red);
    cube.setPosition(350, 250);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }
        CheckButton();
        AnimPlayer();
        window.clear(sf::Color::Black);
        window.draw(heroSprite);
        window.draw(cube);
        window.display();

        SimpleCheckCollisions();
    }
    return 0;
}

void CheckButton()
{
    if(!needResetAnim)
    {
        if (input.GetButton().left)
        {
            heroAnim.y = Left;
            heroSprite.move(-WALK_SPEED, 0);
            heroIdle = false;
        }
        else if (input.GetButton().right)
        {
            heroAnim.y = Right;
            heroSprite.move(WALK_SPEED, 0);
            heroIdle = false;
        }
        else if (input.GetButton().up)
        {
            heroAnim.y = Up;
            heroSprite.move(0, -WALK_SPEED);
            heroIdle = false;
        }
        else if (input.GetButton().down)
        {
            heroAnim.y = Down;
            heroSprite.move(0, WALK_SPEED);
            heroIdle = false;
        }
        else
        {
            heroIdle = true;
        }
        if (input.GetButton().attack)
        {
            needResetAnim = true;
            heroAnim.x = 0; 
            heroAnim.y += 4; 
        }
    }
    if (input.GetButton().escape)
    {
        window.close();
    }
}

void LoadTexture()
{
    if (!heroTexture.loadFromFile("hero_sheet.png"))
    {
        std::cout << "Erreur chargement texture héros." << std::endl;
    }
    heroSprite.setTexture(heroTexture);
}

void AnimPlayer()
{
    heroSprite.setTextureRect(sf::IntRect(heroAnim.x * SPRITE_SIZE, heroAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
    if (heroAnimClock.getElapsedTime().asSeconds() > 0.1f)
    {
        if(heroAnim.x*SPRITE_SIZE >= int(heroTexture.getSize().x) - SPRITE_SIZE)
        {
            heroAnim.x = 0;
            if(needResetAnim)
            {
                needResetAnim = false;
                heroAnim.y -= 4;
            }
        }
        else
        {
            if(!heroIdle || needResetAnim)
                heroAnim.x++;
        }
        heroAnimClock.restart();
    }
}

// Tester la collision entre perso et cube
void SimpleCheckCollisions()
{
    // HitBox du cube
    cubeHitBox = cube.getGlobalBounds();
    // HitBox du personnage
    heroHitBox = heroSprite.getGlobalBounds();
    // Si les 2 box colliders sont en intersection alors il y a collision
    if(heroHitBox.intersects(cubeHitBox))
    {
        std::cout << "collision" << std::endl;
    }
}