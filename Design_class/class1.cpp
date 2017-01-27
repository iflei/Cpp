//1.设计一个类不能被继承

class finalClass
{
public:
	static finalClass* GetInstance()
	{
		return new finalClass();
	}

	static void DeleteInstance(finalClass* pInstance)
	{
		delete pInstance;
	}
private:
	finalClass(){}
	~finalClass(){}
};

//方法2
//利用模版和虚拟继承

template <typename T>
class MakeFinal
{
	//GCC可能不支持模版做友元
	//friend T; 
	friend FinalClass;
	//友元可以调基类构造和析构
private:
	MakeFinal(){}
	~MakeFinal(){}
};

class FinalClass: virtual public MakeFinal/*<FinalClass>*/
{
public:
	FinalClass(){}
	~FinalClass(){}
};
//如果FinalClass再有派生类，由于虚继承，派生的类是直接调用MakeFinal的构造函数(根据虚函数表找，而不会通过FinaClass去调)，但派生类不是它的友元，所以编译不过


