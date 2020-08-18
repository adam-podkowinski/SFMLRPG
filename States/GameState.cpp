//
// Created by PC on 2020-08-07.
//

#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
        : State(window)
{

}

GameState::~GameState() = default;

void GameState::update(const float& dt)
{
    this->updateInput(dt);

    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;

    this->player.render(target);
}

void GameState::updateInput(const float& dt)
{
    this->checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player.move(dt, -1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player.move(dt, 1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player.move(dt, 0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player.move(dt, 0, 1.f);
}

void GameState::endState()
{
    std::cout << "Ending Game State" << std::endl;
}
