#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Platforms.h"
#include "aMonster.h"

class AnimatedSprite : public sf::Sprite {
public:

    AnimatedSprite(int fps, const std::string &path_r,const std::string &path_l);
    void animation(sf::Time &elapsed);
    void add_animation_frame(const sf::IntRect &f);
    virtual ~AnimatedSprite() = default;
    void moving(sf::Time &elapsed, const sf::RenderWindow &window, const bool &collision);
    bool collision(const Platforms &a);
    sf::Texture return_tex();
    bool ret_floor();
    void set_floor(const bool &i);
    void set_dir(const bool &turn);
    void floor_default();
    bool collision_with_monster(const Monster &monster);
    void change_loosed(const bool &i);
    bool return_turn();

private:

    sf::Time time_between_f;
    sf::Time time_passed;
    sf::Texture whole_r;
    sf::Texture whole_l;
    std::vector<sf::IntRect> frames;
    int frame_number = 0;
    sf::Time fps_passed;
    float x_vel = 0.0f;
    float y_vel = 0.0f;
    float gravity = 2800.0f;
    bool floor = 1;
    bool actual_turn = 0;
    bool loosed = 0;

};