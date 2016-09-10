#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include <assert.h>

enum Map
{
	Row = 10,
	Col = 10,
};
struct Pos             //�Թ�����
{
	int _row;
	int _col;
	Pos(int row = 0, int col = 0)
		:_row(row)
		, _col(col)
	{}
};
int** Init_Maze1()
{
	char c;
	int row = 0;
	int col = 0;
	FILE* fm = fopen("MazeMap.txt", "r");
	assert(fm);
	while ((c = fgetc(fm)) != ' '&&c != '\n')
	{
		row = row*10+(c - '0');
	}
	while ((c = fgetc(fm)) != ' '&&c != '\n')
	{
		col = col*10+(c - '0');
	}
	int **map = new int*[col];
	for (int i = 0; i < row; i++)
	{
		map[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col;)
		{
			c = fgetc(fm);
			if (c == '1' || c == '0')
			{
				map[i][j] = c - '0';
				j++;
			}
		}
	}
	return map;
	fclose(fm);
}
void Init_Maze(int *map)
{
	char c;
	int row = 0;
	int col = 0;
	FILE* fm = fopen("MazeMap.txt", "r");
	assert(fm);
	while ((c = fgetc(fm)) != ' '&&c != '\n')
	{
		row = c - '0';
	}
	while ((c = fgetc(fm)) != ' '&&c != '\n')
	{
		col = c - '0';
	}
	for (int i = 0; i < Map::Row; i++)
	{
		for (int j = 0; j < Map::Col; )
		{
			c = fgetc(fm);
			if (c == '1' || c == '0')
			{
				map[i*Map::Col + j] = c-'0';
				j++;
			}
		}
	}
	fclose(fm);
}
void Print_Maze(int **map)
{
	assert(map);
	for (int i = 0; i < Map::Row; i++)
	{
		for (int j = 0; j < Map::Col;j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

bool CheckAccess(Pos cur,int** Map)          //ȷ����ǰ�������ܷ�ͨ��
{
	if (cur._col >= 0 && cur._row >= 0
		&& cur._col < Map::Col&&
		cur._row < Map::Row&&
		Map[cur._row][cur._col] == 0)
	{
		return true;
	}
	else
		return false;
}
bool GetPath(int** Map, int row, int col, Stack<Pos>& s, Pos entry)
{
	Pos cur = entry;
	s.Push(entry);
	Map[entry._row][entry._col]=2;       //����ڷ���ջ��
	while (!s.Empty())
	{
		Pos Next = s.Top();
		cur = Next;
		Map[cur._row][cur._col] = 2;      //�������עΪ�Ѿ��߹�
		if ((Next._row == row - 1)
			|| (Next._col == col - 1)
			|| (Next._row == 0))             //��ֹ����
		{
			return true;
		}
		//������
		Next._row--;
		if (CheckAccess(Next,Map))
		{
			s.Push(Next);
			continue;
		}
		Next = cur;
		//������
		Next._col++;
		if (CheckAccess(Next,Map))
		{
			s.Push(Next);
			continue;
		}
		Next = cur;
		//������
		Next._row++;
		if (CheckAccess(Next,Map))
		{
			s.Push(Next);
			continue;
		}
		Next = cur;
		//������
		Next._col--;
		if (CheckAccess(Next,Map))
		{
			s.Push(Next);
			continue;
		}
		Next = cur;
		//�߲�ͨ
		s.Pop();
		Map[Next._row][Next._col] = 3;   //���޷������޷��ҵ����ڵ�·���Ϊ3
	}
	return false;
}
