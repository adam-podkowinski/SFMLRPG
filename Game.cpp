//
// Created by PC on 2020-08-06.
//

#include "Game.h"
#include "States/MainMenuState.h"

//Initialization

void Game::initVariables()
{
    this->window = nullptr;
    this->fullscreen = false;
    this->dt = 0.f;
}

void Game::initWindow()
{
    //Creates an SFML window using options from a window.ini file

    std::string file_name = "window.ini";

    std::ifstream ifs("Config/" + file_name);
    this->videoModes = sf::VideoMode::getFullscreenModes();

    std::string title = "SFML RPG";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();

    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    unsigned antialiasing_level = 0;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> this->fullscreen;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
        ifs >> antialiasing_level;
    }
    ifs.close();

    this->windowSettings.antialiasingLevel = antialiasing_level;

    if (this->fullscreen)
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
    else
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close,
                                            windowSettings);

    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys()
{
    std::string file_name = "supported_keys.ini";

    std::ifstream ifs("Config/" + file_name);

    if (ifs.is_open())
    {
        std::string key;
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }
    ifs.close();
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}

//Constructors/Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initKeys();
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

//Functions

void Game::endApplication()
{
    std::cout << "Ending application" << std::endl;
}

void Game::updateDt()
{
    // Updates the dt variable with the time it takes to render and update one frame
    this->dt = this->dtClock.restart().asSeconds();
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
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        //Application ends
        this->endApplication();
        this->window->close();
    }

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
