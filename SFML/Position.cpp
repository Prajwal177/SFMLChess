#include "Position.h"

Position::Position(sf::RectangleShape chessPieces[32],sf::Vector2f tileRect) {
	this->tileWidth = tileRect.x;
	this->tileHeight = tileRect.y;
	for (int i = 0; i < 32; i++) {
		chessItems[i] = chessPieces[i];
	}
	isClick = false;

}

sf::RectangleShape Position::highlightMove(sf::RenderWindow* window, bool isClick)
{
	this->isClick = isClick;
	if (isClick) {
		this->blueBox.setSize(sf::Vector2f(this->tileWidth, (this->tileHeight) * 2));

		chessPos.x = (chessItems[8].getPosition()).x;
		chessPos.y = (chessItems[8].getPosition()).y;
		blueBox.setOrigin(sf::Vector2f(tileWidth / 2, tileHeight / 2));
		blueBox.setPosition(sf::Vector2f(chessPos.x, chessPos.y));
		blueBox.setFillColor(sf::Color(3, 227, 252, 120));
	}
	else
	{
		blueBox.setSize(sf::Vector2f(0.f, 0.f));
		blueBox.setFillColor(sf::Color::Transparent);
	}

	return blueBox;
	
}


