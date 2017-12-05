#pragma once


template<typename T, typename S>
static S addRange(T start, T end)
{
	S total = 0;
	T iter = start;

	while (iter != end)
	{
		total += *iter;
		++iter;
	}

	return total;
}






