
namespace YJM1
{
	class Human
	{
	};

	class Man: private Human
	{
		
	};
}

namespace YJM2
{
	class Timer
	{
	public:

		Timer(int times)
			:m_times(times)
		{
		}

		virtual ~Timer() {}

		/** 定时器的调用 */
		virtual void CallBack()
		{
		}

	private:
		/** 间隔多少毫秒调用一次callback */
		int m_times;
	};

	class MsgQueue : private Timer
	{
	private:
		void CallBack() override
		{
			//到时间后虚函数就会被调用
		}
	};
}

int main()
{
	// YJM1::Man man;
	// YJM1::Human& human = man;
	// YJM1::Human* phuman = new YJM1::Man;

	return 0;
}
