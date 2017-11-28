#pragma once

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
