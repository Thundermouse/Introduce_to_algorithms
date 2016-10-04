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
	class RBTnode :public Tnode<T>
	{
	public:
		bool color;
		RBTnode()
		{
			color = 0;
		}
		~RBTnode()
		{}
	};

	template<typename T>
	class RBTree
	{
	public:
		int cnode;
		RBTnode<T> nil;
		RBTnode<T> *root;
		RBTree() :cnode(0), root(&nil)
		{
			nil.rchild = NULL;
			nil.lchild = NULL;
		}


		void DELETE_NODE_WALK(RBTnode<T>*root)
		{
			if (root != &nil)
			{
				DELETE_NODE_WALK(root->lchild);
				DELETE_NODE_WALK(root->rchild);
				delete root;
				cnode--;
			}
		}
		void INORDER_TREE_WALK(RBTnode<T> *root)
		{
			if (root != &nil)
			{
				INORDER_TREE_WALK(root->lchild);
				std::cout << root->data << ' ';
				INORDER_TREE_WALK(root->rchild);
			}
		}
		virtual ~Tree()
		{
			DELETE_NODE_WALK(root);
		}
	};
}
#endif