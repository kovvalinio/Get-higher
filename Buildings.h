#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "included.h"

class Buildings : public sf::Sprite{
public:
    Buildings(const std::string &path_b,const float &x);
private:
    sf::Texture whole;

};