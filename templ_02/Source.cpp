#include <windows.h>
#include <locale.h>
#include <vector>
#include <iostream>


template <class T>
class MyTable
{
public:
	MyTable(int rows, int colums) :m_rows{ rows }, m_colums{ colums }
	{
		m_arr = new T*[m_rows];
		for (int i = 0; i < m_rows; i++)
		{
			m_arr[i] = new T[m_colums];
		}
	};

	~MyTable()
	{
		for (int i = 0; i < m_rows; i++)
		{
			delete[] m_arr[i];
		}
		delete[] m_arr;
	};


	  T* operator[](int a)  
	  {
		  if (a < 0 || (a >= m_rows)) throw std::runtime_error("Ќекоректный индекс к таблице в присвоении  по индексу");
		  return m_arr[a];
	  }

	 const T* operator[](int a)const 
	 { 
		 if (a < 0 || (a >= m_rows)) throw std::runtime_error("Ќекоректный индекс к таблице по индексу");
		 return m_arr[a]; 
	 }

	int Size() const { return this->get_rows() * this->get_colums() ;}


private:
	int get_rows() const { return m_rows; }
	int get_colums() const { return m_colums; }
	int m_rows;		
	int m_colums;
	T** m_arr = nullptr;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	try
	{

		auto test = MyTable<int>(2, 3);
		test[0][0] = 4;
		std::cout <<"test[0][0]: "<< test[0][0] << "\n";

	std::cout << "size: "<<test.Size();
	 
	}
	catch (const std::runtime_error &ex)
	{
		std::cerr << ex.what();
	}

	return 0;
} 