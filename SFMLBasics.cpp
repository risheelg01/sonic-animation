#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>
#include "player.h"
#include "obstacle.h"
#include <iostream>
#include "Ground.h"
#include <SFML/Audio.hpp>

/*int animatePlayer(player* player)
{
	bool jump = player->jumping;
	int count = player->count;

	if (!jump)
	{
		if (count < 4)
		{
			count++;
		}
		else{
			count = 0;
		}
	}
	else{
		if (player->jumpState == 1)
		{
			if (count < 2)
			{
				count++;
			}
		}
		else if (player->jumpState == 2)
		{
			if (count < 4)
			{
				count++;
			}
		}
	}
	return count;
}*/

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 420), "Running!");
	sf::Texture background;
	sf::Sprite bgSprite;
	sf::Music music;
	music.openFromFile("Textures/greenhillzonemodern.wav");
	music.play();
	music.setLoop(true);

	background.loadFromFile("Textures/first4greenhill.png");
	bgSprite.setTexture(background);
	bgSprite.setScale(2, 2);
	//bgSprite.setOrigin(0, 0);
	window.setFramerateLimit(55);

	player thePlayer(sf::Vector2f(290, 256), "Textures/realsonicsprites.png", "Textures/sonicjump.png", "Textures/sonicleft2.png");
	sf::View camera(sf::Vector2f(520,390),sf::Vector2f(520,390));
	//std::vector<obstacle> things;
	ground collisionBlocks;
	collisionBlocks.drawBlocks();
	std::vector <obstacle> ringVector;
	
	obstacle ring(1190,186);
	obstacle ring1(1240, 186);
	obstacle ring2(1290, 186);
	ringVector.push_back(ring);
	ringVector.push_back(ring1);
	ringVector.push_back(ring2);
	//std::vector<ground> blocks;
	/*for (int i = 1; i < 100; i++) {
		blocks.push_back(obj);
	}*/
	sf::Clock animateClock;
	float animateTimer = 0.0f;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					if (!thePlayer.jumping)
					{
						thePlayer.playerSprite.setTexture(thePlayer.jumpingTexture);
						thePlayer.jumping = true;
						thePlayer.count = 0;
						thePlayer.jumpState = 1;
						thePlayer.maxHeight.y = thePlayer.playerSprite.getPosition().y - 200;
					}

				}
				if (event.key.code == sf::Keyboard::S) {
					thePlayer.down = true;
				}
				if (event.key.code == sf::Keyboard::A) {
					thePlayer.left = true;
					thePlayer.playerSprite.setTexture(thePlayer.leftTexture);
				}
				if (event.key.code == sf::Keyboard::D) {
					thePlayer.right = true;
					thePlayer.playerSprite.setTexture(thePlayer.rightTexture);
				}


			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::S) {
					thePlayer.down = false;
					//thePlayer.playerSprite.setTexture(theplayer.)
				}
				if (event.key.code == sf::Keyboard::A) {
					thePlayer.left = false;


				}
				if (event.key.code == sf::Keyboard::D) {
					thePlayer.right = false;

				}
			}

		}
		
		sf::Vector2f movement(0, 0);
		camera.setCenter(thePlayer.xPos, 220);
		if (thePlayer.down)
			movement.y += 0.1f;
		if (thePlayer.right)
		{
			thePlayer.xPos += 10;
			//std::cout << "hi" << std::endl;
		}
		if (thePlayer.left)
		{
			thePlayer.xPos -= 10;
			//std::cout << "hello" << std::endl;
		}










		if (thePlayer.jumping)
		{
			if (thePlayer.right)
			{
				thePlayer.playerSprite.setTexture(thePlayer.jumpingTexture);
				thePlayer.xPos += 1;
			}
			else if (thePlayer.left)
			{
				thePlayer.playerSprite.setTexture(thePlayer.jumpingTexture);
				thePlayer.xPos -= 1;
			}
			if (thePlayer.jumpState == 1)
			{

				if (thePlayer.yPos > thePlayer.maxHeight.y)
				{
					thePlayer.yPos -= 15;
				}
				else {
					thePlayer.jumpState = 2;
				}
			}
			else if (thePlayer.jumpState == 2)
			{
				if (thePlayer.yPos < thePlayer.maxHeight.y + 200)
				{
					
					thePlayer.yPos += 15;
				}
				else {
					thePlayer.playerSprite.setTexture(thePlayer.rightTexture);
					thePlayer.jumpState = 0;
					thePlayer.jumping = false;
				}
			}
			thePlayer.playerSprite.setPosition(thePlayer.xPos, thePlayer.yPos);
		}
		else {
			
			thePlayer.yPos += 10;
			thePlayer.playerSprite.setPosition(thePlayer.xPos, thePlayer.yPos);
		}
	
		animateTimer = animateClock.getElapsedTime().asSeconds();
		if (animateTimer > 0.1f)
		{
			
			if (thePlayer.jumping)
			{
				if (thePlayer.count < 4)
					thePlayer.count++;
				else
					thePlayer.count = 0;

			}
			else if (thePlayer.count < 10) {
				thePlayer.count++;
			}

			else {
				thePlayer.count = 7;
			}
			if (ring.count < 15)
				ring.count++;
			else
				ring.count = 1;
			animateClock.restart();
		}
		for(int i=0; i<ringVector.size();i++)
			ringVector[i].ringSprite.setTextureRect(ring.ringsRect[ring.count]);
		window.clear();
		
		window.draw(bgSprite);
		
		for (int i = 0; i < collisionBlocks.stopBlocks.size(); i++)
		{
			//window.draw(collisionBlocks.stopBlocks[i].groundSprite);
			if (thePlayer.playerSprite.getGlobalBounds().intersects(collisionBlocks.stopBlocks[i].groundSprite.getGlobalBounds()))
			{
			
				
				thePlayer.xPos = collisionBlocks.stopBlocks[i].groundSprite.getPosition().x - 40;
				
				

					thePlayer.playerSprite.setPosition(thePlayer.xPos, thePlayer.yPos);
			}
		}
		for (int i = 0; i < collisionBlocks.blocks.size();i++)
	{
		//window.draw(collisionBlocks.blocks[i].groundSprite);
		/*if (thePlayer.down) {
			if (collisionBlocks.goThrough) {
				
			}
		}*/
		 if (thePlayer.playerSprite.getGlobalBounds().intersects(collisionBlocks.blocks[i].groundSprite.getGlobalBounds()))
		{
			thePlayer.jumping = false;
			if (thePlayer.left)
				thePlayer.playerSprite.setTexture(thePlayer.leftTexture);
			else //if(thePlayer.right)
				thePlayer.playerSprite.setTexture(thePlayer.rightTexture);
			thePlayer.yPos = collisionBlocks.blocks[i].groundSprite.getPosition().y -30;
			thePlayer.playerSprite.setPosition(thePlayer.xPos, thePlayer.yPos);
		}


	}
		for (int i = 0; i < ring.ringsVector.size(); i++)
		{
			window.draw(ring.ringsVector[i].ringSprite);
			if (thePlayer.playerSprite.getGlobalBounds().intersects(ring.ringsVector[i].ringSprite.getGlobalBounds()))
				ring.ringsVector[i].reposition();
		}

		if (thePlayer.left == false && thePlayer.right == false && thePlayer.jumping == false) { 
			thePlayer.count = 0;
		}
		 if (thePlayer.left&&!thePlayer.jumping) {
			thePlayer.playerSprite.setTextureRect(thePlayer.moveLeft[thePlayer.count]);
		}
		else if (thePlayer.right&&!thePlayer.jumping) {
			thePlayer.playerSprite.setTextureRect(thePlayer.moveRight[thePlayer.count]);

		}
		else if (thePlayer.jumping)
		{
			//thePlayer.playerSprite.setTexture(thePlayer.jumpingTexture);
			thePlayer.playerSprite.setTextureRect(thePlayer.jumpRect[thePlayer.count]);
		}
		else
		{
			thePlayer.playerSprite.setTexture(thePlayer.rightTexture);
			thePlayer.playerSprite.setTextureRect(thePlayer.moveRight[0]);
			//std::cout << "wow\n";
		}
		//thePlayer.playerSprite.move(movement);
		if (thePlayer.left || thePlayer.right) { thePlayer.playerSprite.setPosition(thePlayer.xPos, thePlayer.yPos); }
		
		//window.clear();
		
		//window.draw(bgSprite);
		//int a;
		/*for (int i = 0; i < collisionBlocks.blocks.size();i++)
		{
			
			window.draw(collisionBlocks.blocks[i].groundSprite);
			if (thePlayer.playerSprite.getGlobalBounds().intersects(collisionBlocks.blocks[i].groundSprite.getGlobalBounds()))
			{
				thePlayer.jumping = false;
				if (thePlayer.left)
					thePlayer.playerSprite.setTexture(thePlayer.leftTexture);
				else //if(thePlayer.right)
					thePlayer.playerSprite.setTexture(thePlayer.rightTexture);
				thePlayer.yPos = collisionBlocks.blocks[i].groundSprite.getPosition().y -30;
				thePlayer.playerSprite.setPosition(thePlayer.xPos, thePlayer.yPos);
			}
			
			
		}*/
		
		
		/*for (unsigned i = 0; i < things.size(); i++)
		{
			things[i].update();
			window.draw(things[i].obstacleSprite);

		}

		theObstacle.update();
		if (thePlayer.playerSprite.getGlobalBounds().intersects(theObstacle.obstacleSprite.getGlobalBounds())){
			theObstacle.reposition();
		}

		theObstacle.obstacleSprite.setPosition(theObstacle.xPos, theObstacle.yPos);*/
		window.draw(thePlayer.playerSprite);
		for (int i = 0; i < ringVector.size(); i++)
		{
			ringVector[i].drawRings(window);
			if (thePlayer.playerSprite.getGlobalBounds().intersects(ringVector[i].ringSprite.getGlobalBounds())) {
				ringVector[i].reposition();
			}
		}
		window.setView(camera);
		//window.draw(theObstacle.obstacleSprite);
		//window.draw(theObstacle.obstacleSprite);
		window.display();
	}

	return 0;
}

