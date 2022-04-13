#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Platforms.h"
#include "aBullet.h"







class Monster : public sf::Sprite{
public:
    Monster();
    void animation(const sf::Time &elapsed, const Platforms &platforms, const float &hero_pos);
    bool collision(const Platforms &platform);
    void spawn();
    int return_health();
    void substr_health(Bullet &bullet);
    void set_health(const int &h);


private:
    sf::Texture whole1;
    sf::Texture whole2;
    sf::Time time_passed;
    float x_vel = 0.0f;
    float y_vel = 0.0f;
    float gravity = 1800.0f;
    bool turn = 1;
    int health;

};
