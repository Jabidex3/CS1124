/*
	Jabid Methun
	jhm414
	Recitation 3
	Sandwich Company
*/

#include <iostream>
#include <vector>

using namespace std;

class Sandwich
{
public:
	Sandwich(int tomatoes = 2, int cheese = 1, double mustard = 0.5, double mayo = 1) : bread(2), tomatoes(tomatoes), cheese(cheese), mustard(mustard), mayo(mayo)
	{

	}
	//Accessors
	int getTomatoes() const
	{
		return tomatoes;
	}

	int getCheese() const
	{
		return cheese;
	}

	double getMayo() const
	{
		return mayo;
	}

	double getMustard() const
	{
		return mustard;
	}

	//Mutators
	void setTomatoes(int val)
	{
		tomatoes = val;
	}

	void setCheese(int val)
	{
		cheese = val;
	}

	void setMayo(double val)
	{
		mayo = val;
	}

	void setMustard(double val)
	{
		mustard = val;
	}

	void display() const
	{
		cout << "Bread: " << bread << " slices" << endl;
		cout <<	"Cheese: " << cheese << " slices" << endl;
		cout << "Tomatoes: " << tomatoes << " slices" << endl;
		cout << "Mustard: " << mustard << " ounces" << endl;
		cout << "Mayo: " << mayo << " ounces" << endl;
	}
private:
	const int bread;
	int cheese;
	int tomatoes;
	double mustard;
	double mayo;
};

class SandwichTruck
{
public:
	void checkBeforeLeaving()
	{
		for (int i = 0; i < sandwiches.size(); i++)
		{
			sandwiches[i].display();
			cout << endl;
		}
	}
	void insertSandwiches(const Sandwich& sw)
	{
		sandwiches.push_back(sw);
	}
private:
	vector<Sandwich> sandwiches;
};
int main()
{
	/*
	Sandwich MySandwich(3, 2, 0.1, 0.5);
	MySandwich.display();
	*/
	Sandwich sandwichOne;
	Sandwich sandwichTwo;
	sandwichTwo.setMustard(0.0);
	Sandwich sandwichThree;
	sandwichThree.setCheese(2);
	Sandwich sandwichFour;
	SandwichTruck x;
	x.insertSandwiches(sandwichOne);
	x.insertSandwiches(sandwichTwo);
	x.insertSandwiches(sandwichThree);
	x.insertSandwiches(sandwichFour);
	x.checkBeforeLeaving();
	system("pause");
}