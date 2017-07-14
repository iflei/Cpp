//1.实现一个简洁版的MyString类 
//2.要求能正常管理资源，能完成基本的拷贝和赋值就可以。 
//3.完成传统写法和现代写法

#include <iostream>
#include <string.h>
using namespace std;

class myString
{
public:
	myString(const char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	~myString()
	{
		if(_str != NULL)
		{
			delete[] _str;
			_str = NULL;
		}
	}

	//myString(const myString& str)
	//	:_str(new char[strlen(str._str)+1])
	//{
	//	strcpy(_str, str._str);
	//}

	myString(const myString& str)
		:_str(NULL) //让指针不是随机值，就算析构没判断delete空指针也可以的
	{
		myString tmp(str._str);
		swap(_str, tmp._str);
	}

	//myString& operator=(const myString& str)
	//{
	//	if(this != &str)
	//	{
	//		delete[] _str;
	//		//这种方法new和delete分开不符合一致性原则
	//		//还没赋值成功时就已经把原来的空间释放了
	//		_str = new	char[strlen(str._str)+1];
	//		strcpy(_str, str._str);
	//	}
	//	return *this;
	//}
	
	myString& operator=(myString tmp)
	{
		//判断自赋值也可以去掉
		//这种方法new和delete只出现在构造和析构函数中
		swap(_str, tmp._str);
		return *this;
	}

private:
	char* _str;
};

int main()
{
	myString str1("hello");
	myString str2(str1);
	myString str3;
	str3 = str1;
	return 0;
}
