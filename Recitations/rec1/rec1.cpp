/* 
   Jabid Methun
   jhm414
   This program reads a file and prints each line and prints the word count.
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string line ="";
	ifstream ifs("input.txt");
	while (getline(ifs, line)) //reads each line in the text file
	{
		cout << line << endl; //prints each line
	}
	ifs.close();

	int ctr = 0;
	ifstream ifs2("input.txt");
	while (ifs2 >> line) //reads the file word by word
	{
		ctr += 1; //increments counter by 1 for each word
	}
	ifs2.close();
	cout << "count: " << ctr << endl; //prints the count
	system("pause");
	return 0;
}

