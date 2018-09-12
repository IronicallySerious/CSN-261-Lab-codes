#include "stdafx.h"
#include <iostream>
#include <string>

struct Node
{
	std::string name;
	Node *next;
	Node *previous;

	Node(std::string in_name) : name(in_name), next(NULL), previous(NULL) {}
};

class DoubleList
{
public:
	int size;
	Node *start;
	Node *end;

	DoubleList() : size(0), start(NULL), end(NULL) {}
	~DoubleList()
	{
		for(const Node *temp = getBegin(); temp != getEnd(); temp = temp->next)
		{
			if(temp->previous != NULL)
			{
				delete temp->previous;
			}
		}
	}

	void add(const std::string &name);
	void erase(Node *node);
	int getSize() const { return size; }
	Node *getBegin() const { return start; }
	Node *getEnd() const { return end; }
};

void DoubleList::add(const std::string &name)
{
	Node *node = new Node(name);

	if(start == NULL)
	{
		start = node;
	}

	this->end->next = node;
	node->previous = this->end;

	this->end = this->end->next;

	size++;
}

void DoubleList::erase(Node *node)
{
	if(this->start == this->end)
	{
		std::cout << "Underflow occured" << std::endl;
		return;
	}

	node->previous->next = node->next;
	node->next->previous = node->previous;
	size--;
}

void switch3rdNodes(DoubleList *list)
{
	if(list->getSize() < 3)
	{
		return;
	}
	else
	{
		Node *temp = list->start->next;
		list->start = list->start->next->next;
		list->end = list->end->previous->previous;

		while(temp->next != NULL)
		{
			std::swap(temp->next, temp->previous);

			temp = temp->next;
		}
	}
}

void printList(DoubleList &list)
{
	std::cout << "Printing list..\n";
	for(const Node *temp = list.getBegin(); temp != list.getEnd(); temp = temp->next)
	{
		std::cout << temp->name << std::endl;
	}
}

int mainA4_2()
{
	DoubleList list;
	list.add("Orange");
	list.add("Apple");
	list.add("Banana");
	list.add("Guava");
	list.add("Mango");
	printList(list);
	std::cout << "sfsfsd";
	switch3rdNodes(&list);
	printList(list);

	return 0;
}
