#pragma once

#include <vector>

#include "MathLib\Vec2.h"


struct Starship
{
	int id;
	char* name;
	char* shipClass;
};

struct Spiral
{
	vec2 center;
	float tightness;
	float rotation;
};

struct Galaxy
{
	Spiral spiral;
	vec2 center;
	std::vector<vec2> stars;
};
