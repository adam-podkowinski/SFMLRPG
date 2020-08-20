//
// Created by PC on 2020-08-07.
//

#include "MainMenuState.h"
#include "GameState.h"

//Initializer functions
void MainMenuState::initVariables()
{

}

void MainMenuState::initBackground()
{
    this->background.setSize(static_cast<sf::Vector2f>(this->window->getSize()));

    if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png"))
    {
        throw "ERROR: MainMenuState failed to load background texture";
    }

    this->background.setTexture(&this->backgroundTexture);
}

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
    this->buttons["GAME_STATE"] = new Button(300, 480, 250, 50, &this->font, "New Game",
                                             sf::Color(70, 70, 70, 200),
                                             sf::Color(150, 150, 150, 255),
                                             sf::Color(20, 20, 20, 200));

    this->buttons["SETTINGS"] = new Button(300, 550, 250, 50, &this->font, "Settings",
                                           sf::Color(100, 100, 100, 200),
                                           sf::Color(150, 150, 150, 255),
                                           sf::Color(20, 20, 20, 200));

    this->buttons["EXIT_STATE"] = new Button(300, 620, 250, 50, &this->font, "Quit",
                                             sf::Color(100, 100, 100, 200),
                                             sf::Color(150, 150, 150, 255),
                                             sf::Color(20, 20, 20, 200));
}

//Constructors / Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,
                             std::stack<State*>* states)
        : State(window, supportedKeys, states)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
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
        this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    //Quit the game
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        this->endState();
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

    //! Remove later
//    sf::Text mouseText;
//    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 24);
//    mouseText.setFont(this->font);
//    mouseText.setCharacterSize(24);
//    int x = static_cast<int>(this->mousePosView.x);
//    int y = static_cast<int>(this->mousePosView.y);
//    std::string text = std::to_string(x) + ", " + std::to_string(y);
//    mouseText.setString(text);
//    target->draw(mouseText);
}
