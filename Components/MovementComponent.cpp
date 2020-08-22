//
// Created by PC on 2020-08-20.
//

#include "MovementComponent.h"
#include <algorithm>

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration)
        : sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration) {}

MovementComponent::~MovementComponent() = default;

//Getters
const sf::Vector2f& MovementComponent::getVelocity() const
{
    return this->velocity;
}

//Functions
void MovementComponent::move(const float& dir_x, const float& dir_y)
{
    //Acceleration
    this->velocity.x += this->acceleration * dir_x;
    this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float& dt)
{
    //Deceleration
    if (this->velocity.x > 0.f) //check for positive x
    {
        this->velocity.x -= this->deceleration;
        if (this->velocity.x < 0.f)
            this->velocity.x = 0.f;
    }
    else if (this->velocity.x < 0.f) //check for negative x
    {
        this->velocity.x += this->deceleration;
        if (this->velocity.x > 0.f)
            this->velocity.x = 0.f;
    }

    if (this->velocity.y > 0.f) //check for positive y
    {
        this->velocity.y -= this->deceleration;
        if (this->velocity.y < 0.f)
            this->velocity.y = 0.f;
    }
    else if (this->velocity.y < 0.f) //check for negative y
    {
        this->velocity.y += this->deceleration;
        if (this->velocity.y > 0.f)
            this->velocity.y = 0.f;
    }

    //Make sure velocities don't exceed the limits
    this->velocity.x = std::clamp(this->velocity.x, -this->maxVelocity, this->maxVelocity);
    this->velocity.y = std::clamp(this->velocity.y, -this->maxVelocity, this->maxVelocity);

    //Final move
    this->sprite.move(this->velocity * dt);
}
