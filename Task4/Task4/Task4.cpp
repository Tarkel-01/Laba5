// Task4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>


int main()
{
	std::vector<int> books;

	for(int i = 2000;i <= 2020;i++)
	    books.push_back(i);

	std::cout << std::count_if(books.begin(), books.end(), std::bind2nd(std::greater<int>(), 2009)) << std::endl;
}