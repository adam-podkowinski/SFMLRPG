//
// Created by PC on 2020-08-07.
//

#pragma once

#include "State.h"


class GameState : public State
{
private:

public:
    GameState(sf::RenderWindow* window);

    virtual ~GameState();

    //Functions
    void endState() override;

    void update(const float& dt) override;

    void render(sf::RenderTarget* target = nullptr) override;
};



