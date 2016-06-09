/*
	Jabid Methun
	CS-UY 1124
	Section: B
	jhm414
	N14285139
	Rec12
*/

#include <cstdlib> 
#include <iostream>
#include <string>

using namespace std;

struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

class Sequence{
private:
	Node* headPtr;
	Node* currPtr;
public:
	Sequence(Node* head = nullptr) : headPtr(head), currPtr(nullptr){}
	ostream& display(ostream& os = cout, const string& sep = " ")
	{
		if (headPtr ==nullptr)
		{
			return os;
		}
		else
		{
			Node* tPtr = headPtr;
			while (tPtr != nullptr)
			{
				os << tPtr->data << sep;
				tPtr = tPtr->link;
			}
			os << endl;
		}
		return os;
	}

	void add(int data)
	{
		//Node* tempCurr = currPtr;
		if (currPtr != nullptr)
		{
			currPtr->link = new Node(data, currPtr->link);
			currPtr = currPtr->link;
		}
		else
		{
		/*	Node* head = headPtr;
			headPtr = new Node(data);
			headPtr->link = head;
			tempCurr = headPtr;*/
			if (headPtr == nullptr)
				headPtr = new Node(data);
			else
				headPtr = new Node(data, headPtr);
				currPtr = headPtr;

		}
	}

	void remove()
	{
		if (currPtr == nullptr)
			return;
		else
		{
			Node* first = headPtr;
			while (first->link != currPtr)
				first = first->link;
			Node* nextCurr = currPtr;
			first->link = nextCurr->link;
			currPtr = currPtr->link;
			delete nextCurr;

		}

	}

	bool valid()
	{
		if (currPtr != nullptr)
			return true;
		else
			return false;
	}

	void reset(){
		currPtr = headPtr;
	}

	void next()
	{
		if (currPtr != nullptr)
			currPtr = currPtr->link;
		else
			return;
	}

	int data(){
		return currPtr->data;
	}

	void clear(){
		headPtr = nullptr;
		currPtr = nullptr;
	}
};


int main(){
	Sequence s;
	for (int i = 0; i < 6; ++i) s.add(i);
	s.display();
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 3; ++i) s.next();
	s.add(42);
	s.display();
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 2; ++i) s.next();
	s.remove();
	s.display();
	cout << "==========\n";
	s.clear();
	s.display();
	cout << "==========\n";
	
	system("pause");
}