#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Block.h"
#include "MergeSort.h"

using namespace sf;

class Visualization
{
	RenderWindow* window;
	VideoMode videoMode;

	Event ev;

	//std::vector<Block*> blocks;
	std::vector<Block> blocks;
	bool canSpawn = true;

	MergeSort sort;

	// private functions
	void initWindow();

public:
	// cons/dest
	Visualization();
	~Visualization();

	const bool running() const;
	void pollEvents();
	void spawnBlocks();
	void startSorting();

	void update();
	void render();
};

