#include <windows.h>
#include <locale.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>


//template<class T>

class SimpleFunctor
{
public:
	SimpleFunctor(): m_counter_dev(0), m_sum_dev3(0){};
	//SimpleFunctor(std::vector<int> a) : m_counter_dev(0), m_sum_dev3(0) {};
	~SimpleFunctor() {};

	int get_sum() const {return m_sum_dev3 ; }
	int get_count() const { return m_counter_dev; }

	void operator ()(int& buf)
	{
		if ((buf % 3) == 0) { ++m_counter_dev; m_sum_dev3 += buf; }
	}

	//SimpleFunctor operator =()
	//{

	//}

private:
	int m_counter_dev;
	int m_sum_dev3;

};



int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
 
	SimpleFunctor sf2, sf3 ;
	std::vector<int> vec = { 4, 1, 3, 6, 25, 54 };
	std::list<int> vec2 = { 4, 1, 3, 6, 25, 54 };
	
	sf2 = std::for_each(vec.begin(), vec.end(), sf2);
	sf3= std::for_each(vec2.begin(), vec2.end(), sf3);
	std::cout << "[IN]: 4 1 3 6 25 54\n";

	std::cout << "[OUT]: get_sum() = "<<sf2.get_count()<<"\n";
	std::cout <<"[OUT]: get_count() = "<< sf2.get_sum()<<"\n";

	std::cout << "[OUT]: get_sum() = " << sf3.get_count() << "\n";
	std::cout << "[OUT]: get_count() = " << sf3.get_sum() << "\n";

}