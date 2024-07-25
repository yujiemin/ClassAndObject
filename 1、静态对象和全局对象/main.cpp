#include "Test1.h"

#include <iostream>
using namespace std;

namespace YJM1
{
	class TestA
	{
	public:
		TestA()
		{
			m_num = 3;
			cout << "TestA() 构造函数~" << endl;
		}

		~TestA()
		{
			cout << "~TestA() 析构函数~" << endl;
		}

	public:
		int GetNum()
		{
			return m_num;
		}
	private:
		int m_num;
	};

	class TestB
	{
	public:
		TestB()
		{
			cout << "TestB() 构造函数~" << endl;
		}

		~TestB()
		{
			cout << "TestB() 析构函数~" << endl;
		}

	public:
		//注释掉inline
		static TestA testA;
	};

	//使用静态成员变量的时候就要初始化
	//放在在类外，一般在.cpp源文件的开头位置，为静态成员变量赋值（定义并赋值）
	//TestA TestB::testA;
}


YJM1::TestA* GetTestA()
{
	static YJM1::TestA testA;
	return &testA;
}

int main()
{

	//YJM1::TestB testB;

	//cout << testB.testA.GetNum() << endl;

	// cout << GetTestA()->GetNum() << endl;
	// cout << GetTestA()->GetNum() << endl;
	// cout << GetTestA()->GetNum() << endl;

	return 0;
}