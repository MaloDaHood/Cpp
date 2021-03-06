#include "main.hpp"

int main()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP");
    window.setVerticalSyncEnabled(true);
    LoadFont();
    SetText(txt, "TEST");
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }
        window.clear(sf::Color::Blue);
        window.draw(txt);
        window.display();
    }
    return 0;
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
    txt.setCharacterSize(50);
    txt.setFillColor(sf::Color::Red);
    txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
}