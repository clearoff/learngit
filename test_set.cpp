#include <iostream>
#include <set>
using namespace std;

int main()
{
	//set������е�Ԫ���Զ���������
	int a[] = { 0, 1, 2, 4, 3, 5 };
	set<int> mySet(a, a + sizeof(a) / sizeof(a[0]));
	multiset<int> mSet(a, a + 6);
	multiset<int>::iterator mit = mSet.begin();
	set<int>::iterator it= mySet.begin();
	while (it!=mySet.end())
	{
		cout << *it << " ";
		//*it = 10;     //����ͨ����������set�е�ֵ�����޸�
		it++;
	}
	cout << endl;
	cout << "mySet::size--->" << mySet.size() << endl;

	//c����һ���ؼ���
	/*it = mySet.insert(3).first;*/
	cout << *mySet.insert(3).first << "----" << mySet.insert(3).second << endl;
	//insset����ǲ���keyֵ�Ļ����ص���һ��pair<iterator,bool>  
	//����ɹ��ͷ��ز�����Ǹ�λ�õĵ�����
	//���벻�ɹ������Ѿ��������Ԫ��λ�õĵ�����

	//����һ������
	int b[] = { 7, 8, 9 };
	mySet.insert(b, b + sizeof(b) / sizeof(b[0]));  //����һ�������򲻷����κ�ֵ
	it = mySet.begin();
	while (it != mySet.end())
	{
		cout << *it << " ";
		//*it = 10;     //����ͨ����������set�е�ֵ�����޸�
		it++;
	}
	cout << endl;

	mit=mSet.insert(5);
	cout << *mit << endl;
	//ɾ��    
	cout << mySet.erase(7) << endl;   //�����erase(const K& key)  �򷵻���ɾ��Ԫ�صĸ���
	cout << mSet.erase(5) << endl;    

	//lower_bound
	it = mySet.lower_bound(2);      //���ص�һ�����ڵ���Ԫ��2��λ�õĵ�����
	cout << "lower_bound" << endl;
	while (it != mySet.end())
	{
		cout << *it << " ";    
		it++;
	}

	//upper_bound
	it = mySet.upper_bound(2);         //���ص�һ������key�ĵ�����
	cout << "upper_bound" << endl;
	while (it != mySet.end())
	{
		cout << *it << " ";
		it++;
	}
	return 0;
}