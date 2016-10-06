/*
@author:Yuhai Cao<cyh-shanghai@sjtu.edu.cn>
@version 1.0
@date: 29/09/2016
@Introduction to Algorithms(Thrid Edition) Chapter 12
@attention
*/
#ifndef _TREE_H_
#define _TREE_H_
#define NULL 0
#include<iostream>
namespace introAlgorithm
{
	template<typename T>
	class Tnode
	{
	public:
		T data;
		Tnode * lchild;
		Tnode * rchild;
		Tnode * parents;

		Tnode()
		{
			data = 0;
			lchild = 0;
			rchild = 0;
		};
		virtual ~Tnode()
		{}
	};

	template<typename T>
	class Tree
	{
	public:
		Tnode<T> *root;
		Tnode<T> nil;
		int cnode;
		Tree() :cnode(0), root(&nil)
		{
			nil.rchild = NULL;
			nil.lchild = NULL;
		}
		
		bool TREE_INSERT(T z)
		{
			Tnode<T> *Parents = &nil;
			Tnode<T> *Present = root;
			while (Present != &nil)
			{
				Parents = Present;
				if (z > Present->data)
					Present = Present->rchild;
				else Present = Present->lchild;
			}

			Tnode<T> *NewNode = new Tnode<T>;
			NewNode->lchild = NewNode->rchild = &nil;
			NewNode->data = z;
			NewNode->parents = Parents;
			if (Parents == &nil)
			{
				root = NewNode;
				nil.lchild =  NewNode;
				nil.rchild = NewNode;
			}
			else if (z > Parents->data)
				Parents->rchild = NewNode;
			else Parents->lchild = NewNode;
			cnode++;
			return 0;
		}

		Tnode<T>* TREE_MAXIMUM(Tnode<T>*r) const
		{
			while (r->rchild != &nil)
				r = r->rchild;
			return r;
		}

		Tnode<T>* TREE_MINIMUM(Tnode<T>*r) const
		{
			while (r->lchild != &nil)
				r = r->lchild;
			return r;
		}

		Tnode<T>* SUCCESSOR(Tnode<T>*r) const
		{
			if (r == &nil) return &nil;
			else if (r->rchild == nil)
			{
				Tnode<T>*p = r->parents;
				while (p != &nil&&p->rchild == r)
				{
					r = p;
					p = r->parents;
				}
				return p;
			}
			else return TREE_MINIMUM(r->rchild);
		}

		bool TRANSPLANT(Tnode<T>*a, Tnode<T>*b)
		{
			if (a == root)
			{
				nil.lchild = nil.rchild = b;
				root = b;
			}
			else if (a->parents->lchild == a)
				a->parents->lchild = b;
			else a->parents->rchild = b;
			if (b != &nil)
				b->parents = a->parents;
			return 1;
		}

		bool TREE_DELETE(Tnode<T>*a)
		{
			if (a->rchild == &nil)
				TRANSPLANT(a, a->lchild);
			else if (a->lchild == &nil)
				TRANSPLANT(a, a->rchild);
			else
			{
				Tnode<T>*C = TREE_MINIMUM(a->rchild);
				if (C->parents != a)
				{
					TRANSPLANT(C, C->rchild);
					C->rchild = a->rchild;
					a->rchild->parents = C;
				}
				TRANSPLANT(a, C);
				C->lchild = a->lchild;
				a->lchild->parents = C;
			}
			delete a;
			cnode--;
			return 0;
		}

		void DELETE_NODE_WALK(Tnode<T>*root)
		{
			if (root != &nil)
			{
				DELETE_NODE_WALK(root->lchild);
				DELETE_NODE_WALK(root->rchild);
				delete root;
				cnode--;
			}
		}
		void INORDER_TREE_WALK(Tnode<T> *root)
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