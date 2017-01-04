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
