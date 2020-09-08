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
	Block();
	~Block();

	void update();
	void render(RenderTarget* target);
};

