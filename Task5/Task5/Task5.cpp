// Task5.cpp by Romanenko A.A.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Cache
{
private:
	vector<T> data;
public:
	void put(T value) { 
		data.push_back(value); 
	}
	void operator +=(T value) {
		data.push_back(value);
	}
	bool contains(T element) {
		return find(data.begin(), data.end(), element) != data.end(); 
	}
};

template <>
class Cache<string>
{
private:
	vector<string> data;
public:
	void put(string value) { 
		data.push_back(value); 
	}
	void operator += (string value) {
		data.push_back(value);
	}
	void add(string value)
	{
		try { 
			if (data.size() >= 100) 
				throw "В кэше уже есть 100 строк!"; 
			else
				data.push_back(value);
                 
		}
		catch (const char* message) { 
			cout << message; 
		}
	}
	bool contains(string element)
	{
		vector<string>::iterator it = data.begin();
		for(;it != data.end(); it++)
		{
			if ((*it)[0] == element[0]) 
				return true;
		}

		return false;
	}
};

int main()
{

	Cache<int> cache1;
	cache1.put(5);
	cache1.put(4);
	cache1.put(100);
	cache1 += 69;
	cache1 += 125;
	cout << cache1.contains(5) << endl;

	Cache<string> cache2;
	cache2.put("DonNU");
	cout << cache2.contains("Donetsk") << endl;

	return 0;
}
