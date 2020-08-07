//
// Created by PC on 2020-08-06.
//

#include "Game.h"

//Initialization
void Game::initWindow()
{
    //Creates an SFML window using options from a window.ini file

    //use if DEBUG in visual studio
#ifndef NDEBUG
    std::ifstream ifs("../Config/window.ini");
#else
    std::ifstream ifs("Config/window.ini");
#endif

    std::string title = "SFML RPG";
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
//        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates()
{
    this->states.push(new GameState(this->window));
}

//Constructors/Destructors
Game::Game()
{
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

//Static functions

//Functions
void Game::updateDt()
{
    // Updates the dt variable with the time it takes to render and update one frame

    this->dt = this->dtClock.restart().asSeconds();

    // clear for linux, cls for windows
    system("cls");
    std::cout << this->dt << "\n";
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
        this->states.top()->update(this->dt);
}

void Game::render()
{
    this->window->clear();

    //Render items
    if (!this->states.empty())
        this->states.top()->render();

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}

