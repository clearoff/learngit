#include "Heap.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
//using namespace std;
//
//void AdjustDown(int* a, size_t size, size_t parent);    //���µ����㷨
//
//
//void HeapSort(int* a,size_t size)         //������
//{
//
//	//����
//	for (int i = (size - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, size, i);
//	}
//
//	//��������
//	for (size_t i = size - 1; i >= 1; i--)
//	{
//		swap(a[0], a[i]);                  //������Ԫ���Ƶ��ѵ�ĩβ
//		AdjustDown(a, i-1, 0);             //�����Ԫ�س����ԶѶ��������µ���
//	}
//}
//
//void AdjustDown(int* a,size_t size,size_t parent)    //���µ����㷨
//{
//	size_t child = parent*2+1;           //�õ������±�
//
//	while (child < size)                //���µ���������Խ�缴��ֹͣ
//	{
//		if (((child + 1)<size) &&
//			a[child + 1]>a[child])
//		{
//			child++;
//		}
//
//		if (a[parent] < a[child])
//		{
//			swap(a[child], a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//			break;
//	}
//}


//void TestHeapSort()
//{
//	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
//	//Heap<int,Less<int>> hp1(a,sizeof(a)/sizeof(a[0]));
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	HeapSort(a, sizeof(a) / sizeof(a[0]));
//
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}


#define N 100
#define K 10
//n����ȡǰk��������
void SortFrontK(int* a,int* k)
{
	for (size_t i = 0; i < 10; i++)
	{
		k[i] = a[i];
	}
	Heap<int, Less<int>> hp1(k, K);
	for (size_t i = 10; i < N; i++)
	{
		if (a[i]>hp1.Top())
		{
			hp1.Pop();
			hp1.Push(a[i]);
		}
	}
	for (size_t i = 0; i < K; i++)
	{
		k[i] = hp1.Top();
		hp1.Pop();
	}
}
void TestFrontK()
{
	int a[N] = { 0 };
	int k[K] = { 0 };
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 10000 + 1;
	}

	for (size_t i = 0; i < K; i++)
	{
		cout << a[i] << " ";
	}

	SortFrontK(a, k);
	for (size_t i = 0; i < K; i++)
	{
		cout << k[i] << " ";
	}
	cout << endl;
}


int main()
{
	TestFrontK();
	return 0;
}