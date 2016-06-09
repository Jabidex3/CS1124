/*
	Jabid Methun
	CS-UY 1124
	Section: B
	jhm414
	N14285139
	Rec11
*/

#include <cstdlib> // To allow NULL if no other includes
#include <iostream>

using namespace std;

struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

void listDisplay(const Node* p) {
	while (p) {
		cout << p->data << ' ';
		p = p->link;
	}
	cout << endl;
}

void spliceIntoList(Node*head, Node*head2)
{
	Node* temp = head->link;
	head->link = head2;
	while (head2->link != nullptr)
		head2 = head2->link;
	if (head2->link == nullptr)
		head2->link = temp;
}

Node* isSubList(Node*head, Node*head2)
{
	while (head!=nullptr)
	{
		Node* firstHead = head;
		Node* secondHead = head2;
		while (secondHead != nullptr)
		{
			if (firstHead->data == secondHead->data)
			{
				firstHead = firstHead->link;
				secondHead = secondHead->link;
			}
			else
				break;

			if (secondHead == nullptr)
				return head;
		}
		head = head->link;
	}
	return nullptr;
}

int main(){
	cout << "Part One: " << endl;

	Node* list = nullptr;
	listInsertHead(1, list);
	listInsertHead(9, list);
	listInsertHead(7, list);
	listInsertHead(5, list);
	cout <<endl << "L1: ";
	listDisplay(list);

	Node* listTwo = nullptr;
	listInsertHead(2, listTwo);
	listInsertHead(3, listTwo);
	listInsertHead(6, listTwo);
	cout <<  "L2: ";
	listDisplay(listTwo);
	cout << "Target: ";
	listDisplay(list->link);
	cout << "Splicing L2 at target in L1" << endl;
	spliceIntoList(list->link, listTwo);
	cout << "L1: ";
	listDisplay(list);
	cout << "L2: ";
	listDisplay(listTwo);
	cout << "==================" << endl ;

	cout << endl << "Part two" << endl;
	cout << endl;

	Node* listThree = nullptr;
	listInsertHead(6, listThree);
	listInsertHead(5, listThree);
	listInsertHead(4, listThree);
	listInsertHead(2, listThree);
	listInsertHead(3, listThree);
	listInsertHead(2, listThree);
	listInsertHead(3, listThree);
	listInsertHead(2, listThree);
	listInsertHead(1, listThree);
	cout << "Target: ";
	listDisplay(listThree);
	cout << endl;

	Node* list4 = nullptr;
	listInsertHead(1, list4);
	cout << "Attempt match: 1" << endl;
	Node* plzWork = isSubList(listThree, list4);
	listDisplay(plzWork);
	cout << endl;

	Node* list5 = nullptr;
	listInsertHead(9, list5);
	listInsertHead(3, list5);
	cout << "Attempt match: 3 9" ;
	Node* plzWork1 = isSubList(listThree, list5);
	listDisplay(plzWork1);
	cout << "Failed to match" << endl;
	cout << endl;
	
	Node* list6 = nullptr;
	listInsertHead(3, list6);
	listInsertHead(2, list6);
	cout << "Attempt match: 2 3" << endl;
	Node* plzWork2 = isSubList(listThree, list6);
	listDisplay(plzWork2);
	cout << endl;

	Node* list7 = nullptr;
	listInsertHead(6, list7);
	listInsertHead(5, list7);
	listInsertHead(4, list7);
	listInsertHead(2, list7);
	cout << "Attempt match: 2 4 5 6" << endl;
	Node* plzWork3 = isSubList(listThree, list7);
	listDisplay(plzWork3);
	cout << endl;

	Node* list8 = nullptr;
	listInsertHead(4, list8);
	listInsertHead(2, list8);
	listInsertHead(3, list8);
	listInsertHead(2, list8);
	cout << "Attempt match: 2 3 2 4" << endl;
	Node* plzWork4 = isSubList(listThree, list8);
	listDisplay(plzWork4);
	cout << endl;

	Node* list9 = nullptr;
	listInsertHead(7, list9);
	listInsertHead(6, list9);
	listInsertHead(5, list9);
	cout << "Attempt match: 5 6 7";
	Node* plzWork5 = isSubList(listThree, list5);
	listDisplay(plzWork5);
	cout << "Failed to match" << endl;
	cout << endl;
	system("pause");

}