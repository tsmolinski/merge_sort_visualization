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

	//for (auto block : blocks)
	//{
	//	delete block;
	//}
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
			int num = (rand() % 50) + 1;
			//blocks.push_back(new Block(num * 10.f));
			blocks.push_back(Block(num * 10.f));
			//blocks[i]->setPosition(i * 40.f + 80.f, 10.f);
			blocks[i].setPosition(i * 40.f + 80.f, 10.f);
			//cout << "blocks: " << (*blocks[i]) << "\n";
			cout << "blocks: " << blocks[i] << "\n";
		}
		canSpawn = false; 

	}
}

void Visualization::startSorting()
{
	sort.sort(blocks);
}

void Visualization::update()
{
	pollEvents();
	spawnBlocks();
	startSorting();
}

void Visualization::render()
{
	window->clear();

	// render stuff
	//for (auto& i : blocks)
	//{
	//	i->render(window);
	//}
	for (auto& i : blocks)
	{
		i.render(window);
	}

	window->display();
}
