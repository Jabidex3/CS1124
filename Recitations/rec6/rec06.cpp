/*
	Jabid Methun
	CS-UY 1124
	Section: B
	jhm414
	N14285139
	Rec06
*/
#include <iostream>
#include <vector>

using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned numPages)
		: numOfPages(numPages)
	{}
	virtual void displayNumPages() const = 0;
	

private:
	unsigned numOfPages;
};

/*void displayNumberOfPages(const PrintedMaterial& printedThing)
{
	printedThing.displayNumPages();
}*/
void PrintedMaterial::displayNumPages() const {
	cout << numOfPages << endl;
}
class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned numPages)
		: PrintedMaterial(numPages)
	{}
	void displayNumPages() const
	{
		cout << " I'm a Magazine object stored\n"
			<< "(but I can't know that I am being\n"
			<< "stored (by pointer) in a vector of\n"
			<< "PrintedMaterial pointers!\n";
		PrintedMaterial::displayNumPages();
		cout << "(and I'm very glossy!\n";
	}
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned numPages)
		: PrintedMaterial(numPages)
	{}

private:
};

class TextBook : public Book {
public:
	TextBook(unsigned numPages, unsigned numIndxPgs)
		: Book(numPages),
		numOfIndexPages(numIndxPgs)
	{}
	void displayNumPages() const
	{
		//cout << "Pages:";
		//PrintedMaterial::displayNumPages();
		//cout << numOfPages;
		//cout << "Index: " << numOfIndexPages << endl;
		cout << "\nThis is a textbook.\n";
		cout << "It is a very boring textbook.\n";
		cout << "Pages: ";
		PrintedMaterial::displayNumPages();
		cout << "Index pages: ";
		cout << numOfIndexPages << endl;
	}

private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned numPages)
		: Book(numPages)
	{}
	void displayNumPages() const
	{
		cout << "\nThis is the story of a very\n"
			<< " interesting programmer's quest\n"
			<< "  understand inheritance.\n"
			<< "   The journey is just beginning\n"
			<< "    and already the journeyman\n"
			<< "      hacker, no - not a hacker! -\n"
			<< "         a programmer who reads, and\n"
			<< "             studies and understands code\n"
			<< "                 Hackers steal and don't even\n"
			<< "                      try to understand what they stole\n"
			<< "                           before using it.\n"
			<< "\n       ...But I digress.\n"
			<< "\nThis novel is quite long, there\n"
			<< "being this number of pages:\n"
			<< "=====================================\n"
			<< "                 ";
		PrintedMaterial::displayNumPages();
		cout << "=====================================\n"
			<< "Whew!\n"
			<< " but there is an exciting\n"
			<< "  programming adventure on every\n"
			<< "   single one of them!\n"
			<< "    And now, let's let the quest continue..."
			<< endl << endl << endl;
	}
private:
};




// tester/modeler code
int main()
{
	TextBook t(5430, 234);
	Novel n(213);
	Magazine m(6);

	t.displayNumPages();
	n.displayNumPages();
	m.displayNumPages();

	vector< PrintedMaterial* > stuff;
	stuff.push_back(&t);
	stuff.push_back(&n);
	stuff.push_back(&m);
	for (size_t x = 0; x < stuff.size(); x++)
	{
		stuff[x]->displayNumPages();
		cout << endl;
	}
	system("pause");
}