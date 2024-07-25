#include <iostream>

namespace YJM1
{
	class TestA
	{
	public:
		void CallTest()
		{
			Test();
		}
	private:
		virtual void Test()
		{
			
		}
	};

	class TestB: public TestA
	{
	private:
		virtual void Test()
		{
			
		}
	};
}

namespace YJM2
{
	class TestA
	{
	public:
		virtual void Test() = 0;

		virtual ~TestA()
		{
			
		}
	};

}

namespace YJM3
{
	class TestA
	{
	public:
		explicit TestA(int i) //类型转换构造函数
		{
			std::cout << i << std::endl;
		}
	};
}

namespace YJM4
{
	class TestA
	{
	private:
		static void* operator new(size_t size);
		static void operator delete(void* pHead);

		//
		static void* operator new[](size_t size);
		static void operator delete[](void* pHead);
	};
}

namespace YJM5
{
	class TestA
	{
	public:
		//释放创建的堆对象
		void Destroy()
		{
			delete this;
		}

	private:
		//析构函数使用private修饰
		~TestA() {}
		
	};
}


int main()
{
	//编译器通过构造函数把数字12转换成一个TestA类型的类对象（临时对象）并构造在aobj对象预留的空间里。
	// YJM3::TestA test = 12; 报错

	YJM3::TestA test(12); //需要显示的构造

	return 0;
}
