#ifndef __COMPLEXNUMBER_H__
#define __COMPLEXNUMBER_H__
#include <iostream>
using namespace std;

class Complex
{
private:
	double m_real;            //������ʵ��
	double m_image;           //�������鲿
public:
	Complex(double real=0, double image=0);           //���캯��
	~Complex();                                       //��������
	void Print();
	friend Complex operator+(Complex &c1,Complex &c2);
	friend Complex operator-(Complex &c1, Complex &c2);
	friend Complex operator*(Complex &c1, Complex &c2);
	friend Complex operator/(Complex &c1, Complex &c2);
	Complex operator++(int);      //����++
	Complex& operator++();         //ǰ��++
};


#endif  //__COMPLEXNUMBER_H__