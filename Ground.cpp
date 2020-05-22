#include "Ground.h"

// Implement functions / constructors etc. here

ground::ground(){
	groundTexture.loadFromFile("Textures/collisionBlock.png");

	groundSprite.setTexture(groundTexture);
	groundSprite.setOrigin(15, 16);
	groundSprite.setScale(1, 1);
	groundSprite.setPosition(10000, 10000);

	yPos = 0;
	xPos = 282;
}

ground::ground(sf::Vector2f position, std::string texFileLoc) {

	groundTexture.loadFromFile(texFileLoc);

	groundSprite.setTexture(groundTexture);
	groundSprite.setOrigin(15, 16);
	groundSprite.setScale(1,1);
	groundSprite.setPosition(position.x, position.y);

	yPos = position.y;
	xPos = position.x;
}

void ground::update()//change so it doesn't move and it is stationary
{

	xPos = 0;
	
}

void ground::reposition()//set a value for the y-value
{/*
	xPos = 1052;
	yPos = (float)randomizeYPos();
	*/
}

int ground::randomizeYPos() //you might not need this
{/*
	int randomY;
	srand(time(NULL));

	randomY = rand() % 140 + 500;
	return randomY;
	*/
	return 0;
}

//create a function that that allows you to make a whole line of ground blocks
void ground::lineBlocks(sf::RenderWindow *window)
{
	/*int xpos = 0;
	while (xpos < 1000)
	{
		window->draw(groundSprite);
		xpos += 100;
	}*/
}

//create a function that collides with the player and changes the y and x values to its current position so that it doesn't move
/*
void ground::collision(player *s)
{
	if (s->playerSprite.getGlobalBounds().intersects(groundSprite.getGlobalBounds()))
		s->yPos = groundSprite.getPosition().y;
}
*/
void ground::drawBlocks()
{
	for (int i = 0; i < 100; i++) {
		ground obj;
		obj.groundSprite.setColor(sf::Color::Black);
		blocks.push_back(obj);
		blocks[i].groundSprite.setScale(1, 0.01);
		obj.groundSprite.setColor(sf::Color::Red);
		stopBlocks.push_back(obj);
		stopBlocks[i].groundSprite.setScale(0.25, 1.15);
		
	}
	blocks[0].groundSprite.setPosition(sf::Vector2f(0, 280));
	blocks[1].groundSprite.setPosition(sf::Vector2f(120, 280));
	blocks[2].groundSprite.setPosition(sf::Vector2f(240, 280));
	blocks[3].groundSprite.setPosition(sf::Vector2f(365, 280));
	blocks[4].groundSprite.setPosition(sf::Vector2f(490, 280));
	blocks[5].groundSprite.setPosition(sf::Vector2f(590, 290));
	blocks[6].groundSprite.setPosition(sf::Vector2f(1160, 218));
	blocks[7].groundSprite.setPosition(sf::Vector2f(1248, 218));
	blocks[8].groundSprite.setPosition(sf::Vector2f(1364, 218));
	blocks[9].groundSprite.setPosition(sf::Vector2f(998, 405));
	blocks[10].groundSprite.setPosition(sf::Vector2f(1118, 405));
	blocks[11].groundSprite.setPosition(sf::Vector2f(1238, 405));
	blocks[12].groundSprite.setPosition(sf::Vector2f(1358, 405));
	blocks[13].groundSprite.setPosition(sf::Vector2f(1458, 405));
	blocks[14].groundSprite.setPosition(sf::Vector2f(1595, 275));
	blocks[15].groundSprite.setPosition(sf::Vector2f(1712, 275));
	blocks[16].groundSprite.setPosition(sf::Vector2f(1855, 220));
	blocks[17].groundSprite.setScale(1.25, 0.01);
	blocks[17].groundSprite.setPosition(sf::Vector2f(1983, 160));
	blocks[18].groundSprite.setPosition(sf::Vector2f(610, 302));
	blocks[19].groundSprite.setPosition(sf::Vector2f(640, 311));
	blocks[20].groundSprite.setPosition(sf::Vector2f(670, 320));
	blocks[21].groundSprite.setPosition(sf::Vector2f(690, 329));
	blocks[22].groundSprite.setPosition(sf::Vector2f(710, 338));
	blocks[23].groundSprite.setPosition(sf::Vector2f(730, 347));
	blocks[24].groundSprite.setPosition(sf::Vector2f(747, 356));
	blocks[25].groundSprite.setPosition(sf::Vector2f(764, 365));
	blocks[26].groundSprite.setPosition(sf::Vector2f(780, 375));
	blocks[27].groundSprite.setPosition(sf::Vector2f(790, 385));
	blocks[28].groundSprite.setPosition(sf::Vector2f(810, 395));
	blocks[29].groundSprite.setPosition(sf::Vector2f(878, 399));

	stopBlocks[0].groundSprite.setPosition(sf::Vector2f(1598, 308));
}