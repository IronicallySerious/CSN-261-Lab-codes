#include <iostream>
#include <string>
#include <list>

struct Data
{
	unsigned long data;

	Data(unsigned long value) : data(value) {}
};

int main()
{
	std::list<Data> dataList;

	std::cout << "Enter number of elements" << std::endl;
	unsigned long N;
	std::cin >> N;

	std::cout << "Add int values to the list:" << std::endl;
	unsigned long i = 0;
	while (i < N)
	{
		unsigned long temp;
		std::cin >> temp;
		dataList.push_back(Data(temp));
	}

	

	return 0;
}
