#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Block.h"

using namespace sf;

class Visualization
{
	RenderWindow* window;
	VideoMode videoMode;

	Event ev;

	Block* blocks[10];
	bool canSpawn = true;

	// private functions
	void initWindow();

public:
	// cons/dest
	Visualization();
	~Visualization();

	const bool running() const;
	void pollEvents();
	void spawnBlocks();

	void update();
	void render();
};

