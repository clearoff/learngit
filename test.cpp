//#include <iostream>
//using namespace std;
//#include <string>
////struct  __TrueType
////{
////	bool  Get()
////	{
////		return  true;
////	}
////};
////struct  __FalseType
////{
////	bool  Get()
////	{
////		return  false;
////	}
////};
////
////template  <class  _Tp>
////struct  TypeTraits
////{
////	typedef  __FalseType    __IsPODType;
////};
////
////template  <>
////struct  TypeTraits<bool>
////{
////	typedef  __TrueType     __IsPODType;
////};
////
////int main()
////{
////	cout << TypeTraits<int>::__IsPODType().Get() << endl;      //构造函数创建对象，对象才能调用成员函数
////	return 0;
////}
//
//struct  __TrueType
//{
//	bool  Get()
//	{
//		return  true;
//	}
//};
//struct  __FalseType
//{
//	bool  Get()
//	{
//		return  false;
//	}
//};
//template  <class  _Tp>
//struct  TypeTraits
//{
//	typedef  __FalseType    __IsPODType;
//};
//
////通过类的特化来把内置类型萃取为POD
//template  <>
//struct  TypeTraits<  bool>
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  char>
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  unsigned  char  >
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  short>
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  unsigned  short  >
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  int>
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  unsigned  int  >
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  long>
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  unsigned  long  >
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  long  long  >
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  unsigned  long  long>
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  float>
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  double>
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <>
//struct  TypeTraits<  long  double  >
//{
//	typedef  __TrueType       __IsPODType;
//};
//template  <class  _Tp>
//struct  TypeTraits<  _Tp*>
//{
//	typedef  __TrueType       __IsPODType;
//};
//
//  //使用参数推到的萃取处理
//
//template  <class  T>
//void  Copy(const  T*  src, T*  dst, size_t  size, __FalseType)
//{
//	cout << "__FalseType:" << typeid(T).name() << endl;
//	for (size_t i = 0; i < size; ++i)
//	{
//		dst[i] = src[i];
//	}
//}
//template  <class  T>
//void  Copy(const  T*  src, T*  dst, size_t  size, __TrueType)
//{
//	cout << "__TrueType:" << typeid(T).name() << endl;
//	memcpy(dst, src, size*sizeof  (T));
//}
//
//  //使用萃取判断类型的Get函数判断是否是  POD类型来处理
//
//template  <class  T>
//void  Copy(const  T*  src, T*  dst, size_t  size)
//{
//	cout << "__TrueType:" << typeid(T).name() << endl;
//	if (TypeTraits  <T>::__IsPODType().Get())
//	{
//		memcpy(dst, src, size*sizeof  (T));
//	}
//	else
//	{
//		for (size_t i = 0; i < size; ++i)
//		{
//			dst[i] = src[i];
//		}
//	}
//}
//void  Test1()
//{
//	string  s1[10] = { "1", "2", "3", "4444444444444444444444444" };
//	string  s2[10] = { "11", "22", "33" };
//	Copy(s1, s2, 10, TypeTraits  <string>::__IsPODType());
//	Copy(s1, s2, 10);
//	int  a1[10] = { 1, 2, 3 };
//	int  a2[10] = { 0 };
//	Copy(a1, a2, 10, TypeTraits  <int>::__IsPODType());
//	Copy(a1, a2, 10);
//}
//
//int main()
//{
//	Test1();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//
//template<class T>
//class Date
//{
//public:
//	Date()
//   {
//		   cout << "Date()" << endl;
//   }
//private:
//	T _num;
//};
//template<>
//class Date<int>
//{
//public:
//	Date()
//	:_num2(0)
//	{
//		cout << "Date<int>()" << endl;
//	}
//private:
//	int _num2;
//};
//int main()
//{
//	Date<char> d1;
//	Date<int> d2;
//   return 0;
//}
//
//#include <iostream>
//using namespace std;
//#include <string>
//
//struct __TrueType
//{
//	bool Get()
//	{
//		return true;
//	}
//};
//
//struct __FalseType
//{
//	bool Get()
//	{
//		return false;
//	}
//};
//
//template<class _tp>
//struct TypeTrit
//{
//	typedef __FalseType __IsPODType;
//};
//
//template<>
//struct TypeTrit<int>
//{
//	typedef __TrueType __IsPODType;
//};
//template<>
//struct TypeTrit<char>
//{
//	typedef __TrueType __IsPODType;
//};
//template<>
//struct TypeTrit<bool>
//{
//	typedef __TrueType __IsPODType;
//};
//
////void test1()
////{
////	cout << TypeTrit<string>::__IsPODType().Get() << endl;
////	cout << TypeTrit<int>::__IsPODType().Get() << endl;
////}
//template<class T>
//void Copy(T src, T dst, int sz)
//{
//	if (TypeTrit<T>::__IsPODType().Get())
//	{
//		memcpy(dst, src, sz*sizeof(T));
//	}
//	else
//	{
//		for (int i = 0; i < sz; i++)
//		{
//			dst[i] = src[i];
//		}
//	}
//}
//void test2()
//{
//	//int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	//int arr2[10];
//	string s1[] = { "aaaaa", "bbbbb", "cccccc", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" };
//	string s2[4];
//	Copy(s1, s2, 4);
//}
//int main()
//{
//	test2();
//	return 0;
//}