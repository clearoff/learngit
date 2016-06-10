#include "LinkList.h"

void InitLinkList(pLinkList plist)      //对链表进行初始化，让头节点指向NULL
{
	assert(plist);
	plist->phead = NULL;
}
void DestoryLinkList(pLinkList plist)   //释放单链表每一个节点的内存，避免内存泄漏
{
	assert(plist);
	if (plist->phead == NULL)
	{
		printf("单链表已空！\n");
	}
	else
	{
		LinkNode *del = plist->phead;
		LinkNode *cur = plist->phead;
		while (del)
		{
			cur = del->next;
			free(del);
			del = cur;
		}
		plist->phead = NULL;
		printf("内存清空成功！\n");
	}
}
void PushBack(pLinkList plist, DataType data)  //尾插
{
	assert(plist);
	LinkNode *NewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (NewNode == NULL)
	{
		printf("Out of memory!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		NewNode->data = data;
		NewNode->next = NULL;
		if (plist->phead == NULL)
		{
			plist->phead = NewNode;
		}
		else
		{
			LinkNode *crt = NULL;
			LinkNode *cur = plist->phead;
			while (cur)
			{
				crt = cur;
				cur = cur->next;
			}
			crt->next = NewNode;
		}
	}
}
void PopBack(pLinkList plist)
{
	assert(plist);
	LinkNode *del = plist->phead;   //第一个节点
	LinkNode *cur = plist->phead;
	if (plist->phead == NULL)
	{
		printf("链表为空！\n");
	}
	else if (cur->next == NULL)
	{
		free(cur);
		cur = NULL;
		plist->phead = NULL;
	}
	else
	{
		while (cur->next)
		{
			del = cur;
			cur = cur->next;
		}
		free(cur);
		cur = NULL;
		del->next = NULL;
	}
}
void PushFront(pLinkList plist, DataType data)
{
	assert(plist);
	LinkNode *NewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (NewNode == NULL)
	{
		printf("Out of memory!\n");
		exit(EXIT_FAILURE);
	}
	NewNode->data = data;
	NewNode->next = plist->phead;
	plist->phead = NewNode;
}
void PopFront(pLinkList plist)
{
	assert(plist);
	if (plist->phead == NULL)
	{
		printf("链表是空表！\n");
	}
	else if (plist->phead->next == NULL)    //只有一个人节点
	{
		free(plist->phead);
		plist->phead = NULL;
	}
	else
	{
		LinkNode *del = plist->phead;
		plist->phead = del->next;
		free(del);
	}
}
void PrintList(pLinkList plist)
{
	assert(plist);
	LinkNode *cur = plist->phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
pLinkNode FindNode(pLinkList plist, DataType data)
{
	assert(plist);
	if (plist->phead == NULL)
	{
		printf("链表是空链表！\n");
		return NULL;
	}
	else
	{
		LinkNode *cur = plist->phead;
		while (cur)
		{
			if (cur->data == data)
				break;
			cur = cur->next;
		}
		if (cur != NULL)
			return cur;
		else
			return NULL;

	}
}
void Insert(pLinkList plist, DataType data, LinkNode *pos)
{
	assert(plist);
	LinkNode *Ins = (LinkNode *)malloc(sizeof(LinkNode)* 1);
	LinkNode *cur = plist->phead;
	LinkNode *prev = NULL;
	if (Ins == NULL)
	{
		printf("Out of memory!\n");
		exit(EXIT_FAILURE);
	}
	Ins->data = data;
	while (cur)
	{
		if (cur == pos)
		{
			if (plist->phead == pos)
			{
				Ins->next = plist->phead;
				plist->phead = Ins;
				return;
			}
			else
			{
				Ins->next = prev->next;
				prev->next = Ins;
				return;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
void Remove(pLinkList plist, DataType data)
{
	assert(plist);
	if (plist->phead == NULL)
	{
		printf("单链表已空！");
		return;
	}
	else
	{
		LinkNode *del = plist->phead;
		LinkNode *cur = plist->phead;
		while (cur->data != data&&cur)
		{
			del = cur;
			cur = cur->next;
		}
		if (cur != NULL)
		{
			del->next = cur->next;
			free(cur);
			cur = NULL;
		}
		else
		{
			printf("没有找到数据为%d的节点！\n", data);
		}
	}
}
void Erase(pLinkList plist, int pos)
{
	assert(plist);
	int i = 1;
	LinkNode *del = plist->phead;
	LinkNode *cur = plist->phead;
	while (cur&&i != pos)
	{
		del = cur;
		cur = cur->next;
		i++;
	}
	if (cur != NULL)
	{
		del->next = cur->next;
		free(cur);
		cur = NULL;
	}
}
void BubbleSort(pLinkList plist)             //单链表的冒泡排序
{
	assert(plist);
	LinkNode *head = plist->phead;
	LinkNode *tail= NULL;
	LinkNode *crt = plist->phead;
	LinkNode *prev = NULL;
	while (crt->next)                //找到最后一个节点
	{
		crt = crt->next;
	}
	while (head->next)
	{
		tail = plist->phead;
		while (tail != crt)
		{
			if (tail->data > tail->next->data)
			{
				DataType tmp = tail->data;
				tail->data = tail->next->data;
				tail->next->data = tmp;
			}
			prev = tail;
			tail = tail->next;
		}
		head = head->next;
		crt = prev;
	}
}
void Insert_sort(pLinkList plist)
{
	assert(plist);
	pLinkNode  head = NULL;     //定义无序链表的头节点
	pLinkNode pcur2 = NULL;;    //遍历无序链表的指针
	pLinkNode pcur1 = NULL;     //遍历有序链表的指针
	pLinkNode plast = NULL;
	if (plist->phead==NULL)
	{
		return;
	}
	head = plist->phead->next;    //head指向无序表中的第一个节点
	plist->phead->next = NULL;    //拆分有序链表和无序链表
	pcur2 = head;
	plast = plist->phead;
	while (pcur2)
	{
		pLinkNode pIns = pcur2;
		head = head->next;
		pcur1 = plist->phead;
		if (pIns->data < plast->data)                  //有序表的最后一个人元素大于所要插入的元素
		{
			pLinkNode prev = NULL;
			while (pcur1)       //找到插入的位置
			{
			    if (pcur1->data>pIns->data)
					break;
				prev = pcur1;
				pcur1 = pcur1->next;
			}
			if (pcur1 == plist->phead)
			{
				pIns->next = plist->phead;
				plist->phead = pIns;
			}
			else
			{
				pIns->next = prev->next;
				prev->next = pIns;
			}
		}
		else                                       //有序表的最后一个元素小于所要插入的元素
		{                                          //直接把元素插到表尾，并更换尾指针的位置
			plast->next = pIns;
			pIns->next = NULL;
			plast = pIns;
		}
		pcur2 = head;
	}
	
}
void Select_sort(pLinkList plist)                //选择排序
{
	assert(plist);
	pLinkNode cur = plist->phead;
	pLinkNode prev = NULL;
	if (plist->phead == NULL)      //链表为空直接返回
	{
		return;
	}
	else                          //链表不为空则开始遍历
	{
		DataType   min = 0;        //记录最小值
		pLinkNode  pos = NULL;     //记录最小值节点的位置
		pLinkNode ptmp = NULL;     
		while (cur)
		{
			pos = cur;
			min = cur->data;
			ptmp = cur->next;
			while (ptmp)
			{
				if (ptmp->data < min)
				{
					min = ptmp->data;
					pos = ptmp;
				}
				ptmp = ptmp->next;
			}
			if (pos != cur)
			{
				DataType tmp = cur->data;
				cur->data = pos->data;
				pos->data = tmp;
			}
			cur = cur->next;
		}
	}
}
LinkNode *Yuesefu_huan(pLinkList plist, pLinkNode pos, int k)
{
	assert(plist);
	assert(pos);
	assert(k > 0);
	int num = k;
	pLinkNode cur = plist->phead;
	pLinkNode del = NULL;
	pLinkNode prev = plist->phead;
	while (prev->next)               //找到尾节点
	{
		prev = prev->next;
	}
	prev->next = plist->phead;
	cur = pos;
	while (cur->next != cur)
	{
	   while (--num)
	  {
		prev = cur;
		cur = cur->next;
	   }
	   printf("将要删除的节点是%d\n", cur->data);
	   num = k;
	   prev->next = cur->next;
	   del = cur;
	   cur = cur->next;
	   free(del);
	   del = NULL;
	}
	return cur;
}
void EraseNotTail(pLinkNode pos)                            //删除单链表的非尾节点
{                                               
	assert(pos&&pos->next!= NULL);
	pLinkNode del = pos->next;
	pos->data = del->data;                                 //采用交换两个节点的数据，然后删除后一个节点
	pos->next = del->next;
	free(del);
	del = NULL;
}
void Reverse(pLinkList plist)                              //逆序单链表
{
	assert(plist);
	pLinkNode cur = plist->phead;
	pLinkNode tmp = NULL;
	pLinkNode NewNode = NULL;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		tmp->next = NewNode;
		NewNode = tmp;
	}
	plist->phead = tmp;
}
void InsertFrontNode(pLinkNode pos, DataType data)        //在某一个节点前插入一个节点（不提供头节点）
{
	assert(pos);
	pLinkNode pIns = (pLinkNode)malloc(sizeof(LinkNode)* 1);
	DataType tmp ;
	if (pIns == NULL)
	{
		printf("Out of memory!\n");
		exit(EXIT_FAILURE);
	}
	pIns->data = data;
	pIns->next = pos->next;
	pos->next = pIns;
	tmp = pIns->data;
	pIns->data = pos->data;
	pos->data = tmp;
}
pLinkNode FindMidNode(pLinkList plist)                   //寻找链表的中间节点
{
	assert(plist);
	pLinkNode fast = plist->phead;                 //快指针一次走两步
	pLinkNode slow = plist->phead;                 //慢指针一次走一步
	if (plist->phead == NULL||plist->phead->next==NULL)
	{
		return plist->phead;
	}
	while (fast->next != NULL&&fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
void DelKNode(pLinkList plist, int k)                   //删除倒数第k个节点
{
	assert(plist);
	pLinkNode pfront = plist->phead;
	pLinkNode pback  = plist->phead;
	pLinkNode prev = NULL;
	if (plist->phead == NULL || plist->phead->next == NULL || k < 0)
	{
		return;
	}
    while (pfront&&k--)
	{
		pfront = pfront->next;
	}
	while (pfront)
	{
		prev = pback;
		pfront = pfront->next;
		pback = pback->next;
	}
	if (k <= 0)
	{
		pLinkNode ptmp = NULL;
		pback->data = pback->next->data;
		ptmp = pback->next;
		pback->next = ptmp->next;
		free(ptmp);
		ptmp =NULL;
	}
}
