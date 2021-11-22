#include <SFML/Graphics.hpp>

int main()
{
    // Création d'une fenêtre type RenderWindow
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML APP");

    // Activation du V-Sync
    window.setVerticalSyncEnabled(true);
    
    while(window.isOpen())
    {

    }

    return 0;
}