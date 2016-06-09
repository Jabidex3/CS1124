/*
	Jabid Methun
	CS-UY 1124
	Section: B
	jhm414
	N14285139
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TNode 
{
	TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
	: data(data), left(left), right(right) {}
	int data;
	TNode *left, *right;
};

struct Node {
	Node(int data = 0, Node* next = NULL) : data(data), next(next) {}
	int data;
	Node* next;
};

int max(TNode* root)
{
	int maxNum = 0;
	int x = 0;
	int y = 0;
	if (root->data > maxNum)
		maxNum = root->data;
	if (root->left != nullptr)
		x = max(root->left);
	if (root->right != nullptr)
		y = max(root->right);
	if (maxNum > x && maxNum > y)
		return maxNum;
	else if (maxNum < x && x> y)
		return x;
	else
		return y;
}

Node* combineListVal(Node* listOne, Node* listTwo)
{
	if (!listOne || !listTwo)
		return nullptr;
	Node* result = new Node((listOne->data + listTwo->data), combineListVal(listOne->next, listTwo->next));
	return result;
}

void displayBinary(int n)
{
	if (n > 1)
	{
		displayBinary(n / 2);
		cout << n % 2;
	}
	else
		cout << n;
}

int sum(char* ch)
{
	if (ch[0] == '\0')
		return 0;
	else
		return int(ch[0]) + sum(ch + 1);
}

int binarySearch(char arr[], char target, int min, int max)
{
	if (min <= max)
	{
		int mid = (min + max) / 2;
		if (target == arr[mid])
			return mid;
		else if (arr[mid] < target)
			return binarySearch(arr, target, mid + 1, max);
		else
			return binarySearch(arr, target, min, mid - 1);
	}
	else
		return -1;
}

int main()
{
	displayBinary(18);
	cout << endl;
	Node* test1 = new Node(1, new Node(2, nullptr));
	Node* test2 = new Node(5, new Node(6, nullptr));
	Node* sumTest = combineListVal(test1, test2);
	cout << "List 1: " << test1->data << ", " << test1->next->data << endl;
	cout << "List 2: " << test2->data << ", " << test2->next->data <<endl;
	cout << "Combined Value: " << sumTest->data << ", " << sumTest->next->data <<endl;
	
	TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	cout << max(&f) << endl;
	char cstring[15] = "Hello\0";
	cout << sum(cstring)<<endl;
	char charac[15] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h','i','j','k','l','m','n','o'};

	cout << binarySearch(charac, 'j', 0, 14)<<endl;
	system("pause");
}