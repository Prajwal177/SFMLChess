#include "Position.h"

Position::Position(sf::RectangleShape chessPieces[32],sf::Vector2f tileRect) {
	this->tileWidth = tileRect.x;
	this->tileHeight = tileRect.y;
	for (int i = 0; i < 32; i++) {
		chessItems[i] = chessPieces[i];
	}
	isClick = false;

}

sf::RectangleShape Position::highlightMove(sf::RenderWindow* window, bool isClick, int pieceNo)
{
	this->isClick = isClick;
	if (isClick) {
		
		chessPos.x = (chessItems[pieceNo].getPosition()).x;
		chessPos.y = (chessItems[pieceNo].getPosition()).y;

		if (pieceNo > 7 && pieceNo < 16) {
			this->blueBox.setSize(sf::Vector2f(this->tileWidth, (this->tileHeight) * 3));
		}
		if (pieceNo > 15 && pieceNo < 24)
		{
			this->blueBox.setSize(sf::Vector2f(this->tileWidth, -(this->tileHeight) * 3));
			chessPos.y += tileHeight;
		}

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


