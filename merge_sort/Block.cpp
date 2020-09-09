#include "Block.h"

// private functions
void Block::initBlock()
{
	block.setFillColor(Color::Cyan);
	//block.setSize(Vector2f(20.f, 400.f));
}

// public functions
Block::Block(float width, float height, float pos_x, float pos_y)
{
	initBlock();
	block.setSize(Vector2f(width, height));
	block.setPosition(pos_x, pos_y);
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
