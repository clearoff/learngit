//位运算：统计二进制数中1的个数
#include <iostream>
using namespace std;
//int Number_of_1(char num)        //方法一:（将统计的二进制数进行右移在与1操作）   缺点  容易引起死循环  
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


int Number_of_1(char num)          //方法二  （将1先与Num进行与运算，然后再左移，直到为0为止）
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

 
//int Number_of_1(char num)           //方法三   （一个数减去1再和它未减去1之前的数去进行与运算能够削去这个数最右边的1）
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