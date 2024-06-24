#include "World.h"
#include <fstream>
#include <string>
#include "Button.h"
#include <algorithm>

World::World(const int &fps, const std::string &path_a_r, const std::string &path_a_l, const std::string &path_p, const std::string &path_b, const std::string &sky,const float &x, const float &y ): sky_(sky,x,y),build_(path_b,x), hero_(fps,path_a_r,path_a_l), platforms(path_p){
arial.loadFromFile("C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/Arial.ttf");
name_of_game.loadFromFile("C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/gethigher.png");
heart1.setPosition(764,0);
heart2.setPosition(728,0);
heart3.setPosition(692,0);
score_from_boss.setString("+50 000!");
score_from_boss.setFont(arial);
score_from_boss.setFillColor(sf::Color::Black);
score_from_boss.setPosition(-300,100);
}

void World::draw_all(sf::RenderWindow &window){
    score.setFont(arial);
    std::string scr = "Score: ";
    scr += std::to_string(points);
    score.setString(scr);
    score.setCharacterSize(18);

    window.clear(sf::Color::Black);
    window.draw(sky_);
    window.draw(build_);
    window.draw(bullet_);
    window.draw(score_from_boss);

    switch_hearts();

    for(int i = 0 ; i < platforms.size() ; i++){
    window.draw(platforms[i]);
    }

    if(fight){
        if(!monster_spawned){
            monster_.spawn();
            monster_.set_health(100);
            monster_spawned = 1;
        }
        window.draw(monster_);
        health_bar();
        window.draw(filled_h);
        window.draw(empty_h);
        window.draw(boss_t);
    }


    window.draw(hero_);
    window.draw(score);

    window.draw(heart1);
    window.draw(heart2);
    window.draw(heart3);
}

void World::move_scr(sf::Time &elapsed){
    score_from_boss.move(0,elapsed.asSeconds()*(-50));

    if(fight){
        if(monster_.return_health() == 0){
            fight = 0;
            monster_spawned = 0;
            points += 50000;
            score_from_boss.setPosition(30,100);
        }
    }
    if(actual_plat < platforms.return_l() && platforms.return_l() % 10 == 0 && platforms.return_l() != 0 && platforms[0].getGlobalBounds().top + platforms[0].getGlobalBounds().height > 600){
        std::cout <<platforms.return_l() <<std::endl;
        actual_plat = platforms.return_l();
        fight = 1;

    }


    if(!fight){

    if(hero_.getGlobalBounds().top < 180){
        for(int i = 0 ; i < platforms.size() ; i++){
            platforms[i].move(0,200*elapsed.asSeconds());

        }
        hero_.move(0,200*elapsed.asSeconds());
        points += 30*200*elapsed.asSeconds();

        if(hero_.getGlobalBounds().top < 100){
            for(int i = 0 ; i < platforms.size() ; i++){
                platforms[i].move(0,200*elapsed.asSeconds());

            }
            hero_.move(0,200*elapsed.asSeconds());
            points += 30*200*elapsed.asSeconds();
        }

        if(hero_.ret_floor()){
            hero_.set_floor(0);
        }
    }
    }
}

void World::r_a_platf(){
    if(platforms[0].getGlobalBounds().top + platforms[0].getGlobalBounds().height >620){
    platforms.erase(platforms.begin());
    platforms.add_new(platforms[4].getGlobalBounds().top);
    }

}

bool World::loose(){
    if(hero_.getGlobalBounds().top > 1500){
        return 1;
    }
}

void World::game_over(sf::RenderWindow &window,sf::Text &game_o, const sf::Time &elapsed, sf::Uint32 &unicode){

    if(switch_to_rec){

    std::string enter_name = "Enter your name: ";

    sf::Text press_enter;
    press_enter.setString("Enter - continue");
    press_enter.setColor(sf::Color::Black);
    press_enter.setFont(arial);
    press_enter.setOrigin(press_enter.getLocalBounds().width,press_enter.getLocalBounds().height);
    press_enter.setPosition(window.getSize().x-10,window.getSize().y-10);

        if(unicode != 0 && unicode != 8 && unicode != 13 && unicode != 58){


            player += (char)unicode;


        }
        else if(unicode == 8){
            if(player.length() > 0){
            player.erase(player.begin() + player.length()-1);
            }

        }
        else if(unicode == 13){
            save_record();
        }

        enter_name += player;

        play.setFont(arial);
        play.setString(enter_name);
        play.setColor(sf::Color::Black);
        play.setOrigin(play.getLocalBounds().width/2,play.getLocalBounds().height/2);
        play.setPosition(window.getSize().x/2,window.getSize().y/2);
        window.draw(play);
        window.draw(press_enter);
    }

    if(game_o.getGlobalBounds().top + game_o.getGlobalBounds().height/2 < window.getSize().y/3){
    game_o.move(0,elapsed.asSeconds()*200);
    }

    else{
        switch_to_rec = 1;
    }

    window.draw(game_o);

}

