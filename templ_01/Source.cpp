#include <windows.h>
#include <locale.h>
#include <vector>
#include <iostream>

template<class T>
void print_result(T a)
{
	std::cerr << "Function not support type!";
}

template<>
void print_result(int a)
{
	std::cout <<a << "\n ";
}

template<class T>
void print_result(std::vector<T> vec)
{
	for (auto x : vec)
	{
		std::cout << x <<" ";
	}
	std::cout << "\n ";
}

template<class T>
T exponentiation(T a)
{
	std::cerr << "Function not support type!";
	return a;
}

template<>
int exponentiation(int a)
{
	return a * a;
}

template <>
std::vector<int> exponentiation(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = vec[i] * vec[i];
	}

	return  vec;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	int x = 4;
	std::vector<int> vec = { -1,4,8 };

	std::cout << "[IN]: "; print_result(x);
	std::cout << "[IN]: "; print_result(vec);

	x = exponentiation(x);
	vec = exponentiation(vec);

	std::cout << "[OUT]: "; print_result(x);
	std::cout << "[OUT]: "; print_result(vec);

}