#include"chapter6\red_black_tree.h"
#include<map>
using namespace introAlgorithm;
int main()
{
	Tree<int> T;
	int A[11] = {15,6,18,3,7,17,20,2,4,13,9};
	for (int i = 0; i < 11; ++i)
		T.TREE_INSERT(A[i]);
	T.INORDER_TREE_WALK(T.root);
	return 0;
}