void World::save_record(){
    std::fstream file;
    file.open("records.txt", std::ios::app );
    if(player.length() == 0){
        std::cout<< "Error" << std::endl;
    }
    else{
    if(file.is_open()){
        std::cout <<  "file opened correctly" << std::endl;
    }
    file << player << ":" << std::to_string(points) << std::endl;
    file.close();
    m_p_r = 0;
    new_rec = 1;
}
}

void World::menu(sf::RenderWindow &window, const sf::Vector2i &mouse_pos){
    window.clear(sf::Color::Black);
    window.draw(sky_);
    window.draw(build_);

    sf::Sprite title_s;
    title_s.setTexture(name_of_game);
    title_s.setOrigin(title_s.getLocalBounds().width/2,title_s.getLocalBounds().height/2);
    title_s.setPosition(window.getSize().x/2,window.getSize().y/2-100);
    window.draw(title_s);

    play_b.swich_scr(m_p_r,mouse_pos);
    rec_b.swich_scr(m_p_r,mouse_pos);
    cre_b.swich_scr(m_p_r,mouse_pos);
    ex_b.swich_scr(m_p_r,mouse_pos);

    play_b.set_type(0);
    play_b.setOrigin(play_b.getLocalBounds().width/2,play_b.getLocalBounds().height/2);
    play_b.setPosition(window.getSize().x/2,window.getSize().y/2);

    rec_b.set_type(1);
    rec_b.setOrigin(rec_b.getLocalBounds().width/2,rec_b.getLocalBounds().height/2);
    rec_b.setPosition(window.getSize().x/2,window.getSize().y/2+30);

    cre_b.set_type(2);
    cre_b.setOrigin(cre_b.getLocalBounds().width/2,cre_b.getLocalBounds().height/2);
    cre_b.setPosition(window.getSize().x/2,window.getSize().y/2+60);

    ex_b.set_type(3);
    ex_b.setOrigin(ex_b.getLocalBounds().width/2,ex_b.getLocalBounds().height/2);
    ex_b.setPosition(window.getSize().x/2,window.getSize().y/2+90);

    if(m_p_r == 1){
        set_default();
    }

    window.draw(play_b);
    window.draw(rec_b);
    window.draw(cre_b);
    window.draw(ex_b);

}


void World::set_default(){
    hero_.setPosition(0,400);
    hero_.floor_default();
    platforms.level_defaul();
    switch_to_rec = 0;
    player.clear();
    heart1.set_heart(2);
    heart2.set_heart(2);
    heart3.set_heart(2);
    monster_.setPosition(344, 233);
    monster_spawned=0;
    fight = 0;
    hero_.change_loosed(0);
    points = 0;
    lifes = 6;
}

void World::show_records(sf::RenderWindow &window, const sf::Vector2i &mouse_pos){
    window.draw(sky_);
    window.draw(build_);

    std::string records_to_show;

    sf::Text rec;
    rec.setFont(arial);
    rec.setColor(sf::Color::Black);

    bck_b.set_type(4);
    bck_b.setOrigin(bck_b.getLocalBounds().width,bck_b.getLocalBounds().height);
    bck_b.setPosition(window.getSize().x-10,window.getSize().y-10);
    bck_b.swich_scr(m_p_r, mouse_pos);


    if(new_rec){
        read_rec_from_file();
        if(v_of_records.size() !=0){
            sort_records();
        }
        new_rec = 0;

    }
    if(v_of_records.size() == 0){
        rec.setString("No data");
    }
    else if(v_of_records.size() !=0){


        for(int i = 0 ; i < v_of_records.size() ; i++){

            records_to_show += std::to_string(i+1) + ". ";
            records_to_show += v_of_records[i][0];
            records_to_show += "\t\t\t\t";
            records_to_show += v_of_records[i][1];
            records_to_show += "\n";
        }
        rec.setString(records_to_show);
    }
    window.draw(rec);
    window.draw(bck_b);
}

