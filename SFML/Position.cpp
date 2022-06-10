#include "Position.h"

Position::Position(sf::RectangleShape chessPieces[32],sf::Vector2f tileRect) {
	this->tileWidth = tileRect.x;
	this->tileHeight = tileRect.y;
	for (int i = 0; i < 32; i++) {
		chessItems[i] = chessPieces[i];
	}
	isClick = false;
	possibleMoves = 1;
	chessNo = 0;
}

enum {
	pawn = 1, horse
};

void Position::highlightMove(bool isClick, int pieceNo, int color)
{
	this->isClick = isClick;
	if (isClick) {
		blueBox = new sf::RectangleShape[32];

		chessPos.x = (chessItems[pieceNo].getPosition()).x;
		chessPos.y = (chessItems[pieceNo].getPosition()).y;

		if (pieceNo == 1 || pieceNo == 6 || pieceNo == 25 || pieceNo == 30) {
			chessNo = horse;

			posVertical = (color == 1 ? -2 : 2);
			posHorizon = 1;
			possibleMoves = 3;
		}

		if (pieceNo > 7 && pieceNo < 24) {
			chessNo = pawn;
			
			posVertical = (color == 1 ? -1:1);
			posHorizon = 0;
			
	
			possibleMoves = 3;
		}
		movedUp = 0, movedRight = 0;
		for (int i = 0; i < possibleMoves; i++)
		{
			
			this->blueBox[i].setSize(sf::Vector2f(this->tileWidth, this->tileHeight));
			blueBox[i].setOrigin(sf::Vector2f(tileWidth / 2, tileHeight / 2));
			blueBox[i].setPosition(sf::Vector2f(chessPos.x + (tileWidth * movedRight), 
				chessPos.y + (tileHeight * movedUp)));
			blueBox[i].setFillColor(sf::Color(3, 227, 252, 120));
			switch (chessNo)
			{
			case pawn:
				movedRight += posHorizon;
				movedUp += posVertical;
				break;

			case horse:
				movedRight += (i % 2 == 0 ? posHorizon : ( - 2 * posHorizon));
				movedUp += (i % 2 == 0 ? posVertical : 0);
				break;
			default:
				break;
			}

		}
		
	}
	else
	{
		delete[] blueBox;
	}
}


