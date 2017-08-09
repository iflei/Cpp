#include <iostream>
#include <queue>
using namespace std;

void GetMidNum(int* a, int n)
{
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int midSize;
	if(n % 2 == 0)
		midSize = (n+1)/2+1;//如果偶数个元素多push一个
	else
		midSize = (n+1)/2;

	//取数组前一半的元素放入优先级队列中
	for(int i = 0; i < midSize; ++i)
		minHeap.push(a[i]);
	//如果数组剩余元素大于堆顶元素则入堆，若小于则舍弃
	for(int i = midSize; i < n; ++i)
	{
		if(a[i] > minHeap.top())
		{
			minHeap.pop();
			minHeap.push(a[i]);
		}
	}

	if(n%2==0)//如果偶数个元素,pop两个中位数
	{
		int tmp = minHeap.top();
		minHeap.pop();
		cout << tmp << " " << minHeap.top() << endl;
	}
	else
	{
		cout << minHeap.top() << endl;
	}
}

int main()
{
	int a[] = {2, 5, 4, 9, 3, 6, 8, 7, 1, 0};
	int a1[] = {2, 5, 4, 9, 3, 6, 8, 7, 1 };
	int sz = sizeof(a)/sizeof(a[0]);
	int sz1 = sizeof(a1)/sizeof(a1[0]);
	GetMidNum(a, sz);
	GetMidNum(a1, sz1);
	return 0;
}
