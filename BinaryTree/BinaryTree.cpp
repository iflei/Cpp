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
Node* Construct(int* preOrder, int* inOrder, size_t size)
{
	assert(preOrder && inOrder && size > 0);
	return _Construct(preOrder, preOrder+size-1, inOrder, inOrder+size-1);
}

Node* _Construct(int* startPre, int* endPre, int* startIn, int* endIn)
{
	//前序第一个值是根节点
	int rootValue = startPre[0];
	Node* root = new Node();
	root->_value = rootValue;
	root->_left = root->right = NULL;
	//只有一个元素
	if(startPre == endPre)
	{
		if(startIn == endIn && *startPre = *startIn)
		  return root;
		else
		  return NULL;
	}
	//中序序列中找根节点值
	int* rootIn = startIn;
	while(rootIn <= endIn && *rootIn != rootValue)
	  ++rootIn;

	if(rootIn > endIn) //没找到
	  return NULL;

	//左子树
	int leftSize = rootIn - startIn;
	int* leftPreEnd = startPre + leftSize;
	// (startPre+1, leftPreEnd, startIn, rootIn-1)
	if(leftSize	> 0) //构建左子树
	  root->_left = _Construct(startPre+1, leftPreEnd, startIn, rootIn-1);
	//左子树节点数小于整个树节点数，说明右子树也存在
	if(leftSize < endPre - startPre)
	  root->_right = _Construct(leftPreEnd + 1, endPre, rootIn + 1, endIn);

	return root;
}

//判断一棵二叉树是否是平衡二叉树

//求一颗二叉树的镜像
