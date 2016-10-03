/*
@author:Yuhai Cao<cyh-shanghai@sjtu.edu.cn>
@version 1.0   
@date: 29/09/2016
@Introduction to Algorithms(Thrid Edition) Chapter 6
@attention:
	1.index start with 1
*/
#ifndef _HEAP_H_
#define _HEAP_H_
#include<stdlib.h>
#include<stdio.h>

namespace introAlgorithm
{
	template <typename T>
	class heap
	{
	public:
		int maxsize;
		int size;    //number of element
		int*data;
		heap()
		{
			maxsize = 100;
			size = 0;
			data = new int[101];
		}

		heap(int i) 
		{
			if (i <= 0)
			{
				puts("error:maxsize should bigger than 0");
				exit(0);
			}
			maxsize = i;
			size = 0;
			data = new int[i+1];
		}

		~heap()
		{
			delete[] data;
		}

		bool print()
		{
			for (int i = 1; i <= size; ++i)
				print("%d ", data[i]);
		}

		int RIGHT(int i)
		{
			return (i <<1) + 1;
		}

		int LEFT(int i)
		{
			return (i << 1);
		}

	};


	template <typename T>
	class maxheap :public heap<T>
	{
	public:
		bool ismaxheap()
		{
			for (int i = 2; i <= size;++i)
				if (data[i] > data[i / 2]) return 0;
			return 1;
		}

		void MAX_HEAPIFY(int i)
		{
			int largest;
			int l = LEFT(i);
			int r = RIGHT(i);
			T tmp;
			if (data[l] > data[i] && size >= l)
				largest = l;
			else largest = i;

			if (data[r] > data[largest] && size >= r)
				largest = r;

			if (largest != i)
			{
				tmp = data[i];
				data[i] = data[largest];
				data[largest] = tmp;
				MAX_HEAPIFY(largest);
			}
		}

		void BUILD_MAX_HEAP()
		{
			for (int i = size / 2; i >= 1; --i)
				MAX_HEAPIFY(i);
		}

		void HEAPSORT()
		{
			BUILD_MAX_HEAP();
			int tmp = size;
			for (int i = size; i > 1; --i)
			{
				T tmp = data[1];
				data[1] = data[i];
				data[i] = tmp;
				size--;
				MAX_HEAPIFY(1);
			}
			size = tmp;
		}
	};
}
#endif