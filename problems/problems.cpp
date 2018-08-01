// problems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <vector>

class Node
{
	int m_ID;
	std::string m_Name;
};

class MagicDS
{
private:
	std::vector<Node> a1;
	std::vector<Node> a2;

public:
	void enqueue(const Node * node)
	{
		a2.push_back(*node);
	}

	bool dequeue()
	{
		if(!a1.empty())
		{
			a1.pop_back();

			// Remove all elements from a2
			// Add inversely to a1
			// Now perform dequeue operation

			return true;
		}

		return false;
	}
};

int main()
{

	return 0;
}

