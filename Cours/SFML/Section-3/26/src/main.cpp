#include "../includes/main.hpp"

int main()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    LoadTexture();
    LoadMapFromFile("map/map1.txt");
    LoadMapFromFile("map/map1_collision.txt", true);
    Map map;
    if(!map.load("res/tileset.png", sf::Vector2u(SPRITE_SIZE, SPRITE_SIZE), levelLoaded, COL_COUNT, ROW_COUNT))
        return EXIT_FAILURE;
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
        ShowCollisions();
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

std::vector<std::string> explode(std::string const &str, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(str);
    for(std::string token; std::getline(iss, token, delim);)
    {
        result.push_back(std::move(token));
    }
    return result;
}

void LoadMapFromFile(std::string file, bool isCollisionMap)
{
    std::ifstream ifs(file);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    std::string collision {"\n"};
    if(isCollisionMap) collision = "(collisions)\n";
    std::cout << "Map chargée : " << collision << content << std::endl;
    std::vector<std::string> exploded {explode(content, ' ')};
    for(int i {0}; i < COL_COUNT*ROW_COUNT; i++)
    {
        if(!isCollisionMap)
            levelLoaded[i] = std::stoi(exploded[i]);
        else
            levelLoadedCollisions[i] = std::stoi(exploded[i]);
    }
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
