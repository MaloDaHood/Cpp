#include "game.hpp"

void Game::initVariables()
{
    this->window=nullptr;
}

void Game::initWindow()
{
    this->videoMode.height=HEIGHT;
    this->videoMode.width=WIDTH;
    this->window=new sf::RenderWindow(this->videoMode, "SFML GAME", sf::Style::Default);
}

Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

bool Game::running() const
{
    return this->window->isOpen();
}

void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    this->window->clear(sf::Color::Red);

    this->window->display();
}

void Game::pollEvents()
{
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                switch(this->event.key.code)
                {
                    case sf::Keyboard::Escape:
                        this->window->close();
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}