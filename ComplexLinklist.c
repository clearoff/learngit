#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int Datatype;

typedef struct ComplexLinkNode
{
	Datatype data;
	struct ComplexLinkNode *p_Next;    //ָ����һ���ڵ��ָ��
	struct ComplexLinkNode *p_sibling;  //ָ������һ���ڵ���߿�
}ComplexLinkNode;

ComplexLinkNode* Create_list(void)   //����һ�������������г�ʼ��
{
	ComplexLinkNode *node = NULL;
	ComplexLinkNode *ptmp = NULL;
	ComplexLinkNode *head = NULL;
	int num;
	printf("��ʼ��������������-1ֹͣ������");
	scanf("%d", &num);
	while (num != -1)
	{
		node = (ComplexLinkNode*)malloc(sizeof(ComplexLinkNode)* 1);
		if (node == NULL)
		{
			printf("Out of memory!\n");
			exit(EXIT_FAILURE);
		}
		node->data = num;
		node->p_sibling = NULL;
		node->p_Next = NULL;
		if (head == NULL)
		{
			head = node;
			ptmp = head;
		}
			
		else
		{
			ptmp->p_Next = node;
			ptmp = node;
		}
		scanf("%d", &num);
	}
	printf("�����������������湹�츴������\n");
	return head;
}
ComplexLinkNode* MakeListComplex(ComplexLinkNode *list)     //���츴������
{
	assert(list);
	ComplexLinkNode *cur1 = list;
	ComplexLinkNode *prev1 = NULL;
	ComplexLinkNode *cur2 = list;
	ComplexLinkNode *prev2 = NULL;
	int count1 = 0;    
	int count2 = 0;
	printf("��������ĸ��ڵ�ָ���ĸ��ڵ㣺");
	scanf("%d %d", &count1, &count2);
	while ((count1) && (cur1!= NULL))
	{
		count1--;
		prev1 = cur1;
		cur1 = cur1->p_Next;
	}
	while ((count2) && (cur2!= NULL))
	{
		count2--;
		prev2 = cur2;
		cur2 = cur2->p_Next;
	}
	if ((count1 == 0) && (count2 == 0))
	{
		prev1->p_sibling = prev2;
	}
	
	else
	{
		printf("�������󣬸���������ʧ�ܣ�\n");
	}
	return list;
}
//ComplexLinkNode* Clone_Nodes(ComplexLinkNode* list)      //ʱ�临�Ӷ�ΪO��n*n���ķ���
//{
//	assert(list);
//	ComplexLinkNode* list2 = NULL;
//	ComplexLinkNode* cur1  = list;
//	ComplexLinkNode* tmp   = NULL;
//	int count1 = 0;             //��¼ԭ�����ҵ�ָ��Ĳ���
//	int count2 = 0;             //��¼�ҵ�ָ����ָ��ڵ�Ĳ���
//	while (cur1)       //�ȿ������������еĵ�������
//	{
//		ComplexLinkNode* New  = NULL;
//		New = (ComplexLinkNode*)malloc(sizeof(ComplexLinkNode)* 1);     //����һ���½ڵ�
//		if (New == NULL)
//		{
//			printf("Out of memory!\n");
//			exit(EXIT_FAILURE);
//		}
//		New->data = cur1->data;
//		New->p_Next = NULL;
//		New->p_sibling = NULL;
//		if (list2 == NULL)
//		{
//			list2 = New;
//			tmp = list2;
//		}
//		else
//		{
//			tmp->p_Next = New;
//			tmp = New;
//		}
//		cur1 = cur1->p_Next;
//	}
//	cur1 = list;
//	while (cur1)
//	{
//		ComplexLinkNode *pos1 = NULL;
//		ComplexLinkNode *pos2 = NULL;
//		count1 = 0;
//		count2 = 0;
//		if (cur1->p_sibling != NULL)
//		{
//			ComplexLinkNode *pcur1 = list;
//			ComplexLinkNode *pcur2 = list;
//			pos1 = cur1;
//			pos2 = cur1->p_sibling;
//			while (pcur1 != pos1)
//			{
//				count1++;
//				pcur1 = pcur1->p_Next;
//			}
//			while (pcur2 != pos2)
//			{
//				count2++;
//				pcur2 = pcur2->p_Next;
//			}
//			pcur1 = list2;
//			pcur2 = list2;
//			while ((pcur1 != NULL)&&count1)
//			{
//				count1--;
//				pcur1 = pcur1->p_Next;
//			}
//			while ((pcur2 != NULL) && count2)
//			{
//				count2--;
//				pcur2 = pcur2->p_Next;
//			}
//			pcur1->p_sibling = pcur2;
//		}
//		cur1 = cur1->p_Next;
//	}
//	printf("���������Ƴɹ���\n");
//	return list2;
//}

//����Ϊʱ�临�Ӷ�Ϊo(N)�ķ���
ComplexLinkNode* CloneNodes(ComplexLinkNode *list)              //���Ƹ��������pNext���֣�
{
	assert(list);
	ComplexLinkNode *pNode = list;
	while (pNode)
	{
		ComplexLinkNode *pClone = (ComplexLinkNode*)malloc(sizeof(ComplexLinkNode)* 1);
		if (pClone == NULL)
		{
			printf("Out of memory!\n");
			exit(EXIT_FAILURE);
		}
		pClone->data = pNode->data;
		pClone->p_Next = pNode->p_Next;
		pClone->p_sibling = NULL;
		pNode->p_Next = pClone;
		pNode = pClone->p_Next;
	}
	return list;
}
ComplexLinkNode* ConnectSiblingNodes(ComplexLinkNode* head)       //���Ƴ�������p_siblingָ��
{
	assert(head);
	ComplexLinkNode* pNode = head;
	while (pNode)
	{
		ComplexLinkNode* pClone = pNode->p_Next;
		if (pNode->p_sibling != NULL)
		{
			pClone->p_sibling = pNode->p_sibling->p_Next;
		}
		pNode = pClone->p_Next;
	}
	return head;
}
ComplexLinkNode* CutList(ComplexLinkNode* head)
{
	assert(head);
	ComplexLinkNode* head2 = NULL;
	ComplexLinkNode* pNode = head;
	ComplexLinkNode* pClone = NULL;
	if (pNode)                             //����¡�����Ľڵ�����ͷ�ڵ�
	{
		head2 = pNode->p_Next;
		pClone = pNode->p_Next;
		pNode->p_Next = pClone->p_Next;
		pNode = pNode->p_Next;
	}
	while (pNode)
	{
		pClone->p_Next = pNode->p_Next;
		pClone = pNode->p_Next;
		pNode->p_Next = pClone->p_Next;
		pNode = pNode->p_Next;
	}
	return head2;
}
ComplexLinkNode* CloneComplexList(ComplexLinkNode* head)
{
	head=CloneNodes(head);
	head=ConnectSiblingNodes(head);
	head=CutList(head);
	printf("��¡��������ɹ�!\n");
	return head;
}
int main()
{
	ComplexLinkNode* list;
	ComplexLinkNode*list2;
	list=Create_list( );
	list = MakeListComplex(list);
	list2 = CloneComplexList(list);
	return 0;
}