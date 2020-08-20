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
    void initVariables();

protected:
    sf::Texture* texture;
    sf::Sprite* sprite;

    float movementSpeed;

public:
    Entity();
    virtual ~Entity();

    //Component functions
    void createSprite(sf::Texture* texture);

    //Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float& dir_x, const float& dir_y);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};



