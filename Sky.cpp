#include "Sky.h"



Sky::Sky(const std::string &sky, const float &x, const float &y){


    if(whole.loadFromFile(sky)){

        whole.setRepeated(true);

        setTexture(whole);
        setTextureRect(sf::IntRect(0, 0, x, y));


    }

}
