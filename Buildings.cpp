#include "Buildings.h"



Buildings::Buildings(const std::string &path_b, const float &x){
whole.setRepeated(1);
    if(whole.loadFromFile((path_b))){
        setTexture(whole);
        setTextureRect(sf::IntRect(0, 0, x, 129));
        setScale(2.09,2.09);
        setPosition(0,250);
    }
}
