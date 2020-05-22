#include "player.h"

// Implement functions / constructors etc. here



player::player(sf::Vector2f position, std::string rightFileLoc, std::string jumpFileLoc,std::string leftFileLoc){

	rightTexture.loadFromFile(rightFileLoc);
	jumpingTexture.loadFromFile(jumpFileLoc);
	leftTexture.loadFromFile(leftFileLoc);


	moveRight[0] = sf::IntRect(0, 0, 22, 30);
	moveRight[1] = sf::IntRect(0, 30, 29, 32);
	moveRight[2] = sf::IntRect(30, 30, 29, 32);
	moveRight[3] = sf::IntRect(60, 30, 29, 32);
	moveRight[4] = sf::IntRect(90, 30, 29, 32);
	moveRight[5] = sf::IntRect(120, 30, 29, 32);
	moveRight[6] = sf::IntRect(150, 30, 29, 32);
	moveRight[7] = sf::IntRect(180, 30, 29, 32);
	moveRight[8] = sf::IntRect(210, 30, 29, 32);
	moveRight[9] = sf::IntRect(240, 30, 29, 32);
	moveRight[10] = sf::IntRect(270, 30, 29, 32);

	moveLeft[0] = sf::IntRect(303, 0, 22, 30);
	moveLeft[1] = sf::IntRect(300, 30, 29, 32);
	moveLeft[2] = sf::IntRect(270, 30, 29, 32);
	moveLeft[3] = sf::IntRect(240, 30, 29, 32);
	moveLeft[4] = sf::IntRect(210, 30, 29, 32);
	moveLeft[5] = sf::IntRect(180, 30, 29, 32);
	moveLeft[6] = sf::IntRect(150, 30, 29, 32);
	moveLeft[7] = sf::IntRect(120, 30, 29, 32);
	moveLeft[8] = sf::IntRect(90, 30, 29, 32);
	moveLeft[9] = sf::IntRect(60, 30, 29, 32);
	moveLeft[10] = sf::IntRect(30, 30, 29, 32);

	jumpRect[0] = sf::IntRect(13, 175, 36, 35);
	jumpRect[1] = sf::IntRect(50, 175, 36, 35);
	jumpRect[2] = sf::IntRect(90, 175, 36, 35);
	jumpRect[3] = sf::IntRect(125, 175, 37, 35);
	jumpRect[4] = sf::IntRect(162, 175, 37, 35);

	count = 0;

	playerSprite.setTexture(rightTexture);
	playerSprite.setTextureRect(moveRight[0]);
	playerSprite.setOrigin(15, 16);
	playerSprite.setScale(2,2);
	playerSprite.setPosition(position.x, position.y);

	yPos = position.y;
	xPos = position.x;
	jumping = false;
	jumpState = 0;
	dir = stationary;
	up = true; left = right = down = false;
}