#include "String.h"

void test1()
{
	String str1("hello world");
	String str2("abcdef");
	String str3(str1);
	cout << (str1 == str2) << endl;
	cout << (str1 > str2) << endl;
	cout << (str1[4]) << endl;
	str1[4] = 'a';
	cout << str1 << endl;
}
void test2()
{
	String str1("I leap");
	cout << str1 << " " << str1.Strlen() << endl;
	str1.Insert_str("hello world ", 2);
	cout << str1 << " " << str1.Strlen() << endl;
}
void test3()
{
	String str1("I lea");
	cout << str1 << endl;
	str1.PushBack('p');
	cout << str1 << endl;
}
int main()
{
	test2();
	return 0;
}