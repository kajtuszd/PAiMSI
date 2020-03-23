#include <cstdlib>
#include <iostream>
#pragma once
using namespace std;

template <typename type>
class List
{

	typedef struct Node
	{
		type field;
		Node *nextNode;
	} *nodePointer;

	nodePointer head;
	nodePointer current;
	nodePointer temporary;

	public:
	
		class Iterator;
		class ConstIterator;


		void pushBack(const type& newElement);
		void pushFront(const type& newElement);
		void insert(const type& newElement, int index);
		void remove(const type& element);

		Iterator begin(){return Iterator(head);};
		Iterator end(){return Iterator(NULL);};

		ConstIterator cbegin()const{return ConstIterator(head);};
		ConstIterator cend() const {return ConstIterator(NULL);};

		type& operator[](int index);

		List() {head=NULL; current=NULL; temporary=NULL;};
		List(const List &list);
		~List();
		void printList();
		int listLength();

};

template<typename type>
class List<type>::Iterator
{

public:

	Iterator(nodePointer newNode):node(newNode){};

	Iterator& operator++();
	Iterator operator++(type);

	type operator*(){return node->field;};
	bool operator!=(const Iterator& iterator) {return node!=iterator.node;};

private:

	nodePointer node;

};


template<typename type>
typename List<type>::Iterator& List<type>::Iterator::operator++()
{
	node = node->nextNode;
	return *this;
}

template<typename type>
typename List<type>::Iterator List<type>::Iterator::operator++(type)
{
	Iterator iterator = *this;
	++*this;
	return iterator;
}


template<typename type>
class List<type>::ConstIterator
{

public:

	ConstIterator(const nodePointer newNode):c_node(newNode){};

	ConstIterator& operator++();
	ConstIterator operator++(type);

	type operator*()const {return c_node->field;};
	bool operator!=(const ConstIterator& c_iterator) {return c_node!=c_iterator.c_node;};

private:

	nodePointer c_node;

};



template<typename type>
typename List<type>::ConstIterator& List<type>::ConstIterator::operator++()
{
	c_node = c_node->nextNode;
	return *this;
}

template<typename type>
typename List<type>::ConstIterator List<type>::ConstIterator::operator++(type)
{
	ConstIterator c_iterator = *this;
	++*this;
	return c_iterator;
}



template <typename type>
void List<type>::pushBack(const type& newElement)
{
	nodePointer newNodePtr = new Node;      /* pointer to added element */
	newNodePtr->nextNode = NULL;            
	newNodePtr->field = newElement;
	
	if(head != NULL)						/* if exists something behind head */
	{
		current = head;
		while(current->nextNode != NULL)    /* rewind list to the last element */
		{
			current = current->nextNode;
		}
		current->nextNode = newNodePtr;     /* add node to the end */
	}
	else
	{
		head = newNodePtr;                  /* add new node to head */
	}
}

template<typename type>
type& List<type>::operator[](int index)
{
	int i=0;
	current = head;
	while(i<index)                         /* rewinds list until searched element */
	{
		current=current->nextNode;
		i++;
	}
	return current->field;
}


template <typename type>
void List<type>::printList()
{
	current = head;
	while(current != NULL)
	{
		cout << current->field << " ";
		current = current->nextNode;
	}
	cout << endl;
}


template <typename type>
void List<type>::remove(const type& element)
{
	nodePointer PointerToDelete = NULL;
	temporary = head;
	current = head;
	while(current!=NULL && current->field != element)
	{
		temporary = current;
		current = current->nextNode;
	}
	if(current == NULL)
	{
		cout << element << " is not on the list\n";
		delete PointerToDelete;
	}
	else
	{
		PointerToDelete = current;
		current = current->nextNode;
		temporary->nextNode = current;
		if(PointerToDelete == head)
		{
			head = head->nextNode;
			temporary = NULL;
		}
		delete PointerToDelete;
		cout << "The value "<<element<<" was deleted\n"; 
	}

}

template<typename type>
void List<type>::pushFront(const type& newElement)
{
	nodePointer newNodePtr = new Node;      /* pointer to added element */
	newNodePtr->nextNode = head;
	newNodePtr->field = newElement;
	head = newNodePtr;
}


template<typename type>
void List<type>::insert(const type& newElement, int index)
{
	int length = listLength();
	if(length<index || index<0)
	{
		cout << "Misplaced index" <<endl;
	}
	else
	{
		if(index == 0)
		{
			pushFront(newElement);
		}
		else
		{
			if(index==length)
			{
				pushBack(newElement);
			}
			else
			{
				nodePointer newNodePtr = new Node;      /* pointer to added element */
				current = head;
				for(int i=0; i<index; i++)
				{
					temporary = current;
					current = current->nextNode;
				}
				temporary->nextNode = newNodePtr;
				newNodePtr->nextNode = current;
				newNodePtr->field = newElement;
			}
		}	
	}
}

template<typename type>
int List<type>::listLength()
{
	int numberOfElements = 0;
	current = head;
	while(current!=NULL)
	{
		current=current->nextNode;
		numberOfElements++;
	}
	return numberOfElements;
}

template<typename type>
List<type>::~List()
{
	while(head != NULL)
	{
		temporary = head->nextNode;
		delete head;
		head = temporary;
	}
}


template<typename type>
List<type>::List(const List &list)
{
	nodePointer cur = NULL;
	nodePointer nex = NULL;
	if(list.head == NULL)
	{
		head = NULL;
	}
	else
	{
		head = new Node;
		head->field = list.head->field;

		cur = head;
		nex = list.head->nextNode;
	}

	while(nex != NULL)
	{
		cur->nextNode = new Node;
		cur = cur->nextNode;
		cur->field = nex->field;
		nex = nex->nextNode;
	}
	cur -> nextNode = 0;
	
}
