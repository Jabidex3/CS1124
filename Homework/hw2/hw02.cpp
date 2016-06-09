/*
	Jabid Methun
	CS-UY 1124 Section B
	jhm414
	N14285139
	HW #2
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Weapon
{
public:
	//Constructor
	Weapon(string& name, int str) : name(name), strength(str)
	{	}

	//Accessors
	string getName() const
	{
		return name;
	}
	int getStr()
	{
		return strength;
	}

	//Mutators
	void setStr(int val)
	{
		strength = val;
	}
private:
	string name;
	int strength;
};

class Warrior
{
public:
	//Constructor
	Warrior(string& name, Weapon sword) :name(name), sword(sword)
	{	}

	//Accessors
	string getName() const
	{
		return name;
	}

	Weapon& getWeapon() 
	{
		return sword;
	}

	void battleWith(Warrior& nameOfOpponent) //this warrior battles with other warrior
	{
		cout << name << " battles " << nameOfOpponent.getName() << endl;

		if (sword.getStr() == 0 && nameOfOpponent.getWeapon().getStr() > 0) //this warrior has 0 strength and opponent has more than zero strength
		{
			cout << "He's dead, " << nameOfOpponent.getName() << endl;
		}
		else if (sword.getStr() > 0 && nameOfOpponent.getWeapon().getStr() == 0)//this warrior has more than 0 strength and opponent has zero strength
		{
			cout << "He's dead, " << name << endl;
		}
		else if (sword.getStr() == 0 && nameOfOpponent.getWeapon().getStr() == 0)// both warriors have 0 strength
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		else if (sword.getStr() > nameOfOpponent.getWeapon().getStr()) //this warrior has more strength than the opponent
		{
			sword.setStr(sword.getStr() - nameOfOpponent.getWeapon().getStr());
			nameOfOpponent.getWeapon().setStr(0);
			cout << name << " defeats " << nameOfOpponent.getName() << endl;
		}
		else if (nameOfOpponent.getWeapon().getStr() > sword.getStr()) //opponent has more strength than this warrior
		{
			nameOfOpponent.getWeapon().setStr(nameOfOpponent.getWeapon().getStr() - sword.getStr());
			sword.setStr(0);
			cout << nameOfOpponent.getName() << " defeats " << name << endl;
		}
		else if (sword.getStr() == nameOfOpponent.getWeapon().getStr()) // both warriors have equal strength
		{
			sword.setStr(0);
			nameOfOpponent.getWeapon().setStr(0);
			cout << "Mutual Annihilation: " << name << " and " << nameOfOpponent.getName() << " die at each other's hands" << endl;
		}
	}

	void display() //print info
	{
		cout << "Name: " << name << ", weapon: " << sword.getName() << ", " << sword.getStr();
	}

private:
	string name;
	Weapon sword;
};



int main()
{
	ifstream warriorstream("warriors.txt");
	if (!warriorstream) // check if file is there
	{
		cerr << "does not exist\n";
		exit(1);
	}

	vector<Warrior> combatants;

	string commandGiven;
	while (warriorstream >> commandGiven)
	{
		if (commandGiven == "Warrior")
		{
			string name;
			string weaponName;
			int str;

			for (int i = 0; i < 1; i++) //reads one line, not entire file
			{
				warriorstream >> name >> weaponName >> str;
			}
			Weapon item(weaponName, str);
			Warrior awarrior(name, item);
			combatants.push_back(awarrior);
		}
		else if (commandGiven == "Battle")
		{
			string nameOne;
			string nameTwo;
			int firstWarrior;
			int secondWarrior;
			for (int i = 0; i < 1; i++) //reads one line, not entire file
			{
				warriorstream >> nameOne >> nameTwo;
			}
			for (size_t i = 0; i < combatants.size(); i++)
			{
				if (combatants[i].getName() == nameOne) //find index of first warrior
				{
					firstWarrior = i;
				}
			}

			for (size_t j = 0; j < combatants.size(); j++)
			{
				if (combatants[j].getName() == nameTwo) //find index of second warrior
				{
					secondWarrior = j;
				}
			}
			combatants[firstWarrior].battleWith(combatants[secondWarrior]);
		}
		else if (commandGiven == "Status")
		{
			cout << "There are: " << combatants.size() << " warriors" << endl;
			for (Warrior w : combatants)
			{
				w.display();
				cout << endl;
			}
		}
	}
	warriorstream.close();


	system("pause");
}