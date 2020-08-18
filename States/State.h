//
// Created by PC on 2020-08-07.
//

#pragma once

#include "../Entities/Entity.h"


class State
{
private:

protected:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool quit;

public:
    explicit State(sf::RenderWindow* window);

    virtual ~State();

    //Getters
    const bool& getQuit() const;

    //Functions

    virtual void checkForQuit();

    virtual void endState() = 0;
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
