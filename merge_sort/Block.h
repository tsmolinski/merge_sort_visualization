#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Block
{
	RectangleShape block;

	// private functions
	void initBlock();
	
public:
	// public functions
	Block(float width = 20.f, float height = 200.f, float pos_x = 30.f, float pos_y = 30.f);
	~Block();

	void update();
	void render(RenderTarget* target);
};

