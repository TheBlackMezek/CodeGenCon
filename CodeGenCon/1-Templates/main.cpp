
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

		sfw::drawCircle(add(pos.x, pos.y), pos.y, 20);
	}


	return 0;
}
