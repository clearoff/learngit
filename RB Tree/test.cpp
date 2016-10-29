#include "RBTree.hpp"


int main()
{
	RBTree<int, int> t1;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		t1.Insert(a[i], i);
		cout << "IsBalance?" << t1.IsBalance() << "-->" << a[i] << endl;
	}
	t1.InOrder();
	cout<<t1.IsBalance()<<endl;
	return 0;
}