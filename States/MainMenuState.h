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
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;

    //Functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds() override;
    void initButtons();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);

    ~MainMenuState() override;

    //Functions
    void updateInput(const float& dt) override;
    void updateButtons();
    void update(const float& dt) override;

    void renderButtons(sf::RenderTarget* target);
    void render(sf::RenderTarget* target = nullptr) override;
};



