#include <cstdlib>
#include <iostream>
#pragma once
using namespace std;


template<typename type>
class PriorityQueue
{
	typedef struct Node
	{
		type field;
		int importance;
		Node *nextNode;
	} *nodePointer;

	nodePointer front;
	nodePointer back;

public:
	void enqueue(const type& newElement, int priority);
	void dequeue();
	~PriorityQueue();
	PriorityQueue();
	PriorityQueue(const PriorityQueue &pque);


	bool isEmpty();
	void pushBack(const type& newElement, int priority);
	void pushFront(const type& newElement, int priority);
	void pushFirstNode(const type& newElement, int priority);
	void pushInside(const type& newElement, int priority);
	void printPriorityQueue();
};


template<typename type>
PriorityQueue<type>::PriorityQueue()
{
	this->front = NULL;
	this->back = NULL;
}

template<typename type>
bool PriorityQueue<type>::isEmpty()
{
	if(this->front == NULL && this->back == NULL)
		return true;
	else
		return false;
}

template<typename type>
void PriorityQueue<type>::printPriorityQueue()
{
	if(isEmpty())
	{
		cout << "Priority queue is empty " <<endl;
	}
	else
	{
		nodePointer temporary = back;
		while(temporary!=NULL)
		{
			cout << "Field: " << temporary->field << "   Priority: " << temporary->importance <<endl;
			temporary = temporary->nextNode;
		}
		cout << endl;
	}
}


template<typename type>
void PriorityQueue<type>::pushFront(const type& newElement, int priority)
{
	nodePointer adder = new Node;           //
	adder->importance = priority;           // creating new node to be added
	adder->field = newElement;              //
	adder->nextNode = NULL; 
	
	front->nextNode = adder;                 // setting new node as end
	front = adder;
	cout << "Enqueued element "<< newElement << " with priority " << priority << endl;
}

template<typename type>
void PriorityQueue<type>::pushBack(const type& newElement, int priority)
{
	nodePointer adder = new Node;             //
	adder->importance = priority;             // creating new node to be added
	adder->field = newElement;                //

	adder->nextNode = back;                   // setting next node as beginner
	back = adder;                             // reseting back
	cout << "Enqueued element "<< newElement << " with priority " << priority << endl;
}

template<typename type>
void PriorityQueue<type>::pushFirstNode(const type& newElement, int priority)
{
	nodePointer adder = new Node;
	adder->importance = priority;
	adder->field = newElement;
	adder->nextNode = NULL;
	front = adder;                             //    
	back = adder;                              // setting first node as back and front
	cout << "Enqueued element "<< newElement << " with priority " << priority <<endl;
}


template<typename type>
void PriorityQueue<type>::pushInside(const type& newElement, int priority)
{                                   
	nodePointer scroller = back;
	nodePointer save = back;       // 'save' to remember last suitable scroller
	while(scroller != front && scroller->importance < priority)
	{
		save = scroller;                 // try to find a new place so that priority matches
		scroller = scroller->nextNode;
	}
	nodePointer toPush = new Node;
	toPush->importance = priority;
	toPush->field = newElement;
	toPush->nextNode = scroller;
	save->nextNode = toPush;
	cout << "Enqueued element "<< newElement << " with priority " << priority << endl;
}


template<typename type>
void PriorityQueue<type>::enqueue(const type& newElement, int priority)
{
	if(isEmpty())
	{
		pushFirstNode(newElement,priority);
	}
	else
	{
		if(front->importance < priority)
		{
			pushFront(newElement,priority);
		}
		else
		{
			if(back->importance > priority)
			{
				pushBack(newElement,priority);
			}
			else  
			{
				pushInside(newElement,priority);
			}
		}
	}	

}


template<typename type>
void PriorityQueue<type>::dequeue()
{
	if(isEmpty())
	{
		cout << "Priority queue is actually empty" <<endl;
	}
	else
	{
		if(back == front)
		{
			cout << "Dequeued element " << front->field << " with priority " << front->importance << endl;
			free(front);
			front = NULL;
			back = NULL;
		}
		else
		{
			nodePointer temporary = back;
			nodePointer save = back;
			while(temporary != front)
			{
				save = temporary;
				temporary=temporary->nextNode;
			}
			cout << "Dequeued element " << front->field << " with priority " << front->importance << endl;
			front = save;
			front->nextNode = NULL;
			delete temporary;
		}
	}
}




template<typename type>
PriorityQueue<type>::~PriorityQueue()
{
	while(back != NULL)
	{
		nodePointer temporary = back;
		back = back->nextNode;
		delete temporary;
	}
}


template<typename type>
PriorityQueue<type>::PriorityQueue(const PriorityQueue &pque)
{

	if(pque.front == NULL)// && pque.front == NULL)
	{
		back = NULL;
		front = NULL;
	}
	else
	{
		back = NULL;
		front = NULL;
		nodePointer temp = pque.back;

		while(temp != NULL)
		{
			enqueue(temp->field,temp->importance);
			temp = temp->nextNode;
		}
	}
}


