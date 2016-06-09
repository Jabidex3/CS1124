/*
	Jabid Methun
	CS-UY 1124 Section B
	jhm414
	N14285139
	HW #5
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Lord;
class Noble
{
public:
	//constructor
	Noble(const string& name) : name(name)
	{	}

	//accessors
	string getName() const
	{
		return name;
	}

	virtual double getStrength() = 0;
	virtual void setStrength(double val) = 0;
	virtual bool checkDead() = 0;
	virtual void display() = 0;

	void battle(Noble& otherNoble)
	{
		cout << name << " battles " << otherNoble.getName() << endl;

		if (checkDead() == true && otherNoble.checkDead() == true)
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		else if (checkDead())
		{
			cout << "He's dead, " << otherNoble.name << endl;
		}
		else if (otherNoble.checkDead())
		{
			cout << "He's dead, " << name << endl;
		}
		else if (getStrength() > otherNoble.getStrength())
		{
			this->display();
			otherNoble.display();

			cout << name << " defeats " << otherNoble.name << endl;
			double ratio = (double)(otherNoble.getStrength()) / (double)(this->getStrength());
			setStrength(ratio * getStrength());
			otherNoble.setStrength(0);
		}
		else if (getStrength() < otherNoble.getStrength())
		{
			this->display();
			otherNoble.display();
			cout << otherNoble.name << " defeats " << name << endl;
			double ratio = (double)(getStrength()) / (double)(otherNoble.getStrength());
			otherNoble.setStrength(ratio * otherNoble.getStrength());
			setStrength(0);
		}
		else if (getStrength() == otherNoble.getStrength())
		{
			this->display();
			otherNoble.display();
			cout << "Mutual Annihalation : " << name << " and " << otherNoble.name;
			cout << " die at each other's hands" << endl;
			setStrength(0);
			otherNoble.setStrength(0);
		}
	}

private:
	string name;
};

class Protector{
public:
	//Constructor
	Protector(const string& name, int str) : name(name), str(str), employed(false)
	{	}

	//Accessors
	string getName() const
	{
		return name;
	}

	double getStr()
	{
		return str;
	}

	bool getStatus()
	{
		return employed;
	}
	Lord* getEmployer()
	{
		return lord;
	}

	//Mutators
	void setStr(double val)
	{
		str = val;
	}
	void setStatus(bool val)
	{
		employed = val;
	}

	void hire(Lord* employer)
	{
		lord = employer;
	}
	virtual void display() = 0;


private:
	string name;
	double str;
	bool employed;
	Lord* lord;
};

class Lord :public Noble
{
public:
	Lord(const string& name) : Noble(name), isDead(false){}
	double getStrength()
	{
		double totalStrength = 0;
		for (size_t i = 0; i < army.size(); i++)
		{
			totalStrength += army[i]->getStr();
		}
		return totalStrength;
	}

	bool checkDead()
	{
		return isDead;
	}

	void display()
	{
		for (Protector* i : army)
		{
			i->display();
		}
	}
	void setStrength(double val)
	{
		for (Protector* i : army)
		{
			i->setStr(0);
		}
		isDead = true;
	}
	void hires(Protector& combatant)
	{
		if (isDead != true)
		{
			if (combatant.getEmployer() == nullptr)
			{
				combatant.hire(this);
				army.push_back(&combatant);
				//strength += combatant.getStr();
			}
		}
	}
private:
	vector<Protector*> army;
	bool isDead = false;
};



class Wizard :public Protector{
public:
	Wizard(const string& name, int str) : Protector(name, str)
	{}

	virtual void display()
	{
		cout << "POOF!" <<endl;
	}
};

class Warrior :public Protector{
public:
	Warrior(const string& name, int str) : Protector(name, str)
	{}
};

class Archer : public Warrior{
public:
	Archer(const string& name, int str) : Warrior(name, str)
	{}
	virtual void display()
	{
		cout << "TWANG! " << getName() << " says: Take that in the name of my lord, " << getEmployer()->getName() << endl;
	}
};

class Swordsman : public Warrior{
public:
	Swordsman(const string& name, int str) : Warrior(name, str)
	{}
	virtual void display()
	{

		cout << "CLANG! " << getName() << " says: Take that in the name of my lord, " << getEmployer()->getName() << endl;
	}
};



class PersonWithStrengthToFight :public Noble
{
public:
	PersonWithStrengthToFight(const string& name, int str) : Noble(name), strength(str) {}

	double getStrength()
	{ 
		return strength; 
	}

	void setStrength(double str) 
	{ 
		strength = str; 
	}

	bool checkDead()
	{
		if (strength > 0)
			return false;
		else
			return true;
	}
	void display()
	{
		cout << "";
	}

private:
	double strength;
};



int main() 
{
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
	system("pause");
}