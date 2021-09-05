#include "main.hpp"

int main()
{
    sf::ContextSettings options;
    options.antialiasingLevel = 8;
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SFML APP", sf::Style::Default, options);
    window.setVerticalSyncEnabled(true);
    LoadFont();
    SetText(score, "0/0");
    score.setPosition(WIN_WIDTH/2, 50);
    sf::RectangleShape leftRectangle(sf::Vector2f(50.f, 200.f));
    leftRectangle.setFillColor(sf::Color::White);
    leftRectangle.setPosition(50, posYL);
    sf::RectangleShape rightRectangle(sf::Vector2f(50.f, 200.f));
    rightRectangle.setFillColor(sf::Color::White);
    rightRectangle.setPosition(WIN_WIDTH-100, posYR);
    sf::CircleShape ball(25);
    ball.setFillColor(sf::Color::White);
    ball.setOrigin(25, 25);
    ball.setPosition(WIN_WIDTH/2, WIN_HEIGHT/2);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            input.InputHandler(event, window);
            CheckButton();
            leftRectangle.setPosition(50, posYL);
            rightRectangle.setPosition(WIN_WIDTH-100, posYR);
        }
        window.clear(sf::Color::Black);
        window.draw(score);
        window.draw(leftRectangle);
        window.draw(rightRectangle);
        window.draw(ball);
        ball.move(1, 0);
        checkBall(ball);
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
    txt.setFillColor(sf::Color::White);
    txt.setStyle(sf::Text::Bold);
    txt.setOrigin(50, 50);
}

void CheckButton()
{
    if(input.GetButton().z)
    {
        posYL-=SPEED;
        if(posYL<0)
            posYL=0;
    }
    if(input.GetButton().s)
    {
        posYL+=SPEED;
        if(posYL>WIN_HEIGHT-200)
            posYL=WIN_HEIGHT-200;
    }
    if(input.GetButton().up)
    {
        posYR-=SPEED;
        if(posYR<0)
            posYR=0;
    }
    if(input.GetButton().down)
    {
        posYR+=SPEED;
        if(posYR>WIN_HEIGHT-200)
            posYR=WIN_HEIGHT-200;
    }
    if(input.GetButton().escape)
    {
        window.close();
    }
}

void checkBall(sf::CircleShape ball)
{
    if(ball.getPosition().x>WIN_WIDTH)
    {
        ball.setPosition(10, ball.getPosition().y);
    }
}