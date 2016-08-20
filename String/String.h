#ifndef    STRING_H__
#define    STRING_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class String
{
public:
	String(const char* _str="");
	String(const String& _str);
	~String();
private:	
	int m_sz;
	int m_capacity;
	char* m_str;

public:
	friend ostream& operator<<(ostream& os, const String& _str);
	String& operator=(const String& _str);   //赋值运算符重载版本1
	int length() const { return m_sz; };
	friend bool operator>(const String& str1, const String& str2);
	friend bool operator==(const String& str1, const String& str2);
	char& operator[](int i);
	String& Insert_str(const char* I_str, int pos);
	String& PushBack(char c);
	String& operator+=(const char* _str);
	int Strlen() const { return m_sz; };
};

#endif     //STRING_H__s