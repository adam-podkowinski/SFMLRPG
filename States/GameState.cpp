//
// Created by PC on 2020-08-07.
//

#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
        : State(window)
{

}

GameState::~GameState()
{

}

void GameState::update(const float& dt)
{
    std::cout << "Hello from GameState" << std::endl;
}

void GameState::render(sf::RenderTarget* target)
{

}

void GameState::endState()
{

}
