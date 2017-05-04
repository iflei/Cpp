#include <iostream>
#include<string.h>
using namespace std;
 
class String
{
public:
	String(char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}
	//拷贝构造的第二种写法
	String(const String& str)
		:_str(NULL)  //delete空指针是可以的
		//让指针不是随机值
	{
		String tmp(str._str);
		swap(_str, tmp._str);
	}
	~String()
	{
		if (_str != NULL)
		{
			delete[] _str;
			_str = NULL;
		}
	}
	/*String& operator=(const String& str)
	{
		if (this != &str)//判断自赋值也可以去掉
		{
			String tmp(str);
			swap(_str, tmp._str);
		}
		return *this;
	}*/
	String& operator=(String str)
	{
		//这种方法new和delete只出现在构造和析构函数中
		//方便统一管理
		swap(_str, str._str);
		return *this;
	}
	char* c_str()
	{
		return _str;
	}
	int size()
	{
		return strlen(_str);
	}
	
	void insert(int pos, char ch)
	{
		char* tmp = new char[strlen(_str) + 2];
		strcpy(tmp, _str);
		delete[] _str;
		_str = tmp;
 
		int end = strlen(_str);
		while (end >= pos)
		{
			_str[end + 1] = _str[end];
			end--;
		}
		_str[pos] = ch;
	}
	void insert(int pos, char* str)
	{
		char* tmp = new char[strlen(_str) + 1 + strlen(str)];
		strcpy(tmp, _str);
		delete[] _str;
		_str = tmp;
 
		int end = strlen(_str);
		while (end >= pos)
		{
			_str[end + strlen(str)] = _str[end];
			end--;
		}
		while (*str)
		{
			_str[pos++] = *str++;
		}
	}
	void insert(int pos, String& str)
	{
		insert(pos, str._str);
	}
 
	void PushBack(char ch)
	{
		insert(strlen(_str), ch);
	}
private:
	char* _str;
};