#include"chapter6/heap.h"
int main()
{
	introAlgorithm::maxheap<int> H;
	H.size = 10;
	for (int i = 1; i <= 10; ++i)
		H.data[i] = i;
	H.HEAPSORT();
	return 0;
}