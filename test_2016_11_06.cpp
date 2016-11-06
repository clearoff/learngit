#include <iostream>
using namespace std;
#include <string>
#include <vector>



//2016年11月6日  面试题
//class Solution {
//public:
//	/**
//	* 获得两个整形二进制表达位数不同的数量
//	*
//	* @param m 整数m
//	* @param n 整数n
//	* @return 整型
//	*/
//	int countBitDiff(int m, int n) 
//	{
//		int c = m^n;
//		int count = 0;
//		for (int i = 0; i < 32; i++)
//		{
//			if ((c&(1 << i))!= 0)
//				count++;
//		}
//		return count;
//	}
//};



////判断表达式是否合法
//class ChkExpression {
//public:
//	bool chkLegal(string A) 
//	{
//		// write code here
//		int count = 0;
//		for (int i = 0; i < A.size(); i++)
//		{
//			if (A[i] == '(' || A[i] == '[' || A[i] == '{')
//			{
//				count++;
//			}
//			else if (A[i] == ')' || A[i] == ']' || A[i] == '}')
//			{
//				count--;
//			}
//			else
//				continue;
//		}
//
//		return count == 0;
//	}
//};


//请你实现一个简单的字符串替换函数。原串中需要替换的占位符为"%s",
//请按照参数列表的顺序一一替换占位符。
//若参数列表的字符数大于占位符个数。则将剩下的参数字符添加到字符串的结尾。
//给定一个字符串A，同时给定它的长度n及参数字符数组arg，请返回替换后的字符串。
//保证参数个数大于等于占位符个数。保证原串由大小写英文字母组成，同时长度小于等于500。
//大替换小

//n  字符串中的字符个数
//m  参数列表中的参数个数
class StringFormat {
public:
	string formatString(string A, int n, vector<char>& arg, int m)
	{
		// write code here
		string h;
		int index = 0;
		int count = 0;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == '%'&&A[i+1] == 's')
			{
				count++;
				h += arg[index++];
				i++;
			}
			else
				h += A[i];
		}
		while (m>count&&index<m)
		{
			h += arg[index++];
		}
		return h;
	}
};
int main()
{
	//Solution s;
	//cout << s.countBitDiff(1999, 2299) << endl;;
	//ChkExpression ch;
	//cout << ch.chkLegal("[a+b*(5-4)]*{x+b+b*(({1+2)}}");
	StringFormat  InsteadStr;
	vector<char> tmp;
	tmp.push_back('B');
	tmp.push_back('D');
	tmp.push_back('F');
	cout<<InsteadStr.formatString("A%sC%sE", 7, tmp,tmp.size())<<endl;
	return 0;
}