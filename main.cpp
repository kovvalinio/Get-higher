#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include "AnimatedSprite.h"
#include "Platforms.h"
#include <memory>
#include "World.h"
#include <iostream>



using namespace std;

HWND hWnd = GetConsoleWindow();



int main()
{   ShowWindow( hWnd, SW_HIDE );

    sf::RenderWindow window(sf::VideoMode(800, 600), "Get higher!");






    sf::Clock clock;
    sf::Time time;




    World world(10, "C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/sprites.png",
                "C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/sprites1.png",
                "C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/ground0 copy.png",
                "C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/buildings-layer.png",
                "C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/Sky-layer.png",
                window.getSize().x,window.getSize().y);


    world.hero_.add_animation_frame(sf::IntRect(0, 2, 85, 98));
    world.hero_.add_animation_frame(sf::IntRect(85, 2, 85, 98)); // hero running frame 1
    world.hero_.add_animation_frame(sf::IntRect(170, 2, 85, 98)); // hero running frame 1
    world.hero_.add_animation_frame(sf::IntRect(255, 2, 85, 98)); // hero running frame 1
    world.hero_.add_animation_frame(sf::IntRect(340, 2, 85, 98)); // hero running frame 1
    world.hero_.add_animation_frame(sf::IntRect(425, 2, 85, 98));

    world.hero_.add_animation_frame(sf::IntRect(515, 2, 85, 98));
    world.hero_.add_animation_frame(sf::IntRect(430, 2, 85, 98)); // hero running frame 1
    world.hero_.add_animation_frame(sf::IntRect(345, 2, 85, 98)); // hero running frame 1
    world.hero_.add_animation_frame(sf::IntRect(260, 2, 85, 98)); // hero running frame 1
    world.hero_.add_animation_frame(sf::IntRect(175, 2, 85, 98)); // hero running frame 1
    world.hero_.add_animation_frame(sf::IntRect(90, 2, 85, 98)); // hero running frame 1

    sf::Text game_over;
    game_over.setFont(world.arial);
    game_over.setString("Game over");
    game_over.setColor(sf::Color::Black);
    game_over.setCharacterSize(100);
    game_over.setOrigin(game_over.getLocalBounds().width/2,game_over.getLocalBounds().height/2);
    game_over.setPosition(window.getSize().x/2,-100);







    while (window.isOpen()) {
        sf::Uint32 unicode = 0;
        sf::Event event;
        sf::Vector2i mouse_pos;


        time = clock.restart();

        mouse_pos = sf::Mouse::getPosition(window);


        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::TextEntered){
                unicode = event.text.unicode;

            }


        }

        if(world.m_p_r == 0){
            world.menu(window, mouse_pos);
            game_over.setPosition(window.getSize().x/2,-100);
        }




        if(world.m_p_r == 1){

            world.draw_all(window);
            world.bullet_.set_bullet_p(world.hero_.getGlobalBounds(),world.hero_.return_turn(),time);
            world.bullet_.animation(time);
            world.monster_.substr_health(world.bullet_);
            world.hero_.moving(time, window, world.hero_.collision(world.platforms));
            world.hero_.animation(time);
            world.monster_.animation(time, world.platforms, world.hero_.getPosition().x);
            world.r_a_platf();
            world.loose_life(world.hero_.collision_with_monster(world.monster_),time);
            world.move_scr(time);
                if(world.loose()){

                    world.game_over(window,game_over,time,unicode);
                }
        }

        if(world.m_p_r == 2){
            world.show_records(window,mouse_pos);
        }
        if(world.m_p_r == 3){
            world.show_credits(window,mouse_pos);
        }
        if(world.m_p_r == 4){
           return 0;
        }


        window.display();


    }



}
