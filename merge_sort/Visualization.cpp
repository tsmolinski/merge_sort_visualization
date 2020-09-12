#include "Visualization.h"

using namespace sf;

// private functions
void Visualization::initWindow()
{
	videoMode = VideoMode(800, 600);
	window = new RenderWindow(videoMode, "Merge sort visualization", Style::Close | Style::Titlebar);
}


// public functions
Visualization::Visualization()
	//:block(20.f, 400.f, 50.f, 150.f)
{
	initWindow();
}

Visualization::~Visualization()
{
	delete window;

	for (auto block : blocks)
	{
		delete block;
	}
}

const bool Visualization::running() const
{
	return this->window->isOpen();
}

void Visualization::pollEvents()
{
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case Event::Closed:
			window->close();
			break;
		case Event::KeyPressed:
			if (ev.key.code == Keyboard::Escape)
			{
				window->close();
			}
			break;
		}
	}
}

void Visualization::spawnBlocks()
{
	if (canSpawn)
	{
		for (int i = 0; i < 10; i++)
		{
			blocks[i] = new Block(20.f, -1*((((rand() % 50) + 1) * 10.f)), i * 40.f + 80.f, 580.f);
		}
		canSpawn = false;
	}
}

void Visualization::update()
{
	pollEvents();
	spawnBlocks();
}

void Visualization::render()
{
	window->clear();

	// render stuff
	//block.render(window);
	for (auto& i : blocks)
	{
		i->render(window);
	}

	window->display();
}
