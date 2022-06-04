#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class chesspieces
{
public:
	chesspieces(sf::Texture*,sf::Vector2f, sf::Vector2f);

	chesspieces(sf::Vector2i, sf::Vector2f);

	sf::RectangleShape addPieces(int, int, int);

public:
	sf::Texture* texture;
	float itemWidth, itemHeight;

private:
	sf::Vector2f imgCount;
	sf::Vector2f boardSize;
	bool isPawn;
	int imgSelect;
	
};

