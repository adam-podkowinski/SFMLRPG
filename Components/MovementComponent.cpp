//
// Created by PC on 2020-08-20.
//

#include "MovementComponent.h"

MovementComponent::MovementComponent(float maxVelocity)
{
    this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent() = default;

//Getters
const sf::Vector2f& MovementComponent::getVelocity() const
{
    return this->velocity;
}

//Functions
void MovementComponent::move(const float& dir_x, const float& dir_y)
{
    this->velocity.x = this->maxVelocity * dir_x;
    this->velocity.y = this->maxVelocity * dir_y;
}

void MovementComponent::update(const float& dt)
{

}
