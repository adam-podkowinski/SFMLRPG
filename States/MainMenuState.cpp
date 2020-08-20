//
// Created by PC on 2020-08-07.
//

#include "MainMenuState.h"


void MainMenuState::initFonts()
{
    if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
    {
        throw ("ERROR: MainMenuState::Could not load font");
    }
}

void MainMenuState::initKeybinds()
{
    std::string file_name = "mainmenustate_keybinds.ini";

    std::ifstream ifs("Config/" + file_name);

    if (ifs.is_open())
    {
        std::string key;
        std::string key2;

        while (ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }
    ifs.close();
}

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50, &this->font, "New Game", sf::Color(70, 70, 70, 200),
                                             sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
    this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50, &this->font, "Quit", sf::Color(100, 100, 100, 200),
                                             sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
                             std::stack<State*>* states)
        : State(window, supportedKeys, states)
{
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    this->background.setSize(sf::Vector2f(window->getSize()));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
    for (auto& button : this->buttons)
    {
        delete button.second;
    }
}

void MainMenuState::updateInput(const float& dt)
{
    this->checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        this->background.setFillColor(sf::Color::Black);
    }
}

void MainMenuState::updateButtons()
{
    for (auto& button : this->buttons)
    {
        button.second->update(this->mousePosView);
    }

    //New game
    if (this->buttons["GAME_STATE"]->isPressed())
    {
        // Huh
    }

    //Quit the game
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        this->quit = true;
    }
}

void MainMenuState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
    for (auto& button : this->buttons)
    {
        button.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;

    target->draw(this->background);

    this->renderButtons(target);
}

void MainMenuState::endState()
{
    std::cout << "Ending Main Menu State" << std::endl;
}
