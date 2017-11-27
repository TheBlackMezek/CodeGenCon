
#include <iostream>
#include <time.h>

#include "sfwdraw.h"
#include "MathLib\Vec2.h"

#include "TemplateFunctions.h"




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

	bool shouldContinue = true;
	while (sfw::stepContext() && shouldContinue)
	{
		shouldContinue = !sfw::getKey(256);

		sfw::drawCircle(add(pos.x, pos.y), pos.y, 20);
	}


	return 0;
}
