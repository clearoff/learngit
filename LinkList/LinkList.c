#include "LinkList.h"

void InitLinkList(pLinkList plist)      //��������г�ʼ������ͷ�ڵ�ָ��NULL
{
	assert(plist);
	plist->phead = NULL;
}
void DestoryLinkList(pLinkList plist)   //�ͷŵ�����ÿһ���ڵ���ڴ棬�����ڴ�й©
{
	assert(plist);
	if (plist->phead == NULL)
	{
		printf("�������ѿգ�\n");
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
		printf("�ڴ���ճɹ���\n");
	}
}
void PushBack(pLinkList plist, DataType data)  //β��
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
	LinkNode *del = plist->phead;   //��һ���ڵ�
	LinkNode *cur = plist->phead;
	if (plist->phead == NULL)
	{
		printf("����Ϊ�գ�\n");
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
		printf("�����ǿձ�\n");
	}
	else if (plist->phead->next == NULL)    //ֻ��һ���˽ڵ�
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
		printf("�����ǿ�����\n");
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
		printf("�������ѿգ�");
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
			printf("û���ҵ�����Ϊ%d�Ľڵ㣡\n", data);
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
void BubbleSort(pLinkList plist)             //�������ð������
{
	assert(plist);
	LinkNode *head = plist->phead;
	LinkNode *tail= NULL;
	LinkNode *crt = plist->phead;
	LinkNode *prev = NULL;
	while (crt->next)                //�ҵ����һ���ڵ�
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
	pLinkNode  head = NULL;     //�������������ͷ�ڵ�
	pLinkNode pcur2 = NULL;;    //�������������ָ��
	pLinkNode pcur1 = NULL;     //�������������ָ��
	pLinkNode plast = NULL;
	if (plist->phead==NULL)
	{
		return;
	}
	head = plist->phead->next;    //headָ��������еĵ�һ���ڵ�
	plist->phead->next = NULL;    //��������������������
	pcur2 = head;
	plast = plist->phead;
	while (pcur2)
	{
		pLinkNode pIns = pcur2;
		head = head->next;
		pcur1 = plist->phead;
		if (pIns->data < plast->data)                  //���������һ����Ԫ�ش�����Ҫ�����Ԫ��
		{
			pLinkNode prev = NULL;
			while (pcur1)       //�ҵ������λ��
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
		else                                       //���������һ��Ԫ��С����Ҫ�����Ԫ��
		{                                          //ֱ�Ӱ�Ԫ�ز嵽��β��������βָ���λ��
			plast->next = pIns;
			pIns->next = NULL;
			plast = pIns;
		}
		pcur2 = head;
	}
	
}
void Select_sort(pLinkList plist)                //ѡ������
{
	assert(plist);
	pLinkNode cur = plist->phead;
	pLinkNode prev = NULL;
	if (plist->phead == NULL)      //����Ϊ��ֱ�ӷ���
	{
		return;
	}
	else                          //����Ϊ����ʼ����
	{
		DataType   min = 0;        //��¼��Сֵ
		pLinkNode  pos = NULL;     //��¼��Сֵ�ڵ��λ��
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
	while (prev->next)               //�ҵ�β�ڵ�
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
	   printf("��Ҫɾ���Ľڵ���%d\n", cur->data);
	   num = k;
	   prev->next = cur->next;
	   del = cur;
	   cur = cur->next;
	   free(del);
	   del = NULL;
	}
	return cur;
}
void EraseNotTail(pLinkNode pos)                            //ɾ��������ķ�β�ڵ�
{                                               
	assert(pos&&pos->next!= NULL);
	pLinkNode del = pos->next;
	pos->data = del->data;                                 //���ý��������ڵ�����ݣ�Ȼ��ɾ����һ���ڵ�
	pos->next = del->next;
	free(del);
	del = NULL;
}
void Reverse(pLinkList plist)                              //��������
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
void InsertFrontNode(pLinkNode pos, DataType data)        //��ĳһ���ڵ�ǰ����һ���ڵ㣨���ṩͷ�ڵ㣩
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
pLinkNode FindMidNode(pLinkList plist)                   //Ѱ��������м�ڵ�
{
	assert(plist);
	pLinkNode fast = plist->phead;                 //��ָ��һ��������
	pLinkNode slow = plist->phead;                 //��ָ��һ����һ��
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
void DelKNode(pLinkList plist, int k)                   //ɾ��������k���ڵ�
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
