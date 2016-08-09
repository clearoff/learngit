//��ָoffer::������8����ת�������С����
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

	int index1 = 0;             //"ͷָ��"
	int index2 = size_arr - 1;  //"βָ��"
	int index_mid = 0;          //"�м�Ԫ��ָ��"
	while (arr[index1] >= arr[index2])
	{
		//�۰���ҵ����
		if ((index2 - index1) == 1)
		{
			index_mid = index2;
			break;
		}
		else
		{
			index_mid = (index1 + index2) / 2;
		}
		//˳����ҵ����
		if (arr[index1] == arr[index_mid]
			&& arr[index_mid] == arr[index2])
		{
			return Min_order(arr, size_arr);
		}
		//�۰�
		if (arr[index_mid] >= arr[index1])         //��δ������ת��������
			index1 = index_mid;
		else if (arr[index_mid] <= arr[index2])    //�ڽ�����ת���������
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