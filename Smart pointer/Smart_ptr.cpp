
template <typename T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = NULL)
		:_ptr(ptr)
	{}

	AutoPtr(const AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{//��������Ȩ
		ap._ptr = NULL;
	}

	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{
			delete ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T* GetPtr()//����_ptr
	{
		return  _ptr;
	}

	~AutoPtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
		cout << "~AutoPtr()" << endl;
	}
private:
	T* _ptr;
};

template<typename T>
class ScopePtr
{
public:
	ScopePtr(T* ptr = NULL)
		:_ptr(ptr)
	{}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T* GetPtr()
	{
		return _ptr;
	}

	~ScopePtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
		cout << "~ScopedPtr()" << endl;
	}
protected:
	//������:��������͸�ֵ����ֻ����������
	ScopePtr(const ScopePtr<T>& sp);
	ScopePtr<T>& operator=(const ScopePtr<T>& sp);
private:
	T* _ptr;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = NULL)
		:_ptr(ptr)
		, _pCount(new int(1))
	{}

	//���ü���ǳ����
	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _pCount(sp._pCount)
	{
		++(*_pCount);
	}
	void Release()//�ͷ��ڴ�
	{
		if (--(*pCount) == 0)
		{
			delete _ptr;
			delete _pCount;
			_ptr = NULL;
			_pCount = NULL;
		}
	}
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (this != &sp)
		{
			Release();
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			++(*_pCount);
		}
		return *this;
	}

	//�ִ�д��
	//SharedPtr<T>& operator=(SharedPtr<T> sp)
	//{
	//  swap(_ptr, sp._ptr);
	//  swap(_pCount, sp._pCount);
	//  return *this;
	//}

	~SharedPtr()
	{
		Release();
		cout << "~SharedPtr()" << endl;
	}
	T& operator*()
	{
		return *_ptr;
	}
	
	T* operator->()
	{
		return _ptr;
	}
	T* GetPtr()//����_ptr
	{
		return  _ptr;
	}
	int GetCount()//����ͬһ�ڴ�ļ�����
	{
		return *_pCount;
	}
	void Release()//�ͷ��ڴ�
	{
		if (--(*_pCount) == 0)
		{
			delete _ptr;
			delete _pCount;
			_ptr = NULL;
			_pCount = NULL;
		}
	}

private:
	T* _ptr;
	int* _pCount;
};