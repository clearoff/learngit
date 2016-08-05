#include "Date.h"

void test1() //²âÊÔº¯Êı1
{
	Date date1(2016,3,1);
	Date date2(2015,3,2);
	int count = date1 - date2;
	cout << count << endl;
}
int main()
{
	test1();
	return 0;
}