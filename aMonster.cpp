#include "aMonster.h"

Monster::Monster(){
    whole1.loadFromFile("C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/frame-1.png");
    whole2.loadFromFile("C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/frame-2.png");
    setScale(0.1,0.1);
    setPosition(1123, 0);
}

void Monster::animation(const sf::Time &elapsed, const Platforms &platforms, const float &hero_pos){
    time_passed += elapsed;

    y_vel = y_vel + elapsed.asSeconds()*gravity;

    if(time_passed > sf::seconds(1.0/5)){
        setTexture(whole1);
    }
    if(time_passed > sf::seconds(2.0/5)){
        setTexture(whole2);
        time_passed = sf::seconds(0);
    }

    if(collision(platforms)){
        y_vel = 0;
    }

    if(getGlobalBounds().left > hero_pos){

        if(turn == 0){

            turn = 1;

        }
        x_vel = -200;
    }
    if(getGlobalBounds().left < hero_pos){
        x_vel = 200;
        if(turn == 1){

            turn = 0;
        }

    }

    if(y_vel != 0 || x_vel != 0){
    move(x_vel*elapsed.asSeconds(),elapsed.asSeconds()*y_vel);
}
}


bool Monster::collision(const Platforms &a){
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

void Monster::spawn(){
    setPosition(20,200);
}

int Monster::return_health(){
    return health;
}


void Monster::substr_health(Bullet &bullet){

    if (getGlobalBounds().left < bullet.getGlobalBounds().left + bullet.getGlobalBounds().width &&
            getGlobalBounds().top +getGlobalBounds().height > bullet.getGlobalBounds().top && getGlobalBounds().top  <bullet.getGlobalBounds().top + bullet.getGlobalBounds().height &&
                getGlobalBounds().left + getGlobalBounds().width > bullet.getGlobalBounds().left){
        health = health -10;
        bullet.setPosition(-100,-100);

    }

}

void Monster::set_health(const int &h){
    health= h;
}
