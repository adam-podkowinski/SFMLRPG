//
// Created by PC on 2020-08-07.
//

#pragma once

#include "../Components/MovementComponent.h"

class Entity
{
private:
    void initVariables();

protected:
    sf::Texture* texture;
    sf::Sprite* sprite;

    MovementComponent* movementComponent;

public:
    Entity();
    virtual ~Entity();

    //Component functions
    void createSprite(sf::Texture* texture);
    void createMovementComponent(const float& maxVelocity);

    //Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dt, const float& dir_x, const float& dir_y);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};



