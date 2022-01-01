#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

constexpr int WIN_WIDTH {800};
constexpr int WIN_HEIGHT {600};

sf::Font font;

void InputHandler(sf::Event event, sf::RenderWindow &window);
void LoadFont();
void SetText(sf::Text &txt, sf::String const &str);

#endif