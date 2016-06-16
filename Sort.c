#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//void Bubble_sort(int *arr, int sz)    //ð������
//{
//	int flag = 1;
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int pos = 0;    //��¼���һ�ν���deλ��
//	pos = sz - 1;
//	for (i = 0; i < sz-1; i++)
//	{
//		flag = 1;
//		for (j = 0; j < pos; j++)
//		{
//			if (arr[j] >arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = tmp;
//				k = j;
//			}
//			
//		}
//		pos = k;
//	}
//}

//void Select_sort(int *arr, int sz)    //ѡ������
//	int i = 0;
//	int j = 0;
//	int index = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int tmp = 0;
//		for (j = i + 1; j < sz ; j++)
//		{
//			if (arr[j] < arr[i])
//			{
//				index = j;
//			}
//		}
//		tmp = arr[i];
//		arr[i] = arr[index];
//		arr[index] = tmp;
//	}
//}
//
//void InsertSort(int *arr, int sz)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 1; i < sz; i++)
//	{
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (arr[j] < arr[i])       //arr[0.....i]�Ѿ��ź���   ����Ҫ����
//				break;
//		}
//		if (j != i - 1)               //arr[0....i-1]���б�arr[i]���Ԫ�أ�����arr[i]���뵽����λ��              
//		{
//			int tmp = arr[i];
//			for (k = i - 1; k > j; k--)
//			{
//				arr[k + 1] = arr[k];
//			}
//			arr[k + 1] = tmp;       //����λ�������ҵ��ڵ�ĺ�һλ
//		}
//	}
//}

//void InsertSort2(int *arr, int sz)   //��������������
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 1; i < sz; i++)
//	{
//		int tmp = arr[i];
//		if (arr[i] < arr[i - 1])
//		{
//			for (j = i - 1; (j >= 0) && (tmp < arr[j]); j--)
//			{
//				arr[j + 1] = arr[j];
//			}
//			arr[j+1] = tmp;
//		}
//	}
//}
void Quick_sort(int *arr, int low, int high)
{
	assert(arr);
	int left ;
	int right ;
	int flag ;
	if (low > high)
		return;
	 left = low;
	 right = high;
	 flag = arr[low];
	 while (left != right)
	 {
		 while ((arr[right] >= flag) && (right > left))
			 right--;
		 while ((arr[left] <= flag) && (right > left))
			 left++;
	 }
	 if (left < right)
	 {
		 int tmp = arr[right];
		 arr[right] = arr[left];
		 arr[left] = tmp;
	 }
	 arr[low] = arr[left];
	 arr[left] = flag;
	 Quick_sort(arr, low, left - 1);
	 Quick_sort(arr, left + 1, high);
}
int main()
{
	int i;
	int arr[] = { 1,3,2,5,4,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Quick_sort(arr, 0,sz-1);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}