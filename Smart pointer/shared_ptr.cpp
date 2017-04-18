#include <iostream>
#include <boost/shared_ptr.hpp>
using namespace boost;

template<typename T>
class Del
{
public:
	void operator() (const T *ptr)
	{
		delete ptr;
	}
};
//定制删除器仿函数实现FClose和Free
class FClose
{
public:
	void operator () (void* ptr)
	{
		fclose((FILE *)ptr);
	}
};
class Free
{
public:
	void operator () (void* ptr)
	{
		free(ptr);
	}
};
//默认Deleter 是 Del<T>
template<typename T, typename Deleter = Del<T>>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		,_pCount(new int(1))
	{}
	//构造函数重载
	SharedPtr(T* ptr, Deleter del)
		:_ptr(ptr)
		, _pCount(new int(1))
		, _del(del)
	{}
	SharedPtr<T>& operator=(SharedPtr<T> sp)
	{
		swap(_ptr, sp._ptr);
		swap(_pCount, sp._pCount);
		_del = sp._del;
		return *this;
	}
	~SharedPtr()
	{
		cout << "~SharedPtr()" << endl;
		Release();
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	T* GetPtr()//返回原指针_ptr
	{
		return  _ptr;
	}
	void Release()//释放内存
	{
		if (--(*_pCount) == 0)
		{
			_del(_ptr);
			delete _pCount;
		}
	}
private:
	T* _ptr;
	int* _pCount;
	Deleter _del;
};

void Test()
{
	//定制删除器和分配器
	SharedPtr<int> sp(new int(10));
	SharedPtr<FILE, FClose> sp1(fopen("aaa.txt", "w"), FClose());
	SharedPtr<int, Free> sp2((int*)malloc(sizeof(int)* 10), Free());
	//SharedPtr<int > sp3((int *)malloc(sizeof(int)*10), Free(), allocator<int >());
}