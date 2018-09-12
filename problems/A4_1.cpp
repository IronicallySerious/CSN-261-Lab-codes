#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

#define IN_OUT
#define LOG(x)

struct Data
{
	unsigned long data;

	Data(unsigned long value) : data(value) {}
};

//-------------------------------------------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &stream, std::list<Data>&dataList);
std::ostream &operator<<(std::ostream &stream, const Data &data);
void AlternatingSplit(std::list<Data> *dataList, IN_OUT std::list<Data> *listA, IN_OUT std::list<Data> *listB);
Data getItem(std::list<Data> *list, int location);
//-------------------------------------------------------------------------------------------------------------------

Data getItem(std::list<Data> *list, int location)
{
	long i = 0;
	std::list<Data>::const_iterator temp = list->begin();

	while(temp != list->end())
	{
		if(i == location)
		{
			return *temp;
		}

		i++;
		temp++;
	}
}

void AlternatingSplit(std::list<Data> *dataList, IN_OUT std::list<Data> *listA, IN_OUT std::list<Data> *listB)
{
	size_t listSize = dataList->size();

	for(size_t item = 0; item < listSize; item++)
	{
		LOG(getItem(listA, item));
		listA->push_back(getItem(dataList, item));
		item++;

		if(item == listSize)
		{
			break;
		}

		listB->push_back(getItem(dataList, item));
	}
}

std::ostream &operator<<(std::ostream &stream, std::list<Data> &dataList)
{
	stream << "List: " << std::endl;

	for(auto item : dataList)
	{
		stream << item.data << " ";
	}
	std::cout << std::endl;
	return stream;
}

std::ostream &operator<<(std::ostream &stream, const Data &data)
{
	stream << data.data << std::endl;

	return stream;
}

int mainA4_1()
{
	std::list<Data> dataList;
	std::list<Data> listA;
	std::list<Data> listB;

	std::cout << "Enter number of elements" << std::endl;
	unsigned long N;
	std::cin >> N;

	std::cout << "Add int values to the list:" << std::endl;
	unsigned long i = 0;
	while(i < N)
	{
		unsigned long temp;

		std::cin >> temp;
		dataList.push_back(Data(temp));
		i++;
	}

	AlternatingSplit(&dataList, &listA, &listB);

	std::cout << listA << listB << std::endl;
	return 0;
}
