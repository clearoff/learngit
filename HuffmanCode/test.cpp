#define _CRT_SECURE_NO_WARNINGS
#include "HuffmanTree.hpp"
#include "FileCompress.hpp"


//void HuffmanTreeTest()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	HuffmanTree<int> h1(a, sizeof(a) / sizeof(a[0]));
//}

int  main()
{
	FileCompress f1;
	string CompressFilename=f1.Compress("HuffmanTest.txt");
	string UnCompressFileName = f1.UnCompress(CompressFilename.c_str());
	return 0;
}