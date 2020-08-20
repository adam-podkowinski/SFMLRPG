//
// Created by PC on 2020-08-07.
//

#pragma once

#include "State.h"


class GameState : public State
{
private:
    Entity player;

    //Functions
    void initKeybinds() override;

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);

    ~GameState() override;

    //Functions
    void endState() override;

    void updateInput(const float& dt) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget* target = nullptr) override;
};



