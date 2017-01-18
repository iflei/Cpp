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
void mirrorTree(Node* root)
{
	if(root == NUll)
	  return;

	if(root->_left == NULL && root->_right == NULL)
	  return;

	swap(root->_left, root->_right);

	if(root->_left)
	  mirrorTree(root->_left);
	if(root->_right)
	  mirrorTree(root->_right);
}

void mirrorTreeNonR(Node* root)
{
	if(root == NULL)
	  return;

	stack<Node*> s;
	s.push(root);

	while(s.size())
	{
		Node* top = s.top();
		s.pop();

		if(top->_left || top->_right)
		  swap(top->_left, top->_right);

		if(top->_left)
		  s.push(top->_left);
		if(top->_right)
		  s.push(top->_right);
	}
}
//判断一个节点是否在一棵二叉树中
bool IsInTree(Node* root, Node* node)
{
	if(root == NULL)
	  return false;

	if(root == node)
	  return true;

	if(IsInTree(root->_left, node))
	  return true;
	//左子树没有，结果取决于右子树
	return IsInTree(root->_right, node);
}

//判断一颗二叉树是是否是另一颗树的子树
bool HasSubTree(Node* root1, Node* root2)
{
	if(root1 && root2 == NULL)
	  return true;//空树是任何树的子树

	if(root1 == NULL)
	  return false;//root1不能为空

	bool ret = false;
	//如果两个树都不为空，且根节点值相等
	//从相等的节点开始判断是否是子树
	if(root1->_data == root2->_data)
	   ret = SubTree(root1, root2);

	if(ret)
	  return true;
	//看root1的左子树是中是否含有该子树
	else if(HasSubTree(root1->_left, root2))
		return true;
	else  //左子树中没有该子树，再看其右子树中是否含有该子树
		return HasSubTree(root->_right, root2);
}

//起始节点的值已经相等，判断其余节点是否都相等
bool SubTree(Node* root1, Node* root2)
{
	if(root1 == NULL && root2 == NULL)
	  return true; //都为空
	if(root1 == NULL || root2 == NULL)
	  return false; //其中一个为空

	//都不空,并且data不相等
	if(root1->_data != root2->_data)
	  return false;
	//都不空，值相等
	return SubTree(root1->_left, root2->_left)
		&& SubTree(root1->_right, root2->_right);
}

//方法2
bool CheckSubTree(Node* root1, Node* root2)
{
	if(root1 && root2 == NULL)
	  return true;//空树是任何树的子树

	if(root1 == NULL)
	  return false;//root1不能为空

	return _CheckSubTree(root1, root2);
}

bool _CheckSubTree(Node* root1, Node* root2)
{
	if(root1 == NULL && root2 == NULL)
	  return true;
	if(root1 == NULL || root2 == NULL)
	  return false; 

	if(root1->data==root2->data)
        return _CheckSubTree(root1->_left, root2->_left) && _CheckSubTree(root1->_right, root2->_right);
	else
		return _CheckSubTree(root1->_left, root2) || _CheckSubTree(root1->_right,root2);
}

//求两个节点的最近公共祖先
Node* GetCommon(Node* root, Node* node1, Node* node2)
{
	assert(root && node1 && node2);

	if(node1 == root || node2 == root)
	  return root;

	bool node1InLeft, node1InRight, node2InLeft, node2InRight;

	node1InLeft = Find(root->_left, node1);
	if(node1InLeft == false)
	  node1InRight == true;

	node2InLeft = Find(root->_left, node2);
	if(node2InLeft == false)
	  node2InRight = true;

	if((node1InLeft && node2InRight) || (node1InRight && node2InLeft))
	  return root;
	else if(node1InLeft && node2InLeft)
	  return GetCommon(root->_left, node1, node2);
	else
	  return GetCommon(root->_right, node1, node2);
}

bool Find(Node* root, Node* node)
{
	if(root == node)
	  return true;

	if(root == NULL)
	  return false;

	Find(root->_left, node);
	Find(root->_right, node);
}
//求二叉树中最远的两个节点的距离
