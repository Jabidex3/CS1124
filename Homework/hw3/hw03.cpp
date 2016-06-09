/*
	Jabid Methun
	CS-UY 1124 Section B
	jhm414
	N14285139
	HW #3
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Warrior
{
public:
	//Constructor
	Warrior(const string& name, int str) :name(name), str(str)
	{	}

	//Accessors
	string getName() const
	{
		return name;
	}

	int getStr()
	{
		return str;
	}

	//Mutators
	void setStr(int val)
	{
		str = val;
	}

	void display() //print info
	{
		cout << name << ": " << str << endl;
	}

private:
	string name;
	int str;
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

	vector<Warrior*> getWarriors() 
	{
		return warriors; 
	}

	void hire(Warrior& combatant)
	{
		Warrior* employee = new Warrior(combatant.getName(), combatant.getStr());
		warriors.push_back(employee); //add warrior to vector
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
			cout << combatant.getName() << ", you're fired! -- " << name << endl;
			warriors[warriorIdx] = warriors[warriors.size() - 1];
			warriors.pop_back(); //remove warrior
		}
	}

	void display()
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
		
		if (warriors.size()> 0 && otherNoble.getWarriors().size() > 0)
		{
			int totalStrOfThisNoble = 0;
			int	totalStrOfOtherNoble = 0;
			int ratio;

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
					warriors[i]->setStr(warriors[i]->getStr() - (warriors[i]->getStr() * ratio)); //this noble's soldiers lose a portion of their strength
				}
				for (size_t i = 0; i < otherNoble.getWarriors().size(); i++)
				{
					otherNoble.getWarriors()[i]->setStr(0); // all warriors for other noble has 0 str now
				}

				cout << name << " defeats " << otherNoble.getName() << endl;
			}
			else if (totalStrOfOtherNoble > totalStrOfThisNoble)
			{
				ratio = totalStrOfThisNoble / totalStrOfOtherNoble;
				for (size_t i = 0; i < otherNoble.getWarriors().size(); i++)
				{
					otherNoble.getWarriors()[i]->setStr(otherNoble.getWarriors()[i]->getStr() - (otherNoble.getWarriors()[i]->getStr() * ratio)); //other noble's soldiers lose a portion of their strength
				}

				for (size_t i = 0; i < warriors.size(); i++)
				{
					warriors[i]->setStr(0); // all warriors for this noble has 0 str now
				}

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

				cout << "Mutual Annihilation: " << name << " and " << otherNoble.getName()	<< " die at each other's hands" << endl;
			}

		}
		else if (warriors.size() == 0 && otherNoble.getWarriors().size() == 0)
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		else if (warriors.size() == 0 && otherNoble.getWarriors().size()>0)
		{
			cout << "He's dead" << otherNoble.getName() << endl;
		}
		else if (warriors.size()> 0 && otherNoble.getWarriors().size() == 0)
		{
			cout << "He's dead" << name <<endl;
		}
	}

private:
	string name;
	vector <Warrior*> warriors;
};

int main() 
{
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	
	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
	

	system("pause");
}
