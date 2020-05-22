#include <SFML\Graphics.hpp>
#include <string>

enum direction {

	horizontal,vertical,stationary
};

class player{
public:
	sf::Texture rightTexture;
	sf::Texture leftTexture;
	sf::Texture jumpingTexture;
	sf::Sprite playerSprite;
	sf::IntRect moveRight[11];
	sf::IntRect moveLeft[11];
	sf::IntRect jumpRect[5];
	int count;
	direction dir;
	bool left, right, up, down;
	sf::Vector2f maxHeight;
	player(sf::Vector2f position, std::string rightfileLoc, std::string jumpFileLoc,std::string leftFileLoc);

	bool jumping;
	int jumpState;
	float yPos, xPos;
};