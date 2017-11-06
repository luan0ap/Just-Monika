#include <SFML/Graphics.hpp>
#include <iostream>
#include "graphics.hpp"



///GraphicalObject class methods

void GraphicalObject::loadSprite(std::string filePath)
{
    texture.loadFromFile("assets/img/"+filePath);
    texture.setSmooth(true);
    sprite.setTexture(texture);
}

void GraphicalObject::setPosAndOrigin(float posX, float posY, float originX, float originY)
{
    sprite.setPosition(posX,posY);
    sprite.setOrigin(sprite.getLocalBounds().width * originX,   //sets the origin location
                     sprite.getLocalBounds().height * originY); // origin(0,0) is left-top | origin(1,1) is right-bottom
}

void GraphicalObject::setScale(float scaleX,float scaleY)
{
    //Function that changes the scale of the image if necessary
    sprite.setScale(scaleX,scaleY);
}

void GraphicalObject::setTextureRectangle(int posX,int posY,int sizeX, int sizeY)
{
    //posX, posY define the beggining of the cut rectangle
    sprite.setTextureRect(sf::IntRect(posX,posY,sizeX,sizeY));
}

sf::Sprite GraphicalObject::returnSprite()
{return this->sprite;}

sf::Texture GraphicalObject::returnTexture()
{return this->texture;}



///ComplexCircle class methods

void ComplexCircle::setPosAndOrigin(float posX, float posY, float originX, float originY)
{
    circle.setPosition(posX,posY);
    circle.setOrigin(circle.getLocalBounds().width * originX,   //sets the origin location
                     circle.getLocalBounds().height * originY); // origin(0,0) is left-top | origin(1,1) is right-bottom
}

void ComplexCircle::setNewColor(int r, int g, int b)
{
    color.r = r;
    color.g = g;
    color.b = b;
    circle.setFillColor(color);
}

void ComplexCircle::setNewCircleRadius(float radius)
{circle.setRadius(radius);}

sf::CircleShape ComplexCircle::returnCircle()
{return this-> circle;}



///TimeGetter class methods

float TimeGetter::returnTimeInSeconds()
{
    time = clock.getElapsedTime();
    return time.asSeconds();
}

float TimeGetter::returnTimeInMiliseconds()
{
    time = clock.getElapsedTime();
    return time.asMilliseconds();
}



///DisplayedText class methods

void DisplayedText::loadText(std::string filePath, std::string stringContent, int sizeOfText)
{
    font.loadFromFile("assets/fonts/"+filePath);
    text.setFont(font);
    text.setString(stringContent);
    text.setCharacterSize(sizeOfText);
}

void DisplayedText::setPosAndOrigin(float posX, float posY, float originX, float originY)
{
    text.setPosition(posX,posY);
    text.setOrigin(text.getLocalBounds().width * originX,   //sets the origin location
                   text.getLocalBounds().height * originY); // origin(0,0) is left-top | origin(1,1) is right-bottom
}

void DisplayedText::setNewColor(int a, int b, int c)
{
    color.r = a;
    color.b = b;
    color.g = c;
    text.setColor(color);
}

void DisplayedText::createOutline(int sizeOfOutline, int r, int g, int b)
{
    text2.setFont(font);
    text2.setString(text.getString());
    text2.setCharacterSize(text.getCharacterSize() + sizeOfOutline);
    color2.r = r;
    color2.g = g;
    color2.b = b;
    text2.setColor(color2);
    text2.setPosition(text.getPosition().x,text.getPosition().y);
}

int DisplayedText::returnRedColorValue(){return color.r;}
int DisplayedText::returnBlueColorValue(){return color.b;}
int DisplayedText::returnGreenColorValue(){return color.g;}

sf::Text DisplayedText::returnText(){return this->text;}
sf::Text DisplayedText::returnTextOutline(){return this->text2;}
sf::Font DisplayedText::returnFont(){return this->font;}
