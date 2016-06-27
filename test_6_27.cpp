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
//int book[101];          //存储访问过顶点的数组，若顶点已被访问，则对应的下标数组中的元素置1
//int sum;                //记录已经访问过的顶点的个数
//int Graph[101][101];    //存储相应顶点链接关系的图的数组
//int n;                  //存储图中顶点的个数
//int m;                  //存储图中边的个数
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
//	for (i = 1; i <= n;i++)                 //对图中的顶点进行初始化
//	for (j = 1; j <= i; j++)
//	{
//		if (i == j)
//			Graph[i][j] = 0;               //同一个点与同一个点之间无连接关系
//		else
//			Graph[i][j] = -1;
//	}
//	printf("\n请输入图中顶点的边的个数：");
//	scanf("%d", &m);
//	printf("\n");
//	for (i = 1; i <= m; i++)
//	{
//		printf("请输入具有连接关系的两个顶点：\n");
//		scanf("%d %d", &a, &b);           //输入每个顶点之间的连接关系
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

