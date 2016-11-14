#include <iostream>
#include <set>
using namespace std;

int main()
{
	//set会对其中的元素自动进行排序
	int a[] = { 0, 1, 2, 4, 3, 5 };
	set<int> mySet(a, a + sizeof(a) / sizeof(a[0]));
	multiset<int> mSet(a, a + 6);
	multiset<int>::iterator mit = mSet.begin();
	set<int>::iterator it= mySet.begin();
	while (it!=mySet.end())
	{
		cout << *it << " ";
		//*it = 10;     //不能通过迭代器对set中的值进行修改
		it++;
	}
	cout << endl;
	cout << "mySet::size--->" << mySet.size() << endl;

	//c插入一个关键字
	/*it = mySet.insert(3).first;*/
	cout << *mySet.insert(3).first << "----" << mySet.insert(3).second << endl;
	//insset如果是插入key值的话返回的是一个pair<iterator,bool>  
	//插入成功就返回插入的那个位置的迭代器
	//插入不成功返回已经存在这个元素位置的迭代器

	//插入一段区间
	int b[] = { 7, 8, 9 };
	mySet.insert(b, b + sizeof(b) / sizeof(b[0]));  //插入一段区间则不反悔任何值
	it = mySet.begin();
	while (it != mySet.end())
	{
		cout << *it << " ";
		//*it = 10;     //不能通过迭代器对set中的值进行修改
		it++;
	}
	cout << endl;

	mit=mSet.insert(5);
	cout << *mit << endl;
	//删除    
	cout << mySet.erase(7) << endl;   //如果是erase(const K& key)  则返回所删除元素的个数
	cout << mSet.erase(5) << endl;    

	//lower_bound
	it = mySet.lower_bound(2);      //返回第一个大于等于元素2的位置的迭代器
	cout << "lower_bound" << endl;
	while (it != mySet.end())
	{
		cout << *it << " ";    
		it++;
	}

	//upper_bound
	it = mySet.upper_bound(2);         //返回第一个大于key的迭代器
	cout << "upper_bound" << endl;
	while (it != mySet.end())
	{
		cout << *it << " ";
		it++;
	}
	return 0;
}