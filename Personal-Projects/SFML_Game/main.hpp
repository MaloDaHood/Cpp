#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.hpp"
#include <vector>

constexpr int WIN_WIDTH {1280};
constexpr int WIN_HEIGHT {720};
constexpr int SPEED {10};

sf::RenderWindow window;
Input input;
sf::Font font;
sf::Text score;

int posYL {1};
int posYR {1};

void LoadFont();
void SetText(sf::Text &txt, sf::String const &str);
void CheckButton();
bool checkBallColision(sf::CircleShape const &ball, sf::RectangleShape const &rectangle);

#endif