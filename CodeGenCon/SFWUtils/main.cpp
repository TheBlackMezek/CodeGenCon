
#include <iostream>
#include <time.h>
#include <vector>

#include "sfwdraw.h"
#include "MathLib\Vec2.h"

#include "Rectangle.h"


struct BuildingChunk
{
	int start;
	int end;
	int floors;
};

struct Building
{
	vec2 pos;
	vec2 windowSize;
	vec2 windowSpace;
	std::vector<BuildingChunk> chunks;
};


void drawBuilding(Building& b);


int main()
{
	srand(time(NULL));

	sfw::initContext(800, 600, "1-Templates");
	sfw::setBackgroundColor(BLACK);


	Rectangle rect;

	Building b;
	b.pos = { 100, 100 };
	b.windowSize = { 10, 7 };
	b.windowSpace = { 0, 2 };

	BuildingChunk c1;
	c1.start = 0;
	c1.end = 10;
	c1.floors = 7;
	b.chunks.push_back(c1);

	BuildingChunk c2;
	c2.start = 2;
	c2.end = 10;
	c2.floors = 5;
	b.chunks.push_back(c2);
	
	

	bool shouldContinue = true;
	while (sfw::stepContext() && shouldContinue)
	{
		shouldContinue = !sfw::getKey(256);

		rect.draw();
		drawBuilding(b);
	}

	return 0;
}



void drawBuilding(Building& b)
{
	int i = 0;
	BuildingChunk c = b.chunks[i];
	
	sfw::drawLine(b.pos.x + c.start * b.windowSize.x + (c.start + 1) * b.windowSpace.x,
				  b.pos.y,
				  b.pos.x + c.end * b.windowSize.x + (c.end + 2) * b.windowSpace.x,
				  b.pos.y);

	float chunkBottom = b.pos.y;

	for (i; i < b.chunks.size(); ++i)
	{
		c = b.chunks[i];
		
		float chunkTop = chunkBottom + c.floors * b.windowSize.y + (c.floors+1) * b.windowSpace.y;
		float chunkLeft = b.pos.x + c.start * b.windowSize.x + (c.start + 1) * b.windowSpace.x;
		float chunkRight = b.pos.x + c.end * b.windowSize.x + (c.end + 2) * b.windowSpace.x;

		sfw::drawLine(chunkLeft, chunkBottom, chunkLeft, chunkTop);
		sfw::drawLine(chunkRight, chunkBottom, chunkRight, chunkTop);

		Rectangle window;
		window.size = b.windowSize;

		for (int f = 0; f < c.floors; ++f)
		{
			window.pos.y = chunkBottom + f * window.size.y + (f + 1) * b.windowSpace.y;
			for (int w = 0; w < c.end - c.start; ++w)
			{
				window.pos.x = chunkLeft + w * window.size.x + (w + 1) * b.windowSpace.x;
				window.draw();
			}
		}


		if (i < b.chunks.size() - 1)
		{
			BuildingChunk h = b.chunks[i + 1];
			float nextChunkLeft = b.pos.x + h.start * b.windowSize.x + (h.start + 1) * b.windowSpace.x;
			float nextChunkRight = b.pos.x + h.end * b.windowSize.x + (h.end + 2) * b.windowSpace.x;
			
			sfw::drawLine(chunkLeft, chunkTop, nextChunkLeft, chunkTop);
			sfw::drawLine(chunkRight, chunkTop, nextChunkRight, chunkTop);
		}
		else
		{
			sfw::drawLine(chunkLeft, chunkTop, chunkRight, chunkTop);
		}

		chunkBottom += c.floors * b.windowSize.y + (c.floors+1) * b.windowSpace.y;
	}
}
