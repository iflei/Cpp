#include<iostream>
using namespace std;
 
class String
{
public:
	String(char* str = "")
		:_str(new char[strlen(str) + 5])
	{
		_str += 4;
		_GetRefCount() = 1;
		strcpy(_str, str);
	}
 
	String(const String& s)
		:_str(s._str)
	{
		++_GetRefCount();
	}
	String& operator=(const String& s)
	{
		if (_str != s._str)
		{
			_Release();
			_str = s._str;
			++_GetRefCount();
		}
		return *this;
	}
	//写时拷贝,给要修改的对象重新分配空间
	char& operator[](size_t index)
	{
		if (_GetRefCount() > 1) //大于1时需要重新分配空间
		{
			char* tmp = new char[strlen(_str) + 5];
			*(int *)tmp = 1;
			tmp += 4;
			strcpy(tmp, _str);
			--_GetRefCount();//给原来指向的减一
			_str = tmp;//指向新空间
		}
		return _str[index];
	}
	~String()
	{
		cout << "~String()" << endl;
		_Release();
	}
	int& _GetRefCount()
	{
		return (*(int*)(_str - 4));
	}
	void _Release()
	{
		if (--(_GetRefCount()) == 0)
		{
			delete[] (_str - 4);//释放整段空间
		}
	}
	void _Print()
	{
		cout << _str << ":" << _GetRefCount() << endl;
	}
private:
	char* _str;
};