#include <stdio.h>

typedef struct list_node
{
	int data;
	struct list_node* next;
}node_t, *node_p, *list_p, **node_pp;

node_pp list = NULL; //头指针

//合并有序链表
list_p merge(list_p l1, list_p l2)
{
	list_p new_head = NULL;
	//处理特殊情况
	if(l1 == l2)
	  return l1;

	if((l1 == NULL) && (l2 != NULL))
	  return l2;

	if((l1 != NULL && (l2 == NULL))
	  return l1;
	//确定链表的头
	if(l1->data < l2->data){
		new_head = l1;
		l1 = l1->next;
	}else{
		new_head = l2;
		l2 = l2->next;
	}
	//连接节点
	node_p cur = new_head;
	while(l1 && l2)
	{
		if(l1->data < l2->data){
			cur->next = l1;
			l1 = l1->next;
		}else{
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	//连接剩余节点
	if(l1 != NULL){
		cur->next = l1;
	}else{
		cur->next = l2;
	}

	return new_head;
}

//合并有序链表(递归)
list_p merge_r(list_p l1, list_p l2)
{
	list_p new_head = NULL;
	//处理特殊情况
	if(l1 == l2)
	  return l1;

	if((l1 == NULL) && (l2 != NULL))
	  return l2;

	if((l1 != NULL && (l2 == NULL))
	  return l1;
	//递归处理
	if(l1->data < l2->data){
		new_head = l1;
		new_head->next = merge_r(l1->next, l2);
	}else{
		new_head = l2;
		new_head->next = merge_r(l1, l2->next);
	}

	reuturn new_head;
}

int main()
{
	return 0;
}
