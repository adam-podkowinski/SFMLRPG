//
// Created by PC on 2020-08-20.
//

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <map>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class MovementComponent
{
private:
    float maxVelocity;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f deceleration;

    //Initializer functions


public:
    MovementComponent(float maxVelocity);
    virtual ~MovementComponent();

    //getters
    const sf::Vector2f& getVelocity() const;

    //Functions
    void move(const float& dir_x, const float& dir_y);
    void update(const float& dt);
};