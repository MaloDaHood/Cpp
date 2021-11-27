#include "../includes/main.hpp"

int main()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    LoadHeroTexture("res/hero_sheet.png");
    LoadMapFromFile("map/map1.txt");
    Map map;
    if(!map.load("res/tileset.png", sf::Vector2u(SPRITE_SIZE, SPRITE_SIZE), levelLoaded, COL_COUNT, ROW_COUNT))
        return EXIT_FAILURE;
    heroSprite.setOrigin((SPRITE_SIZE / 2), (SPRITE_SIZE / 2));
    heroSprite.setPosition(SPRITE_SIZE, SPRITE_SIZE);
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
        if(debug) ShowCollisions();
        window.display();
    }
    return EXIT_SUCCESS;
}

void CheckButton()
{
    int hPosX {int(heroSprite.getPosition().x) / SPRITE_SIZE};
    int hPosY {int(heroSprite.getPosition().y) / SPRITE_SIZE};
    if(debug)
    {
        std::cout << levelLoaded[(hPosX + hPosY * 25)] << std::endl;
        std::cout << hPosX << " , " << hPosY << std::endl;
    }

    if(!needResetAnim)
    {
        if (input.GetButton().left)
        {
            heroAnim.y = Left;

            // Vérification si à notre gauche on une case solide ou pas
            hPosX = int(heroSprite.getPosition().x) / SPRITE_SIZE;
            // Si la position futures est sur une case non solide
            if(levelLoadedCollisions[(hPosX + hPosY * COL_COUNT)] == 0 && heroSprite.getPosition().x > 8)
            {
                heroSprite.move(-WALK_SPEED, 0);
            }
            heroIdle = false;
        }
        else if (input.GetButton().right)
        {
            heroAnim.y = Right;
            hPosX = (int(heroSprite.getPosition().x) + (WALK_SPEED * 2)) / SPRITE_SIZE;
            if(levelLoadedCollisions[(hPosX + hPosY * COL_COUNT)] == 0 && heroSprite.getPosition().x < WIN_WIDTH - 8)
            {    
                heroSprite.move(WALK_SPEED, 0);
            }
            heroIdle = false;
        }
        else if (input.GetButton().up)
        {
            heroAnim.y = Up;
            hPosY = int(heroSprite.getPosition().y) / SPRITE_SIZE;
            if(levelLoadedCollisions[(hPosX + hPosY * COL_COUNT)] == 0 && heroSprite.getPosition().y > 8)
            {
                heroSprite.move(0, -WALK_SPEED);
            }
            heroIdle = false;
        }
        else if (input.GetButton().down)
        {
            heroAnim.y = Down;
            hPosY = (int(heroSprite.getPosition().y) + (WALK_SPEED * 6)) / SPRITE_SIZE;
            if(levelLoadedCollisions[(hPosX + hPosY * COL_COUNT)] == 0 && heroSprite.getPosition().y < WIN_HEIGHT - 8)
            {
                heroSprite.move(0, WALK_SPEED);
            }
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
    debug = input.GetButton().space;
}

void LoadHeroTexture(std::string file)
{
    if (!heroTexture.loadFromFile(file))
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

void LoadMapFromFile(std::string file)
{
    std::ifstream map(file);
    std::string content((std::istreambuf_iterator<char>(map)), (std::istreambuf_iterator<char>()));
    std::vector<char> exploded {explode(content, ' ')};
    std::cout << "Map chargée :\n" << content << std::endl;
    for(int i {0}; i < COL_COUNT*ROW_COUNT; i++)
    {
        levelLoaded[i] = exploded[i] - '0';
        if(levelLoaded[i] > 0)
            levelLoadedCollisions[i] = 1;
        else
            levelLoadedCollisions[i] = 0;
    }
}

std::vector<char> explode(std::string const &content, char const &delim)
{
    std::vector<char> result;
    for(char const &c : content)
    {
        if(c == delim)
            continue;
        result.push_back(c);
    }
    return result;
}

void ShowCollisions()
{
    for(unsigned int j {0}; j < 18; j++)
    {
        for(unsigned int i {0}; i < 25; i++)
        {
            if(levelLoadedCollisions[(i + j * 25)] == 1)
            {
                sf::Vector2f pos {sf::Vector2f(i * SPRITE_SIZE, j * SPRITE_SIZE)};
                rects[(i + j * 25)].setPosition(pos);
                rects[(i + j * 25)].setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
                rects[(i + j * 25)].setFillColor(sf::Color(250, 0, 0, 100));
                window.draw(rects[(i + j * 25)]);
            }
        }
    }
}
