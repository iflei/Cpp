#include <stdio.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ListNode, *pNode, *pList, **ppList;


//合并有序链表
pList Merge(pList l1, pList l2)
{
	pList newHead = NULL;
	//处理特殊情况
	if(l1 == l2)
	  return l1;

	if((l1 == NULL) && (l2 != NULL))
	  return l2;

	if((l1 != NULL && (l2 == NULL))
	  return l1;
	//确定链表的头
	if(l1->data < l2->data){
		newHead = l1;
		l1 = l1->next;
	}else{
		newHead = l2;
		l2 = l2->next;
	}
	//连接节点
	pNode tail = newHead;
	while(l1 && l2)
	{
		if(l1->data < l2->data){
			tail->next = l1;
			l1 = l1->next;
		}else{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	//连接剩余节点
	if(l1 != NULL){
		tail->next = l1;
	}else{
		tail->next = l2;
	}

	return newHead;
}

//合并有序链表(递归)
pList MergeR(pList l1, pList l2)
{
	pList newHead = NULL;
	//处理特殊情况
	if(l1 == l2)
	  return l1;

	if(l1 == NULL)
	  return l2;

	if(l2 == NULL)
	  return l1;
	
	//递归处理
	if(l1->data < l2->data){
		newHead = l1;
		newHead->next = MergeR(l1->next, l2);
	}else{
		newHead = l2;
		newHead->next = MergeR(l1, l2->next);
	}

	reuturn newHead;
}

//逆置单链表
void ReverseList(ppList ppHead)
{
	assert(ppHead); //头指针不能为空
	pNode newHead = NULL;
	pNode cur = *ppHead;
	pNode prev = NULL;
	//没有节点或只有一个节点
	if(cur == NULL | cur->next == NULL)
		return;
	//调整节点next的指向
	while(cur)
	{
		prev = cur;
		cur = cur->next;
		prev->next = newHead; //最开始newHead为NULL
		newHead = prev;
	}

	*ppHead = newHead;
}

//删除单链表的倒数第k个节点,时间复杂度为O(N)
void DelKNode(ppList ppHead, int k)
{
	assert(k > 1);
	pNode first = *ppHead; //先走
	pNode after = *ppHead; //后走
	//如果k大于链表长度，first->next跳出循环时k>0
	while(--k && first->next) //让快指针先走k-1步
	  first = first->next;

	//快慢指针一起走，当快指针走到末尾节点，慢指针走到倒数第k个节点
	while(first->next){
		first = first->next;
		after = last->next;
	}

	if(k > 0){
		return;
	}
	else{ //偷梁换柱法删除节点
		pNode del = after->next;
		after->data = del->data;
		aftet->next = del->next;
		free(del);
		del = NULL;
	}
}

