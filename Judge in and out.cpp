#include <stack>
#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include <queue>
using namespace std;

//class A
//{
//public:
//	A()
//	{
//		/*memset(this, 0, sizeof(*this));*/
//	}
//	virtual void fun()
//	{
//		cout << "fun()" << endl;
//	}
//};
//int main()
//{
//	A a;
//	a.fun();
//
//	A& ra = a;
//	ra.fun();
//
//	A* pa = &a;
//	pa->fun();
//	return 0;
//}

//��ջ������4   �жϳ�ջ����ջ���еĺϷ���
//str1Ϊ��ջ����
//str2Ϊ��ջ����
//bool CheckInAndOut(const string& str1,const string& str2)
//{
//	assert(str1.size() > 0);
//	assert(str2.size() > 0);
//	assert(str1.size() == str2.size());
//	stack<char> s1;  
//	queue<char> q1;
//	int i = 0;
//	int j = 0;
//	while(j < str2.size())
//	{
//		if (str1[i] == str2[j])
//		{
//			q1.push(str1[i]);
//			//i++;
//			j++;                      //����ǰԪ����ӣ������֮ǰ��ջ��Ԫ�أ������ȣ�Ҳ���
//			while ((s1.size() != 0) && (j<str2.size()) && (str2[j] == s1.top()))
//			{
//				q1.push(s1.top());
//				s1.pop();
//				j++;
//			}
//		}
//		else
//		{
//			s1.push(str1[i]);
//			i++;
//		}
//	}        //ģ�⹹���ջ����
//	int z = 0;
//	for (z = 0; z < str2.size(); z++)
//	{
//		if (str2[z] != q1.front())
//		{
//			break;
//		}
//		else
//		{
//			q1.pop();
//		}
//	}
//	if (z == str2.size()){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
//int main()
//{
//	string s1("12345");
//	string s2("32154");
//	cout << CheckInAndOut(s1, s2) << endl;
//	return 0;
//}