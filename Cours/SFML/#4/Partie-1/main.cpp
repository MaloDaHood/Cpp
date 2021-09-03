#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    // Création d'une fenêtre avec taille et titre
    sf::Window window;
    window.create(sf::VideoMode(800, 600), "SFML APP");

    // Modification du titre de la fenêtre
    window.setTitle("Titre modifié");

    //Boucle qui tourne tant que la fenêtre est ouverte
    while(window.isOpen())
    {
        
    }
    return 0;
}