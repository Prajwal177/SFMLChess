#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include "chesspieces.h"
#include "Position.h"

int main()
{
    float screenWidth = 1024.f, screenHeight = 768.f;
 
    sf::RenderWindow window(sf::VideoMode((int)screenWidth, (int)screenHeight), "Chess",
        sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    sf::RectangleShape board(sf::Vector2f(screenWidth,screenHeight));
    board.setOrigin((float)screenWidth/2, (float)screenHeight/2);
    board.setPosition((float)screenWidth / 2, (float)screenHeight / 2);
    sf::Texture boardTexture;
    boardTexture.loadFromFile("assets/chessboard.png");
    board.setTexture(&boardTexture);

    sf::Texture itemTexture;
    itemTexture.loadFromFile("assets/chesspieces.png");
    int imgRow; //for passing into a function and for selecting different pieces of image segments 
    bool flag; //flag whether to add pieces or not

    chesspieces pcs(&itemTexture, sf::Vector2f(6, 2), sf::Vector2f(screenWidth, screenHeight));

    

    sf::RectangleShape* allpieces;
    allpieces = new sf::RectangleShape[32];
    int pieceCount = 0; //counts all the pieces starting from zero
    for (int boardRow = 0; boardRow < 8; boardRow++) {
        for (int boardCol = 0; boardCol < 8; boardCol++) {

            

            flag = 0;
            if (boardRow == 0 || boardRow == 1)
            {
                imgRow = 0;
                flag = 1;
            }

            else if (boardRow == 6 || boardRow == 7)
            {
                imgRow = 1;
                flag = 1;
            }
            //draw chess pieces and what color
            if (flag == 1) {
                allpieces[pieceCount] = pcs.addPieces(boardRow, boardCol, imgRow);
                //used png has segments of 2 rows & 6 columns
                //rows are 0 & 1
                pieceCount++;
            }
        }
    }

    std::cout << allpieces[8].getPosition().x<<","<<allpieces[8].getPosition().y;
    Position pos1(allpieces,sf::Vector2f(screenWidth/8, screenHeight/8));


    //For toggling mouse clicks on next move highlighter
    static bool isClicked = false;
    sf::Vector2i mousePos;
    sf::Vector2f translatedMPos;
    

    while (window.isOpen())
    {
        //event polling
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (ev.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }
        }

        //Update
        mousePos = sf::Mouse::getPosition(window);
        translatedMPos = window.mapPixelToCoords(mousePos);
        if (allpieces[8].getGlobalBounds().contains(translatedMPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (isClicked)
            {
                isClicked = false;
            }
            else
            {
                isClicked = true;
            }
        }

        //Draw game
        window.clear(sf::Color::Black); //clearing frames


        window.draw(board);

        window.draw(pos1.highlightMove(&window, isClicked));

        //adding chesspieces to the board

        for (int i = 0; i < pieceCount; i++)
        {
            window.draw(allpieces[i]);
        }

        

        //Render
        
        window.display();
    }

    return 0;
}