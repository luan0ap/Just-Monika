/// TO DO LIST:
///     * Create a Menu in Scene 1
///     * Get the Assets
///     * Insteaed posX of posY try SFML Vectors
///     * Use time instead of gameWindow.setFrameLimit(150);
///
///     SCENE 1 TO DO LIST:
///         * Make multiple circles circulate - only one can circulate atm
///         * Get the font for the menu
///         * Make the createOutline work

#include "graphics.cpp"
#include <SFML/Audio.hpp>

enum SceneName{logoScreen, mainMenu};
SceneName scene = logoScreen;

int logoColor = 0, posOfCircleX=0, posOfCircleY=0;
bool sceneJustOpened = true; //firstLogoPhase

void circulateCircles(int &xCoordinate, int &yCoordinate, ComplexCircle &circle, sf::RenderWindow &window);

int main()
{
    sf::RenderWindow gameWindow(sf::VideoMode(1280, 720), "Just Monika", sf::Style::None);
    //gameWindow.setVerticalSyncEnabled(true);    //Enable vertical synchronization

    TimeGetter timer;

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
        case logoScreen:
            {
                gameWindow.clear();
                ///Scene 0 - Displaying logos scene
                //Declaring objects and setting them up
                DisplayedText slippyLogoText;
                slippyLogoText.loadText("/lato/Lato-Black.ttf", "Slipper Presents", 72);
                slippyLogoText.setPosAndOrigin(400, 250, 0, 0);
                gameWindow.setFramerateLimit(150);       //set a frame limit so that the logo displays normally



                //draw the logo until the logo is on the screen for 10 seconds
                if(slippyLogoText.returnGreenColorValue()<255 && sceneJustOpened==true)
                {
                    slippyLogoText.setNewColor(logoColor,logoColor,logoColor);
                    logoColor+=1;
                    if(logoColor == 255)
                        sceneJustOpened = false;
                }

                else if(!sceneJustOpened)
                {
                    slippyLogoText.setNewColor(logoColor,logoColor,logoColor);
                    logoColor-=1;
                    if(logoColor == 0)
                    {
                        scene = mainMenu;
                        sceneJustOpened = true;
                    }
                }
                gameWindow.draw(slippyLogoText.returnText());
                break;
            }

        case mainMenu:
            {
                gameWindow.setFramerateLimit(0);
                ///Scene 1 - Menu
                //Declaring objects and setting up the colors
                gameWindow.clear(sf::Color(255, 255, 255));

                ComplexCircle circle;
                circle.setNewCircleRadius(65);
                circle.setNewColor(255,219,240);

                GraphicalObject sideBar;    //previously mainMenu
                sideBar.loadSprite("Menu_art.png");
                sideBar.setScale(0.67, 0.67);

                GraphicalObject monika;
                monika.loadSprite("Menu_art_m.png");
                monika.setPosAndOrigin(700, 0, 0, 0);



                circulateCircles(posOfCircleX, posOfCircleY, circle, gameWindow);
                gameWindow.draw(sideBar.returnSprite());
                if(sceneJustOpened)
                {
                    DisplayedText text[4];

                    text[0].loadText("lato/Lato-Black.ttf", "Monika", 24);
                        text[0].setPosAndOrigin(50, 430, 0, 0);
                            text[0].createOutline(5, 0, 0, 0);
                    text[1].loadText("lato/Lato-Black.ttf", "Just Monika", 24);
                        text[1].setPosAndOrigin(50, 470, 0, 0);
                    text[2].loadText("lato/Lato-Black.ttf", "Only Monika", 24);
                        text[2].setPosAndOrigin(50, 510, 0, 0);
                    text[3].loadText("lato/Lato-Black.ttf", "Goodbye Monika", 24);
                        text[3].setPosAndOrigin(50, 550, 0, 0);
                    gameWindow.draw(text[0].returnTextOutline());
                    gameWindow.draw(text[0].returnText());
                    gameWindow.draw(text[1].returnText());
                    gameWindow.draw(text[2].returnText());
                    gameWindow.draw(text[3].returnText());
                }

                gameWindow.draw(monika.returnSprite());
                break;
            }

        }
        gameWindow.display();
    }

    return EXIT_SUCCESS;
}

void circulateCircles(int &xCoordinate, int &yCoordinate, ComplexCircle &circle, sf::RenderWindow &window)
{
    float xWindowSize =  window.getSize().x;
    circle.setPosAndOrigin(posOfCircleX,posOfCircleY,0,0);
    posOfCircleX++;
    if(posOfCircleX + circle.circle.getRadius()*2 > xWindowSize
    && posOfCircleX < xWindowSize)
    {
        ComplexCircle circle2;
        circle2.setNewCircleRadius(circle.circle.getRadius());
        circle2.setNewColor(255,219,240);
        circle2.setPosAndOrigin(posOfCircleX-xWindowSize, posOfCircleY, 0, 0);
        window.draw(circle2.returnCircle());
    }
    else if(posOfCircleX >= xWindowSize)
    {
        posOfCircleX = 0;
        circle.setPosAndOrigin(posOfCircleX, posOfCircleY,0,0);
    }
    window.draw(circle.returnCircle());
}
