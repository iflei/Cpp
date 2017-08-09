#include <iostream>
using namespace std;

//前后指针
int partion(int* a, int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int key = a[right]; //三数取中优化

	while(cur <= right)
	{
		if(a[cur] <= key && ++prev != cur)
		  swap(a[prev], a[cur]);
		
		cur++;
	}
	return prev;
}

void GetMidNum(int* a, int n)
{
	int left = 0;
	int right = n - 1;//如果9个数,0-8
	int mid = n/2; //0123[4]5678

	int div = partion(a, left, right);

	while(div != mid)
	{
		if(div < mid)
			div = partion(a, div+1, right);
		else
			div = partion(a, left, div-1);
	}

	cout << a[mid] << endl;
}

int main()
{
	int a[] = {2, 5, 4, 9, 3, 6, 8, 7, 1};
	int a1[] = {3, 6, 1, 2, 7, 10, 12, 22};
	int sz = sizeof(a)/sizeof(a[0]);
	int sz1 = sizeof(a1)/sizeof(a1[0]);
	GetMidNum(a, sz);
	GetMidNum(a1, sz1);
	return 0;
}
