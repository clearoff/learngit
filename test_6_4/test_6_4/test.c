//#include <stdio.h>
//
//int main()
//{
//	int i;
//	int j;
//	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0])-1; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//
//#冒泡排序优化
//#include <stdio.h>
//void Bubble_Sort2(int *arr, int sz)
//{
//	int i;
//	int j;
//	for (i = sz - 1; i > 0; i--)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int i;
//	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bubble_Sort2(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//插入排序

//#include <stdio.h>

//void Insert_Sort(int *arr, int sz)
//{
//	int i;
//	int j;
//	int k;
//	for (i = 1; i < sz; i++)
//	{
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (arr[j] < arr[i])
//				break;
//		}
//		if (j != (i - 1))
//		{
//			 int tmp = arr[i];
//		     for (k = i -1; k >=0; k--)
//		    {
//			   arr[k + 1] = arr[k];
//		     }
//		    arr[j + 1] = tmp;
//	    }
//	}
//}
//插入排序优化算法
//void  Insert_Sort1(int *arr,int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < sz; i++)
//	{
//		if (arr[i]<arr[i - 1])
//		{
//			int tmp = arr[i];
//			for (j = i - 1;j >= 0 && (arr[j] > tmp); j--)    //tmp不能写成arr[j];
//			{
//				arr[j + 1] = arr[j];
//			}
//			arr[j + 1] = tmp;
//		}
//	}
//}
//int main()
//{
//	int i;
//	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Insert_Sort1(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//选择排序
//#include <stdio.h>
//
//void Select_Sort(int *arr, int sz)
//{
//	int i;
//	int j;
//	int index;
//	for (i = 0; i < sz; i++)
//	{
//		index = 0;
//		int tmp = arr[i];
//		for (j = i + 1; j < sz; j++)
//		{
//			if (tmp>arr[j])
//			{
//				tmp = arr[j];
//				index = j;
//			}
//		}
//		if (index > i)
//		{
//			arr[index] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//	
//}
#include <stdio.h>

Insert_Sort2(int *arr, int sz)
{
	int middle;
	int high;
	int low;
	int i;
	int j;
	int tmp;
	for (i = 1; i < sz; i++)
	{
		high = i - 1;
		low = 0;
		tmp = arr[i];
		while (low <= high)
		{
			middle = (high - low) / 2 + low;
			if (arr[middle] > tmp)
			{
				high = middle - 1;
			}
			else
			{
				low = middle + 1;
			}
		}
		for (j = i - 1; j >= (high + 1); j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[high + 1] = tmp;
	}
}

int main()
{
	int i;
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Insert_Sort2(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}