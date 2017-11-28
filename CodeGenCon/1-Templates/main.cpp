
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <time.h>
#include <vector>

#include "sfwdraw.h"
#include "MathLib\Vec2.h"

#include "TemplateFunctions.h"



vec2 getClosestPointOnSpiral(vec2 pos, Spiral spiral);
vec2 getPointOnSpiral(float angleRad, Spiral spiral);
void drawSpiral(Spiral spiral);



int main()
{
	srand(time(NULL));

	sfw::initContext(800, 600, "1-Templates");
	sfw::setBackgroundColor(BLACK);


	vec2 pos = { 100, 200 };

	int v = 2;
	float vv = 2.5f;
	bool vvv = false;
	char s = 'r';
	char* ss = "SEKRJSLKJFLKSJE(FO(JDSOF";
	print(v);
	print(vv);
	print(vvv);
	print(s);
	print(ss);

	print(min<float>(v, vv));
	print(max<float>(v, vv));

	Starship enterprise;
	enterprise.id = 1701;
	enterprise.name = "USS Enterprise 1701-D";
	enterprise.shipClass = "Galaxy class";

	print(enterprise);

	swap(v, enterprise.id);
	print(v);
	print(enterprise.id);

	char a = 'a';
	char b = 'b';
	char z = 'z';

	print(min(a, b));
	print(min(a, z));
	print(max(a, b));
	print(max(a, z));

	print(clamp(2, 1, 5));
	print(clamp(0, 1, 5));
	print(clamp(9, 1, 5));

	boolAssert<true>(true);
	equalAssert(2, 2);
	notEqualAssert(1, 2);



	std::vector<vec2> stars;


	Spiral arm1;
	arm1.center = { 400, 300 };
	arm1.rotation = 0;
	arm1.tightness = 0.5f;

	Spiral arm2;
	arm2.center = { 400, 300 };
	arm2.rotation = PI;
	arm2.tightness = 0.5f;



	for (int x = 0; x < 800; ++x)
	{
		for (int y = 0; y < 600; ++y)
		{
			vec2 pos = { x, y };

		}
	}




	bool shouldContinue = true;
	while (sfw::stepContext() && shouldContinue)
	{
		shouldContinue = !sfw::getKey(256);

		//drawSpiral(arm1);
		//drawSpiral(arm2);


		vec2 mpos = { sfw::getMouseX(), sfw::getMouseY() };
		vec2 mSpiralPos = { mpos.x - 400, mpos.y - 300 };
		vec2 closestSpiralPos = getClosestPointOnSpiral(mpos, arm1);

		sfw::drawCircle(mpos.x, mpos.y, distance(mSpiralPos, closestSpiralPos));
		sfw::drawCircle(mpos.x, mpos.y, 3);
		sfw::drawCircle(closestSpiralPos.x + 400, closestSpiralPos.y + 300, 3);

	}


	return 0;
}

vec2 getClosestPointOnSpiral(vec2 pos, Spiral spiral)
{
	vec2 ret = { 0,0 };



	vec2 posInSpiral = { pos.x - spiral.center.x, pos.y - spiral.center.y };

	float posRad = magnitude(posInSpiral);
	float posTheta = atan2(posInSpiral.y, posInSpiral.x) - spiral.rotation;

	if (posTheta < -PI)
	{
		posTheta += PI * 2;
	}


	float pointTheta = posTheta;
	vec2 point;
	point.x = cos(pointTheta + spiral.rotation);
	point.y = sin(pointTheta + spiral.rotation);
	point = point * (pointTheta * (pointTheta / spiral.tightness));

	bool foundFlag = false;
	while (!foundFlag)
	{
		float newTheta = pointTheta + PI * 2;
		vec2 newPoint;
		newPoint.x = cos(newTheta + spiral.rotation);
		newPoint.y = sin(newTheta + spiral.rotation);
		newPoint = newPoint * (newTheta * (newTheta / spiral.tightness));

		if (distance(point, posInSpiral) <= distance(newPoint, posInSpiral))
		{
			foundFlag = true;
		}
		else
		{
			point = newPoint;
			pointTheta = newTheta;
		}
	}

	ret = point;



	return ret;
}

vec2 getPointOnSpiral(float angleRad, Spiral spiral)
{
	vec2 ret;
	ret.x = cos(angleRad + spiral.rotation);
	ret.y = sin(angleRad + spiral.rotation);

	ret = ret * (angleRad * (angleRad / spiral.tightness));

	ret = ret + spiral.center;

	return ret;
}

void drawSpiral(Spiral spiral)
{
	vec2 pos1 = { 0,0 };
	bool drawLine = false;

	for (float theta = 0; theta < PI * 8; theta += 0.1f)
	{
		vec2 radVec = getPointOnSpiral(theta, spiral);

		if (!drawLine)
		{
			pos1 = radVec;
			drawLine = true;
		}
		else
		{
			sfw::drawLine(pos1.x, pos1.y, radVec.x, radVec.y);
			pos1 = radVec;
		}

	}
}
