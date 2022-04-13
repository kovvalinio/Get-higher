#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "included.h"




class Hearts : public sf::Sprite{
public:
    Hearts();
    void set_heart(const short &which);


private:
    sf::Texture whole;
    sf::Texture half;
    sf::Texture empty;
};
