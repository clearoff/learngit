#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "HuffmanTree.hpp"
#include <string>
#include <cassert>

typedef long long  LongType;


//字符信息
struct CharInfo
{
	char _ch;                  //字符
	LongType _count;           //字符在文件中出现的次数
	string _code;              //Huffman编码

	CharInfo(LongType count)
		:_ch(0)
		, _count(count)
	{}

	CharInfo()
		:_ch(0)
		,_count(0)
	{}

	CharInfo operator+(const CharInfo& info)
	{
		return CharInfo(_count + info._count);
	}

	bool operator<(const CharInfo& info)
	{
		return _count < info._count;
	}

	bool operator!=(const CharInfo& info)
	{
		return  _count != info._count;
	}
};

class FileCompress
{
	typedef HuffmanTreeNode<CharInfo>  Node;
public:
	FileCompress()
	{
		for (int i = 0; i < 256; i++)
		{
			_Infos[i]._ch = i;
		}
	}

	string Compress(const char* filename)
	{

		// 1.统计字符出现的次数
		assert(filename);
		FILE* fout = fopen(filename, "r");                //以只读方式打开文件
		assert(fout);


		//读取文件中的字符  
		char ch = fgetc(fout);
		while (ch != EOF)
		{
			_Infos[ch]._count++;
			ch = fgetc(fout);
		}

		//fclose(fout);

		// 2.生成huffman tree
		CharInfo invaild;
		HuffmanTree<CharInfo> Tree(_Infos, 256,invaild);


		// 3.生成huffmn code
		string code;
		_GenerateHuffmanCode(Tree.ReturnRoot(), code);

		//4.压缩
		string CompressFilename = filename;
		CompressFilename.append(".Compress");
		FILE* fin = fopen(CompressFilename.c_str(), "w");

		fseek(fout, SEEK_SET, 0);
		ch = fgetc(fout);
		
		char value = 0;
		size_t pos = 0;
		while (ch != EOF)
		{
			code = _Infos[ch]._code;

			for (size_t i = 0; i < code.size(); i++)
			{
				//value &= (code[i]&1);
				//value <<= 1;
				if (code[i] == '1')
				{
					value <<= 1;
					value |= 1;
				}
				else
					value <<= 1;

				pos++;
				if (pos == 8)
				{
					pos = 0;
					fputc(value, fin);
					value = 0;
				}
			}
			ch = fgetc(fout);
		}
		if (pos != 0)
		{
			value <<= (8 - pos);
			fputc(value, fin);
		}
		cout << "文件压缩成功" << endl;
		fclose(fin);
		fclose(fout);
		return CompressFilename;
	}

	string UnCompress(const char* filename)                 //解压缩
	{
        //打开要被解压缩的文件
		assert(filename);
		FILE* fout = fopen(filename, "r");
		assert(fout);

		//消除压缩文件的后缀（.Compress）
		string CompressFilename = filename;
		size_t index=CompressFilename.rfind('.');
		string UnCompressFilename = CompressFilename.substr(0, index);
		UnCompressFilename.append(".UnCompress");

		// 生成huffman tree
		CharInfo invaild;
		HuffmanTree<CharInfo> Tree(_Infos, 256, invaild);

		//创建解压缩文件,并写入
		FILE* fin = fopen(UnCompressFilename.c_str(), "w");
		assert(fin);
		Node* root = Tree.ReturnRoot();
		Node* cur = root;
		size_t count = root->_Weight._count;

	    char ch = fgetc(fout);
		int pos = 7;
		char value = 0;
		value = (ch>>pos) & 1;                               //取ch的最高位
		while (ch != EOF&&(count!=0))
		{

			if (value == 0)                          //读到的字符是‘0’ 往哈夫曼树的左边走
			{
			   //
				pos--;
				cur = cur->_Left;
			}

			if (value == 1)                          //读到的字符是 ‘1’ 往哈夫曼树的右边走
			{
				//
				pos--;
				cur = cur->_Right;
			}

			if (cur->_Left == NULL&&
				cur->_Right == NULL)                   //向文件中写入字符的条件
			{
				fputc((cur->_Weight._ch), fin);
				count--;
				cur = root;
			}

			if (pos < 0)
			{
				pos = 7;
				ch = fgetc(fout);
			}
			value = (ch >> pos) & 1;
		}

		return UnCompressFilename;
	}

protected:
	void _GenerateHuffmanCode(Node* root, string code)
	{
		if (root == NULL)
			return;

		if (root->_Left == NULL&&
			root->_Right == NULL)
		{
			_Infos[root->_Weight._ch]._code = code;
		}

		_GenerateHuffmanCode(root->_Left, code + '0');              //往左子树走编码追加'0'
		_GenerateHuffmanCode(root->_Right, code + '1');             //往右子树走编码追加'1'
	}
protected:
	CharInfo _Infos[256];
};