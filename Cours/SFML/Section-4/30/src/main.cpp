#include "../includes/main.hpp"

std::vector<Slime> slimes;

int main()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    LoadHeroTexture("res/hero_sheet.png");
    LoadArrowTexture("res/arrow.png");
    UpdateMap();

    slimes.reserve(SLIME_COUNT);
    for(int i {0}; i < SLIME_COUNT; i++)
    {
        slimes.emplace_back("res/slime.png");
        slimes[i].setPosition(WIN_WIDTH / (i + 1), WIN_HEIGHT / 2);
    }
    

    goToMap1.setFillColor(sf::Color(0, 0, 250, 100));
    goToMap1.setPosition(goToMap1Coord.x, goToMap1Coord.y);
    goToMap2.setFillColor(sf::Color(0, 0, 250, 100));
    goToMap2.setPosition(goToMap2Coord.x, goToMap2Coord.y);

    //slime.setPosition(WIN_WIDTH / 5, WIN_HEIGHT / 2);

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
        window.draw(mapInstance);
        for(size_t i {0}; i < slimes.size(); i++)
        {
            window.draw(slimes[i].animate());
        }
        Draw({heroSprite});
        HandleArrow();
        if(debug)
        {
            ShowCollisions();
            window.draw(goToMap1);
            window.draw(goToMap2);  
        }
        SimpleCollisions();
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
        std::cout << levelLoaded[(hPosX + hPosY * COL_COUNT)] << std::endl;
        std::cout << hPosX << " , " << hPosY << std::endl;
    }

    if(!needResetAnim)
    {
        if (input.GetButton().left)
        {
            heroAnim.y = Left;
            hPosX = int(heroSprite.getPosition().x) / SPRITE_SIZE;
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
            if(levelLoaded[(hPosX + hPosY * COL_COUNT)] == 15 || levelLoaded[(hPosX + hPosY * COL_COUNT)] == 1)
            {
                levelLoaded[(hPosX + hPosY * COL_COUNT)] -= 1;
                if(!mapInstance.load("res/tileset.png", sf::Vector2u(SPRITE_SIZE, SPRITE_SIZE), levelLoaded, COL_COUNT, ROW_COUNT))
                    std::cout << "Erreur lors du chargement de la map" << std::endl;
            }
            for(size_t i {0}; i < slimes.size(); i++)
            {
                if(slimes[i].getHitBox().intersects(heroSprite.getGlobalBounds()) && slimes[i].isAlive())
                {
                    std::cout << "hit" << std::endl;
                    slimes[i].takeDamage(1);
                }  
            }
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
    heroSprite.setOrigin((SPRITE_SIZE / 2), (SPRITE_SIZE / 2));
    heroSprite.setPosition(SPRITE_SIZE, SPRITE_SIZE);
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

void LoadArrowTexture(std::string file)
{
    if (!arrowTexture.loadFromFile(file))
    {
        std::cout << "Erreur chargement texture héros." << std::endl;
    }
    arrowSprite.setTexture(arrowTexture);
}

std::vector<std::string> explode(std::string const &content, char const &delim)
{
    std::vector<std::string> result;
    std::istringstream iss(content);
    for(std::string token; std::getline(iss, token, delim);)
    {
        result.push_back(std::move(token));
    }
    return result;
}

void ShowCollisions()
{
    for(unsigned int j {0}; j < ROW_COUNT; j++)
    {
        for(unsigned int i {0}; i < COL_COUNT; i++)
        {
            if(levelLoadedCollisions[(i + j * COL_COUNT)] == 1)
            {
                sf::Vector2f pos {sf::Vector2f(i * SPRITE_SIZE, j * SPRITE_SIZE)};
                rects[(i + j * COL_COUNT)].setPosition(pos);
                rects[(i + j * COL_COUNT)].setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
                rects[(i + j * COL_COUNT)].setFillColor(sf::Color(250, 0, 0, 100));
                window.draw(rects[(i + j * COL_COUNT)]);
            }
        }
    }
}

void UpdateMap()
{
    std::ifstream mapLvl("map/map" + std::to_string(actualMap) + ".lvl");
    std::string contentLvl;
    std::getline(mapLvl, contentLvl);
    std::vector<std::string> explodedLvl {explode(contentLvl, ' ')};
    mapLvl.close();
    std::ifstream mapCol("map/map" + std::to_string(actualMap) + ".col");
    std::string contentCol;
    std::getline(mapCol, contentCol);
    std::vector<std::string> explodedCol {explode(contentCol, ' ')};
    mapCol.close();
    std::cout << "Map chargée :\n" << contentLvl << std::endl;
    for(int i {0}; i < COL_COUNT*ROW_COUNT; i++)
    {
        levelLoaded[i] = std::stoi(explodedLvl[i]);
        levelLoadedCollisions[i] = std::stoi(explodedCol[i]);
    }
    if(!mapInstance.load("res/tileset.png", sf::Vector2u(SPRITE_SIZE, SPRITE_SIZE), levelLoaded, COL_COUNT, ROW_COUNT))
        std::cout << "Erreur lors du chargement de la map" << std::endl;
}

// Fonction de tir + déplacement + collision + ... de la flèche
void HandleArrow()
{

}

void Draw(std::vector<sf::Sprite> const &drawables)
{
    for(sf::Sprite const &sprite : drawables)
    {
        window.draw(sprite);
    }
}