//
// Created by PC on 2020-08-22.
//

#pragma once


class AnimationComponent
{
private:
    class Animation
    {
    public:
        //Variables
        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        float animationTimer;
        float timer;
        int width;
        int height;
        sf::IntRect startRect;
        sf::IntRect currentRect;
        sf::IntRect endRect;

        Animation(sf::Sprite& sprite, sf::Texture& texture_sheet, float animation_timer,
                  int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height)
                : sprite(sprite), textureSheet(texture_sheet), animationTimer(animation_timer), width(width),
                  height(height)
        {
            this->timer = 0.f;
            this->startRect = sf::IntRect(start_frame_x * width, start_frame_y, width, height);
            this->currentRect = this->startRect;
            this->endRect = sf::IntRect(frames_x * width, frames_y * height, width, height);

            this->sprite.setTexture(this->textureSheet, true);
            this->sprite.setTextureRect(this->startRect);
        }

        //Functions
        void play(const float& dt)
        {
            //Update timer
            this->timer += 125.f * dt;
            if (this->timer >= this->animationTimer)
            {
                //Reset timer;
                this->timer = 0.f;

                //Animate
                if (this->currentRect != this->endRect)
                    this->currentRect.left += this->width;
                else //Reset
                    this->currentRect.left = this->startRect.left;
            }

            this->sprite.setTextureRect(this->currentRect);
        }

        void reset()
        {
            this->timer = 0.f;
            this->currentRect = this->startRect;
        }
    };

    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    std::map<std::string, Animation*> animations;

public:
    AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
    virtual ~AnimationComponent();

    //Functions
    void addAnimation(const std::string& key, float animation_timer, int start_frame_x, int start_frame_y,
                      int frames_x, int frames_y, int width, int height);

    void play(const std::string& key, const float& dt);
};
