
namespace YJM1
{
	class TestA
	{
	public:
		TestA(const TestA& testa) = delete;

		TestA& operator=(const TestA& testa) = delete;
	};
}

namespace YJM2
{
	class TestB
	{
	public:
		TestB()
		{}

		void Test()
		{
			YJM2::TestB b;
			*this = b;
		}

	private:
		TestB(const TestB& testb)
		{
		}

		TestB& operator=(const TestB& testb)
		{
			
		}
	};
}

namespace YJM3
{
	class NonCopyable
	{
	protected: //只允许本类和子类成员访问
		NonCopyable() {};
	 	~NonCopyable() {};

	private:
		NonCopyable(const NonCopyable& nonCopyable);

		NonCopyable& operator=(const NonCopyable& nonCopyable);
	};

	//根据...实现出： 组合关系（通过NonCopyable实现出TestA类）
	class TestA: public NonCopyable
	{
	public:
		TestA()
		{
			
		}
	};
}

int main()
{

	return 0;
}

