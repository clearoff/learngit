#include "SparseMartix.hpp"


int main()
{
	int array[6][5] = { 
	{ 1, 0, 3, 0, 5 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 1, 0, 3, 0, 5 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 } };
	SparseMartix<int> sm((int*)array,6,5,0);
	sm.DisPlay();
	sm.Transport();
	sm.DisPlay();
	return 0;
}