#include "Rectangle.h"

#include "sfwdraw.h"


Rectangle::Rectangle()
{
	pos = { 0,0 };
	size = { 10,10 };
	color = WHITE;
}


Rectangle::~Rectangle()
{
}


vec2 Rectangle::getCenter()
{
	return vec2{ pos.x + size.x / 2, pos.y + size.y / 2 };
}

void Rectangle::draw()
{
	sfw::drawLine(pos.x,		  pos.y,          pos.x + size.x, pos.y,          color);
	sfw::drawLine(pos.x,		  pos.y,          pos.x,          pos.y + size.y, color);
	sfw::drawLine(pos.x,		  pos.y + size.y, pos.x + size.x, pos.y + size.y, color);
	sfw::drawLine(pos.x + size.x, pos.y,          pos.x + size.x, pos.y + size.y, color);
}
