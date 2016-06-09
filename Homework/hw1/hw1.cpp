/*
	Name: Jabid Methun
	Net id: jhm414
	N-id: N14285139
	Description - This program reads a file of commands and depending on the command, either 
	creates a new warrior, causes a battle or lists the status of the warriors.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Warrior
{
	string name;
	int strength;
};

void battleWarriors(vector<Warrior>& combatants, string& nameOne, string& nameTwo) //warrior one battles warrior two
{
	int firstWarrior = 0;
	int secondWarrior = 0;
	for (int i = 0; i < combatants.size(); i++) 
	{
		if (combatants[i].name == nameOne) //find index of first warrior
		{
			firstWarrior = i;
		}
	}

	for (int j = 0; j < combatants.size(); j++) 
	{
		if (combatants[j].name == nameTwo) //find index of second warrior
		{
			secondWarrior = j;
		}
	}

	cout << combatants[firstWarrior].name << " battles " << combatants[secondWarrior].name << endl;
	
	if (combatants[secondWarrior].strength == 0 && combatants[firstWarrior].strength > 0) //2nd warrior had 0 strength and opponent has more than zero
	{
		cout << "He's dead " << combatants[firstWarrior].name << endl; 
	}
	else if (combatants[secondWarrior].strength > 0 && combatants[firstWarrior].strength == 0)//1st warrior had 0 strength and opponent has more than zero
	{
		cout << "He's dead " << combatants[secondWarrior].name << endl;
	}
	else if (combatants[secondWarrior].strength == 0 && combatants[firstWarrior].strength == 0)// both warriors have 0 strength
	{
		cout << "Oh, NO! they're both dead! Yuck!" << endl;
	}
	else if (combatants[firstWarrior].strength > combatants[secondWarrior].strength) //1st warrior has more strength than the 2nd warrior
	{
		combatants[firstWarrior].strength = combatants[firstWarrior].strength - combatants[secondWarrior].strength;
		combatants[secondWarrior].strength = 0;
		cout << combatants[firstWarrior].name << " defeats " << combatants[secondWarrior].name << endl;
	}
	else if (combatants[secondWarrior].strength > combatants[firstWarrior].strength) //2nd warrior has more strength than the 1st warrior
	{
		combatants[secondWarrior].strength = combatants[secondWarrior].strength - combatants[firstWarrior].strength;
		combatants[firstWarrior].strength = 0;
		cout << combatants[secondWarrior].name << " defeats " << combatants[firstWarrior].name << endl;
	}
	else if (combatants[firstWarrior].strength == combatants[secondWarrior].strength) // both warriors have equal strength
	{
		combatants[firstWarrior].strength = 0;
		combatants[secondWarrior].strength = 0;
		cout << "Mutual Annihilation: " << combatants[firstWarrior].name << " and " << combatants[secondWarrior].name << " die at each other's hands" << endl;
	}
}

void printStatus(vector<Warrior>&combatants) //prints name and strength of all warriors in vector
{
	cout << "There are: " << combatants.size() << " warriors" << endl;
	for (int i = 0; i < combatants.size(); i++)
	{
		cout << "Warrior: " << combatants[i].name << ", strength: " << combatants[i].strength << endl;
	}

}

int main()
{
	ifstream warriorstream("warriors.txt");
	if (!warriorstream) // check if file is there
	{
		cerr << "does not exist\n";
	}
	vector<Warrior> combatants; //vector of warriors

	string commandGiven;
	while (warriorstream >> commandGiven) 
	{
		if (commandGiven == "Warrior")
		{
			string name;
			int str;
			for (int i = 0; i < 1; i++) //reads one line, not entire file
			{
				warriorstream >> name >> str;
			}
			Warrior aWarrior;
			aWarrior.name = name;
			aWarrior.strength = str;
			combatants.push_back(aWarrior); //add warrior to vector
		}
		else if (commandGiven == "Battle")
		{
			string nameOne;
			string nameTwo;
			for (int i = 0; i < 1; i++) //reads one line, not entire file
			{
				warriorstream >> nameOne >> nameTwo;
			}
			battleWarriors(combatants, nameOne, nameTwo);
		}
		else if (commandGiven == "Status")
		{
			printStatus(combatants);
		}
	}
	system("pause");
}