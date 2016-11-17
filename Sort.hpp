#pragma once 
#include <iostream>
using namespace std;



void PrintArray(int *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void InsertSort(int *a, int size)
{
	int index = 1;
	while (index<size)
	{
		int pos = index - 1;
		int tmp = a[index];
		while (pos >= 0 && a[pos] > tmp)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = tmp;
		index++;
	}
}
void ShellSort(int *a, int size)
{
	int gap=size;
	while (gap >1)
	{
		gap = gap / 3 + 1;
		int index = gap;
		for (index = gap; index <size; index++)
		{
			int tmp = a[index];
			int pos = index - gap;
			while (pos >= 0 && a[pos] > tmp)
			{
				a[pos + gap] = a[pos];
				pos -= gap;
			}
			a[pos + gap] = tmp;
		}
	}
}


void TestInsert()
{
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a)/sizeof(a[0]));
}

void TestShell()
{
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}