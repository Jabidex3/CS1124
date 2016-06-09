/*
	Jabid Methun
	CS-UY 1124
	Section: B
	jhm414
	N14285139
	Rec07
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Instrument
{
public:
	virtual void makeSound() = 0;
};

class Brass : public Instrument
{
private:
	unsigned mouthpieceSize;
public:
	Brass(unsigned mouthpieceSize) :mouthpieceSize(mouthpieceSize){}
	void makeSound()
	{
		cout << "To make a sound... blow on a mouthpiece of size " << mouthpieceSize << endl;
	}
};

class String : public Instrument
{
private:
	unsigned pitch;
public:
	String(unsigned pitch) :pitch(pitch){}
	void makeSound()
	{
		cout << "To make a sound... bow a string with pitch "<< pitch << endl;
	}
};

class Percussion : public Instrument
{
private:
public:
	void makeSound()
	{
		cout << "To make a sound... hit me!" << endl;
	}
};

class Trumpet :public Brass
{
private:
public:
	Trumpet(unsigned mouthpieceSize) :Brass(mouthpieceSize){}
	void makeSound()
	{
		cout << "Toot";
	}
};

class Trombone :public Brass
{
private:
public:
	Trombone(unsigned mouthpieceSize) :Brass(mouthpieceSize){}
	void makeSound()
	{
		cout << "Blat";
	}
};

class Violin :public String
{
private:
public:
	Violin(unsigned pitch) :String(pitch){}
	void makeSound()
	{
		cout << "Screech";
	}
};

class Cello :public String
{
private:
public:
	Cello(unsigned pitch) :String(pitch){}
	void makeSound()
	{
		cout << "Squawk";
	}
};

class Drum :public Percussion
{
private:
public:
	Drum(){}
	void makeSound()
	{
		cout << "Boom";
	}
};

class Cymbal :public Percussion
{
private:
public:
	Cymbal(){}
		void makeSound()
	{
		cout << "Crash";
	}
};

class MILL{
private:
	vector < Instrument* > LendingLibrary ;
public:
	MILL(){}
	void receiveInstr(Instrument& x)
	{
		//x.makeSound();
		Instrument* thing = &x;
		for (size_t i = 0; i < LendingLibrary.size(); i++)
		{
			if (LendingLibrary[i] == NULL)
			{
				LendingLibrary[i] = thing;
				break;
			}	
		}
		LendingLibrary.push_back(thing);	
	}
	Instrument* loanOut()
	{
		Instrument* thing = NULL;
		for (size_t i = 0; i < LendingLibrary.size(); i++)
		{
			if (LendingLibrary[i] != NULL)
			{
				thing = LendingLibrary[i];
				LendingLibrary[i] = NULL;
				return thing;
			}
		}
		return thing;
	}
	void dailyTestPlay()
	{
		for (size_t i = 0; i < LendingLibrary.size(); i++)
		{
			if (LendingLibrary[i] != NULL)
				LendingLibrary[i]->makeSound();
		}
	}

};


class Musician 
{
public:
	Musician() : instr(NULL) {}
	void acceptInstr(Instrument & i) { instr = &i; }
	Instrument* giveBackInstr() {
		Instrument* tmp(instr);
		instr = NULL;
		return tmp;
	}
	void testPlay() const {
		if (instr)
			instr->makeSound();
		else
			cerr << "";//have no instr\n";
	}
private:
	Instrument* instr;
};

class Orch{
private:
	vector<Musician*> members;
public:
	Orch() :members(25){}
	void addPlayer(Musician& x)
	{
		members.push_back(&x);
	}

	void play()
	{
		for (int i = 0; i < members.size();i++)
		{
			if (members[i] != NULL)
				members[i]->testPlay();
		}
		
	}
};


int main()
{
	// PART ONE
/*	 cout << "Define some instruments ----------------------------------------\n";
	 Drum drum;
	 Cello cello(673);
	 Cymbal cymbal;
	 Trombone tbone( 4 );
	 Trumpet trpt( 12 ) ;
	 Violin violin( 567 ) ;

	 // use the debugger to look at the mill
	 cout << "Define the MILL ------------------------------------------------\n";
	 MILL mill;

	 cout << "Put the instruments into the MILL ------------------------------\n";
	 mill.receiveInstr( trpt );
	 mill.receiveInstr( violin );
	 mill.receiveInstr( tbone );
	 mill.receiveInstr( drum );
	 mill.receiveInstr( cello );
	 mill.receiveInstr( cymbal );

	 cout << "Daily test -----------------------------------------------------\n";
	 cout << endl;
	 cout << "dailyTestPlay()" << endl;
	 mill.dailyTestPlay();
	 cout << endl;

	 cout << "Define some Musicians-------------------------------------------\n";
	 Musician j;
	 Musician jj;
	 Musician q;

	 cout << "TESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
	 q.testPlay();	
	 cout << endl;
	 q.acceptInstr( *mill.loanOut() );
	 cout << endl;
	 q.testPlay();
	 cout << endl;
	 cout << "dailyTestPlay()" << endl;
	 mill.dailyTestPlay();

	 cout << endl << endl;

	 q.testPlay();	
	 cout << endl;
	 mill.receiveInstr( *q.giveBackInstr() );
	 j.acceptInstr( *mill.loanOut() );
	 q.acceptInstr( *mill.loanOut() );
	 cout << endl;
	 q.testPlay();
	 cout << endl;
	 j.testPlay();
	 cout << endl;
	 cout << "dailyTestPlay()" << endl;
	 mill.dailyTestPlay();

	 cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";

	 // fifth
	 mill.receiveInstr( *q.giveBackInstr() );
	 cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
	 mill.receiveInstr( *j.giveBackInstr() );


	 cout << endl;
	 cout << "dailyTestPlay()" << endl;
	 mill.dailyTestPlay();
	 cout << endl;

	 cout << endl;*/
	// The initialization phase

	//Part 2
	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	
	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());
	cout << endl;
	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << endl;
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());
	cout << endl;
	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);
	cout << endl;
	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();
	cout << endl;
	system("pause");
}