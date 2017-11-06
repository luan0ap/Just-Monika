#include <SFML/Graphics.hpp>
#include <iostream>

class GraphicalObject
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    void loadSprite(std::string filePath);
    void setPosAndOrigin(float posX, float posY, float originX, float originY);
    void setScale(float scaleX,float scaleY);
    void setTextureRectangle(int posX,int posY,int sizeX, int sizeY);
    sf::Sprite returnSprite();
    sf::Texture returnTexture();
};

class ComplexCircle
{
private:
    sf::Color color;
public:
    sf::CircleShape circle;
    void setPosAndOrigin(float posX, float posY, float originX, float originY);
    void setNewColor(int r, int g, int b);
    void setNewCircleRadius(float radius);
    sf::CircleShape returnCircle();
};

class TimeGetter
{
private:
    sf::Clock clock;
    sf::Time time;
public:
    float returnTimeInSeconds();
    float returnTimeInMiliseconds();

};

class DisplayedText
{
private:
    sf::Font font;
    sf::Text text;
    sf::Text text2;
    sf::Color color;
    sf::Color color2;

public:
    void loadText(std::string filePath, std::string stringContent, int sizeOfText);
    void setPosAndOrigin(float posX, float posY, float originX, float originY);
    void setNewColor(int a, int b, int c);
    void createOutline(int sizeOfOutline, int r, int g, int b);
    int returnRedColorValue();
    int returnBlueColorValue();
    int returnGreenColorValue();
    sf::Text returnText();
    sf::Text returnTextOutline();
    sf::Font returnFont();
};
