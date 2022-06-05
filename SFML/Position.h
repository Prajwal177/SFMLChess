#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Position
{
public:
	Position(sf::RectangleShape chessPieces[32], sf::Vector2f tileRect);

	sf::RectangleShape highlightMove(sf::RenderWindow* window, bool);


public:
	sf::RectangleShape blueBox;

	sf::RenderWindow window1;

private:
	float tileWidth, tileHeight;
	
	sf::RectangleShape chessItems[32];
	sf::Vector2f chessPos;//position at top left of rectangle box containing chess piece
	bool isClick; //for toggling highlighter and getting if from the main whether mouse is clicked or not
};

