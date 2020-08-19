//
// Created by PC on 2020-08-19.
//

#pragma once


#include "State.h"
#include "../UI/Button.h"

class MainMenuState : public State
{
private:
    //Variables
    sf::RectangleShape background;
    sf::Font font;

    //Functions
    void initFonts();
    void initKeybinds() override;

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);

    ~MainMenuState() override;

    //Functions
    void endState() override;

    void updateInput(const float& dt) override;
    void update(const float& dt) override;
    void render(sf::RenderTarget* target = nullptr) override;
};



