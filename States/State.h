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

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


class State
{
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;

public:
    State(sf::RenderWindow* window);

    virtual ~State();

    virtual void endState() = 0;

    virtual void update(const float& dt) = 0;

    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
