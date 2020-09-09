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
	:block(20.f, 400.f, 50.f, 150.f)
{
	initWindow();
}

Visualization::~Visualization()
{
	delete window;
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

void Visualization::update()
{
	pollEvents();
}

void Visualization::render()
{
	window->clear();

	// render stuff
	block.render(window);

	window->display();
}
