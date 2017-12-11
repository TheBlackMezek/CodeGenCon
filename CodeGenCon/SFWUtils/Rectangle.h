#pragma once

#include "MathLib\Vec2.h"


class Rectangle
{
public:
	Rectangle();
	~Rectangle();

	vec2 pos;
	vec2 size;
	int color;

	vec2 getCenter();
	void draw();
};

