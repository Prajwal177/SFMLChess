#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Position
{
public:
	Position(sf::RectangleShape chessPieces[32], sf::Vector2f tileRect);

	void listenInput(sf::RenderWindow* window);

	void highlightMove();

public:
	sf::RectangleShape blueBox;


private:
	float tileWidth, tileHeight;
	sf::Vector2i mousePos;
	sf::Vector2f translatedMPos;
	sf::RectangleShape chessItems[32];
	sf::Vector2f chessPos;//position at top left of rectangle box containing chess piece
};

