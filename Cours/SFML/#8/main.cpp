#include "main.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP");
    window.setVerticalSyncEnabled(true);
    LoadFont();
    SetText(txt, "TEST");
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            InputHandler(event, window);
        }
        window.clear(sf::Color::Blue);
        window.draw(txt);
        window.display();
    }
    return 0;
}

void InputHandler(sf::Event const event, sf::RenderWindow &window)
{
    if(event.type==sf::Event::Closed)
    {
        window.close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        SetText(txt, "UP !");
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        SetText(txt, "DOWN !");
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        SetText(txt, "LEFT CLICK !");
    }
}

void LoadFont()
{
    if(!font.loadFromFile("poppins.ttf"))
    {
        std::cout << "Erreur lors du chargement de la police d'écriture." << std::endl;
    }
}

void SetText(sf::Text &txt, sf::String const &str)
{
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(26);
    txt.setFillColor(sf::Color::Red);
    txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
}