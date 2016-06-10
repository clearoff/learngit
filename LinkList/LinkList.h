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
void PushBack(pLinkList plist, DataType data);                            //β��
void PopBack(pLinkList plist);                                           //βɾ
void PushFront(pLinkList plist, DataType data);                         //ͷ��
void PopFront(pLinkList plist);                                        //ͷɾ
void PrintList(pLinkList plist);                                      //��ӡ����
pLinkNode FindNode(pLinkList plist, DataType data);                  //����
void Insert(pLinkList plist, DataType data, pLinkNode pos);         //����
void Remove(pLinkList plist, DataType data);                       //ɾ��
void Erase(pLinkList plist, int pos);
void BubbleSort(pLinkList plist);                                //ð������
void Insert_sort(pLinkList plist);                              //��������
void Select_sort(pLinkList plist);                             //ѡ������
LinkNode *Yuesefu_huan(pLinkList plist, pLinkNode pos, int k);//Լɪ������
void EraseNotTail(pLinkNode pos);                            //ɾ��������ķ�β�ڵ�
void Reverse(pLinkList plist);                              //��������
void InsertFrontNode(pLinkNode pos, DataType data);        //��ĳһ���ڵ�ǰ����һ���ڵ㣨���ṩͷ�ڵ㣩
pLinkNode FindMidNode(pLinkList plist);                   //Ѱ��������м�ڵ�
void DelKNode(pLinkList plist, int k);                   //ɾ��������k���ڵ�
#endif _LINKLIST_H__