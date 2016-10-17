#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "HuffmanTree.hpp"
#include <string>
#include <cassert>

typedef long long  LongType;


//�ַ���Ϣ
struct CharInfo
{
	char _ch;                  //�ַ�
	LongType _count;           //�ַ����ļ��г��ֵĴ���
	string _code;              //Huffman����

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

		// 1.ͳ���ַ����ֵĴ���
		assert(filename);
		FILE* fout = fopen(filename, "r");                //��ֻ����ʽ���ļ�
		assert(fout);


		//��ȡ�ļ��е��ַ�  
		char ch = fgetc(fout);
		while (ch != EOF)
		{
			_Infos[ch]._count++;
			ch = fgetc(fout);
		}

		//fclose(fout);

		// 2.����huffman tree
		CharInfo invaild;
		HuffmanTree<CharInfo> Tree(_Infos, 256,invaild);


		// 3.����huffmn code
		string code;
		_GenerateHuffmanCode(Tree.ReturnRoot(), code);

		//4.ѹ��
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
		cout << "�ļ�ѹ���ɹ�" << endl;
		fclose(fin);
		fclose(fout);
		return CompressFilename;
	}

	string UnCompress(const char* filename)                 //��ѹ��
	{
        //��Ҫ����ѹ�����ļ�
		assert(filename);
		FILE* fout = fopen(filename, "r");
		assert(fout);

		//����ѹ���ļ��ĺ�׺��.Compress��
		string CompressFilename = filename;
		size_t index=CompressFilename.rfind('.');
		string UnCompressFilename = CompressFilename.substr(0, index);
		UnCompressFilename.append(".UnCompress");

		// ����huffman tree
		CharInfo invaild;
		HuffmanTree<CharInfo> Tree(_Infos, 256, invaild);

		//������ѹ���ļ�,��д��
		FILE* fin = fopen(UnCompressFilename.c_str(), "w");
		assert(fin);
		Node* root = Tree.ReturnRoot();
		Node* cur = root;
		size_t count = root->_Weight._count;

	    char ch = fgetc(fout);
		int pos = 7;
		char value = 0;
		value = (ch>>pos) & 1;                               //ȡch�����λ
		while (ch != EOF&&(count!=0))
		{

			if (value == 0)                          //�������ַ��ǡ�0�� �����������������
			{
			   //
				pos--;
				cur = cur->_Left;
			}

			if (value == 1)                          //�������ַ��� ��1�� �������������ұ���
			{
				//
				pos--;
				cur = cur->_Right;
			}

			if (cur->_Left == NULL&&
				cur->_Right == NULL)                   //���ļ���д���ַ�������
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

		_GenerateHuffmanCode(root->_Left, code + '0');              //���������߱���׷��'0'
		_GenerateHuffmanCode(root->_Right, code + '1');             //���������߱���׷��'1'
	}
protected:
	CharInfo _Infos[256];
};