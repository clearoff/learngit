#include <iostream>
using namespace std;
#include <string>
#include <vector>



//2016��11��6��  ������
//class Solution {
//public:
//	/**
//	* ����������ζ����Ʊ��λ����ͬ������
//	*
//	* @param m ����m
//	* @param n ����n
//	* @return ����
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



////�жϱ��ʽ�Ƿ�Ϸ�
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


//����ʵ��һ���򵥵��ַ����滻������ԭ������Ҫ�滻��ռλ��Ϊ"%s",
//�밴�ղ����б��˳��һһ�滻ռλ����
//�������б���ַ�������ռλ����������ʣ�µĲ����ַ���ӵ��ַ����Ľ�β��
//����һ���ַ���A��ͬʱ�������ĳ���n�������ַ�����arg���뷵���滻����ַ�����
//��֤�����������ڵ���ռλ����������֤ԭ���ɴ�СдӢ����ĸ��ɣ�ͬʱ����С�ڵ���500��
//���滻С

//n  �ַ����е��ַ�����
//m  �����б��еĲ�������
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