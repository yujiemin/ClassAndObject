

namespace YJM1
{
	class TestA
	{
	public:
		//...
	};

	class TestB: public TestA
	{
	public:
		TestB()
		{
			m_p = new char[10];
		}

		~TestB()
		{
			delete m_p;
		}

	private:
		char* m_p;
	};
}


namespace YJM1
{
	class TestA final
	{
	public:
		//...
	};
}

int main()
{
	YJM1::TestA* test = new YJM1::TestB;

	//只能调用TestA的析构函数，不能够调用TestB的析构函数
	//照成内存泄露
	delete test;

	return 0;
}
