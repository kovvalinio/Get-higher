#include <iostream>
#include <memory>
#include "Sky.h"
#include "AnimatedSprite.h"
#include "Buildings.h"
#include "aBullet.h"
#include "Hearts.h"
#include "aMonster.h"
#include "Platforms.h"
#include "Sky.h"

AnimatedSprite::AnimatedSprite(int fps,const std::string &path_r, const std::string &path_l) : time_between_f(sf::seconds(1.0/fps)){
if(whole_r.loadFromFile(path_r)){
    setTexture(whole_r);
    setPosition(0,400);
}
whole_l.loadFromFile(path_l);


}

void AnimatedSprite::animation(sf::Time &elapsed){
    time_passed += elapsed;
    if(!actual_turn){
    if(time_passed > fps_passed){
        setTextureRect(frames[frame_number]);
        fps_passed += time_between_f;
        frame_number++;

    }
    }

    if(actual_turn){
    if(time_passed > fps_passed){
        setTextureRect(frames[6+frame_number]);
        fps_passed += time_between_f;
        frame_number++;

    }
    }


    if(frame_number == frames.size()/2){
        time_passed = time_passed - fps_passed;
        fps_passed = sf::seconds(0);
        frame_number = 0;
    }

}

void AnimatedSprite::add_animation_frame(const sf::IntRect &f){
    frames.emplace_back(f);
}

void AnimatedSprite::moving(sf::Time &elapsed, const sf::RenderWindow &window,const bool &collision){
    y_vel = y_vel + elapsed.asSeconds()*gravity;

    if(floor == 1){

    if(getGlobalBounds().top + getGlobalBounds().height >= window.getSize().y){
    if(y_vel >0){
        y_vel = 0;
    }
    }

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    set_dir(1);
    x_vel = -800;
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        set_dir(0);
        x_vel = 800;
    }

    else{
        x_vel = 0;
    }


    if(!loosed){
        if(collision){
            y_vel = 0;
        }
    }

    if(y_vel == 0){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            y_vel = -1300;
        }

    }

    if(y_vel != 0 || x_vel != 0){
    move(x_vel*elapsed.asSeconds(),elapsed.asSeconds()*y_vel);
}
}














bool AnimatedSprite::collision(const Platforms &a){
    if(y_vel >= 0){
for(int i = 0 ; i < a.size() ; i++){
    if(getGlobalBounds().top + getGlobalBounds().height >= a[i].getGlobalBounds().top &&
            getGlobalBounds().top + getGlobalBounds().height <= a[i].getGlobalBounds().top + a[i].getGlobalBounds().height &&
            getGlobalBounds().left + getGlobalBounds().width - 20 >= a[i].getGlobalBounds().left &&
            getGlobalBounds().left + 20  <= a[i].getGlobalBounds().left + a[i].getGlobalBounds().width){
        return true;



    }
    }
    }
    else{
        return false;
    }
}




bool AnimatedSprite::ret_floor(){
    return floor;
}

void AnimatedSprite::set_floor(const bool &i){
    floor = i;
}



void AnimatedSprite::set_dir(const bool &turn){
    if(turn != actual_turn){
    if(turn){
        setTexture(whole_l);
        setTextureRect(frames[6]);

        actual_turn = turn;
        frame_number = 1;

    }
    else{
        setTexture(whole_r);
        setTextureRect(frames[0]);

        actual_turn = turn;
        frame_number = 1;

    }
    }
}

void AnimatedSprite::floor_default(){
    floor = 1;
}


bool AnimatedSprite::collision_with_monster(const Monster &monster){
    if (getGlobalBounds().left < monster.getGlobalBounds().left + monster.getGlobalBounds().width &&
            getGlobalBounds().top +getGlobalBounds().height > monster.getGlobalBounds().top && getGlobalBounds().top  < monster.getGlobalBounds().top + monster.getGlobalBounds().height &&
                getGlobalBounds().left + getGlobalBounds().width > monster.getGlobalBounds().left){

        return 1;
    }
}

void AnimatedSprite::change_loosed(const bool &i){
    loosed = i;
    if(i == 1){
    y_vel = -1300;
    }
}

bool AnimatedSprite::return_turn(){
    return actual_turn;
}





































