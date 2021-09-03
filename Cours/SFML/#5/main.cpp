#include "main.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP");
    window.setVerticalSyncEnabled(true);
    while(window.isOpen())
    {
        sf::Event event; // Variable pour gérer l'événement

        // On boucle sur les événements de la fenêtre
        while(window.pollEvent(event))
        {
            // Gestion des entrées
            InputHandler(event, window);
        }
    }
    return 0;
}

// Gestion des entrées dans la boucle principale
void InputHandler(sf::Event event, sf::RenderWindow &window)
{
    // Fermer la fenêtre si on clique sur la croix
    if(event.type==sf::Event::Closed)
    {
        window.close();
    }
}