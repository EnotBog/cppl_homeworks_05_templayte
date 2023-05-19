#include <windows.h>
#include <locale.h>
#include <vector>
#include <iostream>


//template<class T,class T2>

class SimpleFunctor
{
public:
	SimpleFunctor(): m_counter_dev(0), m_sum_dev3(0){};
	SimpleFunctor(std::vector<int> a) : m_counter_dev(0), m_sum_dev3(0) {};
	~SimpleFunctor() {};

	int get_sum() const {return m_sum_dev3 ; }
	int get_count() const { return m_counter_dev; }

	void operator ()(std::vector<int> a)
	{
		for (auto buf : a)
		{
			if ((buf % 3) == 0) { ++m_counter_dev; m_sum_dev3 += buf; }
		}
	}

private:
	int m_counter_dev;
	int m_sum_dev3;

};



int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
 
	SimpleFunctor sf;
	std::vector<int> vec = { 4, 1, 3, 6, 25, 54 };
	//get_sum();
	sf(vec);
	std::cout << "[IN]: 4 1 3 6 25 54\n";
	std::cout << "[OUT]: get_sum() = "<<sf.get_count()<<"\n";
	std::cout <<"[OUT]: get_count() = "<< sf.get_sum()<<"\n";



}