#include "main.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP");
    window.setVerticalSyncEnabled(true);
    LoadFont();
    SetText(/*txt, */"TEST");
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

    // Gestion des inputs (clavier / souris)

    // Détection boutton appuyé
    if(event.type==sf::Event::KeyPressed)
    {
        // Tester quelle touche a été utilisée
        if(event.key.code==sf::Keyboard::Escape)
        {
            window.close();
        }

        // Flèches clavier
        if(event.key.code==sf::Keyboard::Up)
        {
            SetText(/*txt, */"UP !");
        }
        if(event.key.code==sf::Keyboard::Down)
        {
            SetText(/*txt, */"DOWN !");
        }
    }

    // Détection boutton souris
    if(event.type==sf::Event::MouseButtonPressed)
    {
        // Tester quelle boutton a été utilisé
        if(event.mouseButton.button==sf::Mouse::Left)
        {
            SetText(/*txt, */"Clique Gauche !");
        }
        if(event.mouseButton.button==sf::Mouse::Right)
        {
            SetText(/*txt, */"Clique Droit !");
        }
    }
}

void LoadFont()
{
    if(!font.loadFromFile("poppins.ttf"))
    {
        std::cout << "Erreur lors du chargement de la police d'écriture." << std::endl;
    }
}

void SetText(/*sf::Text &txt, */sf::String const &str)
{
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(26);
    txt.setFillColor(sf::Color::Red);
    txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
}