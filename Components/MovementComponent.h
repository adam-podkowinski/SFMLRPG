//
// Created by PC on 2020-08-20.
//

#pragma once

class MovementComponent
{
private:
    sf::Sprite& sprite;

    float maxVelocity;

    sf::Vector2f velocity;
    float acceleration;
    float deceleration;
    //Initializer functions


public:
    MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
    virtual ~MovementComponent();

    //getters
    const sf::Vector2f& getVelocity() const;

    //Functions
    void move(const float& dir_x, const float& dir_y);
    void update(const float& dt);
};