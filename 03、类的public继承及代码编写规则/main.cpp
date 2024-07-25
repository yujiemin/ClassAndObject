#include <iostream>

using namespace std;

namespace YJM1
{
	class Human
	{
	public:
		void Eat()
		{
			cout << "Human eat()" << endl;
		}
	};

	class Man: public Human
	{
	public:
		void Eat()
		{
			cout << "Man Eat()" << endl;
		}
	};
}

namespace YJM2
{
	class Human
	{
	public:
		virtual void AverageAge();

		virtual ~Human(){}
	};

	void Human::AverageAge()
	{
		cout << "女生： 平均年龄75岁~" << endl;
	}

	class Woman: public Human
	{
	public:
		void AverageAge() override
		{
			Human::AverageAge();
		}
	};

	class Man: public Human
	{
	public:
		void AverageAge() override
		{
			cout << "男生： 平均年龄70岁~" << endl;
		}
	};
}

namespace YJM3
{
	class TestA
	{
	public:
		// virtual void Test()
		// {}
		//
		// virtual ~TestA() {}
	};

	class TestB: public TestA
	{};

	class TestC: public TestB
	{};

	void MyFunc(TestA test)
	{
		cout << "MyFunc ~ TestA" << endl;
	}

	void MyFunc(TestB test)
	{
		cout << "MyFunc ~ TestB" << endl;
	}

	// void MyFunc(TestC test)
	// {
	// 	cout << "MyFunc ~ TestC" << endl;
	// }
}

int main()
{

	// YJM1::Human* man1 = new YJM1::Man();
	// //调用的是父类(Human)的Eat函数
	// man1->Eat();
	//
	// YJM1::Man* man2 = new YJM1::Man();
	// //调用的是子类(Man)的Eat函数
	// man2->Eat();
	//
	// YJM1::Man man3;
	// //调用的是子类(Man)的Eat函数
	// man3.Eat();
	// //调用的是父类(Human)的Eat函数
	// man3.Human::Eat();

	// delete man1;
	// delete man2;

	// YJM2::Human* woman = new YJM2::Woman;
	// woman->AverageAge();
	//
	// YJM2::Human* man = new YJM2::Man;
	// man->AverageAge();
	//
	// delete woman;
	// delete man;

	YJM3::TestA testa;
	YJM3::TestB testb;
	YJM3::TestC testc;

	//
	YJM3::MyFunc(testa);
	YJM3::MyFunc(testb);
	YJM3::MyFunc(testc);


	return 0;
}
