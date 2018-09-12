#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *prev, *next;
	static Node* getnode(int data)
	{
		Node* newNode = (Node*) malloc(sizeof(Node));
		newNode->data = data;
		newNode->prev = newNode->next = NULL;
		return newNode;
	}
};

class Deque
{
	Node* front;
	Node* rear;
	int Size;

public:
	Deque()
	{
		front = rear = NULL;
		Size = 0;
	}

	void push_front(int data);
	void push_back(int data);
	void pop_front();
	void pop_back();
	int getFront();
	int get_back();
	int size();
	bool isEmpty();
	void erase();
};

bool Deque::isEmpty()
{
	return (front == NULL);
}

int Deque::size()
{
	return Size;
}

void Deque::push_front(int data)
{
	Node* newNode = Node::getnode(data);
	if(newNode == NULL)
		cout << "OverFlow\n";
	else
	{
		if(front == NULL)
			rear = front = newNode;

		else
		{
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}

		Size++;
	}
}

void Deque::push_back(int data)
{
	Node* newNode = Node::getnode(data);
	if(newNode == NULL)
		cout << "OverFlow\n";
	else
	{
		if(rear == NULL)
			front = rear = newNode;

		else
		{
			newNode->prev = rear;
			rear->next = newNode;
			rear = newNode;
		}

		Size++;
	}
}

void Deque::pop_front()
{
	if(isEmpty())
		cout << "UnderFlow\n";

	else
	{
		Node* temp = front;
		front = front->next;

		if(front == NULL)
			rear = NULL;
		else
			front->prev = NULL;
		free(temp);

		Size--;
	}
}

void Deque::pop_back()
{
	if(isEmpty())
		cout << "UnderFlow\n";

	else
	{
		Node* temp = rear;
		rear = rear->prev;

		if(rear == NULL)
			front = NULL;
		else
			rear->next = NULL;
		free(temp);

		Size--;
	}
}

int Deque::getFront()
{
	if(isEmpty())
		return -1;
	return front->data;
}

int Deque::get_back()
{
	if(isEmpty())
		return -1;
	return rear->data;
}

void Deque::erase()
{
	rear = NULL;
	while(front != NULL)
	{
		Node* temp = front;
		front = front->next;
		free(temp);
	}
	Size = 0;
}

int mainA4_3()
{
	Deque dq;

	dq.push_back(5);
	dq.push_back(10);

	cout << "Rear end element: " << dq.get_back() << endl;
	dq.pop_back();
	dq.push_front(15);

	cout << "Front end element: " << dq.getFront() << endl;
	cout << "Number of elements in Deque: " << dq.size() << endl;
	dq.pop_front();
	std::cin.get();
	return 0;
}