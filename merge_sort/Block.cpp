#include "Block.h"

// private functions
void Block::initBlock()
{
	block.setFillColor(Color::Cyan);
	//block.setSize(Vector2f(width, height));
    //block.setPosition(pos_x, pos_y);
}

// public functions
//Block::Block(float width, float height, float pos_x, float pos_y)
Block::Block(unsigned value)
{
	initBlock();
	m_value = value;
	block.setSize(Vector2f(20.f, value));
}

Block::~Block()
{
}

// modifiers
void Block::setPosition(float pos_x, float pos_y)
{
	block.setPosition(pos_x, pos_y);
}

bool Block::operator <(const Block& b)
{
	return m_value < b.m_value;
}

bool Block::operator >(const Block& b)
{
	return m_value > b.m_value;
}

int Block::compare(Block& a, Block& b)
{
	return (a < b ? -1 : (a > b ? 1 : 0));
}

void Block::update()
{
}

void Block::render(RenderTarget* target)
{
	target->draw(block);
}

std::ostream& operator<<(std::ostream& out, Block& b)
{
	out << b.m_value;
	return out;
}
