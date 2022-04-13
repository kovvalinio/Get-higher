#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>






class Bullet : public sf::Sprite{
public:
    Bullet();

    void animation(const sf::Time &elapsed);
    void set_bullet_p(const sf::FloatRect &bounds, const bool &turn1, const sf::Time &elapsed);
private:
    sf::Texture bullet_t1;
    sf::Texture bullet_t2;
    bool turn;
    float vel;
    sf::Time time_shot = sf::seconds(2);
};
