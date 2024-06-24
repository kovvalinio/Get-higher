#include "Button.h"
#include <iostream>

Button::Button(){

    font.loadFromFile("C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/Arial.ttf");
    setFont(font);
    setFillColor(sf::Color::Black);

}

void Button::set_type(const short i){
    type = i;
    if(type == 0){
        setString("Play!");

    }
    if(type == 1){
        setString("Best records");
    }
    if(type == 2){
        setString("Credits");
    }
    if(type == 3){
        setString("Exit");
    }
    if(type == 4){
        setString("Back");
    }

}

void Button::swich_scr(short &i, const sf::Vector2i &mouse_pos){

if(mouse_pos.x < getGlobalBounds().left + getGlobalBounds().width && mouse_pos.x > getGlobalBounds().left && mouse_pos.y > getGlobalBounds().top && mouse_pos.y < getGlobalBounds().top +getGlobalBounds().height){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(type == 0){

            i = 1;
        }
        if(type == 1){
            i = 2;
        }
        if(type == 2){
            i = 3;
        }
        if(type == 3){
            i = 4;
        }
        if(type == 4){
            i = 0;
        }

    }
}

}
