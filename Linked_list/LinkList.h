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

//判断链表是否带环、求环的长度、求环的入口点
pNode CheckCycle(pList list)
{
	pNode fast = list;
	pNode slow = list;
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
		  return fast; //返回相遇点
	}

	return NULL; //不带换
}

int CircleLength(pNode meet)
{
	assert(meet);
	pNode start = meet;
	int length = 0;
	do{
		start = start->next;
		length++;
	}while(start != meet)

	return length;
}
//2(L+X) = L+X+nC   L = nC-X 
pNode CircleEntry(pList list, pNode meet)
{
	pNode entry = list;
	while(entry != meet)
	{
		entry = entry->next;
		meet = meet->next;
	}

	return entry;
}

//判断两个链表是否相交，若相交，求交点。（假设链表不带环）
int CheckCross(pList l1, pList l2)
{
	//链表为空或同一个链表
	if(l1 == NULL || l2 == NULL || l1 == l2)
	{
		return 0;
	}

	while(l1->next)
	  l1 = l1->next;

	while(l2->next)
	  l2 = l2->next;

	if(l1 == l2)
	  return 1;
	else
	  return 0;
}

int GetCross(pList l1, pList l2)
{
	//假设l1是长链表
	pNode longList = l1;
	pNode shortList = l2;
	int n = 0;
	int n1 = 0;
	int n2 = 0;
	//统计两个链表长度
	while(longList->next)
	{
		longList = longList->next;
		n1++;
	}

	while(shortList->next)
	{
		shortList = shortList->next;
		n2++;
	}

	//确定长短链表
	if(n1 < n2)
	{
		shortList = l1;
		longList = l2;
	}
	else
	{
		longList = l1;
		shortList = l2;
	}

	//长链表先走n步
	n = abs(n1-n2);
	while(n--)
		longList = longList->next;

	//两个链表一起走,找相遇点
	while(longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}

	return longList;
}

//删除一个无头单链表的非尾节点
void EraseNotTail(pNode pos)
{
	pNode del = pos->next;
	pos->data = del-data;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//从尾到头打印单链表
void PrintListReverse(pList pHead)
{
	if(pHead)
	{
		if(pHead->next)
		  PrintListReverse(pHead->next);

		printf("%d -> ", pHead->data);
	}
}

void PrintListReverseNonR(pList pHead)
{
	stack<pNode> pNodes;
	pNode cur = pHead;
	//压栈
	while(cur)
	{
		pNodes.push(cur);
		cur = cur->next;
	}
	//出栈打印
	while(!pNodes.empty())
	{
		pNode top = pNodes.top();
		printf("%d -> ", top->data);
		pNodes.pop();
	}
}

//复杂链表的复制
typedef struct ComplexListNode
{
public:
	ComplexListNode(const int& x)
		:data(x)
		 ,next(NULL)
		 ,random(NULL)
	{}
public:
	int data;
	struct ComplexListNode* next;
	struct ComplexListNode* random;
}ListNode, *pNode, *pList, **ppList;

//方法1
pNode ComplexListCopy(pList pHead)
{
	//第一步：复制原始链表上的每个结点，并用_next链接起来
	pNode cur = pHead;
	//创建新链表的第一个结点
	pNode newHead = new ListNode(cur->data);
	cur = cur->next;
	//后面的节点都连接在dest后面
	pNode dest = newHead;
	while(cur)
	{
		pNode clone = new ListNode(cur->data);
		dest->next = clone;
		dest = dest->next;
		cur = cur->next;
	}

	/*第二步：定位原链表每个结点_random所指向结点到pHead的距离，
	 *	从而找到复制的新链表的每个结点_random指向的结点*/
	cur = pHead;
	dest = newHead;
	while(cur)
	{
		//对于原链表的一个结点，从head开始找到_random所指向的结点，并计数
		pNode head = pHead;
		int count = -1;
		while(head)
		{
			if(cur->random == NULL)
			  break; //random为NULL时count = -1

			count++;
			if(cur->random == head)
			  break;

			head = head->next;
		}

		//对于新链表的一个结点，从头开始，destCur走count步找到_random指向的结点
		pNode destCur = newHead;
		if(count == -1)
			dest->random = NULL;
		else
		{
			while(count--)
				destCur = destCur->next; //destCur往后走count步
			dest->random = destCur;
		}
		//cur和dest是对应的节点
		dest = dest->next;
		cur = cur->next;
	}
	return newHead;
}


