//
// Created by PC on 2020-08-07.
//

#pragma once

#include "State.h"


class GameState : public State
{
private:
    Entity player;

public:
    explicit GameState(sf::RenderWindow* window);

    ~GameState() override;

    //Functions
    void endState() override;

    void updateInput(const float& dt) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget* target = nullptr) override;
};



