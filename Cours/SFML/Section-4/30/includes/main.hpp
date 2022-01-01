#ifndef MAIN_HPP
#define MAIN_HPP

#include "config.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include "input.hpp"
#include "map.hpp"
#include "portal.hpp"
#include "monster.hpp"
#include "player.hpp"
#include "arrow.hpp"

void CheckButton(Input const &input, sf::RenderWindow &window, bool &debug);
std::vector<std::string> explode(std::string const &content, char const &delim);
void ShowCollisions(sf::RenderWindow &window, sf::RectangleShape rects[COL_COUNT * ROW_COUNT]);
void Draw(std::vector<sf::Sprite> const &drawables, sf::RenderWindow &window);
void setSlimesPosition(std::vector<Slime> &slimes);

#endif