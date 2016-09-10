#pragma once
#include "Stack.h"
#include <cassert>

struct Pos     //坐标
{
	int Pos_x;   //横坐标
	int Pos_y;   //纵坐标
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
		while ((c = fgetc(fm)) != ' '&&c != '\n')  //读取地图的行数
		{
			Rows = Rows * 10 + (c - '0');
		}		
		while ((c = fgetc(fm)) != ' '&&c != '\n')  //读取地图的列数
		{
			Cols = Cols * 10 + (c - '0');
		}
		while ((c = fgetc(fm)) != ' '&&c != '\n')  //读取地图的入口横坐标
		{
			_entry.Pos_x = c - '0';
		}
		while ((c = fgetc(fm)) != ' '&&c != '\n')  //读取地图的入口纵坐标
		{
			_entry.Pos_y = c - '0';
		}
		//开辟空间
		_map = new T*[Cols];
		for (int i = 0; i < Cols; i++)
		{
			_map[i] = new T[Rows];
		}
		//地图初始化
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
		_s.Push(cur);                 //将当前坐标信息入栈
		_map[cur.Pos_x][cur.Pos_y] = 2;
		while (!_s.Empty())
		{
			Pos Next = _s.Top();      //取得当前位置的节点
			cur = Next;
			_map[cur.Pos_x][cur.Pos_y] = 2;
			if (cur.Pos_x == Rows - 1 || cur.Pos_y == Cols - 1 || cur.Pos_x == 0)
			{
				return true;
			}
			//向上走
			Next.Pos_x--;
			if (CheckAccess(Next))
			{
				_s.Push(Next);         //如果可以通过  将坐标压入栈内
				continue;
			}
			Next = cur;               //不可以则返回当前位置
			//向右走
			Next.Pos_y++;
			if (CheckAccess(Next))
			{
				_s.Push(Next);         //如果可以通过  将坐标压入栈内
				continue;
			}
			Next = cur;               //不可以则返回当前位置
			//向下走
			Next.Pos_x++;
			if (CheckAccess(Next))
			{
				_s.Push(Next);         //如果可以通过  将坐标压入栈内
				continue;
			}
			Next = cur;               //不可以则返回当前位置
			//向左走
			Next.Pos_y--;
			if (CheckAccess(Next))
			{
				_s.Push(Next);         //如果可以通过  将坐标压入栈内
				continue;
			}
			Next = cur;               //不可以则返回当前位置
			
			//不能通过则将当前位置出栈
			_s.Pop();
			_map[Next.Pos_x][Next.Pos_y] = 3;   //标记不能走到终点的位置为3
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
	Pos _entry;          //入口坐标
	int Rows;            //地图的行
	int Cols;            //地图的列
	Stack<Pos> _s;         //存储路径的栈
};