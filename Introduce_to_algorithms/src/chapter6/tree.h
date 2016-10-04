/*
@author:Yuhai Cao<cyh-shanghai@sjtu.edu.cn>
@version 1.0
@date: 29/09/2016
@Introduction to Algorithms(Thrid Edition) Chapter 12
@attention
*/
#ifndef _TREE_H_
#define _TREE_H_
namespace introAlgorithm
{
	template<typename T>
	class node
	{
	public:
		T data;
		node * lchild;
		node * rchild;
		node * parents;
		node()
		{
			data = 0;
			lchild = 0;
			rchild = 0;
		};
		virtual ~node()
		{}
	};
}
#endif