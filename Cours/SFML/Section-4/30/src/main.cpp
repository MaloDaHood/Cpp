#include "../includes/main.hpp"


int main()
{
    sf::RenderWindow window;
    Map mapInstance;
    Input input;
    Player player("res/hero_sheet.png");
    Portal portal1(sf::Vector2f(17, 0), 2, sf::Vector2f(17, 17));
    Portal portal2(sf::Vector2f(17, 18), 1, sf::Vector2f(17, 0));
    std::vector<Slime> slimes;
    Arrow arrow("res/arrow.png");
    sf::RectangleShape rects[COL_COUNT * ROW_COUNT];
    bool debug {false};

    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    UpdateMap(mapInstance);

    slimes.reserve(SLIME_COUNT);
    for(int i {0}; i < SLIME_COUNT; i++)
    {
        slimes.emplace_back("res/slime.png");
        slimes[i].setPosition(WIN_WIDTH / (i + 1), WIN_HEIGHT / 2);
    }
    
    // goToMap1.setFillColor(sf::Color(0, 0, 250, 100));
    // goToMap1.setPosition(goToMap1Coord.x, goToMap1Coord.y);
    // goToMap2.setFillColor(sf::Color(0, 0, 250, 100));
    // goToMap2.setPosition(goToMap2Coord.x, goToMap2Coord.y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }
        CheckButton(input, window, debug);
        player.handleInputs(input, slimes, mapInstance, debug);
        window.clear(sf::Color::Black);
        window.draw(mapInstance);
        Draw({player.animate()}, window);
        for(size_t i {0}; i < slimes.size(); i++)
        {
            window.draw(slimes[i].animate());
        }
        if(debug)
        {
            ShowCollisions(window, rects);
            window.draw(portal1.getPortal());
            window.draw(portal2.getPortal());  
        }
        //SimpleCollisions(player, mapInstance);
        portal1.checkCollisions(player, mapInstance, input);
        portal2.checkCollisions(player, mapInstance, input);
        window.display();
    }
    return EXIT_SUCCESS;
}

void CheckButton(Input const &input, sf::RenderWindow &window, bool &debug)
{
    if (input.GetButton().escape)
    {
        window.close();
    }
    debug = input.GetButton().space;
}

void ShowCollisions(sf::RenderWindow &window, sf::RectangleShape rects[COL_COUNT * ROW_COUNT])
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

void Draw(std::vector<sf::Sprite> const &drawables, sf::RenderWindow &window)
{
    for(sf::Sprite const &sprite : drawables)
    {
        window.draw(sprite);
    }
}