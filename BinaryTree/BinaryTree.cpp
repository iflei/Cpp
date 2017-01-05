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