void World::read_rec_from_file(){
    std::fstream file;

    file.open("records.txt", std::ios::in);

    if(file.is_open()){
        std::cout << "file opened correctly" << std::endl;
    }

    v_of_records.clear();

    std::string line;

    while(!file.eof()){
        std::getline(file, line);
        int pos;

        pos = line.find(':');

        std::vector<std::string> score_a_name;

            if(pos != line.npos){
            score_a_name.emplace_back(line.substr(0,pos));
            score_a_name.emplace_back(line.substr(pos+1, line.length()));
            v_of_records.emplace_back(score_a_name);
            score_a_name.erase(score_a_name.begin());
            score_a_name.erase(score_a_name.begin());

            }
    }
    file.close();
}

void World::show_credits(sf::RenderWindow &window, const sf::Vector2i &mouse_pos){
    window.draw(sky_);
    window.draw(build_);
    window.draw(bck_b);

    sf::Text credits_to_show;

    if(credits.length()==0){
        credits += "The graphics used to create this game has been based on a free copyright licence.\nAuthors of graphics:\n-Marta Nowaczyk\n-irmirx\n-ansimuz\n-flamingtext\n-bevouliin.com\n-TokyoGeisha";
    }

    bck_b.set_type(4);
    bck_b.setOrigin(bck_b.getLocalBounds().width,bck_b.getLocalBounds().height);
    bck_b.setPosition(window.getSize().x-10,window.getSize().y-10);
    bck_b.swich_scr(m_p_r, mouse_pos);

    credits_to_show.setFont(arial);
    credits_to_show.setColor(sf::Color::Black);
    credits_to_show.setString(credits);
    credits_to_show.setCharacterSize(18);
    window.draw(credits_to_show);
}

bool sort(const std::vector<std::string> &i, const std::vector<std::string> &k){

if(std::stoi(i[1]) > std::stoi(k[1])){
    return true;
}
else{
    return false;
}
}

void World::sort_records(){
    std::sort(v_of_records.begin(), v_of_records.end(), sort);
}

void World::loose_life(const bool &collision, const sf::Time &elapsed){
   if(monster_spawned){

    if(immortality > sf::seconds(0)){
        immortality = immortality - elapsed;
    }

    if(immortality < sf::seconds(0)){

        immortality = sf::seconds(0);
    }

    if(immortality == sf::seconds(0)){
    if(lifes != 0){
        if(collision){
            lifes = lifes -1;
            immortality = sf::seconds(1);
        }
    }
    }
   }

}

void World::switch_hearts(){
    if(lifes == 5){
        heart1.set_heart(1);
        std::cout << "g" <<std::endl;
    }
    if(lifes == 4){
        heart1.set_heart(0);
    }
    if(lifes == 3){
        heart2.set_heart(1);
    }
    if(lifes ==2){
        heart2.set_heart(0);
    }
    if(lifes == 1){
        heart3.set_heart(1);
    }
    if(lifes <= 0){
        heart3.set_heart(0);
        hero_.change_loosed(1);
        lifes = 6;
    }
}

void World::health_bar(){
    sf::Vector2f filled;
    sf::Vector2f empty;
    filled.x = 3*static_cast<float>(monster_.return_health());
    filled.y = static_cast<float>(40);
    empty.x = 3*static_cast<float>(100-monster_.return_health());
    empty.y = static_cast<float>(40);
    filled_h.setSize(filled);
    empty_h.setSize(empty);
    filled_h.setPosition(250,5);
    empty_h.setPosition(filled_h.getGlobalBounds().left + filled_h.getGlobalBounds().width,5);
    filled_h.setFillColor(sf::Color::Green);
    empty_h.setFillColor(sf::Color::Red);
    boss_t.setFont(arial);
    boss_t.setString("Boss's health");
    boss_t.setOrigin(boss_t.getLocalBounds().width/2,boss_t.getLocalBounds().height/2);
    boss_t.setPosition(400,22);
    boss_t.setFillColor(sf::Color::Black);

}