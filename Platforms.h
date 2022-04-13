#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>


class Platforms : public std::vector<sf::Sprite>{
public:
    Platforms(const std::string &path) ;
    virtual ~Platforms() = default;
    void add_new(const float &y);
    sf::Sprite ret_s();
    int return_l();
    void level_defaul();





private:

    sf::Texture whole;
    std::vector<sf::IntRect> platf_r;
    int level;

};
