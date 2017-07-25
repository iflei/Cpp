typedef struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
}Node;

//实现一颗二叉树的层序遍历
void LevelOrder()
{
	queue<Node*> q;
	if(_root != NULL)
	  q.push(_root);

	while(!q.empty())
	{
		Node* front = q.front();
		cout << front->_data << " ";
		q.pop();

		if(front->_left)
		  q.push(front->_left);
		if(front->_right)
		  q.push(front->_right);
	}
	cout << endl;
}
//第k层节点个数
size_t _GetKLevel(int k, Node* root)
{
	if(root == NULL)
	  return 0;

	if(k == 1)
	  return 1;

	size_t leftSize = _GetKLevel(k - 1, root->_left);
	size_t rightSize = _GetKLevel(k - 1, root->right);
	return leftSize + rightSize;
}
//叶子节点个数
size_t _LeafSize(Node* root)
{
	if (root == 0)
	  return 0;
	
	if (root->_left == 0 && root->_right == 0)
	  return 1;
	
	return _LeafSize(root->_left) + _LeafSize(root->_right);
}

//二叉树高度
size_t _Depth(Node* root)
{
	if(root == NULL)
	  return 0;

	size_t leftDepth = _Depth(root->_left);
	size_t rightDepth = _Depth(root->_right);

	return leftDepth > rightDepth ? leftDepth : rightDepth;
}

//销毁二叉树
void _Destroy(Node* root)
{
	if(root == NULL)
		return;

	if(root->_left)
		_Destroy(root->_left);

	if(root->_right)
		_Destroy(root->_right);

	delete root;
	root = NULL;
}

//由前序遍历和中序遍历重建二叉树
Node* Rebuild(int* prevOrder, int& prevIndex, int* inOrder, int inBegin, int inEnd)
{

	assert(prevOrder && inOrder);

	Node* root = NULL;
	if (inBegin <= inEnd)
	{
		root = new Node(prevOrder[prevIndex]);
		if (inBegin == inEnd)
			return root;

		int i = inBegin;
		for (; i <= inEnd; ++i)
		{
			if (prevOrder[prevIndex] == inOrder[i])
				break;
		}

		if (i > inEnd)
			throw invalid_argument("树遍历序列不匹配");

		root->left = Rebuild(prevOrder, ++prevIndex, inOrder, inBegin, i - 1);
		//左子树构建完指针 prevIndex 会指到 prevOrder 中左子树节点最后一个

		if (i < inEnd)  //（i == iEnd时没有右子树）
			root->right = Rebuild(prevOrder, ++prevIndex, inOrder, i + 1, inEnd);
	}

	return root;
}
//判断一棵二叉树是否是平衡二叉树
//红黑树
bool IsBlance()
{
	//空树返回true
	if(_root == NULL)
	  return true;
	//根节点为红返回false
	if(_root->_color == RED)
	  return false;
	//计算一条路径上的黑色节点数
	int k = 0;
	Node* cur = _root;
	while(cur)
	{
		if(cur->_color == BLACK)
		  k++;

		cur = cur->_next;
	}
	//
	int count = 0;
	_IsBlance(_root, k, count);
}

bool _IsBlance(Node* root, const int k, int count)
{
	if(root == NULL)
	  return true;

	//检查是否存在连续红节点
	if(root->_color == RED && root->_parent->_color == RED)
	  return false;

	//统计黑色节点个数
	if(root->_color == BLACK)
	  ++count;
	//到叶子节点时检测黑色节点数是否和k相等
	if(root->_left == NULL && root->_right == NULL && k != count)
	  return false;

	//递归左子树和右子树
	return _IsBalance(root->_left, k, count) && _IsBalance(root->_right, k, count);
}

//AVL树

//是否是完全二叉树
bool IsCompleteTree(Node* root)
{
	queue<Node*> q;
	if(root)
	  q.push(root);

	bool flag = true;
	while(!q.empty())
	{
		Node* front = q.front();
		q.pop();

		if(front->_left == NULL)
		  flag = false;
		else 
		{
			//1. 有左子树，但层序中前一个节点没有右子树
			if(flag == false)
			  return false;
			//前节点有右子树
			q.push(front->left);
		}

		if(front->_right == NULL)
		  flag = false;
		else
		{
			//2. 有右子树，但没有左子树
			if(flag == false)
			  return false;
			//有左子树
			q.push(front->_right);
		}

		return true;
	}
}
