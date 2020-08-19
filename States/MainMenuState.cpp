//
// Created by PC on 2020-08-07.
//

#include "MainMenuState.h"


void MainMenuState::initFonts()
{

}

void MainMenuState::initKeybinds()
{
    std::string file_name = "gamestate_keybinds.ini";

//use if DEBUG in visual studio
#ifndef NDEBUG
    std::ifstream ifs("../Config/" + file_name);
#else
    std::ifstream ifs("Config/" + file_name);
#endif

    if (ifs.is_open())
    {
        std::string key;
        std::string key2;

        while (ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }
    ifs.close();
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
        : State(window, supportedKeys)
{
    this->initKeybinds();

    this->background.setSize(sf::Vector2f(window->getSize()));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState() = default;

void MainMenuState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);
}

void MainMenuState::updateInput(const float& dt)
{
    this->checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        this->background.setFillColor(sf::Color::Black);
    }
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;

    target->draw(this->background);
}

void MainMenuState::endState()
{
    std::cout << "Ending Main Menu State" << std::endl;
}
