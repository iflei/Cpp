//使用两个栈实现一个队列
#include <stack>
using namespace std;

template <typename T>
class Queue
{
public:
	void Push(const T& x)
	{
		s1.push(x);
	}

	void Pop()
	{
		//如果栈2为空
		if(s2.empty())
		{
			//把栈1全导入栈2
			while(!s1.empty())
			{
				T& top = s1.top();
				s2.push(top);
				s1.pop();
			}
		}
		//如果栈2还为空，说明栈1也为空
		if(s2.empty())
		  return;
		//栈2不为空，队列也就不为空
		s2.pop();
	}
private:
	stack<T> s1;
	stack<T> s2;
};
//使用两个队列实现一个栈

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack
{
public:
	void Push(const T& x)
	{
		//如果q1和q2都为空，那么汪q1中插入元素
		if(q1.empty() && q2.empty())
		  q1.push(x);
		//如果q1不空，往q1中插入元素
		else if(!q1.empty())
		  q1.push(x);
		else
		  q2.push(x);
	}

	void Pop()
	{
		if(!q1.empty())
		{
			while(q1.size() != 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}
		else
		{
			while(q2.size() != 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
	}
private:
	queue<T> q1;
	queue<T> q2;
};
//实现一个栈Stack，返回最小值的操作的时间复杂度为O(1) 
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class myStack
{
public:
	void Push(const T& x)
	{
		//s.empty()说明整个栈为空
		if(s.empty() || x <= m.top())
		{
			s.push(x);
			m.push(x);
		}
		else
		  s.push(x);
	}

	void Pop()
	{
		if(!s.empty())
		{
			if(s.top() == m.top())
			{
				s.pop();
				m.pop();
			}
			else
			  s.pop();
		}
	}

	T Min()
	{
		if(!m.empty())
		  return m.top();
	}
private:
	stack<T> s;//存数据
	stack<T> m;//存当前最小元素
};






