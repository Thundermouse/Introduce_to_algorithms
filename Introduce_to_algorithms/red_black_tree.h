/*
@author:Yuhai Cao<cyh-shanghai@sjtu.edu.cn>
@version 1.0
@date: 29/09/2016
@Introduction to Algorithms(Thrid Edition) Chapter 13 Red Black Tree
@attention
*/
#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_
#include"tree.h"
#include<stdio.h>
#define BLACK 1
#define RED 0
namespace introAlgorithm
{
	template<typename T>
	class redblacknode :public node<T>
	{
	public:
		bool color;
		redblacknode()
		{
			color = 0;
		}
		~redblacknode()
		{}
	};
}
#endif