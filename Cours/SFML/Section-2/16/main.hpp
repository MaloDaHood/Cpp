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
constexpr int SPRITE_SIZE {32}; // On a des sprites de 32x32 pixels
constexpr int WALK_SPEED {1}; // Vitesse de déplacement du personnage

sf::RenderWindow window;
Input input;

// Préparation affichage personnage 2D
sf::Texture heroTexture;
sf::Sprite heroSprite;

// enum des actions / directions
enum Dir {Down, Right, Up, Left, Down_Atk, Right_Atk, Up_Atk, Left_Atk};

// Définir l'animation (ligne) à jouer
// x = lignes & y = col
sf::Vector2i heroAnim(0, Down); 

void CheckButton();
void LoadTexture();

#endif