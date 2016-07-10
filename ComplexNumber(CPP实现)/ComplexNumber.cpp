#include <iostream>
#include "ComplexNumber.h"

Complex::Complex(double real , double image )          //��ȱʡ�����Ĺ��캯��
{
	m_real = real;
	m_image = image;
}
Complex::~Complex()
{
	cout << "Over!!!" << endl;
}
void Complex::Print()
{
	cout << "��������ĸ���Ϊ::" << m_real << "+<" << m_image << "i>" << endl;
}
Complex operator+(Complex &c1, Complex &c2)
{
	Complex c3;
	c3.m_real = c1.m_real + c2.m_real;
	c3.m_image = c1.m_image + c2.m_image;
	return c3;
}
Complex operator-(Complex &c1, Complex &c2)
{
	Complex c3;
	c3.m_real = c1.m_real - c2.m_real;
	c3.m_image = c1.m_image - c2.m_image;
	return c3;
}
Complex operator*(Complex &c1, Complex &c2)
{
	Complex c3;
	c3.m_real = c1.m_real*c2.m_real - c1.m_image*c2.m_image;
	c3.m_image = c1.m_real*c2.m_image + c1.m_image*c2.m_real;
	return c3;
}
Complex operator/(Complex &c1, Complex &c2)     //[(ac+bd)+(bc-ad)i]/(c*c+d*d)
{
	Complex c3;
	c3.m_real = (c1.m_real*c2.m_real + c1.m_image + c2.m_image) / (c2.m_real*c2.m_real + c2.m_image*c2.m_image);
	return c3;
}
Complex Complex::operator++(int)      //����++
{
	Complex tmp(*this);
	this->m_image++;
	this->m_real++;
	return tmp;
}
Complex& Complex::operator++()         //ǰ��++
{
	this->m_image++;
	this->m_real++;

	return *this;
}