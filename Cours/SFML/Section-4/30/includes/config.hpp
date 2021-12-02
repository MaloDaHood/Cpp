#ifndef CONFIG_HPP
#define CONFIG_HPP

constexpr int WIN_WIDTH {800}; // 25 tiles de 32 pixels
constexpr int WIN_HEIGHT {576}; // 18 tiles de 32 pixels
constexpr int SPRITE_SIZE {32}; // On a des sprites de 32x32 pixels
constexpr int WALK_SPEED {2}; // Vitesse de déplacement du personnage
constexpr int COL_COUNT {25}; // Nombres de cases en largeur (col)
constexpr int ROW_COUNT {18}; // Nombre de cases en lignes (row)
constexpr int ARROW_SPEED {4}; // Vitesse de la flèche
constexpr int SLIME_COUNT {5}; // Nombre de slimes

int levelLoaded[COL_COUNT * ROW_COUNT];
int levelLoadedCollisions[COL_COUNT * ROW_COUNT];
int actualMap {1};

#endif