#include <iostream>
#include <mutex>
#include <windows.h>
using namespace std;

namespace Lazy
{
	class Lock
	{
	public:
		//RAII
		Lock(mutex& mtx)
			:_mtx(mtx)
		{
			_mtx.lock();
		}

		~Lock()
		{
			_mtx.unlock();
		}
	private:
		Lock(const Lock&);
		Lock& operator=(const Lock&);

		mutex& _mtx; //������������ã���֤��ͬһ����
	};

	class Singleton
	{
	public:
		static Singleton* GetInstance(int a)
		{
			if (_inst == NULL)
			{
				lock_guard<mutex> lock(_mtx);

				if (_inst == NULL)
				{
					//1. operator new
					//2. ���캯��
					//3. ��ֵ
					//�������Ż����������ܽ���˳��
					//_inst = new Singleton(a);

					Singleton* tmp = new Singleton(a);
					MemoryBarrier(); //�ڴ�դ��windows.h
					_inst = tmp;
				}
			}
			return _inst;
		}

		void DelInstance()
		{
			lock_guard<mutex> lock(_mtx);
			if (_inst)
			{
				delete _inst;
				_inst = NULL;
			}
		}

		void Print()
		{
			cout << _a << endl;
		}
	private:
		Singleton(int a)
			:_a(a)
		{}

		Singleton(const Singleton&);
		Singleton& operator=(Singleton&);

		int _a;
		static Singleton* _inst;
		static mutex _mtx;
	};

	Singleton* Singleton::_inst = NULL;
	mutex Singleton::_mtx;
}

namespace Hungry
{
	class Singleton
	{
	public:
		static Singleton& GetInstance()
		{
			static Singleton inst;
			return inst;
		}

		void Print()
		{
			cout << _a << endl;
		}
	private:
		Singleton()
			:_a(0)
		{}

		Singleton(const Singleton&);
		Singleton& operator=(Singleton&);

		int _a;
	};
}

int main()
{
	Lazy::Singleton::GetInstance(5)->Print();
	Lazy::Singleton::GetInstance(2)->Print();

	Hungry::Singleton::GetInstance().Print();
	Hungry::Singleton::GetInstance().Print();
	system("pause");
}