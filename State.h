//
// Created by PC on 2020-08-07.
//

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <vector>

class State
{
private:
    std::vector<sf::Texture> textures;

public:
    State();

    virtual ~State();

    virtual void update() = 0;

    virtual void render() = 0;
};
