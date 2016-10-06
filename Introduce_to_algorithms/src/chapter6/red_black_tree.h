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
	class RBTnode
	{
	public:
		bool color;
		RBTnode * lchild;
		RBTnode * rchild;
		RBTnode * parents;
		T data;
		RBTnode()
		{
			color = 0;
			data = 0;
			lchild = rchild = parents = NULL;
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
			nil.color = BLACK;
		}

		

		bool LEFT_ROTATE(RBTnode<T> *x)
		{
			if (x == &nil)
				return 0;
			RBTnode<T> *y;
			y = x->rchild;
			if (y == &nil)
				return 0;
			x->rchild = y->lchild;
			if (y->lchild != &nil)
				y->rchild->parents = x;
			y->parents = x->parents;
			if (x->parents == &nil)
			{
				nil.lchild = nil.rchild = y;
				root=y;
			}
			else if (x->parents->lchild == x)
				x->parents->lchild = y;
			else x->parents->rchild = y;
			y->lchild = x;
			x->parents = y;

			return 1;
		}

		bool RIGHT_ROTATE(RBTnode<T> *y)
		{
			if (y == &nil)return 0;
			RBTnode<T> *x = y->lchild;
			if (x == &nil) return 0;
			y->lchild = x->rchild;
			if (x->rchild != &nil)
				x->rchild->parents = y;
			x->parents = y->parents;
			if (y->parents == &nil)
			{
				nil.rchild = nil.lchild = x;
				root = x;
			}
			else if (y->parents->lchild == y)
				y->parents->lchild = x;
			else y->parents->rchild = x;
			y->parents = x;
			x->rchild = y;
			return 1;
		}

		bool RB_INSERT_FIXUP(RBTnode<T>*p)
		{
			while (p->parents->color == RED)
			{
				if (p->parents = p->parents->parents->lchild)
				{
					RBTnode<T>*uncle = p->parents->parents->rchild;
					if (uncle->color == RED)  //case1
					{
						p->parents->color = BLACK;
						uncle->color = BLACK;
						p->parents->parents->color = RED;
						p = p->parents->parents;
					}
					else if(p==p->parents->rchild)  //case2,case2运行后必然会导致case3所以一并写上
					{
						p = p->parents;
						LEFT_ROTATE(p);
						p->parents->color = BLACK;
						p->parents->parents->color = RED;
						RIGHT_ROTATE(p->parents->parents);
					}
					else
					{
						p->parents->color = BLACK;
						p->parents->parents->color = RED;
						RIGHT_ROTATE(p->parents->parents);
					}
				}
				else
				{
					RBTnode<T>*uncle = p->parents->parents->lchild;
					if (uncle->color == RED)
					{
						p->parents->color = BLACK;
						uncle->color = BLACK;
						p->parents->parents = RED;
						p = p->parents->parents;
					}
					else if (p->parents->lchild == p)
					{
						p = p->parents;
						RIGHT_ROTATE(p);
						p->parents->color = BLACK;
						p->parents->parents->color = RED;
						LEFT_ROTATE(p->parents->parents);
					}
					else
					{
						p->parents->color = BLACK;
						p->parents->parents->color = RED;
						LEFT_ROTATE(p->parents->parents);
					}
				}
			}
			root->color = BLACK;
			return 1;
		}

		bool RB_INSERT(T x)
		{
			RBTnode<T>*c = root;
			RBTnode<T>*p = &nil;
			while (c != &nil)
			{
				p = c;
				if (x > c->data)
					c = c->rchild;
				else c = c->lchild;
			}
			RBTnode<T>*New = new RBTnode<T>;
			New->data = x;
			New->parents = p;
			if (p == &nil)
			{
				root = New;
				nil.rchild = nil.lchild = New;
			}
			else if (x < p->data)
				p->lchild = New;
			else p->rchild = New;
			cnode++;
			New->color = RED;
			New->lchild = New->rchild = &nil;
			RB_INSERT_FIXUP(New);
			return 1;
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

		virtual ~RBTree()
		{
			DELETE_NODE_WALK(root);
		}
	};
}
#endif