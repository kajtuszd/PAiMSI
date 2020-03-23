#include <cstdlib>
#include <iostream>
#pragma once
using namespace std;

template <typename type>
class Stack
{
	typedef struct Node
	{
		type field;
		Node *nextNode;
	} *nodePointer;

	nodePointer top;   /* pointer to the node on the peak */
	
public:

	void push(const type& newElement);
	void pop();
	void printStack();

	Stack(){this->top = NULL;};
	~Stack();
	Stack(const Stack &stack);


};


template<typename type>
void Stack<type>::push(const type& newElement)
{
	nodePointer temporary = new Node;   
	temporary->field = newElement;
	if(top == NULL)
	{
		temporary->nextNode = NULL;
	}
	else
	{
		temporary->nextNode = top;
	}
	top = temporary;			 /* setting new top */
}

template<typename type>
void Stack<type>::pop()
{
	if(top != NULL)
	{
		nodePointer temporary = top;
		top = top->nextNode;
		cout << "Popped value: "<< temporary->field << endl;
		delete temporary;
	}
	else
	{
		cout << "Stack underflow" << endl;
	}
}

template<typename type>
Stack<type>::~Stack()
{
	while(top != NULL)
	{
		nodePointer temporary = top;
		top = top->nextNode;
		delete temporary;
	}
}

template <typename type>
void Stack<type>::printStack()
{
	cout << "________" << endl << endl;
	nodePointer temporary = top;
	while(temporary != NULL)
	{
		cout << "   " << temporary->field << endl;
		temporary = temporary->nextNode;
	}
	cout << "________" << endl << endl;
}

template<typename type>
Stack<type>::Stack(const Stack &stack)
{
	nodePointer cur;
	nodePointer nex;
	if(stack.top == NULL)
	{
		top = NULL;
	}
	else
	{
		top = new Node;
		top->field = stack.top->field;

		cur = top;
		nex = stack.top->nextNode;

		while(nex != NULL)
		{
			cur->nextNode = new Node;
			cur = cur->nextNode;
			cur->field = nex->field;
			nex = nex->nextNode;
		}
		cur -> nextNode = 0;
	}	
}