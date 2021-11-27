#include "../includes/main.hpp"

int main()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    LoadTexture();

    // Chargement map depuis fichier
    std::ifstream ifs("map/map1.txt");
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    std::cout << "Map chargée :\n" << content << std::endl;
    // Instance de map et chargement de la map
    Map map;
    // if(!map.load("res/tileset.png", sf::Vector2u(SPRITE_SIZE, SPRITE_SIZE), levelLoaded, COL_COUNT, ROW_COUNT))
    //     return EXIT_FAILURE;
        
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
        window.draw(map);
        window.draw(heroSprite);
        window.display();
    }
    return EXIT_SUCCESS;
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
    if (!heroTexture.loadFromFile("res/hero_sheet.png"))
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