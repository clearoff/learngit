#ifndef __COMPLEXNUMBER_H__
#define __COMPLEXNUMBER_H__
#include <iostream>
using namespace std;

class Complex
{
private:
	double m_real;            //复数的实部
	double m_image;           //复数的虚部
public:
	Complex(double real=0, double image=0);           //构造函数
	~Complex();                                       //析构函数
	void Print();
	friend Complex operator+(Complex &c1,Complex &c2);
	friend Complex operator-(Complex &c1, Complex &c2);
	friend Complex operator*(Complex &c1, Complex &c2);
	friend Complex operator/(Complex &c1, Complex &c2);
	Complex operator++(int);      //后置++
	Complex& operator++();         //前置++
};


#endif  //__COMPLEXNUMBER_H__