#include "main.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP");
    window.setVerticalSyncEnabled(true);

    // Chargement de la police
    LoadFont();

    // Création d'un texte
    sf::Text txt;
    
    // On règle toutes les propriétés du texte
    SetText(txt, "TEST");

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            InputHandler(event, window);
        }

        // Couleur de la fenêtre
        window.clear(sf::Color::Blue);

        // C'est ici que l'on dessine les éléments du jeu
        window.draw(txt);

        // Dessiner tous les éléments à l'écran
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
}

// Chargement de la police d'écriture
void LoadFont()
{
    // On vérifie que la police d'écriture est bien chargée
    if(!font.loadFromFile("poppins.ttf"))
    {
        // Si erreur
        std::cout << "Erreur lors du chargement de la police d'écriture." << std::endl;
    }
}

// Réglages des propriétés du texte
void SetText(sf::Text &txt, sf::String const &str)
{
    // On lui indique quelle police utiliser
    txt.setFont(font);
    // On indique la chaîne de caractères à afficher
    txt.setString(str);
    // On indique la taille de la police d'écriture
    txt.setCharacterSize(26);
    // On donne la couleur
    txt.setFillColor(sf::Color::Red);
    // Modification du style
    txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
}