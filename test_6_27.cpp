#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
////using namespace std;
//	namespace name1
//  {
//	int a ;
//   };
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main()
//{
//	int poodle;
//	cout << name1::a << " Please input your number :" << endl;
//	cin >>poodle;
//	cout << poodle<< endl;
//	return 0;
//}

//
//#include <stdio.h>
//int book[101];          //�洢���ʹ���������飬�������ѱ����ʣ����Ӧ���±������е�Ԫ����1
//int sum;                //��¼�Ѿ����ʹ��Ķ���ĸ���
//int Graph[101][101];    //�洢��Ӧ�������ӹ�ϵ��ͼ������
//int n;                  //�洢ͼ�ж���ĸ���
//int m;                  //�洢ͼ�бߵĸ���
//void dfs(int cur)
//{
//	int i;
//	printf("%d  ", cur);
//	sum++;
//	if (sum == n)
//		return;
//	for (i = 1; i <= n; i++)
//	{
//		if (Graph[cur][i] == 1 && book[i] == 0)
//		{
//			book[i] = 1;
//			dfs(i);
//		}
//	}
//	return;
//}
//void Init_Graph()
//{
//	int i, j;
//	int a, b;
//	printf("Please input the graph points number:");
//	scanf("%d", &n);
//	for (i = 1; i <= n;i++)                 //��ͼ�еĶ�����г�ʼ��
//	for (j = 1; j <= i; j++)
//	{
//		if (i == j)
//			Graph[i][j] = 0;               //ͬһ������ͬһ����֮�������ӹ�ϵ
//		else
//			Graph[i][j] = -1;
//	}
//	printf("\n������ͼ�ж���ıߵĸ�����");
//	scanf("%d", &m);
//	printf("\n");
//	for (i = 1; i <= m; i++)
//	{
//		printf("������������ӹ�ϵ���������㣺\n");
//		scanf("%d %d", &a, &b);           //����ÿ������֮������ӹ�ϵ
//		Graph[a][b] = 1;
//		Graph[b][a] = 1;
//	}
//}
//int main()
//{
//	Init_Graph();
//	book[1] = 1;
//	dfs(1);
//	return 0;
//}

//#include <iostream>
////using namespace std;
//	namespace name1
//  {
//	int a ;
//   };
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main()
//{
//	int poodle;
//	cout << name1::a << " Please input your number :" << endl;
//	cin >>poodle;
//	cout << poodle<< endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//
//int main()
//{
//	char alarm = '\a';
//	cout.put('M');
//	cout << alarm;
//}
#include <iostream>
	namespace name1
	{
		int a;
		int b;
	};
int main()
{

	wchar_t bob = L'P';
	//wcout << L"tall" << endl;
}

