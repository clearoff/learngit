#include "String.h"


String::String(const char* _str)
:m_sz(strlen(_str))
, m_capacity(strlen(_str)+1)
,m_str(new char[m_capacity])                      //一定要注意对对象中的成员变量的初始化顺序
{
	cout << "String(const char* _str)" << endl;
	strcpy(m_str, _str);
}

String::String(const String& _str)
:m_sz(_str.m_sz)
, m_capacity(_str.m_capacity)
,m_str(new char[m_capacity])
{
	cout << "String(const String& _str)" << endl;
	strcpy(m_str, _str.m_str);
}

String::~String()
{
	cout << "~String()" << endl;
	if (this->m_str)
	{
		delete[] m_str;
		m_str = NULL;
		m_capacity = 1;
		m_sz = 0;
	}
}

ostream& operator<<(ostream& os, const String& _str)
{
	os << _str.m_str;
	return os;
}

String& String:: operator=(const String& _str)         //版本1
{
	cout << "operator=()" << endl;
	delete[] this->m_str;						 //先释放当前的这块空间
	m_str = new char[_str.m_capacity];
	this->m_capacity = _str.m_capacity;
	this->m_sz = _str.m_sz;
	strcpy(m_str, _str.m_str);
	return *this;
}

bool operator>(const String& str1, const String& str2)
{
	if (strcmp(str1.m_str, str2.m_str) > 0)
		return true;
	else
		return false;
}

bool operator==(const String& str1, const String& str2)
{
	if (strcmp(str1.m_str, str2.m_str) == 0)
		return true;
	else
		return false;
}

char& String::operator[](int i)
{
	return this->m_str[i];
}

String& String::Insert_str(const char* I_str, int pos)
{
	int i;
	int len = strlen(I_str);
	m_capacity = m_capacity + len;
	m_sz = len + m_sz;
	char* tmp = new char[m_capacity];
	for (i = 0; i < pos; i++)
	{
		tmp[i] = m_str[i];
	}
	tmp[pos] = '\0';
	strcat(tmp, I_str);
	strcat(tmp, m_str + pos);
	std::swap(tmp, m_str);
	delete[] tmp;
	return *this;
}

String&String::PushBack(char c)
{
	char* tmp = new char[++m_capacity];
	strcpy(tmp, m_str);
	tmp[m_sz++] = c;
	tmp[m_sz] = '\0';
	std::swap(tmp, m_str);
	delete[] tmp;
	return *this;
}

//String& String::operator+=(const char* _str)
//{
//
//}