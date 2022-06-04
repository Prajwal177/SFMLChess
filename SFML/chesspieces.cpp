#include "chesspieces.h"
#include <iostream>

chesspieces::chesspieces(sf::Texture *texture, sf::Vector2f imgCount, sf::Vector2f boardSize) {
	this->imgCount = imgCount;
	this->boardSize = boardSize;
    this->texture = texture;
    this->imgSelect = 0;
    this->isPawn = true;
    
}

sf::RectangleShape chesspieces::addPieces(int bRow, int bCol, int row)
{
    itemWidth = boardSize.x / 10, itemHeight = boardSize.y / 8;

    sf::RectangleShape chessItem(sf::Vector2f(itemWidth, itemHeight));
    chessItem.setOrigin(itemWidth / 2, itemHeight / 2);
    chessItem.setPosition((boardSize.x / (8 * 2))+ ((boardSize.x*2 / (8 * 2)) * bCol),
        (boardSize.y / (8 * 2)) + ((boardSize.y*2 / (8 * 2)) * bRow));
    
    chessItem.setTexture(texture);
    sf::Vector2u itemTextureSize = texture->getSize();
    itemTextureSize.x /= (int)imgCount.x;
    itemTextureSize.y /= (int)imgCount.y;
    isPawn = 0;
    //since our image file have pieces in random order, manually setting value using switch case
    if (bRow == 1 || bRow == 6)
    {
        isPawn = true;
        imgSelect = 5;
        //for excluding case for pawns since all chess pieces in front row are pawn on both side
        //this bool is set to true to give switch message that to select pawn or not from the image segment
    }
    if(!isPawn)
        switch (bCol)
        {
            case 0:
                imgSelect = 4;
                break;
            case 1:
                imgSelect = 3;
                break;
            case 2:
                imgSelect = 2;
                break;
            case 3:
                imgSelect = 0;
                break;
            case 4:
                imgSelect = 1;
                break;
            case 5:
                imgSelect = 2;
                break;
            case 6:
                imgSelect = 3;
                break;
            case 7:
                imgSelect = 4;
                break;
            default:
                break;
        }

    chessItem.setTextureRect(sf::IntRect(itemTextureSize.x * imgSelect, itemTextureSize.y * row,
        itemTextureSize.x, itemTextureSize.y));
	return chessItem;

}


