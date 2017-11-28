
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <time.h>

#include "sfwdraw.h"
#include "MathLib\Vec2.h"

#include "TemplateFunctions.h"



vec2 getClosestPointOnSpiral(vec2 pos);


float thetaModMod = 0.01f;
float thetaMod = 1;
float posMod = 1;

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



	bool shouldContinue = true;
	while (sfw::stepContext() && shouldContinue)
	{
		shouldContinue = !sfw::getKey(256);

		vec2 pos1 = { 0,0 };
		bool drawLine = false;

		for (float theta = 0; theta < PI * 8; theta += 0.1f)
		{
			vec2 radVec;
			radVec.x = cos(theta + posMod);
			radVec.y = sin(theta + posMod);

			radVec = radVec * (theta * (theta / thetaMod));

			vec2 center = { 400, 300 };

			radVec = radVec + center;

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

			//sfw::drawCircle(radVec.x + center.x, radVec.y + center.y, 2);
		}

		//thetaMod += thetaModMod;
		if (thetaMod > 2)
		{
			thetaModMod = -0.01f;
		}
		else if (thetaMod < 1)
		{
			thetaModMod = 0.01f;
		}

		//posMod -= 0.01f;


		vec2 mpos = { sfw::getMouseX(), sfw::getMouseY() };
		vec2 mSpiralPos = { mpos.x - 400, mpos.y - 300 };
		vec2 closestSpiralPos = getClosestPointOnSpiral(mpos);

		sfw::drawCircle(mpos.x, mpos.y, distance(mSpiralPos, closestSpiralPos));
		sfw::drawCircle(mpos.x, mpos.y, 3);
		sfw::drawCircle(closestSpiralPos.x + 400, closestSpiralPos.y + 300, 3);

		


	}


	return 0;
}

vec2 getClosestPointOnSpiral(vec2 pos)
{
	vec2 ret = { 0,0 };



	vec2 spiralPos = { pos.x - 400, pos.y - 300 };

	float posRad = magnitude(spiralPos);
	float posTheta = atan2(spiralPos.y, spiralPos.x) - posMod;

	if (posTheta < -PI)
	{
		posTheta += PI * 2;
	}

	std::cout << PI << "   " << posTheta << std::endl;

	float pointTheta = posTheta;
	vec2 point;
	point.x = cos(pointTheta + posMod);
	point.y = sin(pointTheta + posMod);
	point = point * (pointTheta * (pointTheta / thetaMod));

	bool foundFlag = false;
	while (!foundFlag)
	{
		float newTheta = pointTheta + PI * 2;
		vec2 newPoint;
		newPoint.x = cos(newTheta + posMod);
		newPoint.y = sin(newTheta + posMod);
		newPoint = newPoint * (newTheta * (newTheta / thetaMod));

		if (distance(point, spiralPos) <= distance(newPoint, spiralPos))
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
