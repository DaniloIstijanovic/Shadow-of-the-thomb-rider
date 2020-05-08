#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "hpps/Animal.h"
#include "hpps/Bear.h"
#include "hpps/Aligator.h"
#include "hpps/Armour.h"
#include "hpps/Deer.h"
#include "hpps/Chicken.h"
#include "hpps/Cow.h"
#include "hpps/Bow.h"
#include "hpps/Citizen.h"
#include "hpps/Wolf.h"
#include "hpps/Thief.h"
#include "hpps/Oruzje.h"
#include "hpps/Eagle.h"
#include "hpps/Gun.h"
#include "hpps/Realic.h"
#include "hpps/Npc.h"
#include "hpps/Item.h"
#include "hpps/Sword.h"
#include "hpps/Snake.h"

int windowW = 1920;
int windowH = 1080;
int halfWinHeight = windowH / 2;
int halfWinWight = windowW / 2;
using namespace std;




class PlayerAttack {
public:
	virtual void Playerattack() = 0;
};


class playerstats {
private:
	string Name;
	int Hp;
	int Money;
	int Stamina;
public:
	void Playerattack() {
		cout << "Attack" << endl;
	}

	void setname(string Pname) {
		Name = Pname;
	}
	void setHp(int Php) {
		Hp = Php;
	}
	void setStamina(int PS) {
		Stamina = PS;
	}
	string getName() {
		return Name;
	}
	int getHp() {
		return Hp;

	}
	int getStamina() {
		return Stamina;

	}


};

class block {
public:

	float x;
	float y;
	float xpos;
	float ypos;
	float scale;
	sf::Sprite image;
	float topS;
	float botS;
	float rightS;
	float leftS;

	block(float xpos, float ypos, sf::Sprite zemlja) {

		image = zemlja;
		scale = 1;
		image.setPosition(xpos, ypos);
		image.setScale(scale, scale);
		leftS = image.getPosition().x;
		rightS = image.getPosition().x + (image.getLocalBounds().width * scale);
		topS = image.getPosition().y;
		botS = image.getPosition().y + (image.getLocalBounds().height * scale);

	};
};

class player {
public:
	bool collid;
	bool ground;
	float x;
	float y;
	float xpos;
	float ypos;
	bool Tright;
	bool Tup;
	float topS;
	float botS;
	float rightS;
	float leftS;
	float scale = 0;
	sf::Sprite image;
	player(sf::Sprite likS) {
		scale = 1;
		image = likS;
		ypos = 0;
		xpos = 0;
		x = 0;
		y = 0;
		Tright = true;
		Tup = true;
		ground = false;
		collid = false;

	}

	void uppdate(bool up, bool down, bool left, bool right, block level[5], float timer) {
		if (right)
		{
			Tright = true;
			x = -15;
		}
		if (left)
		{
			Tright = false;
			x = 15;
		}
		if (up)
		{
			Tup = true;
			y = -15;
		}
		if (down)
		{
			Tup = false;
			y = 15;
		}
		if (!(right || left)) {
			x = 0;
		}
		if (ground == true)
		{
			y = 0;
		}

		image.move(sf::Vector2f(x * timer, 0));
		collide(x, 0, level);
		image.move(sf::Vector2f(0, y * timer));
		collide(0, y, level);

	}
	void collide(float x2, float y2, block level[5]) {
		for (int i = 0; i < 5; i++)
		{
			if (image.getPosition().x + image.getLocalBounds().width * scale > level[i].leftS && image.getPosition().x < level[i].rightS &&
				image.getPosition().y + image.getLocalBounds().height * scale > level[i].topS && image.getPosition().y < level[i].botS)
			{
				collid = true;
			}
			else {
				collid = false;
			}
			if (collid) {
				if (x2 > 0) {

					image.setPosition(sf::Vector2f(level[i].leftS - image.getLocalBounds().width * scale, image.getPosition().y));
				}
				if (x2 < 0) {
					image.setPosition(sf::Vector2f(level[i].rightS, image.getPosition().y));
				}
				if (y2 > 0) {
					image.setPosition(sf::Vector2f(image.getPosition().x, level[i].topS - image.getLocalBounds().height * scale));
				}
				if (y2 < 0) {

					image.setPosition(sf::Vector2f(image.getPosition().x, level[i].botS));
				}
			}
		}

	}

};
int main() {
		int aw;
		int ah;
		int ahp;
	sf::Clock gameTimer;
	sf::RenderWindow window(sf::VideoMode(windowW, windowH), "Thomb rider");
	bool up, down, left, right = false;

	sf::Texture zemljaT;
	zemljaT.loadFromFile("assets/cobblestone.jpg");
	sf::Sprite zemlja(zemljaT);
	zemlja.setTextureRect(sf::IntRect(0, 0, 405, 258));



	block level[5] = { block(100,500,zemlja),block(205,500,zemlja),
					  block(310,500,zemlja),block(415,500,zemlja),
					  block(520,500,zemlja) };


	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(windowW, windowH));
	sf::Texture likT;
	if (!likT.loadFromFile("assets/lik.jpg"))
		return EXIT_FAILURE;
	sf::Sprite likS(likT);
	player PObject(likS);
	likS.scale(2, 2);
	sf::Texture Sword;
	if (!Sword.loadFromFile("assets/sword.png"))
		return EXIT_FAILURE;
	sf::Sprite sword(Sword);

	sf::Texture sheet;
	if (!sheet.loadFromFile("assets/spritesheet2.jpg"))
		return EXIT_FAILURE;
	sf::Sprite ST(sheet);
	ST.setTextureRect(sf::IntRect(0, 0, 195, 54));


	sf::Font font;
	if (!font.loadFromFile("data/OpenSans-Bold.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Thomb Rider RipOf", font, 10);

	sf::Music music;
	if (!music.openFromFile("data/Bruh-sound-effect.ogg"))
		return EXIT_FAILURE;

	music.play();

	


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			cout << "Hi Im npc(Name)";

		right = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		left = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		up = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		down = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		float timer = gameTimer.getElapsedTime().asMilliseconds();
		gameTimer.restart().asMilliseconds();

		PObject.uppdate(right, left, up, down, level, timer);
		view.setCenter(sf::Vector2f(PObject.image.getPosition().x + PObject.image.getLocalBounds().width * PObject.scale / 2.0f, PObject.image.getPosition().y + PObject.image.getLocalBounds().height * PObject.scale / 2.0f));
		window.setView(view);

		window.clear(sf::Color(60, 180, 223));
		window.draw(PObject.image);
		window.draw(sword);
		for (int i = 0; i < 5; i++)
		{
			window.draw(level[i].image);


		}




		window.draw(text);

		window.display();

	}
	return EXIT_SUCCESS;

};
