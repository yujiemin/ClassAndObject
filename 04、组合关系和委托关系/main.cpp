#include <iostream>
#include <string>
#include <map>
using namespace std;

namespace YJM1
{
	class Info
	{
	private:
		/** 名字 */
		string m_name;

		/** 性别 */
		int m_gender;

		/** 年龄 */
		int m_age;

	};

	class Human
	{
	public:
		Info m_info;
	};
}

namespace YJM2
{
	template <typename T, typename U>
	class SMap
	{
	public:
		void Insert(const T& key, const U& value)
		{
			if (container.find(key) != container.end())
			{
				return;
			}

			container.insert(make_pair(key, value));
		}

	private:
		multimap<T, U> container;
		
	};
}

namespace YJM3
{
	class TestA
	{
	public:
		void FuncA()
		{
		}
	};

	class TestB
	{
	public:
		TestB(TestA* testa)
			:m_testa(testa)
		{
			
		}

		void FuncB()
		{
			m_testa->FuncA();
		}

	private:
		TestA* m_testa;
	};
}

int main()
{
	multimap<int, int> tempMultimap;
	tempMultimap.insert(std::make_pair(1, 1));
	tempMultimap.insert(std::make_pair(2, 3));
	tempMultimap.insert(std::make_pair(1, 4));

	YJM3::TestA* testa = new YJM3::TestA();
	YJM3::TestB* testb = new YJM3::TestB(testa);

	testb->FuncB();

	delete testa;
	delete testb;

	return 0;
}