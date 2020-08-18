//
// Created by PC on 2020-08-06.
//

#pragma once

#include "States/GameState.h"

class Game
{
private:
    //Variables
    sf::RenderWindow* window{};
    sf::Event sfEvent{};

    sf::Clock dtClock;
    float dt{};

    std::stack<State*> states;

    std::map<std::string, int> supportedKeys;

    //Initialization
    void initWindow();
    void initStates();
    void initKeys();

public:

    //Constructors/Destructors
    Game();

    virtual ~Game();

    //Funcitons

    //Regular
    void endApplication();

    //Update
    void updateDt();
    void updateSFMLEvents();
    void update();

    //Render
    void render();

    //Core
    void run();
};



