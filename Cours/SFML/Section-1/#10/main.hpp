#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.hpp"

constexpr int WIN_WIDTH {800};
constexpr int WIN_HEIGHT {600};
constexpr int SPEED {10};

sf::RenderWindow window;
Input input;
sf::Font font;
sf::Text txt;

int posX {1};
int posY {1};
char tempX[256];
char tempY[256];

void LoadFont();
void SetText(sf::Text &txt, sf::String const &str);
void CheckButton();

#endif