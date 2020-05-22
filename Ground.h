#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <stdlib.h>
#include <ctime>
class ground {
public:
	sf::Texture groundTexture;
	sf::Sprite groundSprite;
	std::vector <ground> blocks;
	std::vector<ground> stopBlocks;
	bool goThrough;
	ground();
	ground(sf::Vector2f position, std::string texFileLoc);

	float yPos;
	float xPos;

	void update();
	void reposition();
	int randomizeYPos();
	void lineBlocks(sf::RenderWindow *window);
	//void collision(Actor &s);
	void drawBlocks();

};