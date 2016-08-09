//剑指offer::面试题8：旋转数组的最小数字
#include <iostream>
#include <assert.h>
using namespace std;

int Min_order(int*arr, int size_arr)
{
	int index1 = 0;
	int index2 = size_arr - 1;
	int i;
	int tmp = arr[index1];
	for (i = index1 + 1; i<size_arr; i++)
	{
		if (tmp>arr[i])
			tmp = arr[i];
	}
	return tmp;
}
int Find_Min(int* arr , int size_arr)
{
	assert(arr&&size_arr > 0);

	int index1 = 0;             //"头指针"
	int index2 = size_arr - 1;  //"尾指针"
	int index_mid = 0;          //"中间元素指针"
	while (arr[index1] >= arr[index2])
	{
		//折半查找的情况
		if ((index2 - index1) == 1)
		{
			index_mid = index2;
			break;
		}
		else
		{
			index_mid = (index1 + index2) / 2;
		}
		//顺序查找的情况
		if (arr[index1] == arr[index_mid]
			&& arr[index_mid] == arr[index2])
		{
			return Min_order(arr, size_arr);
		}
		//折半
		if (arr[index_mid] >= arr[index1])         //在未进行旋转的序列中
			index1 = index_mid;
		else if (arr[index_mid] <= arr[index2])    //在进行旋转后的序列中
			index2 = index_mid;
	}
	return arr[index_mid];
}
int main(void)
{
	int arr[] = {3,4,5,1,2};
	int arr1[] = { 1, 0, 1, 1, 1, 1 };
	cout<<Find_Min(arr1, sizeof(arr1)/sizeof(arr1[0]))<<endl;
	return 0;
}