#include <iostream>
#include <stack>
#include <list>
#include <queue>
#include <map>
using namespace std;



int main()
{
	cout << "Simple program which tests STL structures" << endl;
/****** List *******/
	cout << endl << "*****************" <<endl;
	cout << "List" << endl;
	cout << "Testing: push_back(), push_front(), insert(), erase(), iterator, const_iterator"<< endl;
	list<int> myList;
	list<int>::iterator it;
	list<int>::const_iterator iter;
	int alist;
	int anumber;
	cout << "How many numbers do you want to push back? ";
	cin >> alist;
	for(int a=0; a<alist; a++)
	{
		cout << "Enter your number: ";
		cin >> anumber;
		myList.push_back(anumber);
		cout << "Pushed: " << anumber << endl; 
	}
	cout << "Printing the list: " << endl;
	for(it=myList.begin(); it!=myList.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	

	int aalist;
	cout << "Push front a number: ";
	cin >> aalist;
	myList.push_front(aalist);
	cout << "Printing the list: " << endl;
	for(iter=myList.begin(); iter!=myList.end();++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	it = myList.begin()++;
	myList.erase(it);
	cout << "Deleted " << *it <<endl;
	cout << "Printing the list: " << endl;
	for(it=myList.begin(); it!=myList.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	it = myList.begin();
	it++;
	cout << "Inserting new number with index 1" <<endl;
	myList.insert(it,9);
	for(iter=myList.begin(); iter!=myList.end();++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;	


	cout << endl << "List test ended" << endl << endl;


/****** Stack *******/
	cout << endl << "*****************" <<endl;
	cout << "Stack" << endl;
	cout << "Testing push(), pop(), empty()" <<endl;
	stack<int> myStack;
	cout << "Is the stack empty? (1-yes  0-no) " << myStack.empty() << endl;
	cout << "How many numbers do you want to push? ";
	int i;
	cin >> i;
	int number;
	for(int j=0; j<i; j++)
	{
		cout << "Enter your number: ";
		cin >> number;
		myStack.push(number);
		cout << "Pushed: " << number << endl; 
	}
	cout << "Is the stack empty? (1-yes  0-no) " << myStack.empty() << endl;
	while(!myStack.empty())
	{
		cout << "Popped " << myStack.top() <<endl;
		myStack.pop();
	}
	cout << endl << "Stack test ended" << endl << endl;



/****** Queue *******/
	cout << endl << "*****************" <<endl;
	cout << "Queue" << endl;
	cout << "Testing push(), back(), pop(), front(), size(), empty()" <<endl;
	queue<string> myQueue;
	cout << "Now, we try to test data structure on strings" << endl;
	cout << "Is the queue empty? (1-yes 0-no) " << myQueue.empty() << endl;
	cout << "Pushed some fruits to the queue" << endl;
	myQueue.push("apple");
	myQueue.push("orange");
	myQueue.push("banana");
	cout << "Last element is: " << myQueue.back() <<endl;
	string text;
	cout << "Push your fruit: ";
	cin >> text;
	myQueue.push(text);
	cout << "Last element is: " << myQueue.back() <<endl;
	cout << "First element is: " << myQueue.front() <<endl;
	cout << "Popped front: " << myQueue.front() <<endl;
	myQueue.pop();
	cout << "First element is: " << myQueue.front() <<endl;
	cout << "Size of queue: " << myQueue.size() <<endl;
	cout << endl << "Queue test ended" << endl << endl;




/****** PriorityQueue *******/
	cout << endl << "*****************" <<endl;
	cout << "Priority Queue" << endl;
	cout << "Testing push(), pop(), top(), empty()" <<endl;
	priority_queue<int> myPrior;
	cout << "How many numbers do you want to push? ";
	int x;
	cin >> x;
	cout << "Enter different numbers " <<endl;
	int n;
	for(int i=0; i<x; i++)
	{
		cout << "Enter number: ";
		cin >> n;
		myPrior.push(n);
	}
	
	while(!myPrior.empty())
	{
		cout << "Popped " << myPrior.top() << endl;
		myPrior.pop();
	}
	cout << endl << "Priority Queue test ended" << endl << endl;



/****** Map *******/
	cout << endl << "*****************" <<endl;
	cout << "Map" << endl;
	map<int,string> fruits;
	fruits[1] = "apple";
	fruits[2] = "banana";
	fruits[3] = "pear";
	fruits[4] = "orange";
	fruits[5] = "plum";

	map<int, string>::iterator findit = fruits.find(4);
	cout << "Fruits [4]: "<< findit->second << endl;

	cout << "fruits[1]: " << fruits[1] << endl; 

	cout << endl << "Map test ended" << endl << endl;
	
}
