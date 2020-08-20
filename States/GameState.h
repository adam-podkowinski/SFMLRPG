//
// Created by PC on 2020-08-07.
//

#pragma once

#include "State.h"


class GameState : public State
{
private:
    Player* player;

    //Functions
    void initKeybinds() override;
    void initTextures();
    void initPlayers();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);

    ~GameState() override;

    //Functions
    void updateInput(const float& dt) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget* target = nullptr) override;
};



