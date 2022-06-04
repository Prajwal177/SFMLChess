#include "Position.h"

Position::Position(sf::RectangleShape chessPieces[32],sf::Vector2f tileRect) {
	this->tileWidth = tileRect.x;
	this->tileHeight = tileRect.y;
	for (int i = 0; i < 32; i++) {
		chessItems[i] = chessPieces[i];
	}
	this->blueBox.setSize(sf::Vector2f(this->tileWidth, this->tileHeight));
	blueBox.setFillColor(sf::Color(3, 227, 252, 170));

}

void Position::listenInput(sf::RenderWindow* window)
{
	mousePos = sf::Mouse::getPosition(*window);
	translatedMPos = window->mapPixelToCoords(mousePos);
	if (chessItems[8].getGlobalBounds().contains(translatedMPos) && sf::Mouse::isButtonPressed
		&& sf::Mouse::Left)
	{
		chessPos.x = (chessItems[8].getPosition()).x - (tileWidth/2);
		chessPos.y = (chessItems[8].getPosition()).y - (tileHeight / 2);
		blueBox.setPosition(chessPos + sf::Vector2f(0,tileHeight));
	}
}

void Position::highlightMove()
{
	sf::RenderWindow window1;

	window1.clear();
	window1.draw(blueBox);
	
}
