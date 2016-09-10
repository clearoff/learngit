#pragma once
#include "Stack.h"
#include <cassert>

struct Pos     //����
{
	int Pos_x;   //������
	int Pos_y;   //������
public:
	Pos(int row=0,int col=0)
		:Pos_x(row)
		, Pos_y(col)
	{}
};

template <class T>
class Maze
{
public:
	Maze()
		:_map(NULL)
		, _entry(Pos())
		, Rows(0)
		, Cols(0)
		, _s(Stack<Pos>())
	{}
	void InitMaze()
	{
		char c;
		FILE* fm = fopen("MazeMap.txt", "r");
		assert(fm);
		while ((c = fgetc(fm)) != ' '&&c != '\n')  //��ȡ��ͼ������
		{
			Rows = Rows * 10 + (c - '0');
		}		
		while ((c = fgetc(fm)) != ' '&&c != '\n')  //��ȡ��ͼ������
		{
			Cols = Cols * 10 + (c - '0');
		}
		while ((c = fgetc(fm)) != ' '&&c != '\n')  //��ȡ��ͼ����ں�����
		{
			_entry.Pos_x = c - '0';
		}
		while ((c = fgetc(fm)) != ' '&&c != '\n')  //��ȡ��ͼ�����������
		{
			_entry.Pos_y = c - '0';
		}
		//���ٿռ�
		_map = new T*[Cols];
		for (int i = 0; i < Cols; i++)
		{
			_map[i] = new T[Rows];
		}
		//��ͼ��ʼ��
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols;)
			{
				if ((c = fgetc(fm)) == '1' || c == '0')
				{
					_map[i][j] = c - '0';
					j++;
				}
			}
		}
		fclose(fm);
	}
	bool GetPath()
	{
		assert(_map);
		Pos cur = _entry;
		_s.Push(cur);                 //����ǰ������Ϣ��ջ
		_map[cur.Pos_x][cur.Pos_y] = 2;
		while (!_s.Empty())
		{
			Pos Next = _s.Top();      //ȡ�õ�ǰλ�õĽڵ�
			cur = Next;
			_map[cur.Pos_x][cur.Pos_y] = 2;
			if (cur.Pos_x == Rows - 1 || cur.Pos_y == Cols - 1 || cur.Pos_x == 0)
			{
				return true;
			}
			//������
			Next.Pos_x--;
			if (CheckAccess(Next))
			{
				_s.Push(Next);         //�������ͨ��  ������ѹ��ջ��
				continue;
			}
			Next = cur;               //�������򷵻ص�ǰλ��
			//������
			Next.Pos_y++;
			if (CheckAccess(Next))
			{
				_s.Push(Next);         //�������ͨ��  ������ѹ��ջ��
				continue;
			}
			Next = cur;               //�������򷵻ص�ǰλ��
			//������
			Next.Pos_x++;
			if (CheckAccess(Next))
			{
				_s.Push(Next);         //�������ͨ��  ������ѹ��ջ��
				continue;
			}
			Next = cur;               //�������򷵻ص�ǰλ��
			//������
			Next.Pos_y--;
			if (CheckAccess(Next))
			{
				_s.Push(Next);         //�������ͨ��  ������ѹ��ջ��
				continue;
			}
			Next = cur;               //�������򷵻ص�ǰλ��
			
			//����ͨ���򽫵�ǰλ�ó�ջ
			_s.Pop();
			_map[Next.Pos_x][Next.Pos_y] = 3;   //��ǲ����ߵ��յ��λ��Ϊ3
		}
		return false;
	}
	void PrintMaze()
	{
		assert(_map);
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				cout << _map[i][j] << " ";
			}
			cout << endl;
		}
	}
	~Maze()
	{
		if (_map != NULL)
		{
			for (int i = 0; i < Rows; i++)
			{
				delete[] _map[i];
			}
			delete[] _map;
			_map = NULL;
			cout << "The Maze memory is Realsed" << endl;
		}
	}
protected:
	bool CheckAccess(Pos cur)
	{
		if (cur.Pos_x >= 0 && cur.Pos_y >= 0
			&& cur.Pos_x < Rows&&cur.Pos_y < Cols
			&&_map[cur.Pos_x][cur.Pos_y] == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
protected:
	T** _map;
	Pos _entry;          //�������
	int Rows;            //��ͼ����
	int Cols;            //��ͼ����
	Stack<Pos> _s;         //�洢·����ջ
};