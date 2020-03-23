#include <iostream>
#include <cstdlib>
#include "List.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "PriorityQueue.cpp"
#include "Map.cpp"
using namespace std;



int main()
{  

/*********** List ************/
	cout << endl << "*****************" <<endl;
	cout << "List" << endl << endl;
	List<int> myList;
	myList.pushBack(1);
	myList.pushBack(5);
	myList.pushBack(3);
	myList.pushBack(7);
	myList.printList();
	cout << "Pushed back 1,5,3,7" <<endl <<endl;
	myList.pushFront(2);
	myList.pushFront(5);
	myList.pushFront(1);
	myList.printList();
	cout << "Pushed front 2,5,1" <<endl<<endl;

	myList.insert(100,5);
	myList.printList();
	cout << "Inserted 100 with index 5 " << endl<<endl;

	cout << myList[0] << " " << myList[1] << endl;
	cout << "Operator [] overload " << endl<<endl;

	myList.remove(5);
	myList.printList();

	cout << "Printing list(+1) with iterator" << endl;
	for(List<int>::Iterator it = myList.begin(); it!=myList.end(); it++)
	{
		cout << *it+1 << " ";
	}
	cout << endl;

	cout << "Printing list with const iterator" << endl;
	for(List<int>::ConstIterator cit = myList.cbegin(); cit!=myList.cend(); cit++)
	{
		cout << *cit << " ";
	}
	cout << endl;

	List<int> second(myList);
	cout << "Printing copy: " << endl;
	for(List<int>::Iterator itt = second.begin(); itt!=second.end(); itt++)
	{
		cout << *itt << " ";
	}
	cout << endl;	

	myList.~List();
	second.~List();



/********* Stack *************/
	cout << endl << "*****************" <<endl;
	cout << "Stack" <<endl <<endl;

	Stack<string> stack;
	stack.push("a");
	stack.push("b");
	stack.push("c");
	stack.push("d");
	stack.push("e");
	stack.printStack();
	cout << "Pushed back a,b,c,d,e" <<endl <<endl;

	stack.pop();
	Stack<string> cp(stack);
	stack.pop();
	stack.~Stack(); 
	cp.printStack();
	cp.~Stack();




/********* Queue ****************/
	cout << endl << "*****************" <<endl;
	cout << "Queue" <<endl <<endl;
	Queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.printQueue();
	cout << "^queue" << endl << endl;

	cout << "Dequeued last number" << endl;
	queue.dequeue();
	queue.printQueue();
	cout << "^queue" << endl << endl;

	Queue<int> cpy(queue);
	cpy.printQueue();
	cout << "^copy" << endl << endl;

	cpy.enqueue(10);
	cpy.printQueue();
	cout << "^copy" << endl << endl;

	queue.printQueue();
	cout << "^queue" << endl << endl;

	queue.~Queue();
	cpy.~Queue();



/********* PriorityQueue ****************/
	cout << endl << "*****************" <<endl;
	cout << "Priority Queue" <<endl <<endl;
	PriorityQueue <int> pq;
	pq.enqueue(1,1);
	pq.enqueue(2,10);
	pq.enqueue(4,5);
	pq.enqueue(0,6);
	pq.enqueue(8,3);
	cout << endl;
	pq.printPriorityQueue();
	cout << "^priority queue" << endl << endl;
	pq.dequeue();
	cout << endl;
	pq.printPriorityQueue();
	cout << "^priority queue" << endl << endl;
	PriorityQueue <int> pq_copy(pq);
	pq_copy.printPriorityQueue();
	cout << "^copy" << endl << endl;
	pq_copy.enqueue(100,100);
	pq_copy.printPriorityQueue();
	cout << "^copy" << endl << endl;
	pq_copy.~PriorityQueue();
	pq.~PriorityQueue();




/********* Map ****************/
	cout << endl << "*****************" <<endl;
	cout << "Map" <<endl <<endl;
	Map<string,string> map;
	cout << "Inserting values: " << endl;
	map.insert("a","Hello");
	map.insert("b","Welcome");
	map.insert("c","Hi");
	map.insert("d","Bye");
	map.insert("e","Yo");
	map.printAll(); 
	cout << endl << endl;
	map.printBuckets();
	cout << "^map" << endl << endl;
	cout << "Reference to value from key: ";
	string x = map("a");
	cout << x << endl << endl;
	map.remove("a");
	map.printBuckets();
	cout << "^map" << endl << endl;
	cout << endl << endl;
	Map<string,string> map_copy(map);
	map_copy.insert("zzz","NEW VALUE");
	cout << "Inserted new value to copy map" << endl;
	map_copy.printBuckets();
	cout << "^copy" << endl << endl;
	cout << endl;
	map.~Map();
	map_copy.~Map();

	Map<int,int> mymap;
	mymap.insert(1,3);
	mymap.insert(2,9);
	mymap.insert(13,78);
	mymap.insert(89,90);
	mymap.printBuckets();
	mymap.~Map();

}