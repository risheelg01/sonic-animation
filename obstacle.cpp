#include "obstacle.h"

// Implement functions / constructors etc. here




void obstacle:: setRects()
{
	ringsRect[0] = sf::IntRect(0, 0, 64, 64);
	ringsRect[1] = sf::IntRect(64, 0, 64, 64);
	ringsRect[2] = sf::IntRect(128, 0, 64, 64);
	ringsRect[3] = sf::IntRect(192, 0, 64, 64);
	ringsRect[4] = sf::IntRect(0,64, 64, 64);
	ringsRect[5] = sf::IntRect(64, 64, 64, 64);
	ringsRect[6] = sf::IntRect(128, 64, 64, 64);
	ringsRect[7] = sf::IntRect(192, 64, 64, 64);
	ringsRect[8] = sf::IntRect(0, 128, 64, 64);
	ringsRect[9] = sf::IntRect(64, 128, 64, 64);
	ringsRect[10] = sf::IntRect(128, 128, 64, 64);
	ringsRect[11] = sf::IntRect(192, 128, 64, 64);
	ringsRect[12] = sf::IntRect(0, 192, 64, 64);
	ringsRect[13] = sf::IntRect(64, 192, 64, 64);
	ringsRect[14] = sf::IntRect(128, 192, 64, 64);
	ringsRect[15] = sf::IntRect(192, 192, 64, 64);
}
obstacle::obstacle(int x, int y) {

	ringTexture.loadFromFile("Textures/sonicring.png");

	ringSprite.setTexture(ringTexture);
	ringSprite.setOrigin(15, 16);
	ringSprite.setPosition(x,y);
	ringSprite.setScale(0.5, 0.5);
	setRects();
	yPos = y;
	xPos = x;
} 
void obstacle::drawRings(sf::RenderWindow &window)
{
	/*
	for (int i = 0; i < 100; i++)
	{
		obstacle obj;
		ringsVector.push_back(obj);
		ringsVector[i].ringSprite.setScale(0.25, 0.25);
		//ringsVector[i].ringSprite.setTextureRect(ringsRect[0]);
	}
	ringsVector[0].ringSprite.setPosition(sf::Vector2f(1170, 186));*/
	window.draw(ringSprite);
}
/*void obstacle::update()
{
	xPos -= 5;
	if (xPos < 0)
	{
		xPos = 1052;
	}
}



int obstacle::randomizeYPos()
{
	int randomY;
	srand(time(NULL));

	randomY = rand() % 140 + 500;
	return randomY;
}*/
void obstacle::reposition()
{
	xPos = 100000;
	yPos = 100000;
	ringSprite.setPosition(xPos, yPos);
}