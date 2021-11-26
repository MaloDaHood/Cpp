#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.hpp"

constexpr int WIN_WIDTH {800};
constexpr int WIN_HEIGHT {600};

sf::RenderWindow window;
Input input;
sf::Font font;
sf::Text txt;

// Positions
int posX {1};

// Astuce pour afficher un chiffre sous forme de string
// char tempX[256];

void LoadFont();
void SetText(sf::Text &txt, sf::String const &str);
void CheckButton();

#endif