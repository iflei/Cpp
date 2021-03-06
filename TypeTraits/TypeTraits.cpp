#include <iostream>
#include <string>
using namespace std;


struct __TrueType
{
	bool Get()
	{
		return true;
	}
};

struct __FalseType
{
	bool Get()
	{
		return false;
	}
};

template <typename T>
struct TypeTraits
{
	typedef __FalseType __IsPODType;
};

template <>
struct TypeTraits< bool>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< char>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< unsigned char >
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< short>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< unsigned short >
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< int>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< unsigned int >
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< long>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< unsigned long >
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< long long >
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< unsigned long long>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< float>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< double>
{
	typedef __TrueType __IsPODType;
};

template <>
struct TypeTraits< long double >
{
	typedef __TrueType __IsPODType;
};

template <typename T>
struct TypeTraits<T*>
{
	typedef __TrueType __IsPODType;
};



// 使用参数推导的萃取处理
template <typename T>
void Copy(const T* src, T* dst, size_t size, __FalseType)
{
	cout << "__FalseType:" << typeid(T).name() << endl;
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
}

template <typename T>
void Copy(const T* src, T* dst, size_t size, __TrueType)
{
	cout << "__TrueType:" << typeid(T).name() << endl;
	memcpy(dst, src, size * sizeof(T));
}


// 使用萃取判断类型的Get函数判断是否是 POD类型来处理
template <class T>
void Copy(const T* src, T* dst, size_t size)
{
	cout << "__TrueType:" << typeid(T).name() << endl;
	if (TypeTraits <T>::__IsPODType().Get())
	{
		memcpy(dst, src, size*sizeof (T));
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}
}

int main()
{
	string s1[10] ={ "1", "2", "3", "4444444444444444444444444" };
	string s2[10] = { "11", "22", "33" };
	
	Copy(s1, s2, 10, TypeTraits <string>::__IsPODType());
	Copy(s1, s2, 10);
	
	int a1[10] = { 1, 2, 3 };
	int a2[10] = { 0 };

	Copy(a1, a2, 10, TypeTraits <int>::__IsPODType());
	Copy(a1, a2, 10);

	return 0;
