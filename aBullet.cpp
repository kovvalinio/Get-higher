
#include "aBullet.h"
#include "AnimatedSprite.h"

Bullet::Bullet(){
    bullet_t1.loadFromFile("C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/bullet.png");
    bullet_t2.loadFromFile("C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/bullet1.png");
}

void Bullet::set_bullet_p(const sf::FloatRect &bounds, const bool &turn1, const sf::Time &elapsed){
    time_shot += elapsed;

    if(time_shot > sf::seconds(0.5)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            std::cout << "afaf" << std::endl;
            if(turn1 == 0 ){
                setTexture(bullet_t1);
                setPosition(bounds.left+bounds.width,bounds.top +bounds.height/2);
                turn =0;
                time_shot = sf::seconds(0);
            }
            if(turn1){
                setTexture(bullet_t2);
                setPosition(bounds.left - bullet_t2.getSize().x, bounds.top + bounds.height/2);
                turn = 1;
                time_shot = sf::seconds(0);
            }
        }
    }

}

void Bullet::animation(const sf::Time &elapsed){
    if(turn){
       vel = -1500;
    }
    if(!turn){
        vel= 1500;
    }
    move(elapsed.asSeconds()*vel,0);
}
