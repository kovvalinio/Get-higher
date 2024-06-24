#include "Hearts.h"

Hearts::Hearts(){
    whole.loadFromFile("C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/0.bmp");
    half.loadFromFile("C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/1.bmp");
    empty.loadFromFile("C:/Users/Michal/OneDrive/Documents/Qt projects/Get higher/2.bmp");

}

void Hearts::set_heart(const short &which){
    if(which == 2){
        setTexture(whole);
    }

    if(which == 1){
        setTexture(half);
    }
    if(which == 0){
        setTexture(empty);
    }
}