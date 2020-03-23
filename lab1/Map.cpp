#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

int static const tabCapacity = 10;

template<typename KeyType, typename ValueType>
class Map
{

		
	typedef struct Hash
	{
		KeyType bucketKey;
		ValueType bucketValue;
		int index;
		Hash *nextHash;
	} *hashPointer;

	hashPointer head;
	hashPointer current;
	ValueType buckets[tabCapacity] ={};

public:
	Map();
	~Map();
	Map(const Map &map);
	void insert(const KeyType& key, const ValueType& value);
	ValueType& operator()(const KeyType& key);
	void remove(const KeyType& key);

	void printBuckets();
	bool isEmpty();
	void printAll();

};

int hashFunction(int key);
int hashFunction(string key);



template<typename KeyType, typename ValueType>
Map<KeyType,ValueType>::Map()
{
	this->head = NULL;
	this->current = NULL;
}

template<typename KeyType, typename ValueType>
Map<KeyType,ValueType>::~Map()
{
	current = head;
	while(head != NULL)
	{
		current = head->nextHash;
		delete head;
		head = current;
	}

}

template<typename KeyType, typename ValueType>
Map<KeyType,ValueType>::Map(const Map &map)
{
	if(map.head == NULL)
	{
		head = NULL;
		current = NULL;
	}
	else
	{
		head = NULL;
		current = NULL;
		hashPointer temp = map.head;
		while(temp != NULL)
		{
			insert(temp->bucketKey, temp->bucketValue);
			temp = temp->nextHash;
		}	
	}
}


template<typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::isEmpty()
{
	if(this->head == NULL && this->current == NULL)
		return true;
	else
		return false; 
}

template<typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::printAll()
{
	current = head;

	while(current!=NULL)
	{
		cout << current->bucketKey << " " << current->bucketValue << " " << current->index << endl;
		current = current->nextHash;
	}
}


template<typename KeyType, typename ValueType>
ValueType& Map<KeyType,ValueType>::operator()(const KeyType& key)
{
	current = head;

	while(current!=NULL && current->bucketKey != key)
	{
		current = current->nextHash;
	}
	if(current->bucketKey == key)
	{
		return buckets[current->index];
	}
	else
	{
		exit(1);
	}
}



template<typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::insert(const KeyType& key, const ValueType& value)
{
	hashPointer temporary = new Hash();
	temporary->bucketKey = key;
	temporary->bucketValue = value;
	temporary->index = hashFunction(key);
	temporary->nextHash = NULL;
	this->buckets[temporary->index] = temporary->bucketValue;
	
	if(isEmpty())
	{
		head = temporary;
	}
	else
	{
		current = head;
		while(current->nextHash != NULL)
		{
			current = current->nextHash;
		}
		current->nextHash = temporary;
	}
}


template<typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::printBuckets()
{
	for(int i=0; i<tabCapacity; i++)
	{
		cout << i <<". " << buckets[i] << endl;
	}
}



template<typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::remove(const KeyType& key)
{
	current = head;
	hashPointer temporary = head;
	hashPointer toDelete = NULL;

	while(current!=NULL && current->bucketKey != key)
	{
		temporary = current;
		current = current->nextHash;
	}
	if(current == NULL)
	{
		cout << "Element is not on the list\n";
		delete toDelete;

	}
	else
	{
		toDelete = current;
		current = current->nextHash;
		temporary->nextHash = current;
		if(toDelete == head)
		{
			head = head->nextHash;
		}
		buckets[toDelete->index] = "";
		cout << "Removed key: " << toDelete->bucketKey << ", with value: "<< toDelete->bucketValue << endl;
		delete toDelete;
	}
}



int hashFunction(string key)
{
	int hash = 0;
	int index;


	for (unsigned int i=0;  i<key.length(); i++)
	{
		hash = hash + (int)key[i];
	}
	index = hash%tabCapacity;
	return index;
}



int hashFunction(int key)
{
	int index;
	index = key%tabCapacity;
	return index;
}









