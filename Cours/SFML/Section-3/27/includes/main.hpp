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
#include "map.hpp"

constexpr int WIN_WIDTH {800}; // 25 tiles de 32 pixels
constexpr int WIN_HEIGHT {576}; // 18 tiles de 32 pixels
constexpr int SPRITE_SIZE {32}; // On a des sprites de 32x32 pixels
constexpr int WALK_SPEED {2}; // Vitesse de déplacement du personnage
constexpr int COL_COUNT {25}; // Nombres de cases en largeur (col)
constexpr int ROW_COUNT {18}; // Nombre de cases en lignes (row)

sf::RenderWindow window;
Input input;
sf::Texture heroTexture;
sf::Sprite heroSprite;
enum Dir {Down, Right, Up, Left, Down_Atk, Right_Atk, Up_Atk, Left_Atk};
sf::Vector2i heroAnim(0, Down);
sf::Clock heroAnimClock;
bool heroIdle {true};
bool needResetAnim {false};
int levelLoaded[COL_COUNT * ROW_COUNT];
int levelLoadedCollisions[COL_COUNT * ROW_COUNT];
sf::RectangleShape rects[COL_COUNT * ROW_COUNT];
bool debug {false};

void CheckButton();
void LoadHeroTexture(std::string file);
void AnimPlayer();
void LoadMapFromFile(std::string file);
std::vector<char> explode(std::string const &content, char const &delim);
void ShowCollisions();

#endif