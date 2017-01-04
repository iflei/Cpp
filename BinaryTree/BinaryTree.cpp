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
size_t GetKLevel(int k)
{
	assert(k > 0);
	return _GetKLevel(k, _root);
}

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
size_t LeafSize() 
{
	return _LeafSize(_root);
}
size_t _LeafSize(Node* root)
{
	if (root == 0)
	  return 0;
	
	if (root->_left == 0 && root->_right == 0)
	  return 1;
	
	return _LeafSize(root->_left) + _LeafSize(root->_right);
}
