#include <SFML/Graphics.hpp>
#include <iostream>

class GraphicalObject
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    void loadSprite(std::string filePath)
    {
        texture.loadFromFile("assets/img/"+filePath);
        texture.setSmooth(true);
        sprite.setTexture(texture);
    }

    void setPosAndOrigin(float posX, float posY, float originX, float originY)
    {
        sprite.setPosition(posX,posY);
        sprite.setOrigin(sprite.getLocalBounds().width * originX,   //sets the origin location
                         sprite.getLocalBounds().height * originY); // origin(0,0) is left-top | origin(1,1) is right-bottom
    }

    void setScale(float scaleX,float scaleY)
    {
        //Function that changes the scale of the image if necessary
        sprite.setScale(scaleX,scaleY);
    }

    void setTextureRectangle(int posX,int posY,int sizeX, int sizeY)
    {
        //posX, posY define the beggining of the cut rectangle
        sprite.setTextureRect(sf::IntRect(posX,posY,sizeX,sizeY));
    }

    sf::Sprite returnSprite()
    {return this->sprite;}
    sf::Texture returnTexture()
    {return this->texture;}
};

class ComplexCircle
{
private:
    sf::Color color;
public:
    sf::CircleShape circle;
    void setPosAndOrigin(float posX, float posY, float originX, float originY)
    {
        circle.setPosition(posX,posY);
        circle.setOrigin(circle.getLocalBounds().width * originX,   //sets the origin location
                         circle.getLocalBounds().height * originY); // origin(0,0) is left-top | origin(1,1) is right-bottom
    }

    void setNewColor(int r, int g, int b)
    {
        color.r = r;
        color.g = g;
        color.b = b;
        circle.setFillColor(color);
    }

    void setNewCircleRadius(float radius)
    {circle.setRadius(radius);}

    sf::CircleShape returnCircle()
    {return this-> circle;}
};

class TimeGetter
{
private:
    sf::Clock clock;
    sf::Time time;
public:
    float returnTimeInSeconds()
    {
        time = clock.getElapsedTime();
        return time.asSeconds();
    }

    float returnTimeInMiliseconds()
    {
        time = clock.getElapsedTime();
        return time.asMilliseconds();
    }

};

class DisplayedText
{
private:
    sf::Font font;
    sf::Text text;
    sf::Color color;

public:
    void loadText(std::string filePath, std::string stringContent, int sizeOfText)
    {
        font.loadFromFile("assets/fonts/"+filePath);
        text.setFont(font);
        text.setString(stringContent);
        text.setCharacterSize(sizeOfText);
    }

    void setPosAndOrigin(float posX, float posY, float originX, float originY)
    {
        text.setPosition(posX,posY);
        text.setOrigin(text.getLocalBounds().width * originX,   //sets the origin location
        text.getLocalBounds().height * originY); // origin(0,0) is left-top | origin(1,1) is right-bottom
    }

    void setNewColor(int a, int b, int c)
    {
        color.r = a;
        color.b = b;
        color.g = c;
        text.setColor(color);
    }

    int returnRedColorValue()
    {return color.r;}

    int returnBlueColorValue()
    {return color.b;}

    int returnGreenColorValue()
    {return color.g;}

    sf::Text returnText()
    {return this->text;}

    sf::Font returnFont()
    {return this->font;}
};
