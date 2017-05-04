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
	//дʱ����,��Ҫ�޸ĵĶ������·���ռ�
	char& operator[](size_t index)
	{
		if (_GetRefCount() > 1) //����1ʱ��Ҫ���·���ռ�
		{
			char* tmp = new char[strlen(_str) + 5];
			*(int *)tmp = 1;
			tmp += 4;
			strcpy(tmp, _str);
			--_GetRefCount();//��ԭ��ָ��ļ�һ
			_str = tmp;//ָ���¿ռ�
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
			delete[] (_str - 4);//�ͷ����οռ�
		}
	}
	void _Print()
	{
		cout << _str << ":" << _GetRefCount() << endl;
	}
private:
	char* _str;
};