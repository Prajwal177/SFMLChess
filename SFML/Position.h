#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Position
{
public:
	Position(sf::RectangleShape chessPieces[32], sf::Vector2f tileRect);

	void highlightMove(bool, int);
	sf::RectangleShape* hintMoves(sf::RenderWindow& );


public:
	sf::RectangleShape blueBox[64];
	int possibleMoves;

private:
	float tileWidth, tileHeight;

	int posVertical, posHorizon;
	
	int movedUp, movedRight;
	sf::RectangleShape chessItems[32];
	sf::Vector2f chessPos;//position at top left of rectangle box containing chess piece
	bool isClick; //for toggling highlighter and getting if from the main whether mouse is clicked or not
};

