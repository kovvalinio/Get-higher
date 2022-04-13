#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "included.h"


struct World {

    World(const int &fps, const std::string &path_a_r, const std::string &path_a_l,const std::string &path_p, const std::string &path_b, const std::string &sky,const float &x, const float &y );

    void draw_all(sf::RenderWindow &window);
    void move_scr(sf::Time &elapsed);
    void r_a_platf();
    bool loose();
    void game_over(sf::RenderWindow &window, sf::Text &game_o, const sf::Time &elapsed, sf::Uint32 &unicode);
    void save_record();
    void menu(sf::RenderWindow &window, const sf::Vector2i &mouse_pos);
    void set_default();
    void show_records(sf::RenderWindow &window, const sf::Vector2i &mouse_pos);
    void read_rec_from_file();
    void show_credits(sf::RenderWindow &window, const sf::Vector2i &mouse_pos);
    void sort_records();
    void loose_life(const bool &collision, const sf::Time &elapsed);
    void switch_hearts();
    void health_bar();



    Buildings build_;
    Sky sky_;
    AnimatedSprite hero_;
    Platforms platforms;
    int points = 0;
    bool switch_to_rec = 0;
    std::string player;
    sf::Text play;
    short m_p_r = 0;
    Button play_b;
    Button rec_b;
    Button cre_b;
    Button ex_b;
    Button bck_b;
    sf::Text score;
    sf::Font arial;
    std::vector<std::vector<std::string>> v_of_records;
    std::string credits;
    sf::Texture name_of_game;
    short new_rec = 1;
    Monster monster_;
    bool fight = 0;
    bool monster_spawned = 0;
    Hearts heart1;
    Hearts heart2;
    Hearts heart3;
    short lifes = 6;
    sf::Time immortality = sf::seconds(0);
    sf::RectangleShape filled_h;
    sf::RectangleShape empty_h;
    sf::Text boss_t;
    Bullet bullet_;
    int actual_plat = 0;
    sf::Text score_from_boss;



};
