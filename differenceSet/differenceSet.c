//若集合A={5,10,20,15,25,30}，集合B={5,15,35,25}，完成计算后A={10,20,30}。 
typedef struct node
{
	int data;
	struct node* next;
}node;

//O(m*n) 判断在B里没可以优化成set：O(m+n)
void difference(node** LA , node* LB)；
{
	node* pa, *pb, *pre, *del;
	pre = NULL;
	pa = *LA;

	while(pa)
	{
		pb = LB;
		while(pb && pb->date != pa->date)
		  pb = pb->next;

		if(pb) //在B里找到
		{
			if(pre == NULL)
			  *LA = pa->next;
			else
			  pre->next = pa->next;

			del = pa;
			pa = pa->next;
			free(del;)
		}
		else
		{
			pre = pa;
			pa = pa->next;
		}
	}
}
