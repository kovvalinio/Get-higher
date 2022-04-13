#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "included.h"




class Button : public sf::Text{
public:
    Button();
    void set_type(const short i);
    void swich_scr(short &i, const sf::Vector2i &mouse_pos);


private:
    sf::Font font;
    short type;
};
