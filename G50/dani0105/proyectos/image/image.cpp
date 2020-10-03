//
// Created by Daniel on 1/10/2020.
//

#include "image.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>

using namespace std;

char * getFont(short type){
    char* result;
    switch (type) {
        case 1:
            result = ("C:\\Windows\\fonts\\arial.ttf");
            break;
        case 2:
            result =("C:\\Windows\\fonts\\impact.ttf");
            break;
        case 3:
            result =("C:\\Windows\\fonts\\INFROMAN.TTF");
            break;
        default:
            result =("C:\\Windows\\fonts\\arial.ttf");
            break;
    }
    return result;
}

int getMiddle(int stringLength,short fontSize,int width){
    return (width/2)-(stringLength*(fontSize/2))/2;
}

int execute(char *path, char *topText, char *bottomText, short typeFont,short fontSize){

    sf::Texture texture;
    texture.loadFromFile(path);

    sf::Sprite image;
    image.setTexture(texture);

    sf::Font font;
    cout<<"Loading Font\n";
    if (!font.loadFromFile(getFont(typeFont))){
        cout<<"Error loading font\n";
       return -1;
    }

    sf::Text textTop;
    textTop.setFont(font);
    textTop.setString(topText);
    textTop.setCharacterSize(fontSize);
    textTop.setFillColor(sf::Color::White);
    int middle = getMiddle(strlen(topText),fontSize,texture.getSize().x);
    if(middle < 10){
        cout<<"Text To Long\n";
        return -1;
    }
    textTop.setPosition(middle,10);

    sf::Text textBottom;
    textBottom.setFont(font);
    textBottom.setString(bottomText);
    textBottom.setCharacterSize(fontSize);
    textBottom.setFillColor(sf::Color::White);
    middle = getMiddle(strlen(bottomText),fontSize,texture.getSize().x);
    if(middle < 10){
        cout<<"Text To Long\n";
        return -1;
    }

    textBottom.setPosition(middle,texture.getSize().y - fontSize -15);


    sf::RenderTexture render;

    render.create( texture.getSize().x,texture.getSize().y);


    cout<<"Writing text\n";
    render.draw(image);
    render.draw(textTop);
    render.draw(textBottom);

    sf::Image final;
    final = render.getTexture().copyToImage();
    final.flipVertically();
    cout<<"Saving\n";
    final.saveToFile(path);

    return 0;
}
