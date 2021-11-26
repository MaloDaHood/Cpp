#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility> 
#include "input.hpp"

constexpr int WIN_WIDTH {800}; // 25 tiles de 32 pixels
constexpr int WIN_HEIGHT {576}; // 18 tiles de 32 pixels
constexpr int SPEED {10};

sf::RenderWindow window;
Input input;

void CheckButton();

#endif