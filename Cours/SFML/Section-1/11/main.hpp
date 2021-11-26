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

void LoadFont();
void SetText(sf::Text &txt, sf::String const &str);

#endif