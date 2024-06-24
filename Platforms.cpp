#include "Platforms.h"

Platforms::Platforms(const std::string &path){
    srand(135134*time(NULL));
    platf_r.emplace_back(sf::IntRect(0,0,256,128));
    platf_r.emplace_back(sf::IntRect(0,0,384,128));
    platf_r.emplace_back(sf::IntRect(0,0,512,128));
    platf_r.emplace_back(sf::IntRect(0,0,2667,128));

if(whole.loadFromFile(path)){
    whole.setRepeated(true);
for(int i = 0 ; i < 5 ; i++){
    sf::Sprite platform;
    platform.setTexture(whole);
    platform.setScale(0.3,0.3);
    platform.setTextureRect(platf_r[rand() % 3]);
    platform.setPosition((rand() % (800-static_cast<int>(platform.getGlobalBounds().width))) , 400 - 200*i);
    emplace_back(platform);
}
level = 5;
}
}
void Platforms::add_new(const float &y){
    sf::Sprite platform;
    platform.setTexture(whole);
    platform.setScale(0.3,0.3);
    if(level % 10 == 0){
        platform.setTextureRect(platf_r[3]);
        platform.setPosition(0, y - 200);
        emplace_back(platform);

    }
    else{
    platform.setTextureRect(platf_r[rand() % 3]);
    platform.setPosition((rand() % (800 - static_cast<int>(platform.getGlobalBounds().width))), y - 200);
    emplace_back(platform);
    }
    level = level + 1;
}
int Platforms::return_l(){
    return level - 5;
}
void Platforms::level_defaul(){
    level = 5;
    for(int i = 0 ; i < size(); i++){
        erase(begin());
        sf::Sprite platform;
        platform.setTexture(whole);
        platform.setScale(0.3,0.3);
        platform.setTextureRect(platf_r[rand() % 3]);
        platform.setPosition((rand() % (800-static_cast<int>(platform.getGlobalBounds().width))) , 400 - 200*i);
        emplace_back(platform);

    }
}