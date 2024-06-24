#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "included.h"

class Sky : public sf::Sprite{

public:
    Sky(const std::string &sky, const float &x, const float &y);
private:
    sf::Texture whole;

};