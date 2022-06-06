#include "Position.h"

Position::Position(sf::RectangleShape chessPieces[32],sf::Vector2f tileRect) {
	this->tileWidth = tileRect.x;
	this->tileHeight = tileRect.y;
	for (int i = 0; i < 32; i++) {
		chessItems[i] = chessPieces[i];
	}
	isClick = false;
	possibleMoves = 1;

}


void Position::highlightMove(bool isClick, int pieceNo)
{
	this->isClick = isClick;
	if (isClick) {
		
		chessPos.x = (chessItems[pieceNo].getPosition()).x;
		chessPos.y = (chessItems[pieceNo].getPosition()).y;


		if (pieceNo > 7 && pieceNo < 16) {
			posVertical = 1;
			posHorizon = 0;

			possibleMoves = 3;
		}
		if (pieceNo > 15 && pieceNo < 24)
		{
			posVertical = -1;
			posHorizon = 0;
			possibleMoves = 3;
		}
		movedUp = 0, movedRight = 0;
		for (int i = 0; i < possibleMoves; i++)
		{
			
			this->blueBox[i].setSize(sf::Vector2f(this->tileWidth, this->tileHeight));
			blueBox[i].setOrigin(sf::Vector2f(tileWidth / 2, tileHeight / 2));
			blueBox[i].setPosition(sf::Vector2f(chessPos.x + (tileWidth * movedRight), chessPos.y + (tileHeight * movedUp)));
			blueBox[i].setFillColor(sf::Color(3, 227, 252, 120));
			movedRight += posHorizon;
			movedUp += posVertical;

		}
		
	}
}



