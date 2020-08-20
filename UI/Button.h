//
// Created by PC on 2020-08-19.
//

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

enum ButtonState
{
    BTN_IDLE = 0,
    BTN_HOVER,
    BTN_ACTIVE
};

class Button
{
private:
    ButtonState buttonState;

    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button(float x, float y, float width, float height, sf::Font* font, const std::string& text,
           sf::Color idleColor,
           sf::Color hoverColor, sf::Color activeColor);

    virtual ~Button();

    //Getters
    bool isPressed() const;

    //Functions
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget* target);
};



