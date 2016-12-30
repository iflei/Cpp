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

//元素出栈、入栈顺序的合法性
#include <stack>
#include <vector>
using namespace std;

bool IsPopOrder(vector<int> pushOrder, vector<int> popOrder)
{
	if(pushOrder.size() != popOrder.size() || pushOrder.size() == 0)
	  return false;

	int len = pushOrder.size();
	int indexPopOrder = 0; //pop序列不用入栈
	stack<int> s;

	for(int i = 0; i < len && indexPopOrder < len; ++i)
	{
		//模拟入栈顺序
		s.push(pushOrder[i]);
		//如果栈顶元素等于出栈顺序中的元素，pop出栈顶元素并偏移出栈序列的下标
		while(!s.empty() && s.top() == popOrder[indexPopOrder])
		{
			s.pop();
			indexPopOrder++;
		}
	}
	//上面循环结束有两种情况：
	//1. i == len 说明有元素不符合出栈顺序，没有执行内层循环而++i
	//2. indexPopOrder == len 或 s.empty() 说明出栈顺序已经遍历完了，那么栈也对应的空了
	if(s.empty() // 等价if(indexPopOrder == len)
		return true;

	return false;
}

//用一个数组实现两个栈
template <typename T>
class TwoStack
{
public:
	TwoStack()
		:arr(NULL)
		,top1(0)
		,top2(9)
		,capacity(10)
	{
		arr = new T[capacity];
	}

	~TwoStack()
	{
		if(arr)
		  delete[] arr;
	}

	void Push1(const T& x)
	{
		_CheckCapacity();
		arr[top1++] = x;
	}

	void Push2(const T& x)
	{
		_CheckCapacity();
		arr[top2--] = x;
	}

	void Pop1()
	{
		if(top1 > 0)
		  --top1;
	}

	void Pop2()
	{
		if(top2 < capacity - 1)
		  ++top2;
	}
private:
	void _CheckCapacity()
	{
		if(top1 > top2)
		{
			//开新空间
			size_t oldCapacity = capacity;
			capacity = capacity * 2; //扩容为2倍
			T* tmp = new T[capacity];

			//拷贝数据
			for(int i = 0; i < top1; ++i)
			  tmp[i] = arr[i];
			for(i = oldCapacity - 1, j = capacity - 1; i > top2; --i, --j)
			  tmp[j] = tmp[i];

			delete[] arr;
			arr = tmp;
			top2 += oldCapacity; //调整top2
		}
	}
private:
	T* arr;
	size_t top1;
	size_t top2;
	size_t capacity;
};
