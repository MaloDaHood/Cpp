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

sf::RenderWindow window;
Input input;
sf::Texture heroTexture;
enum Dir {Down, Right, Up, Left, Down_Atk, Right_Atk, Up_Atk, Left_Atk};
sf::Vector2i heroAnim(0, Down);
sf::Clock heroAnimClock;
bool heroIdle {true};
bool needResetAnim {false};
int levelLoaded[COL_COUNT * ROW_COUNT];
int levelLoadedCollisions[COL_COUNT * ROW_COUNT];
sf::RectangleShape rects[COL_COUNT * ROW_COUNT];
bool debug {false};

// Monstre
// sf::Texture slimeTexture;
// sf::Sprite slimeSprite;
// Projectile
sf::Texture arrowTexture;
sf::Sprite arrowSprite;

void CheckButton();
void LoadHeroTexture(std::string file);
void LoadSlimeTexture(std::string file);
void LoadArrowTexture(std::string file);
void AnimPlayer();
std::vector<std::string> explode(std::string const &content, char const &delim);
void ShowCollisions();
void HandleArrow();

#endif