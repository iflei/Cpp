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
	//��������ĵڶ���д��
	String(const String& str)
		:_str(NULL)  //delete��ָ���ǿ��Ե�
		//��ָ�벻�����ֵ
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
		if (this != &str)//�ж��Ը�ֵҲ����ȥ��
		{
			String tmp(str);
			swap(_str, tmp._str);
		}
		return *this;
	}*/
	String& operator=(String str)
	{
		//���ַ���new��deleteֻ�����ڹ��������������
		//����ͳһ����
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