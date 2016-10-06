#include"chapter6\red_black_tree.h"
#include<map>
using namespace introAlgorithm;
int main()
{
	RBTree<int> T;
	int A[6] = {41,38,31,12,19,8};
	for (int i = 0; i < sizeof(A) / sizeof(int); ++i)
		T.RB_INSERT(A[i]);
	return 0;
}