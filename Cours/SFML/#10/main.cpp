#include "main.hpp"

int main()
{
    sf::ContextSettings options;
    options.antialiasingLevel = 8;
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default, options);
    window.setVerticalSyncEnabled(true);
    LoadFont();
    SetText(txt, "TEST");

    // Préparation des formes
    sf::CircleShape circle(75);
    circle.setFillColor(sf::Color(100, 175, 80));
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(5);
    circle.setPosition(posX, 150);

    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setPosition(200, 300);
    rectangle.setFillColor(sf::Color(255, 0, 0));
    rectangle.setSize(sf::Vector2f(200.f, 100.f));

    sf::CircleShape triangle(80.f, 3);
    triangle.setFillColor(sf::Color::Yellow);

    // Forme libre
    // Créer une forme vide
    sf::ConvexShape convex;
    // Définir le nombre de points (5)
    convex.setPointCount(5);
    // Définir les points
    convex.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex.setPoint(1, sf::Vector2f(150.f, 10.f));
    convex.setPoint(2, sf::Vector2f(120.f, 90.f));
    convex.setPoint(3, sf::Vector2f(30.f, 100.f));
    convex.setPoint(4, sf::Vector2f(0.f, 50.f));

    convex.setPosition(500, 400);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            input.InputHandler(event, window);
            CheckButton();
            circle.setPosition(posX, posY);
        }
        window.clear(sf::Color::Blue);
        window.draw(txt);
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        window.draw(convex);
        window.display();
    }
    return 0;
}

void LoadFont()
{
    if(!font.loadFromFile("poppins.ttf"))
    {
        std::cout << "Erreur lors du chargement de la police d'écriture." << std::endl;
    }
}

void SetText(sf::Text &txt, sf::String const &str)
{
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(50);
    txt.setFillColor(sf::Color::Red);
    txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void CheckButton()
{
    if(input.GetButton().left)
    {
        posX-=SPEED;
        if(posX<0)
            posX=0;
        sprintf(tempX, "%d", posX);
        SetText(txt, tempX);
    }
    if(input.GetButton().right)
    {
        posX+=SPEED;
        if(posX>WIN_WIDTH)
            posX=WIN_WIDTH;
        sprintf(tempX, "%d", posX);
        SetText(txt, tempX);
    }
    if(input.GetButton().up)
    {
        posY-=SPEED;
        if(posY<0)
            posY=0;
        sprintf(tempY, "%d", posY);
        SetText(txt, tempY);
    }
    if(input.GetButton().down)
    {
        posY+=SPEED;
        if(posY>WIN_HEIGHT)
            posY=WIN_HEIGHT;
        sprintf(tempY, "%d", posY);
        SetText(txt, tempY);
    }
    if(input.GetButton().attack)
    {
        SetText(txt, "Attack");
    }
    if(input.GetButton().escape)
    {
        window.close();
    }
}