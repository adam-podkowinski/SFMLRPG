//
// Created by PC on 2020-08-19.
//

#pragma once

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

    sf::Color textIdleColor;
    sf::Color textHoverColor;
    sf::Color textActiveColor;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button(float x, float y, float width, float height, sf::Font* font, std::string text,
           unsigned character_size, sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
           sf::Color idle_color, sf::Color hover_color, sf::Color active_color);

    virtual ~Button();

    //Getters
    bool isPressed() const;

    //Functions
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget* target);
};



