//λ���㣺ͳ�ƶ���������1�ĸ���
#include <iostream>
using namespace std;
//int Number_of_1(char num)        //����һ:����ͳ�ƵĶ�������������������1������   ȱ��  ����������ѭ��  
//{
//	int count=0;
//	while (num)
//	{
//		if ((num & 1) == 1)
//			count++;
//		num=num >> 1;
//	}
//	return count;
//}


int Number_of_1(char num)          //������  ����1����Num���������㣬Ȼ�������ƣ�ֱ��Ϊ0Ϊֹ��
{
	int count = 0;
	char tmp = 1;
	while (tmp)
	{
		if ((tmp&num) != 0 )
		{
			count++;
		}
		tmp = tmp << 1;
	}
	return count;
}

 
//int Number_of_1(char num)           //������   ��һ������ȥ1�ٺ���δ��ȥ1֮ǰ����ȥ�����������ܹ���ȥ��������ұߵ�1��
//{
//	int count = 0;
//	while (num)
//	{
//		count++;
//		num = (num - 1)&num;
//	}
//	return count;
//}


int main()
{
	cout << Number_of_1(255) << endl;
	return 0;
}