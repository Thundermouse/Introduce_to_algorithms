#include<iostream>
#include"chapter3\sort.h"
using namespace introAlgorithm;
int main()
{
	int A[12] = {5,2,4,7,1,3,2,6,7,8,9,10};
	MERGE_SORT(A, 0, 11);
	return 0;
}