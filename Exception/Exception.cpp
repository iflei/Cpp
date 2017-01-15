#include <iostream>
#include <string>
using namespace std;

class Exception:public exception
{
public:
	Exception(int errId = 0, const char* errMsg = "")
		:_errId(errId)
		, _errMsg(errMsg)
	{}
	virtual const char* what() const
	{
		cout << "errId:" << _errId << " errMsg:" << _errMsg << endl;
		return _errMsg.c_str();
	}
private:
	int _errId; //´íÎóÂë
	string _errMsg; //´íÎóÏûÏ¢
};

void Func1()
{
	try
	{
		throw Exception(1, "Exception1");
		throw Exception(2, "Exception2");
	}
	catch (exception& e)
	{
		e.what();
	}
}

void Func2()
{
	try{
		int* p = new int[0x7fffffff / 4];
	}
	catch (bad_alloc& ba)
	{
		std::cout << ba.what() << '\n' << endl;
	}
	catch (exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

int main()
{
	Func1();
	Func2();
	return 0;
}
