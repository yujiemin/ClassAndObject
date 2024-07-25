#include <iostream>

using namespace std;
#pragma  warning(disable:4996)

namespace YJM1
{
	class TestA
	{
	public:
		/** 构造函数 */
		TestA()
			:m_a(0), m_b(0)
		{
		}

		/** 析构函数 */
		~TestA()
		{
		}

		/** 拷贝构造 */
		TestA(const TestA& testA)
		{
			m_a = testA.m_a;
			m_b = testA.m_b;
		}

		/** 赋值拷贝运算符号 */
		TestA& operator=(const TestA& testA)
		{
			m_a = testA.m_a;
			m_b = testA.m_b;

			return *this;
		}

	public:
		int m_a;
		int m_b;
	};
}

namespace YJM2
{
	class TestA
	{
	public:
		/** 构造函数 */
		TestA()
			:m_a(0), m_b(0), m_char(new char[100])
		{
		}

		/** 析构函数 */
		~TestA()
		{
			delete[]m_char;
		}

		/** 拷贝构造 */
		TestA(const TestA& testA)
		{
			m_char = new char[100];
			memcpy(m_char, testA.m_char, 100);

			m_a = testA.m_a;
			m_b = testA.m_b;
		}

		// /** 赋值拷贝运算符号 */
		// TestA& operator=(const TestA& testA)
		// {
		// 	if (this == &testA)
		// 	{
		// 		return *this;
		// 	}
		//
		// 	delete []m_char;
		// 	m_char = new char[100];
		// 	memcpy(m_char, testA.m_char, 100);
		//
		// 	m_a = testA.m_a;
		// 	m_b = testA.m_b;
		//
		// 	return *this;
		// }


		/** 赋值拷贝运算符号 */
		TestA& operator=(const TestA& testA)
		{

			char* m_temp = new char[100];
			memcpy(m_temp, testA.m_char, 100);
			delete []m_char;
			m_char = m_temp;
		
			m_a = testA.m_a;
			m_b = testA.m_b;
		
			return *this;
		}

	public:
		int m_a;
		int m_b;

		char* m_char;
	};
}

namespace YJM3
{
	class TestA
	{
	public:
		/** 构造函数 */
		TestA()
			:m_a(0), m_b(0), m_char(new char[100])
		{
		}

		/** 析构函数 */
		~TestA()
		{
			delete[]m_char;
		}

		/** 拷贝构造 */
		TestA(const TestA& testA)
		{
			m_char = new char[100];
			memcpy(m_char, testA.m_char, 100);

			m_a = testA.m_a;
			m_b = testA.m_b;
		}

		/** 赋值拷贝运算符号 */
		TestA& operator=(const TestA& testA)
		{

			char* m_temp = new char[100];
			memcpy(m_temp, testA.m_char, 100);
			delete[]m_char;
			m_char = m_temp;

			m_a = testA.m_a;
			m_b = testA.m_b;

			return *this;
		}

	public:
		int m_a;
		int m_b;

		char* m_char;
	};

	class TestB: public TestA
	{
	public:
		TestB()
			:TestA()
		{}

		/** 拷贝构造 */
		TestB(const TestB& testb)
			:TestA(testb)
		{
		}

		/** 赋值运算符 */
		TestB& operator=(const TestB& testb)
		{
			TestA::operator=(testb);
			return *this;
		}
	};
}

int main()
{
	YJM3::TestB testb1;
	testb1.m_a = 10;
	testb1.m_b = 20;

	strcpy(testb1.m_char, "yyyyyyyyy");

	YJM3::TestB testb2 = testb1; //调用了拷贝构造函数

	testb2 = testb1;//调用了赋值构造函数
	return 0;
}
