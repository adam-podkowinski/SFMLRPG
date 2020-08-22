//
// Created by PC on 2020-08-07.
//

#pragma once

#include "../Components/MovementComponent.h"
#include "../Components/AnimationComponent.h"

class Entity
{
private:
    void initVariables();

protected:
    sf::Sprite sprite;

    MovementComponent* movementComponent;
    AnimationComponent* animationComponent;

public:
    Entity();
    virtual ~Entity();

    //Component functions
    void setTexture(sf::Texture& texture);
    void createMovementComponent(const float& maxVelocity, const float& acceleration, const float& deceleration);
    void createAnimationComponent(sf::Texture& texture_sheet);

    //Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float& dir_x, const float& dir_y, const float& dt);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};



