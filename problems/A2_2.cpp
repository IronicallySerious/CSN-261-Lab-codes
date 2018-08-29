// A2_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

stack<int> sort(stack<int>& stack_in)
{
	stack<int> tempStack;

	while(!stack_in.empty())
	{
		int tmp = stack_in.top();
		stack_in.pop();

		while(!tempStack.empty() && tempStack.top() > tmp)
		{
			stack_in.push(tempStack.top());
			tempStack.pop();
		}

		tempStack.push(tmp);
	}

	return tempStack;
}

stack<int> mergeSort(stack<int>& s1, stack<int>& s2)
{
	stack<int> result;

	while(!s1.empty())
	{
		result.push(s1.top());
		s1.pop();
	}

	while(!s2.empty())
	{
		result.push(s2.top());
		s2.pop();
	}

	return sort(result);
}

int mainA2_2()
{
	stack<int> stack1, stack2;
	stack1.push(3);
	stack1.push(5);
	stack1.push(65);
	stack2.push(2);
	stack2.push(87);
	stack2.push(54);

	stack<int> tempStack = mergeSort(stack1, stack2);
	cout << "Final Stack: ";

	while(!tempStack.empty())
	{
		cout << tempStack.top() << " ";
		tempStack.pop();
	}

	cin.get();

	return 0;
}

