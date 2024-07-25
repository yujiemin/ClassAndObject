#include <functional>
#include <memory>
#include <iostream>
using namespace std;

namespace YJM2
{
	class MyString
	{
	public:
		MyString(const char* cstr)
			:m_value(new StringValue(cstr))
		{
			//...
		}

		/** 析构函数 */
		~MyString()
		{
			--m_value->refCount;
			if (m_value->refCount == 0)
			{
				delete m_value;
			}
		}

		/** 拷贝构造 */
		MyString(const MyString& str)
		{
			if (str.m_value->shareable)
			{
				m_value = str.m_value;
				++m_value->refCount;
			}
			else
			{
				//复制一份
				m_value = new StringValue(str.m_value->point);
			}
		}

		/** 拷贝赋值运算符 */
		MyString& operator=(const MyString& str)
		{
			if (this == &str)
			{
				return *this;
			}

			//先把之前的释放掉
			--m_value->refCount;
			if (m_value->refCount == 0)
			{
				delete m_value;
			}

			if (str.m_value->shareable)
			{
				m_value = str.m_value;
				++m_value->refCount;
			}
			else
			{
				//复制一份
				m_value = new StringValue(str.m_value->point);
			}

			return *this;
		}

		/** 实现了非const 就不会调用该const */
		const char& operator[](int index) const
		{
			return m_value->point[index];
		}

		char& operator[](int index)
		{
			if (m_value->refCount > 1)
			{
				//说明还有其他对象指向这个字符串
				--m_value->refCount;
				m_value = new StringValue(m_value->point);
			}

			m_value->shareable = false;

			return m_value->point[index];
		}
	private:
		struct StringValue
		{
			/** 引用计数 */
			size_t refCount;

			/** 指向实际字符串 */
			char* point;

			/** 一个是否能够被共享的标记 */
			bool shareable;

			/** EXPR */
			StringValue(const char* str)
				:refCount(1), point(nullptr), shareable(true)
			{
				point = new char[strlen(str) + 1];
				strcpy_s(point, strlen(str) + 1, str);
			}

			~StringValue()
			{
				delete []point;
			}
		};

	private:
		/** mystring类中指向stringvalue对象的指针 */
		StringValue* m_value = nullptr;
	};
}


int main()
{

	YJM2::MyString str1 = "Hello World!";
	//这边有一个引用了str1 ，会导致后面改动这个类也会改动其他的对象
	char& tempChar = str1[0];


	YJM2::MyString str2 = "Hello World!";

	YJM2::MyString str3 = str1;
	YJM2::MyString str4 = str1;
	YJM2::MyString str5 = str1;

	str2 = str1;
	tempChar = 'I';
	

	return 0;
}
