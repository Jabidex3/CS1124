/*
	Jabid Methun
	CS-UY 1124 Section B
	jhm414
	N14285139
	HW #4
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Warrior
{
public:
	//Constructor
	Warrior(const string& name, int str) :name(name), str(str), freeAgent(true)
	{	}

	//Accessors
	string getName() const
	{
		return name;
	}

	int getStr() const
	{
		return str;
	}
	bool getJobStatus()
	{
		return freeAgent;
	}
	//Mutators
	void setStr(int val)
	{
		str = val;
	}
	void setJobStatus(bool thing)
	{
		freeAgent= thing;
	}
	void display() const//print info
	{
		cout << name << ": " << str << endl;
	}

private:
	string name;
	int str;
	bool freeAgent;
};

class Noble
{
public:
	//constructor
	Noble(const string &name) : name(name)
	{	}

	//accessors
	string getName() const
	{
		return name;
	}

	bool aliveNow() 
	{
		return isAlive;
	}

	vector<Warrior*> getWarriors()
	{
		return warriors;
	}

	//mutators
	void setAlive(bool thing)
	{
		isAlive = thing;
	}

	void hire(Warrior& combatant)
	{
		warriors.push_back(&combatant);
		combatant.setJobStatus(false);
	}

	void fire(Warrior& combatant)
	{
		int warriorIdx = 0;
		for (size_t i = 0; i < warriors.size(); i++)
		{
			if (combatant.getName() == warriors[i]->getName())
			{
				warriorIdx = i;
			}
		}

		if (warriorIdx >= 0)
		{
			cout <<"You don't work for me anymore "<< combatant.getName() << "! -- " << name << endl;
			warriors[warriorIdx] = warriors[warriors.size() - 1];
			warriors.pop_back(); //remove warrior
			combatant.setJobStatus(true);
		}
	}

	void display() const
	{
		cout << name << " has an army of " << warriors.size() << endl;
		for (size_t i = 0; i < warriors.size(); i++)
		{
			cout << "	";
			warriors[i]->display();
		}
	}

	void battle(Noble& otherNoble)
	{
		cout << name << " battles " << otherNoble.getName() << endl;

		if (isAlive == true && otherNoble.aliveNow() == true)
		{
			int totalStrOfThisNoble = 0;
			int	totalStrOfOtherNoble = 0;
			double ratio;

			for (size_t i = 0; i < warriors.size(); i++)
			{
				totalStrOfThisNoble += warriors[i]->getStr(); //find sum of str of warriors for first noble
			}

			for (size_t i = 0; i < otherNoble.getWarriors().size(); i++)
			{
				totalStrOfOtherNoble += otherNoble.getWarriors()[i]->getStr(); //find sum of str of warriors for other noble
			}

			if (totalStrOfThisNoble > totalStrOfOtherNoble)
			{
				ratio = totalStrOfOtherNoble / totalStrOfThisNoble;
				for (size_t i = 0; i < warriors.size(); i++)
				{
					warriors[i]->setStr((warriors[i]->getStr() - (warriors[i]->getStr() * ratio))); //this noble's soldiers lose a portion of their strength
				}
				for (size_t i = 0; i < otherNoble.getWarriors().size(); i++)
				{
					otherNoble.getWarriors()[i]->setStr(0); // all warriors for other noble has 0 str now
				}

				otherNoble.setAlive(false);
				cout << name << " defeats " << otherNoble.getName() << endl;
			}
			else if (totalStrOfOtherNoble > totalStrOfThisNoble)
			{
				ratio = totalStrOfThisNoble / totalStrOfOtherNoble;
				for (size_t i = 0; i < otherNoble.getWarriors().size(); i++)
				{
					otherNoble.getWarriors()[i]->setStr((otherNoble.getWarriors()[i]->getStr() - (otherNoble.getWarriors()[i]->getStr() * ratio))); //other noble's soldiers lose a portion of their strength
				}

				for (size_t i = 0; i < warriors.size(); i++)
				{
					warriors[i]->setStr(0); // all warriors for this noble has 0 str now
				}

				isAlive = false;
				cout << otherNoble.getName() << " defeats " << name << endl;
			}
			else if (totalStrOfThisNoble == totalStrOfOtherNoble)
			{
				for (size_t i = 0; i < warriors.size(); i++)
				{
					warriors[i]->setStr(0);
				}

				for (size_t i = 0; i < otherNoble.getWarriors().size(); i++)
				{
					otherNoble.getWarriors()[i]->setStr(0);
				}
				otherNoble.setAlive(false);
				isAlive = false;
				cout << "Mutual Annihilation: " << name << " and " << otherNoble.getName() << " die at each other's hands" << endl;
			}

		}
		else if (isAlive == false && otherNoble.aliveNow() == false)
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		else if (isAlive == false && otherNoble.aliveNow() == true)
		{
			cout << "He's dead " << otherNoble.getName() << endl;
		}
		else if (isAlive == true && otherNoble.aliveNow() == false)
		{
			cout << "He's dead " << name << endl;
		}
	}

private:
	string name;
	vector <Warrior*> warriors;
	bool isAlive = true;
};

int main()
{
	ifstream warriorstream("nobleWarriors.txt");
	if (!warriorstream) // check if file is there
	{
		cerr << "does not exist\n";
	}
	vector<Noble*> nobles;
	vector<Warrior*> warriors;
	string commandGiven;
	while (warriorstream >> commandGiven)
	{
		if (commandGiven == "Noble")
		{
			string name;
			bool isThere = false;
			for (int i = 0; i < 1; i++) 
			{
				warriorstream >> name;
			}
			for (size_t i = 0; i < nobles.size(); i++)
			{
				if (name == nobles[i]->getName())
				{
					cout << "Noble Already Exists" << endl;
					isThere = true;
				}
			}
			if (isThere == false)
			{
				nobles.push_back(new Noble(name));
			}
		}
		else if (commandGiven == "Warrior")
		{
			string name;
			int str;
			bool isThere = false;
			for (int i = 0; i < 1; i++) 
			{
				warriorstream >> name >> str;
			}
			for (size_t i = 0; i < warriors.size(); i++)
			{
				if (name == warriors[i]->getName())
				{
					cout << "Warrior Already Exists" << endl;
					isThere = true;
				}
			}
			if (isThere == false)
			{
				warriors.push_back(new Warrior(name, str));
			}
		}
		else if (commandGiven == "Hire")
		{
			string nobleName;
			string warriorName;
			bool nobleBorn = false;
			bool warriorBorn = false;
			int indexOfNoble;
			int indexOfWarrior;
			for (int i = 0; i < 1; i++)
			{
				warriorstream >> nobleName >> warriorName;
			}
			for (size_t i = 0; i < nobles.size(); i++)
			{
				if (nobleName == nobles[i]->getName())
				{
					indexOfNoble = i;
					nobleBorn = true;
				}
			}
			if (nobleBorn == false)
			{
				cout << "Noble Does Not Exist" << endl;
			}

			for (size_t i = 0; i < warriors.size(); i++)
			{
				if (warriorName == warriors[i]->getName())
				{
					indexOfWarrior = i;
					warriorBorn = true;
				}
			}
			if (warriorBorn == false)
			{
				cout << "Warrior Does Not Exist" << endl;
			}
			if (nobleBorn == true && warriorBorn == true)
			{
				nobles[indexOfNoble]->hire(*warriors[indexOfWarrior]);
			}
		}
		else if (commandGiven == "Status")
		{
			cout << "Status" << endl << "======="<<endl << "Nobles:" <<endl;
			for (Noble* n : nobles)
			{
				n->display();
			}

			cout << "Unemployed Warriors:" << endl;
			for (size_t i = 0; i < warriors.size(); i++)
			{
				if (warriors[i]->getJobStatus()==true)
				{	
					warriors[i]->display();
				}
			}

			if (nobles.size() == 0)
			{
				cout << "NONE" << endl;
			}

		}
		else if (commandGiven == "Fire")
		{
			string nobleName;
			string warriorName;
			int indexOfNoble;
			int indexOfWarrior;
			for (int i = 0; i < 1; i++)
			{
				warriorstream >> nobleName >> warriorName;
			}
			for (size_t i = 0; i < nobles.size(); i++)
			{
				if (nobleName == nobles[i]->getName())
				{
					indexOfNoble = i;
				}
			}
			for (size_t i = 0; i < warriors.size(); i++)
			{
				if (warriorName == warriors[i]->getName())
				{
					indexOfWarrior = i;
				}
			}
			nobles[indexOfNoble]->fire(*warriors[indexOfWarrior]);
		}
		else if (commandGiven == "Battle")
		{
			string nobleOne;
			string otherNoble;
			int indexOfOne = 0;
			int indexOfOther = 0;
			for (int i = 0; i < 1; i++)
			{
				warriorstream >> nobleOne >> otherNoble;
			}
			for (size_t i = 0; i < nobles.size(); i++)
			{
				if (nobleOne == nobles[i]->getName())
				{
					indexOfOne = i;
				}		
			}
			for (size_t i = 0; i < nobles.size(); i++)
			{
				if (otherNoble == nobles[i]->getName())
				{
					indexOfOther = i;
				}
			}
			nobles[indexOfOne]->battle(*nobles[indexOfOther]);
		}
		else if (commandGiven == "Clear")
		{
			nobles.clear();
			warriors.clear();
		}
	}
	system("pause");
}
