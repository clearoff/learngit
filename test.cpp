#include <iostream>

using namespace std;

//int main()
//{
//	int num = 10;
//	int *pNum = &num;
//    int &refnum = *pNum;;
//	cout << "num:" << num << endl;
//	cout << "refnum:" << refnum << endl;
//	int num1 = 20;
//	pNum = &num1;
//	cout << "num1:" << num1 << endl;
//	cout << "refnum:" << refnum << endl;            //改变了指针变量的指向  依然不能改变refnum是num引用的事实
//	return 0;
//}

//int main()
//{
//	int Num = 10;
//	const int &refNum = Num;
//    cout << "Num:" << Num << endl;
//    cout << "refNum:" << refNum << endl;
//	//refNum = 20;                                  //错误的代码  不能向常量的引用赋值
//	cout << "Num:" << Num << endl;
//	cout << "refNum:" << refNum << endl;
//	return 0;
//}


//void Cube(int &ra)
//{
//	
//}
//int main()
//{
//	int a = 3;
//	Cube(a+3);             //错误传参   非常量引用的 初始值必须为左值
//	cout << a << endl;
//}



//关于函数形参为const引用类型的临时变量是否创建的问题
//void Swap(const long int &a, const long int &b)
//{
//	//int tmp;
//	//tmp = (int)a;
//	//(long int)a = (int)b;
//	//(long int)b = tmp;
//}
//
//
//int main()
//{
//    int num1 = 2;
//    int num2 = 3;            //传参时创建临时变量
//      long int num3=2;       //传参时不创建临时变量
//	cout << "num1:" << num1 << endl;
//	cout << "num2:" << num2 << endl;
//	Swap(num1, num2);
//	cout << "Swap;;num1:" << num1 << endl;
//	cout << "Swap;;num2:" << num2 << endl;
//	return 0;
//}
