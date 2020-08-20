//
// Created by PC on 2020-08-07.
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


class Entity
{
private:

protected:
    sf::RectangleShape shape;
    float movementSpeed;

public:
    Entity();
    virtual ~Entity();

    //Functions
    virtual void move(const float& dt, const float& dir_x, const float& dir_y);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};



