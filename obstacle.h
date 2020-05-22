#include <SFML\Graphics.hpp>
#include <string>
#include <stdlib.h>
#include <ctime>

class obstacle {
public:
	sf::Texture ringTexture;
	sf::Sprite ringSprite;
	std::vector<obstacle> ringsVector;
	sf::IntRect ringsRect[16];
	
	obstacle(int x, int y);
	float yPos;
	float xPos;
	int count = 0;;
	void setRects();
	void drawRings(sf::RenderWindow &window);
	/*void update();
	
	intz randomizeYPos();
	*/
	void reposition();

};