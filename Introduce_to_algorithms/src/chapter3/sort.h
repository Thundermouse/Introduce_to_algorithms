/*
@author:Yuhai Cao<cyh-shanghai@sjtu.edu.cn>
@version 1.0
@date: 05/10/2016
@Introduction to Algorithms(Thrid Edition) Chapter 2 Fundamentals of Alogrithmics
@attention
*/
#ifndef _SORT_H_
#define _SORT_H_
namespace introAlgorithm
{
	template<typename T>
	bool MERGE(T *S, int p, int q, int r)
	{
		if (r == q)return 0; 
		int lenA = q - p + 1;
		int lenB = r - q;
		T *A = new T[lenA];
		T *B = new T[lenB];
		memcpy(A, S + p, lenA*sizeof(T));
		memcpy(B, S + q + 1, lenB*sizeof(T));
		int cA = 0;
		int cB = 0;
		int k;
		for (k = p; k <= r; ++k)
		{
			if (cA == lenA || cB == lenB) break;
			if (A[cA] > B[cB]) S[k] = B[cB++];
			else S[k] = A[cA++];
		}
		if (cA < lenA)
			memcpy(S+k, A+cA, (lenA - cA) * sizeof(T));
		else if (cB < lenB)
			memcpy(S+k, B+cB, (lenB - cB) * sizeof(T));
		delete[] A;
		delete[] B;
		return 1;
	}

	template<typename T>
	bool MERGE_SORT(T *S,int p,int q)
	{
		if (q > p)
		{
			int mid = (p + q) / 2;
			MERGE_SORT(S, p, mid);
			MERGE_SORT(S,mid + 1, q);
			MERGE(S, p, mid, q);
		}
		return 1;
	}

	template<typename T>
	bool INSERT_SORT(T *S, int p, int q)
	{

	}

	template<typename T>  //for Problem 2-1
	bool MERGE_INSERT_SORT(T *S, int p, int q,int k)
	{

	}
}
#endif 

