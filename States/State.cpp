//
// Created by PC on 2020-08-07.
//

#include "State.h"

State::State(sf::RenderWindow* window)
{
    this->window = window;
    this->quit = false;
}

State::~State() = default;

void State::checkForQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit = true;
    }
}

const bool& State::getQuit() const
{
    return this->quit;
}
