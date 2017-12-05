
#include <iostream>
#include <time.h>

#include "sfwdraw.h"
#include "MathLib\Vec2.h"



int main()
{
	srand(time(NULL));

	sfw::initContext(800, 600, "1-Templates");
	sfw::setBackgroundColor(BLACK);

	bool shouldContinue = true;
	while (sfw::stepContext() && shouldContinue)
	{
		shouldContinue = !sfw::getKey(256);

		sfw::drawCircle(100, 100, 100);
	}

	return 0;
}