//
// Created by PC on 2020-08-20.
//

#include "Player.h"

//Initializer functions
void Player::initVariables()
{

}

void Player::initComponents()
{
    this->createMovementComponent(100.f);
}

// Constructors / destructors
Player::Player(float x, float y, sf::Texture* texture)
{
    this->initVariables();
    this->initComponents();

    this->createSprite(texture);
    this->setPosition(x, y);
}

Player::~Player() = default;