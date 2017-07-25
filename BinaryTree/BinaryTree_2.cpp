//搜索二叉树转化为排序的双向链表
Node* _ToSortList(Node* root, Node* &prev)
{
	if (root == NULL)
		return;

	_ToSortList(root->left, prev); 
	//prev指向上一个中序的root，然后一直找右子树的最左节点，

	// 转化
	root->left = prev; //右子树的最左节点的left指向prev
	if (prev)
		prev->right = root; //prev的right指向右子树的最左节点

	prev = root; //prev指向当前的中序root

	_ToSortList(root->right, prev); //递归右子树
}

Node* ToSortList(Node* root)
{
	Node* prev = NULL;
	_ToSortList(root, prev);

	//寻找双向链表的头,left向前right向右
	Node* head = root;
	while (head && head->left)
	{
		head = head->left;
	}

	return head;
}
//求一颗二叉树的镜像

//前序线索化

//中序迭代器

//判断一个节点是否在一棵二叉树中

//求两个节点的最近公共祖先

//求二叉树中最远的两个节点的距离
