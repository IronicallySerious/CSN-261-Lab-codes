#include <iostream>
#include <string>
#include <list>

#define IN_OUT

struct Data
{
	unsigned long data;

	Data(unsigned long value) : data(value) {}
};

Data &getItem(std::list<Data> &list, int location)
{
	long i = 0;
	auto temp = list.begin();

	while (i < list.size())
	{
		temp++;

		if (i == location)
		{
			return temp->data;
		}
	}
}

void AlternatingSplit(std::list<Data> &dataList, IN_OUT std::list<Data> &listA, IN_OUT std::list<Data> &listB)
{
	size_t listSize = dataList.size();

	for (size_t item = 0; item < listSize; item++)
	{
		listA.push_back(getItem(listA, item));
		item++;

		if (item == listSize)
		{
			break;
		}

		listB.push_back(getItem(listB, item));
	}
}

std::ostream &operator<<(std::ostream &stream, std::list<Data> &dataList)
{
	stream << "List: " << std::endl;

	for (auto item : dataList)
	{
		stream << item.data << " " << std::endl;
	}

	return stream;
}

int main()
{
	std::list<Data> dataList;
	std::list<Data> listA;
	std::list<Data> listB;

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
		i++;
	}

	AlternatingSplit(dataList, listA, listB);

	std::cout << listA << listB << std::endl;

	return 0;
}
