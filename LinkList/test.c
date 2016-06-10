#include "LinkList.h"

void test1()
{
	LinkList list;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PopBack(&list);
	PopBack(&list);
	PopBack(&list);
	PrintList(&list);
	PushFront(&list, 6);
	PushFront(&list, 7);
	PushFront(&list, 8);
	PrintList(&list);
	PopFront(&list);
	PrintList(&list);
	DestoryLinkList(&list);
	PrintList(&list);
}
void test2()
{
	LinkList list;
	LinkNode *ret = NULL;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PrintList(&list);
	ret = FindNode(&list, 1);
	Insert(&list, 9, ret);
	PrintList(&list);
}
void test3()
{
	LinkList list;
	LinkNode *ret = NULL;
	InitLinkList(&list);
	PushBack(&list, 5);
	PushBack(&list, 4);
	PushBack(&list, 3);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PrintList(&list);
	BubbleSort(&list);
	PrintList(&list);
	DestoryLinkList(&list);
}
void test4()
{
	LinkNode *ret = NULL;
	LinkList list;
	InitLinkList(&list);
	PushBack(&list, 5);
	PushBack(&list, 4);
	PushBack(&list, 3);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PrintList(&list);
	Erase(&list, 3);
	PrintList(&list);
	//Remove(&list, 4);
	//PrintList(&list);
	/*ret=FindNode(&list, 3);*/
	//if (ret == NULL)
	//{
	//	printf("没有找到节点！\n");
	//}
	//else
	//{
	//	printf("%d \n", ret->data);
	//}
}
void test5()
{
	LinkNode *ret = NULL;
	LinkList list;
	InitLinkList(&list);
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PushBack(&list, 6);
	PushBack(&list, 7);
	PushBack(&list, 8);
	PushBack(&list, 9);
	PushBack(&list, 10);
	ret = FindNode(&list, 1);
	ret = Yuesefu_huan(&list, ret, 2);
	printf("最后剩下的节点的数据是%d\n", ret->data);
}
void test6()
{
	LinkList list;
	LinkNode *ret = NULL;
	InitLinkList(&list);
	PushBack(&list, 3);
	PushBack(&list, 5);
	PushBack(&list, 4);
	PushBack(&list, 2);
	PushBack(&list, 1);
	PrintList(&list);
	//ret = FindNode(&list, 2);
	//InsertFrontNode(ret, 0);           //3 5 4 0 2 1
	//PrintList(&list);
	//ret=FindMidNode(&list);
	DelKNode(&list, 5);
	PrintList(&list);
	DestoryLinkList(&list);
}
int main()
{
	test6();
	return 0;
}

