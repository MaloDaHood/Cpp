#include "main.hpp"

int main()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    LoadTexture();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }
        CheckButton();
        AnimPlayer(); // Animation personnage
        window.clear(sf::Color::Black);
        window.draw(heroSprite);
        window.display();
    }
    return 0;
}

void CheckButton()
{
    if(!needResetAnim) // Si pas d'attaque en cours
    {
        if (input.GetButton().left)
        {
            heroAnim.y = Left;
            heroSprite.move(-WALK_SPEED, 0);
            heroIdle = false;
        }
        else if (input.GetButton().right)
        {
            heroAnim.y = Right;
            heroSprite.move(WALK_SPEED, 0);
            heroIdle = false;
        }
        else if (input.GetButton().up)
        {
            heroAnim.y = Up;
            heroSprite.move(0, -WALK_SPEED);
            heroIdle = false;
        }
        else if (input.GetButton().down)
        {
            heroAnim.y = Down;
            heroSprite.move(0, WALK_SPEED);
            heroIdle = false;
        }
        else // Personnage en idle
        {
            heroIdle = true;
        }
        if (input.GetButton().attack)
        {
            needResetAnim = true; // Après attaque, retourner sur anim walk
            heroAnim.x = 0; // Retourner à la col 0 (jouer anim depuis le début)
            // On passe de la ligne walk à la ligne attaque sur la texture
            heroAnim.y += 4; // On descend de 4 lignes sur notre sprite sheet
        }
    }
    if (input.GetButton().escape)
    {
        window.close();
    }
}

void LoadTexture()
{
    // Chargement visuel hero
    if (!heroTexture.loadFromFile("hero_sheet.png"))
    {
        std::cout << "Erreur chargement texture héros." << std::endl;
    }
    // On applique la texture à notre sprite
    heroSprite.setTexture(heroTexture);
}

void AnimPlayer()
{
    heroSprite.setTextureRect(sf::IntRect(heroAnim.x * SPRITE_SIZE, heroAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
    // Animer en boucle la col (0 -> 3)
    // Si il s'est écoulé 0.1 secondes
    if (heroAnimClock.getElapsedTime().asSeconds() > 0.1f)
    { // Animation de 10 FPS
        // On est au bout de la texture
        if(heroAnim.x*SPRITE_SIZE >= int(heroTexture.getSize().x) - SPRITE_SIZE)
        {
            heroAnim.x = 0;
            // Si l'anim d'attaque tourne
            if(needResetAnim)
            {
                // On l'arrête et on retourne sur l'anim de marche
                needResetAnim = false;
                heroAnim.y -= 4;
            }
        }
        // On se décale d'une colonne
        else
        {
            // Si le personnage n'est pas à l'arrêt = !idle
            if(!heroIdle || needResetAnim)
                heroAnim.x++;
        }
        heroAnimClock.restart();
    }
}