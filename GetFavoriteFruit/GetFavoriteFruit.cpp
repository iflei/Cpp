#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//make_heap用函数指针,priority_queue用仿函数
struct Compare
{
	bool operator()(map<string, int>::iterator it1, map<string, int>::iterator it2)
	{
		return it1->second < it2->second;
	}
};

void GetFavoriteFruit(const vector<string>& fruit, size_t k)
{
	map<string, int> countMap;
	for(int i = 0; i < fruit.size(); ++i)
		countMap[fruit[i]]++;

	priority_queue<map<string, int>::iterator, vector<map<string, int>::iterator>, Compare> pq;

	map<string, int>::iterator it = countMap.begin();
	for(; it != countMap.end(); ++it)
	{
		pq.push(it);
		cout << it->first << ": " << it->second << endl;
	}

	cout << "---------------------------------------------" << endl;
	for(int i = 0; i < k; ++i)
	{
		cout << pq.top()->first << ": " << pq.top()->second << endl;
		pq.pop();
	}
}

int main()
{
	const char* fruits[] = {"苹果", "哈密瓜", "香蕉", "香蕉", "苹果", "猕猴桃", "苹果", "火龙果", "猕猴桃", "苹果", "猕猴桃", "苹果"};
	vector<string> fruit(fruits, fruits+sizeof(fruits)/sizeof(fruits[0]));

	GetFavoriteFruit(fruit, 3);
	return 0;
}
