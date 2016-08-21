#include "Seqlist.h"
using namespace std;

void test()
{
	Seqlist seq1;
    seq1.PushBack(1);
	seq1.PushBack(2);
	seq1.PushBack(3);
	seq1.PushBack(4);
	seq1.PushBack(5);
	seq1.PushBack(1);
	seq1.PushBack(2);
	seq1.PushBack(3);
	seq1.PushBack(4);
	seq1.PushBack(5);
	seq1.PushBack(5);
	Seqlist seq2(seq1);
	seq2[1] = 0;
	cout << (seq1) << endl;
	cout << "se1::size:" << (seq1.GetSize()) <<" "<<  "se1::capacity:"<<seq1.GetCapacity()<< endl;
	cout << (seq2) << endl;
	cout << "se2::size:" << (seq2.GetSize()) << " " << "se2::capacity:" << seq2.GetCapacity() << endl;
}
void test2()
{
	Seqlist seq1;
	seq1.PushBack(10);
	seq1.PushBack(9);
	seq1.PushBack(8);
	seq1.PushBack(7);
	seq1.PushBack(6);
	seq1.PushBack(5);
	seq1.PushBack(4);
	seq1.PushBack(3);
	seq1.PushBack(2);
	seq1.PushBack(1);
	seq1.PushBack(0);
	cout << seq1 << endl;
	seq1.Bubble_Sort();
	cout << (seq1) << endl;
}
int main()
{
	test2();
	system("pause");
	return 0;
}