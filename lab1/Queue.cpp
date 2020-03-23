#include <cstdlib>
#include <iostream>
#pragma once
using namespace std;


template<typename type>
class Queue
{
	typedef struct Node
	{
		type field;
		Node *nextNode;
	} *nodePointer;

	nodePointer back;
	nodePointer front;

public:

	void enqueue(const type& newElement);
	void dequeue();
	bool isEmpty();
	Queue();
	~Queue();

	Queue(const Queue &queue);

	void printQueue();



};

template<typename type>
Queue<type>::Queue()
{
	this->back = NULL;
	this->front = NULL;
}

template<typename type>
bool Queue<type>::isEmpty()
{
	if(back == NULL && front == NULL)
		return true;
	else
		return false; 
}


template<typename type>
void Queue<type>::enqueue(const type& newElement)
{
	nodePointer pointer = new Node;      /* creating new pointer to be added */
	pointer->field = newElement;
	pointer->nextNode = NULL;

	if(front == NULL)					/* as first element */
	{
		front = pointer;
		back = pointer;
	}
	else
	{
		back->nextNode = pointer;       /* adding next node to back */
		back = pointer;					/* setting added node as new "back" */
	}
}

template<typename type>
void Queue<type>::dequeue()
{
	if(isEmpty())					// no elements
		cout << "Queue empty" << endl;
	else
		if(back == front)       //one element
		{
			cout << "dequeued: " << front->field << endl;
			free(front);
			front = NULL;
			back = NULL;
		}
		else 				    // more elements
		{
			nodePointer temporary = front;
			front = front->nextNode;
			cout << "dequeued: " << temporary->field << endl;
			delete temporary;
		}
}

template<typename type>
void Queue<type>::printQueue()
{
	if(isEmpty())
	{
		cout << "Queue empty" << endl;
	}
	else
	{
		nodePointer temporary = front;
		cout << "+++++++++++++++" << endl;
		while(temporary != NULL)
		{
			cout << temporary->field << " ";
			temporary = temporary->nextNode;
		}
		cout << endl <<"+++++++++++++++" << endl;	
	}

}

template<typename type>
Queue<type>::~Queue()
{
	while(front != NULL)
	{
		nodePointer temporary = front;
		front = front->nextNode;
		delete temporary;
	}
}

template<typename type>
Queue<type>::Queue(const Queue &queue)
{

	if(queue.back == NULL)
	{
		back = NULL;
		front = NULL;
	}
	else
	{
		back = NULL;
		front = NULL;
		nodePointer temp = queue.front;

		while(temp != NULL)
		{
			enqueue(temp->field);
			temp = temp->nextNode;
		}
	}
}



