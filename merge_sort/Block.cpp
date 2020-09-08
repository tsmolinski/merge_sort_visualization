#include "Block.h"

// private functions
void Block::initBlock()
{
	block.setFillColor(Color::Cyan);
	block.setSize(Vector2f(20.f, 400.f));
}

// public functions
Block::Block()
{
	initBlock();
}

Block::~Block()
{
}

void Block::update()
{
}

void Block::render(RenderTarget* target)
{
	target->draw(block);
}
