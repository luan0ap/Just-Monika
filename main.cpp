/// TO DO LIST:
///     * Create a Menu in Scene 1
///     * Get the Assets
///     * Change the scene into an enum
///     * Insteaed posX of posY try SFML Vectors
///     * Use time instead of gameWindow.setFrameLimit(150);
///
///     SCENE 1 TO DO LIST:
///         * Make multiple circles circulate - only one can circulate atm
///         * Create the left background
///         * Get the font for the menu

#include "graphics.h"

int scene=0, logoColor = 0, posOfCircleX=0, posOfCircleY=0;
bool firstLogoPhase = true;

void circulateCircles(int &xCoordinate, int &yCoordinate, ComplexCircle &circle, sf::RenderWindow &window);

int main()
{
    sf::RenderWindow gameWindow(sf::VideoMode(1280, 720), "Just Monika", sf::Style::None);

    TimeGetter logoLoadTimer;

    while (gameWindow.isOpen())
    {
        ///Event loop
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();
        }

        switch(scene)
        {
        case 0:
            {
                gameWindow.clear();
                ///Scene 0 - Displaying logos scene
                //Declaring objects and setting them up
                DisplayedText slippyLogoText;
                slippyLogoText.loadText("/lato/Lato-Black.ttf", "Slipper Presents", 72);
                slippyLogoText.setPosAndOrigin(400, 250, 0, 0);
                gameWindow.setFramerateLimit(150);       //set a frame limit so that the logo displays normally

                //draw the logo until the logo is on the screen for 10 seconds
                if(slippyLogoText.returnGreenColorValue()<255 && firstLogoPhase==true)
                {
                    slippyLogoText.setNewColor(logoColor,logoColor,logoColor);
                    logoColor+=1;
                    if(logoColor == 255)
                        firstLogoPhase = false;
                }

                else if(!firstLogoPhase)
                {
                    slippyLogoText.setNewColor(logoColor,logoColor,logoColor);
                    logoColor-=1;
                    if(logoColor == 0)
                        scene = 1;
                }

                gameWindow.draw(slippyLogoText.returnText());
                break;
            }
        case 1:
            ///Scene 1 - Menu
            //Declaring objects and setting up the colors
            gameWindow.clear(sf::Color(255, 255, 255));
            ComplexCircle circle;
            circle.setNewCircleRadius(65);
            circle.setNewColor(255,219,240);
            GraphicalObject mainMenu;
            mainMenu.loadSprite("Menu_art.png");
            mainMenu.setScale(0.67, 0.67);

            circulateCircles(posOfCircleX, posOfCircleY, circle, gameWindow);
            gameWindow.draw(mainMenu.returnSprite());



            break;


        }
        gameWindow.display();
    }

    return EXIT_SUCCESS;
}

void circulateCircles(int &xCoordinate, int &yCoordinate, ComplexCircle &circle, sf::RenderWindow &window)
{
    circle.setPosAndOrigin(posOfCircleX,posOfCircleY,0,0);
    posOfCircleX++;
    if(circle.circle.getPosition().x + circle.circle.getRadius()*2 > window.getSize().x
    && circle.circle.getPosition().x < window.getSize().x)
    {
        ComplexCircle circle2;
        circle2.setNewCircleRadius(circle.circle.getRadius());
        circle2.setNewColor(255,219,240);
        circle2.setPosAndOrigin(posOfCircleX-(float)(window.getSize().x), posOfCircleY, 0, 0);
        window.draw(circle2.returnCircle());
    }
    else if(circle.circle.getPosition().x >= window.getSize().x)
    {
        posOfCircleX = 0;
        circle.setPosAndOrigin(posOfCircleX, posOfCircleY,0,0);
    }
    window.draw(circle.returnCircle());
}
