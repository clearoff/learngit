#ifndef _LINKLIST_H__
#define _LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int DataType;
typedef struct LinkNode
{
	DataType data;
	struct LinkNode *next;
}LinkNode, *pLinkNode;
typedef struct Linklist
{
	LinkNode *phead;
}LinkList, *pLinkList;

void InitLinkList(pLinkList plist);
void DestoryLinkList(pLinkList plist);
void PushBack(pLinkList plist, DataType data);                            //尾插
void PopBack(pLinkList plist);                                           //尾删
void PushFront(pLinkList plist, DataType data);                         //头插
void PopFront(pLinkList plist);                                        //头删
void PrintList(pLinkList plist);                                      //打印链表
pLinkNode FindNode(pLinkList plist, DataType data);                  //查找
void Insert(pLinkList plist, DataType data, pLinkNode pos);         //插入
void Remove(pLinkList plist, DataType data);                       //删除
void Erase(pLinkList plist, int pos);
void BubbleSort(pLinkList plist);                                //冒泡排序
void Insert_sort(pLinkList plist);                              //插入排序
void Select_sort(pLinkList plist);                             //选择排序
LinkNode *Yuesefu_huan(pLinkList plist, pLinkNode pos, int k);//约瑟夫环问题
void EraseNotTail(pLinkNode pos);                            //删除单链表的非尾节点
void Reverse(pLinkList plist);                              //逆序单链表
void InsertFrontNode(pLinkNode pos, DataType data);        //在某一个节点前插入一个节点（不提供头节点）
pLinkNode FindMidNode(pLinkList plist);                   //寻找链表的中间节点
void DelKNode(pLinkList plist, int k);                   //删除倒数第k个节点
#endif _LINKLIST_H__