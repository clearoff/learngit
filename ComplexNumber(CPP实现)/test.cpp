#include <iostream>
#include "ComplexNumber.h"
using namespace std;


int main()
{
	Complex c1(1.0, 2.0);
	Complex c2(2.0, 3.0);
	Complex ret = ++c1;
	ret.Print();
	return 0;
}