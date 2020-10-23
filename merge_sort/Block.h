#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Block
{
	RectangleShape block;
	unsigned m_value;

	// private functions
	void initBlock();
	
public:
	// public functions
	//Block(float width = 20.f, float height = 200.f, float pos_x = 30.f, float pos_y = 30.f);
	Block(unsigned value = 100.f);
	~Block();

	// modifiers
	void setPosition(float pos_x, float pos_y);

	bool operator <(const Block& b);
	bool operator >(const Block& b);
	friend std::ostream& operator <<(std::ostream& out, Block& b);

	int compare(Block& a, Block& b);

	void update();
	void render(RenderTarget* target);
};

