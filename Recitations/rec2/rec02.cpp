/*  
	Name: Jabid Methun
	net id: jhm414
	N-id: N14285139
	Description: This program reads a series of hydrocarbons from a text file and then
				 prints them in order of the number of carbons it has.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Hydrocarbon
{
	int numCarbon;
	int numHydrogen;
	vector<string> names;
};

size_t searchHC(vector<Hydrocarbon>& molecules, int numC, int numH) //searches through Hydrocarbon vector to see if molecule is already there
{
	for (size_t i = 0; i < molecules.size(); i++)
	{
		if (molecules[i].numCarbon == numC && molecules[i].numHydrogen == numH)
		{
			return i; //if it is there return position
		}
		else
		{
			return molecules.size(); //if not there, return size of vector, so you can add it
		}
	}
}

void readAndProcess(ifstream& ifs, vector<Hydrocarbon>& molecules) //populates molecules vector
{
	string name;
	int numC;
	int	numH;
	char junk;

	while (ifs >> name >> junk >> numC >> junk >> numH) //reads file
	{
		size_t index = searchHC(molecules, numC, numH);
			if (index == molecules.size())
			{
				Hydrocarbon AHyrdocarbon;
				AHyrdocarbon.numCarbon = numC;
				AHyrdocarbon.numHydrogen= numH;
				AHyrdocarbon.names.push_back(name);
				molecules.push_back(AHyrdocarbon);
			}
			else
			{
				molecules[index].names.push_back(name);
			}
	}
}
void displayHydrocarbon(vector<Hydrocarbon>& molecules) //prints hydroCarbons
{
	int biggestCarbon = 0;
	for (int i = 0; i < molecules.size(); i++)
	{
		if (molecules[i].numCarbon > biggestCarbon)
		{
			biggestCarbon = molecules[i].numCarbon;
		}
	}

	for (int i = 0; i <= biggestCarbon; i++)
	{
		for (int j = 0; j < molecules.size(); j++)
		{
			if (molecules[j].numCarbon == i)
			{
				cout << "C" << molecules[j].numCarbon << "H" << molecules[j].numHydrogen << endl;
				for (int k = 0; k < molecules[j].names.size(); k++)
				{
					cout << molecules[j].names[k] << endl;
				}
			}
		}
	}

}


int main()
{
	ifstream hydrostream("hydrocarbons.txt");
	if (!hydrostream)
	{
		cerr << "does not exist\n";
		exit(1);
	}
	vector<Hydrocarbon> molecules;
	readAndProcess(hydrostream, molecules);
	displayHydrocarbon(molecules);
	system("pause");
}